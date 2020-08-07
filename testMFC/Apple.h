#pragma once

#include "constants.h"

#include <cstdlib>
#include <ctime>

class Apple
{
public:
	Apple()
		: point_(0, 0)
	{
		srand(static_cast<tUINT32>(time(nullptr)));
		NewLocation();
	}

	void NewLocation()
	{
		point_.SetX((rand() % 40) * CELL);
		point_.SetY((rand() % 25) * CELL);
	}

	void Draw(CDC* dc)
	{
		CRect cellRect(CPoint(point_.GetX(), point_.GetY()), CSize(CELL, CELL));
		COLORREF col = RGB(255, 51, 0);
		dc->FillRect(&cellRect, &CBrush(col));
	}

	__forceinline const Point& GetLocation() const { return point_; }

private:
	Point point_;
};
