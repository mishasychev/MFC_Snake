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
				gameMode.Create(DIALOG, static_cast<tUINT32>(settingsMode.GetSpeed()) * 10);
				currentMode = &gameMode;
				return;
			}
			case Modes::RESULT:
			{
				resultMode.score = gameMode.Clean(DIALOG);
				currentMode = &resultMode;
				return;
			}
		}
	}

	const Modes GetMode() const override
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