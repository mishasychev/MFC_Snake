#pragma once

#include "ModeDispatcher.h"

#include <vector>
#include <algorithm>

using namespace std;

class ResultMode : public Mode
{
public:
	WORD score = 0;

	void OnKeyDown(IModeDispatcher* dispatcher, UINT& nChar) override
	{
		switch (nChar)
		{
			case 87:
			{
				if (ans == 0)
				{
					ans = 2;
					return;
				}
				ans--;
				return;
			}
			case 83:
			{
				if (ans == 2)
				{
					ans = 0;
					return;
				}
				ans++;
				return;
			}
			case 32:
			{
				if (ans == 0)
					dispatcher->SetMode(Modes::GAME);
				else if (ans == 1)
					dispatcher->SetMode(Modes::SETTINGS);
				else
					exit(0);
				return;
			}
		}
		
	}

	void Draw(IModeDispatcher* dispatcher, CClientDC* dc) override
	{
		COLORREF color;

		WORD score = this->score;

		//TEXT:score
		vector<vector<bool>> scoreText =
		{
			{0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},
			{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
			{0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
			{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
			{0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0}
		};

		int cell = 10;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (scoreText[i][j])
				{
					CSize s(cell, cell);
					CPoint p(j * cell + 30, i * cell + 30);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(COLORREF(0x000000FF)));
				}
			}
		}

		//TEXT:commands
		vector<vector<bool>> commands =
		{
			{1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
			{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0}
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
		color = RGB(0, 255, 153);
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 36; j++)
			{
				if (commands[i][j])
				{
					CSize s(cell, cell);
					CPoint p(j * cell + 400, i * cell + 230);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
			for (int j = 0; j < 40; j++)
			{
				if (settingsText[i][j])
				{
					CSize s(cell, cell);
					CPoint p(j * cell + 400, i * cell + 280);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
			for (int j = 36; j < 55; j++)
			{
				if (commands[i][j])
				{
					CSize s(cell, cell);
					CPoint p((j - 36) * cell + 400, i * cell + 330);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
		}

		//DRAW ARROW
		color = RGB(255, 255, 102);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (arrow[i][j])
				{
					CSize s(cell, cell);
					CPoint p(j * cell + 330, i * cell + 230 + ans * 50);
					CRect r(p, s);
					dc->FillRect(&r, &CBrush(color));
				}
			}
		}

		//TEXT:numbers
		vector<vector<bool>> numbers =
		{
			{0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0},
			{0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
			{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1},
			{0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
			{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
			{0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0}
		};

		vector<WORD> scoreV;
		while (score >= 10)
		{
			scoreV.push_back(score % 10);
			score /= 10;
		}
		scoreV.push_back(score);
		reverse(scoreV.begin(), scoreV.end());

		int offsetX = 330, numX, pNumX;
		cell = 10;
		for (size_t c = 0; c < scoreV.size(); c++)
		{
			if (scoreV[c] == 1)
			{
				numX = 0;
				pNumX = 3;
			}
			else if (scoreV[c] == 0)
			{
				numX = 3;
				pNumX = 4;
			}
			else
			{
				numX = (scoreV[c] - 2) * 4 + 7;
				pNumX = 4;
			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = numX; j < numX + pNumX; j++)
				{
					if (numbers[i][j])
					{
						CSize s(cell, cell);
						CPoint p((j - numX) * cell + offsetX, i * cell + 30);
						CRect r(p, s);
						dc->FillRect(&r, &CBrush(COLORREF(0x00FFFFFF)));
					}
				}
			}
			offsetX += (pNumX * 10 + 10);
		}
	}
private:
	BYTE ans = 0;
};