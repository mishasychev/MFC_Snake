#pragma once

#include <deque>
#include "IModeDispatcher.h"

#include <cstdlib>
#include <ctime>

using namespace std;

class Snake
{
public:
	void Movement(IModeDispatcher* dispatcher, Directions& d, Apple* apple)
	{
		if (WrongDirection(d))
		{
			d = lastDirection;
		}

		auto* begin = &sn.back();
		switch (d)
		{
			case Directions::UP:
			{
				if (begin->second == 0)
				{
					sn.push_back(make_pair(begin->first, 24 * CELL));
					break;
				}
				sn.push_back(make_pair(begin->first, begin->second - CELL));
				break;
			}
			case Directions::DOWN:
			{
				sn.push_back(make_pair(begin->first, (begin->second + CELL) % 500));
				break;
			}
			case Directions::LEFT:
			{
				if (begin->first == 0)
				{
					sn.push_back(make_pair(39 * CELL, begin->second));
					break;
				}
				sn.push_back(make_pair(begin->first - CELL, begin->second));
				break;
			}
			case Directions::RIGHT:
			{
				sn.push_back(make_pair((begin->first + CELL) % 800, begin->second));
				break;
			}
		}

		if (!CheckApple(apple))
		{
			sn.pop_front();
		}
		CheckSnake(dispatcher);

		lastDirection = d;
	}

	void Draw(CClientDC* dc)
	{
		/*COLORREF col = RGB(51, 204, 51);*/
		COLORREF col;
		srand(/*static_cast<UINT>(time(nullptr))*/rand());

		for(const auto& i : sn)
		{
			col = RGB(rand() % 256, rand() % 256, rand() % 256);
			CPoint p(i.first, i.second);
			CSize s(CELL, CELL);
			CRect rect(p, s);
			dc->FillRect(&rect, &CBrush(col));
		}
	}

	void Reset()
	{
		lastDirection = Directions::UP;
		sn.clear();
		sn.push_back(make_pair(19 * CELL, 13 * CELL));
	}

private:
	deque<pair<UINT16, UINT16>> sn;
	Directions lastDirection = Directions::UP;

	bool WrongDirection(Directions& d)
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

	bool CheckApple(Apple* apple)
	{
		if (apple->GetLocation() == sn.back())
		{
			apple->NewLocation();
			return true;
		}
		return false;
	}
	void CheckSnake(IModeDispatcher* dispatcher)
	{
		for (UINT64 i = 0; i < sn.size() - 1; i++)
		{
			if (sn[i].first == sn.back().first && sn[i].second == sn.back().second)
			{
				dispatcher->SetMode(Modes::RESULT);
				return;
			}
		}
	}
};