#pragma once

#include "Mode.h"
#include "ModeDispatcher.h"

#include <vector>

using namespace std;

class StartMode : public Mode
{
public:
	void OnKeyDown(IModeDispatcher* dispatcher, UINT& nChar) override
	{
		if (nChar == 87)
		{
			if (ans == 0)
			{
				ans = 2;
				return;
			}
			ans--;
		}
		else if (nChar == 83)
		{
			if (ans == 2)
			{
				ans = 0;
				return;
			}
			ans++;
		}
		else if (nChar == 32)
		{
			if (ans == 0)
				dispatcher->SetMode(Modes::GAME);
			else if (ans == 1)
				dispatcher->SetMode(Modes::SETTINGS);
			else
				exit(0);
		}
	}

	void Draw(IModeDispatcher* dispatcher, CClientDC* dc) override
	{
		COLORREF color;
		int cell;

		//DRAW commands
		vector <vector<bool>> playText =
		{
			{1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1},
			{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
			{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0},
			{1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0}
		};

		vector <vector<bool>> settingsText =
		{
			{0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
			{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1},
			{0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
			{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1},
			{0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
		};

		vector <vector<bool>> exitText =
		{
			{1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0}
		};

		color = RGB(0, 255, 153);
		cell = 5;
		for (int i = 0; i < 6; i++)
		{
			for (int j1 = 0; j1 < 20; j1++)
			{
				if (playText[i][j1])
				{
					CSize s(cell, cell);
					CPoint p(j1 * cell + 400, i * cell + 180);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
			for (int j2 = 0; j2 < 40; j2++)
			{
				if (settingsText[i][j2])
				{
					CSize s(cell, cell);
					CPoint p(j2 * cell + 400, i * cell + 230);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
			for (int j3 = 0; j3 < 19; j3++)
			{
				if (exitText[i][j3])
				{
					CSize s(cell, cell);
					CPoint p(j3 * cell + 400, i * cell + 280);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
		}

		//DRAW arrow
		vector<vector<bool>> arrow =
		{
			{1, 1, 0, 0, 0, 0, 0},
			{1, 1, 1, 1, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 0},
			{1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 0},
			{1, 1, 1, 1, 0, 0, 0},
			{1, 1, 0, 0, 0, 0, 0},
		};

		cell = 5;
		color = RGB(255, 255, 102);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (arrow[i][j])
				{
					CSize s(cell, cell);
					CPoint p(j * cell + 330, i * cell + 180 + ans * 50);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
		}
	}
private:
	int ans = 0;
};