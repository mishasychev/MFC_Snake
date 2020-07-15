#pragma once

typedef char INT8;
typedef short INT16;
typedef int INT32;
typedef long long INT64;

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;



constexpr UINT8 CELL = 20;

enum class Modes {START, SETTINGS, GAME, RESULT};
enum class Directions {UP, DOWN, LEFT, RIGHT};