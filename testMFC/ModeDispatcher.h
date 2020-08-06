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

	ModeDispatcher(CtestMFCDlg* newDlg)
		: dlg_(newDlg)
	{
	}

	void SetMode(const Modes& newMode) override
	{
		switch (newMode)
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
				dlg_->SetTimer(2, 100 - static_cast<tUINT32>(settingsMode.GetSpeed()) * 7, 0);
				gameMode.Create();
				currentMode = &gameMode;
				return;
			}
			case Modes::RESULT:
			{
				dlg_->KillTimer(2);
				resultMode.score = gameMode.GetSnake()->GetScore();
				gameMode.Clean();
				currentMode = &resultMode;
				return;
			}
		}
	}

	const Modes& GetMode() const override
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

	__forceinline CtestMFCDlg* GetDialog() const override
	{
		return dlg_;
	}

private:
	StartMode startMode;
	SettingsMode settingsMode;
	GameMode gameMode;
	ResultMode resultMode;

	CtestMFCDlg* dlg_;
};