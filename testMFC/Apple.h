#pragma once

#include "constants.h"

#include <cstdlib>
#include <ctime>

class Apple
{
public:
	Apple()
	{
		srand(static_cast<tUINT32>(time(nullptr)));
		NewLocation();
	}

	__inline void NewLocation()
	{
		point_ = Point((rand() % 40) * CELL, (rand() % 25) * CELL);
	}

	void Draw(CDC* dc)
	{
		CRect cellRect(CPoint(point_.GetX(), point_.GetY()), CSize(CELL, CELL));
		COLORREF col = RGB(255, 51, 0);
		dc->FillRect(&cellRect, &CBrush(col));
	}

	__forceinline const Point& GetLocation() const { return point_; }

private:
	Point point_{ 0, 0 };
};
