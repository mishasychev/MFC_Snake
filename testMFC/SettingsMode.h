#pragma once

#include "ModeDispatcher.h"

#include <vector>

using namespace std;

class SettingsMode : public Mode
{
public:
	int speed = 0;

	void OnKeyDown(IModeDispatcher* dispatcher, UINT& nChar) override
	{
		if (nChar == 68)
		{
			if (speed < 5)
				speed++;
		}
		else if (nChar == 65)
		{
			if (speed > 0)
				speed--;
		}
		else if (nChar == 32)
		{
			dispatcher->SetMode(Modes::START);
		}
	}

	void Draw(IModeDispatcher* dispatcher, CClientDC* dc) override
	{
		COLORREF color;
		int cell;

		//DRAW Speed
		vector<vector<bool>> speedText =
		{
			{0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
			{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
			{0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1},
			{0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
			{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
			{0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0}
		};

		color = RGB(0, 255, 153);
		cell = 5;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				if (speedText[i][j])
				{
					CSize s(cell, cell);
					CPoint p(j * cell + 270, i * cell + 220);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
		}

		if (speed >= 0 && speed <= 1)
			color = RGB(51, 204, 51);
		else if (speed >= 2 && speed <= 3)
			color = RGB(255, 255, 102);
		else if (speed >= 4 && speed <= 5)
			color = RGB(255, 51, 0);

		for (int i = 0; i < speed + 1; i++)
		{
			CSize s(2 * cell, 6 * cell);
			CPoint p(i * 3 * cell + 430, 220);
			CRect r(p, s);
			dc->FillRect(&r, &CBrush(color));
		}
	}
};