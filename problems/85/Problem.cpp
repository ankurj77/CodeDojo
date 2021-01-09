// Copyright 2021
// Author: Ankur Jain

#include "Problem.h"

/*
  Given three 32-bit integers x, y and b, return x if b is 1 and y if b is 0, using
  only mathematical or bit operations. You can assume b can only be 1 or 0.
*/

int32_t Problem::getXorY(int32_t& x, int32_t& y, int32_t& b)
{
  return (x * b) | (y * (1 - b));
}
