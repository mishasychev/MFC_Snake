#pragma once

#include <deque>
#include "IModeDispatcher.h"

using namespace std;

class Snake
{
public:
	void Movement(IModeDispatcher* dispatcher, Directions& d, Apple* apple)
	{
		if (WrongDirection_(d))
		{
			d = lastDirection;
		}

		auto* begin = &sn.back();
		switch (d)
		{
			case Directions::UP:
			{
				if (begin->GetY() == 0)
				{
					sn.push_back(Location(begin->GetX(), 24 * CELL));
					break;
				}
				sn.push_back(Location(begin->GetX(), begin->GetY() - CELL));
				break;
			}
			case Directions::DOWN:
			{
				sn.push_back(Location(begin->GetX(), (begin->GetY() + CELL) % 500));
				break;
			}
			case Directions::LEFT:
			{
				if (begin->GetX() == 0)
				{
					sn.push_back(Location(39 * CELL, begin->GetY()));
					break;
				}
				sn.push_back(Location(begin->GetX() - CELL, begin->GetY()));
				break;
			}
			case Directions::RIGHT:
			{
				sn.push_back(Location((begin->GetX() + CELL) % 800, begin->GetY()));
				break;
			}
		}

		if (!CheckApple_(apple))
		{
			sn.pop_front();
		}
		CheckSnake_(dispatcher);

		lastDirection = d;
	}

	void Draw(CClientDC* dc)
	{
		COLORREF col = RGB(51, 204, 51);

		for(const auto& i : sn)
		{
			CPoint p(i.GetX(), i.GetY());
			CSize s(CELL, CELL);
			CRect rect(p, s);
			dc->FillRect(&rect, &CBrush(col));
		}
	}

	inline void Reset()
	{
		lastDirection = Directions::UP;
		sn.clear();
		sn.push_back(Location(19 * CELL, 13 * CELL));
	}

private:
	deque<Location> sn;
	Directions lastDirection = Directions::UP;

	bool WrongDirection_(Directions& d)
	{
		if (d == Directions::UP && lastDirection == Directions::DOWN)
			return true;
		if (d == Directions::DOWN && lastDirection == Directions::UP)
			return true;
		if (d == Directions::LEFT && lastDirection == Directions::RIGHT)
			return true;
		if (d == Directions::RIGHT && lastDirection == Directions::LEFT)
			return true;
		return false;
	}

	bool CheckApple_(Apple* apple)
	{
		if (apple->GetLocation() == sn.back())
		{
			apple->NewLocation();
			return true;
		}
		return false;
	}
	void CheckSnake_(IModeDispatcher* dispatcher)
	{
		for (mUINT64 i = 0; i < sn.size() - 1; i++)
		{
			if (sn[i] == sn.back())
			{
				dispatcher->SetMode(Modes::RESULT);
				return;
			}
		}
	}
};