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
				direction_ = Directions::UP;
				return;
			}
			case 83:
			{
				direction_ = Directions::DOWN;
				return;
			}
			case 65:
			{
				direction_ = Directions::LEFT;
				return;
			}
			case 68:
			{
				direction_ = Directions::RIGHT;
				return;
			}
		}
	}

	__inline void Draw(IModeDispatcher* dispatcher, CDC* dc) override
	{
		snake_->Draw(dc);
		apple_->Draw(dc);
		snake_->Movement(dispatcher, direction_, apple_);
	}
	__inline void Create()
	{
		apple_ = new Apple;
		snake_ = new Snake;

		direction_ = Directions::UP;
	}

	__inline void Clean()
	{
		delete apple_;
		apple_ = nullptr;
		delete snake_;
		snake_ = nullptr;
	}

	__forceinline constexpr Apple* GetApple()
	{
		return apple_;
	}

	__forceinline constexpr Snake* GetSnake()
	{
		return snake_;
	}

	~GameMode()
	{
		if (apple_ != nullptr)
		{
			delete apple_;
		}
		if (snake_ != nullptr)
		{
			delete snake_;
		}
	}

private:
	Directions direction_ = Directions::UP;

	Snake* snake_ = nullptr;
	Apple* apple_ = nullptr;
};