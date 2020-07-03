#pragma once

#include "constants.h"

#include <cstdlib>
#include <ctime>

class Apple
{
public:
	SHORT x, y, score = -1;

	Apple()
	{
		srand(static_cast<UINT>(time(nullptr)));
		NewLocation();
	}

	void NewLocation()
	{
		x = (rand() % 40) * CELL;
		y = (rand() % 25) * CELL;

		score++;
	}

	void Draw(CClientDC* dc)
	{
		CRect cellRect(CPoint(x, y), CSize(CELL, CELL));
		COLORREF col = RGB(255, 51, 0);
		dc->FillRect(&cellRect, &CBrush(col));
	}

	void Reset()
	{
		score = -1;
		NewLocation();
	}
};
