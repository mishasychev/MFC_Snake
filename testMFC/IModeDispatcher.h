#pragma once

#include "constants.h"

class IModeDispatcher
{
public:
	virtual void SetMode(Modes value) = 0;
	virtual Modes GetMode() = 0;
};