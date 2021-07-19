#pragma once

#include <deque>
#include "Apple.h"
#include "IModeDispatcher.h"

using namespace std;

class Snake
{
public:
	Snake()
		: lastDirection_(Directions::UP)
		, snake_{ Point(19 * CELL, 13 * CELL) }
		, score_(0)
	{
	}

	void Movement(IModeDispatcher* dispatcher, Directions& d, Apple* apple)
	{
		if (WrongDirection_(d))
		{
			d = lastDirection_;
		}

		auto* begin = &snake_.back();
		switch (d)
		{
			case Directions::UP:
			{
				if (begin->GetY() == 0)
				{
					snake_.push_back(Point(begin->GetX(), 24 * CELL));
					break;
				}
				snake_.push_back(Point(begin->GetX(), begin->GetY() - CELL));
				break;
			}
			case Directions::DOWN:
			{
				snake_.push_back(Point(begin->GetX(), (begin->GetY() + CELL) % 500));
				break;
			}
			case Directions::LEFT:
			{
				if (begin->GetX() == 0)
				{
					snake_.push_back(Point(39 * CELL, begin->GetY()));
					break;
				}
				snake_.push_back(Point(begin->GetX() - CELL, begin->GetY()));
				break;
			}
			case Directions::RIGHT:
			{
				snake_.push_back(Point((begin->GetX() + CELL) % 800, begin->GetY()));
				break;
			}
		}

		if (!CheckApple_(apple))
		{
			snake_.pop_front();
		}
		if (CheckSnake_())
		{
			dispatcher->SetMode(Modes::RESULT);
		}

		lastDirection_ = d;
	}

	void Draw(CDC* dc)
	{
		COLORREF col = RGB(51, 204, 51);
		CSize s(CELL, CELL);

		for(const auto& i : snake_)
		{
			CPoint p(i.GetX(), i.GetY());
			CRect rect(p, s);
			dc->FillRect(&rect, &CBrush(col));
		}
	}

	__forceinline constexpr tUINT16 GetScore() const { return score_; }

private:
	deque<Point> snake_;
	Directions lastDirection_;
	tUINT16 score_;

	constexpr bool WrongDirection_(const Directions& d)
	{
		return d == Directions::UP && lastDirection_ == Directions::DOWN
			   || d == Directions::DOWN && lastDirection_ == Directions::UP
			   || d == Directions::LEFT && lastDirection_ == Directions::RIGHT
			   || d == Directions::RIGHT && lastDirection_ == Directions::LEFT;
	}

	constexpr bool CheckApple_(Apple* apple)
	{
		if (apple->GetLocation() == snake_.back())
		{
			apple->NewLocation();
			score_++;
			return true;
		}
		return false;
	}

	bool CheckSnake_()
	{
		for (tUINT64 i = 0; i < snake_.size() - 1; i++)
		{
			if (snake_[i] == snake_.back())
			{
				return true;
			}
		}
		return false;
	}
};
