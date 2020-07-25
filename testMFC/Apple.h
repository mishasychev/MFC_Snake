#pragma once

#include "constants.h"

#include <cstdlib>
#include <ctime>

class Apple
{
public:
	Apple()
		: location_(0, 0)
	{
		srand(static_cast<mUINT32>(time(nullptr)));
		NewLocation();
	}

	__inline void NewLocation()
	{
		location_.SetX((rand() % 40) * CELL);
		location_.SetY((rand() % 25) * CELL);
	}

	__inline void Draw(CDC* dc)
	{
		CRect cellRect(CPoint(location_.GetX(), location_.GetY()), CSize(CELL, CELL));
		COLORREF col = RGB(255, 51, 0);
		dc->FillRect(&cellRect, &CBrush(col));
	}

	__forceinline const Location GetLocation() const
	{
		return location_;
	}

private:
	Location location_;
};
