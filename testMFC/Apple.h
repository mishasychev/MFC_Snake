#pragma once

#include <cstdlib>
#include <ctime>

class Apple
{
private:
	const int CELL = 20;
public:
	int x, y, score = -1;

	Apple()
	{
		NewLocation();
	}

	void NewLocation()
	{
		srand(time(0));

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
