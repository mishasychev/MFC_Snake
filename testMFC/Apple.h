#pragma once

#include "constants.h"

#include <cstdlib>
#include <ctime>

class Apple
{
public:
	Apple()
	{
		srand(static_cast<UINT32>(time(nullptr)));
		NewLocation();
	}

	void NewLocation()
	{
		x_ = (rand() % 40) * CELL;
		y_ = (rand() % 25) * CELL;

		score_++;
	}

	void Draw(CClientDC* dc)
	{
		CRect cellRect(CPoint(x_, y_), CSize(CELL, CELL));
		COLORREF col = RGB(255, 51, 0);
		dc->FillRect(&cellRect, &CBrush(col));
	}

	__forceinline void Reset()
	{
		score_ = -1;
		NewLocation();
	}

	__forceinline std::pair<UINT16, UINT16> GetLocation()
	{
		return std::make_pair(x_, y_);
	}

	__forceinline INT16 GetScore()
	{
		return score_;
	}

private:
	UINT16 x_;
	UINT16 y_;
	INT16 score_ = -1;
};
