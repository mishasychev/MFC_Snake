#pragma once

#include "constants.h"

class IModeDispatcher
{
public:
	virtual void SetMode(const Modes& value) = 0;
	virtual const Modes GetMode() const = 0;
	virtual CtestMFCDlg* GetDialog() const = 0;
};