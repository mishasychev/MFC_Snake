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
		score_++;
	}

	__inline void Draw(CDC* dc)
	{
		CRect cellRect(CPoint(location_.GetX(), location_.GetY()), CSize(CELL, CELL));
		COLORREF col = RGB(255, 51, 0);
		dc->FillRect(&cellRect, &CBrush(col));
	}

	__forceinline void Reset()
	{
		score_ = -1;
		NewLocation();
	}

	__forceinline Location GetLocation()
	{
		return location_;
	}

	__forceinline constexpr mINT16 GetScore()
	{
		return score_;
	}

private:
	Location location_;
	mINT16 score_ = -1;
};
