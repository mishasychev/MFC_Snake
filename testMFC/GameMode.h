#pragma once

#include "ModeDispatcher.h"
#include "Snake.h"
#include "Apple.h"

class GameMode : public Mode
{
public:
	void OnKeyDown(IModeDispatcher* dispatcher, const UINT& nChar) override
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

	void Draw(IModeDispatcher* dispatcher, CDC* dc) override
	{
		snake_->Draw(dc);
		apple_->Draw(dc);
		snake_->Movement(dispatcher, direction, apple_);
	}
	__inline void Create()
	{
		apple_ = new Apple;
		snake_ = new Snake;

		direction = Directions::UP;
	}

	__forceinline void Clean()
	{
		delete apple_;
		delete snake_;
	}

	__forceinline Apple* GetApple()
	{
		return apple_;
	}

	__forceinline Snake* GetSnake()
	{
		return snake_;
	}

private:
	Directions direction = Directions::UP;

	Snake* snake_;
	Apple* apple_;
};