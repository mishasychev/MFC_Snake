#pragma once

#include <deque>
#include "IModeDispatcher.h"

using namespace std;

class Snake
{
private:
	deque<pair<int, int>> sn;
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
public:
	void Movement(IModeDispatcher* dispatcher, Directions& d, Apple* apple)
	{
		if (WrongDirection(d))
		{
			d = lastDirection;
		}

		pair<int, int>* begin = &sn.back();
		switch (d)
		{
		case Directions::UP:
		{
			if (begin->second == 0)
			{
				sn.push_back(pair<int, int>(begin->first, 24 * CELL));
				break;
			}
			sn.push_back(pair<int, int>(begin->first, begin->second - CELL));
			break;
		}
		case Directions::DOWN:
		{
			sn.push_back(pair<int, int>(begin->first, (begin->second + CELL) % 500));
			break;
		}
		case Directions::LEFT:
		{
			if (begin->first == 0)
			{
				sn.push_back(pair<int, int>(39 * CELL, begin->second));
				break;
			}
			sn.push_back(pair<int, int>(begin->first - CELL, begin->second));
			break;
		}
		case Directions::RIGHT:
		{
			sn.push_back(pair<int, int>((begin->first + CELL) % 800, begin->second));
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
		int count = sn.size();
		while (--count)
		{
			CPoint p((sn.begin() + count)->first, (sn.begin() + count)->second);
			CSize s(CELL, CELL);
			CRect rect(p, s);
			COLORREF col = RGB(51, 204, 51);
			dc->FillRect(&rect, &CBrush(col));
		}
	}

	void Reset()
	{
		lastDirection == Directions::UP;
		sn.clear();
		sn.push_back(pair<int, int>(19 * CELL, 12 * CELL));
		sn.push_back(pair<int, int>(19 * CELL, 13 * CELL));
	}

private:
	bool CheckApple(Apple* apple)
	{
		if (apple->x == sn.back().first && apple->y == sn.back().second)
		{
			apple->NewLocation();
			return true;
		}
		return false;
	}
	void CheckSnake(IModeDispatcher* dispatcher)
	{
		pair<int, int>* begin = &sn.back();
		int count = sn.size();
		while (--count)
		{
			if ((sn.begin() + count - 1)->first == begin->first && (sn.begin() + count - 1)->second == begin->second)
			{
				dispatcher->SetMode(Modes::RESULT);
				return;
			}
		}
	}
};