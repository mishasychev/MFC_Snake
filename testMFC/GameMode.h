#pragma once

#include "Mode.h"
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

	void Draw(IModeDispatcher* dispatcher, CDC* dc) override
	{
		snake_->Draw(dc);
		apple_->Draw(dc);
		snake_->Movement(dispatcher, direction_, apple_);
	}

	void Create(CDialog* dlg, tINT32 snakeSpeed)
	{
		apple_ = new Apple;
		snake_ = new Snake;

		direction_ = Directions::UP;

		dlg->SetTimer(2, 100 - snakeSpeed, nullptr);
	}
	
	/*@returns Count of eaten apples*/
	tUINT16 Clean(CDialog* dlg)
	{
		dlg->KillTimer(2);

		delete apple_;
		delete snake_;

		return snake_->GetScore();
	}

	__forceinline constexpr Apple* GetApple() const { return apple_; }

	__forceinline constexpr Snake* GetSnake() const { return snake_; }

private:
	Directions direction_ = Directions::UP;

	Snake* snake_ = nullptr;
	Apple* apple_ = nullptr;
};