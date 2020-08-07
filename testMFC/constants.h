#pragma once

typedef char					tINT8;
typedef short					tINT16;
typedef int						tINT32;
typedef long long				tINT64;

typedef unsigned char			tUINT8;
typedef unsigned short			tUINT16;
typedef unsigned int			tUINT32;
typedef unsigned long long		tUINT64;


constexpr tUINT8 CELL = 20;


enum class Modes {START, SETTINGS, GAME, RESULT};
enum class Directions {UP, DOWN, LEFT, RIGHT};



class Point
{
public:
	Point(const tINT16& X, const tINT16& Y)
		: x_(X)
		, y_(Y)
	{
	}

	__forceinline void SetX(const tINT16& newX) { x_ = newX; }

	__forceinline void SetY(const tINT16& newY) { y_ = newY; }

	__forceinline constexpr tINT16 GetX() const { return x_; }

	__forceinline constexpr tINT16 GetY() const { return y_; }

	__inline constexpr bool operator==(const Point& anotherOne) const
	{
		return x_ == anotherOne.GetX() && y_ == anotherOne.GetY() ? true : false;
	}
 
private:
	tINT16 x_;
	tINT16 y_;
};