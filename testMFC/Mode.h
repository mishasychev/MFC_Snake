#pragma once

#include "IModeDispatcher.h"

class Mode
{
public:
	virtual void OnKeyDown(IModeDispatcher* dispatcher, UINT& nChar) = 0;
	virtual void Draw(IModeDispatcher* dispatcher, CDC* dc) = 0;
};