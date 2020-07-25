#pragma once

typedef char mINT8;
typedef short mINT16;
typedef int mINT32;
typedef long long mINT64;

typedef unsigned char mUINT8;
typedef unsigned short mUINT16;
typedef unsigned int mUINT32;
typedef unsigned long long mUINT64;


constexpr mUINT8 CELL = 20;

enum class Modes {START, SETTINGS, GAME, RESULT};
enum class Directions {UP, DOWN, LEFT, RIGHT};



class Location
{
public:
	Location(const mINT16& newX, const mINT16& newY)
		: x_(newX)
		, y_(newY)
	{
	}

	__forceinline void SetX(const mINT16& newX)
	{
		x_ = newX;
	}

	__forceinline void SetY(const mINT16& newY)
	{
		y_ = newY;
	}

	__forceinline constexpr const mINT16 GetX() const
	{
		return x_;
	}

	__forceinline constexpr const mINT16 GetY() const
	{
		return y_;
	}

	__inline constexpr const bool operator==(const Location& anotherOne) const
	{
		return (x_ == anotherOne.GetX() && y_ == anotherOne.GetY() ? true : false);
	}

private:
	mINT16 x_;
	mINT16 y_;
};