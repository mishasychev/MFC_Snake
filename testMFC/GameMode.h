#pragma once

#include "ModeDispatcher.h"
#include "Snake.h"
#include "Apple.h"

class GameMode : public Mode
{
public:
	Snake snake;
	Apple apple;

	void OnKeyDown(IModeDispatcher* dispatcher, UINT& nChar) override
	{
		switch (nChar)
		{
		case 87:
		{
			direction = Directions::UP;
			return;
		}
		case 83:
		{
			direction = Directions::DOWN;
			return;
		}
		case 65:
		{
			direction = Directions::LEFT;
			return;
		}
		case 68:
		{
			direction = Directions::RIGHT;
			return;
		}
		}
	}

	void Draw(IModeDispatcher* dispatcher, CClientDC* dc) override
	{
		snake.Draw(dc);
		apple.Draw(dc);
		snake.Movement(dispatcher, direction, &apple);
	}
	void Reset()
	{
		apple.Reset();
		snake.Reset();
		direction = Directions::UP;
	}
private:
	Directions direction = Directions::UP;
};