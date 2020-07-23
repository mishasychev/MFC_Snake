#pragma once

#include "ModeDispatcher.h"

#include <vector>

using namespace std;

class SettingsMode : public Mode
{
public:
	void OnKeyDown(IModeDispatcher* dispatcher, UINT& nChar) override
	{
		switch (nChar)
		{
			case 68:
			{
				if (speed_ < 5)
					speed_++;
				return;
			}
			case 65:
			{
				if (speed_ > 0)
					speed_--;
				return;
			}
			case 32:
			{
				dispatcher->SetMode(Modes::START);
				return;
			}
		}
	}

	void Draw(IModeDispatcher* dispatcher, CDC* dc) override
	{
		COLORREF color;
		int cell;

		//DRAW speed_
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

		if (speed_ >= 0 && speed_ <= 1)
			color = RGB(51, 204, 51);
		else if (speed_ >= 2 && speed_ <= 3)
			color = RGB(255, 255, 102);
		else if (speed_ >= 4 && speed_ <= 5)
			color = RGB(255, 51, 0);

		for (int i = 0; i < speed_ + 1; i++)
		{
			CSize s(2 * cell, 6 * cell);
			CPoint p(i * 3 * cell + 430, 220);
			CRect r(p, s);
			dc->FillRect(&r, &CBrush(color));
		}
	}

	__forceinline mINT8 GetSpeed()
	{
		return speed_;
	}

private:
	mUINT8 speed_ = 0;
};