#pragma once

#include "Mode.h"
#include "StartMode.h"
#include "SettingsMode.h"
#include "GameMode.h"
#include "ResultMode.h"

class ModeDispatcher : public IModeDispatcher
{
public:
	Mode* currentMode = &startMode;
	CtestMFCDlg* dlg = nullptr;

	void SetMode(Modes value) override
	{
		switch (value)
		{
			case Modes::START:
			{
				currentMode = &startMode;
				return;
			}
			case Modes::SETTINGS:
			{
				currentMode = &settingsMode;
				return;
			}
			case Modes::GAME:
			{
				dlg->SetTimer(2, 100 - static_cast<UINT32>(settingsMode.speed) * 7, 0);
				gameMode.Reset();
				currentMode = &gameMode;
				return;
			}
			case Modes::RESULT:
			{
				dlg->KillTimer(2);
				resultMode.score = gameMode.apple.GetScore();
				currentMode = &resultMode;
				return;
			}
		}
	}

	Modes GetMode() override
	{
		if (currentMode == &startMode)
		{
			return Modes::START;
		}
		else if (currentMode == &settingsMode)
		{
			return Modes::SETTINGS;
		}
		else if (currentMode == &gameMode)
		{
			return Modes::GAME;
		}
		else
		{
			return Modes::RESULT;
		}
	}
private:
	StartMode startMode;
	SettingsMode settingsMode;
	GameMode gameMode;
	ResultMode resultMode;
};