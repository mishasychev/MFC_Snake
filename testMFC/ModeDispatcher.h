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

	bool isGameMode = false;

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
			dlg->SetTimer(2, 100 - settingsMode.speed * 7, 0);
			isGameMode = true;
			gameMode.Reset();
			currentMode = &gameMode;
			return;
		}
		case Modes::RESULT:
		{
			isGameMode = false;
			dlg->KillTimer(2);
			resultMode.score = gameMode.apple.score;
			currentMode = &resultMode;
			return;
		}
		}
	}
private:
	StartMode startMode;
	SettingsMode settingsMode;
	GameMode gameMode;
	ResultMode resultMode;
};