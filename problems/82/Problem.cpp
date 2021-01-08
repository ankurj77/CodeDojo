// Copyright 2021
// Author: Ankur Jain

#include "Problem.h"

/*
  Using a read7() method that returns 7 characters from a file, implement readN(n)
  which reads n characters.
*/

Problem::Problem(const string& s)
{
  contents = s;
  position = 0;
  buffer = "";
}

string Problem::read7()
{
  if (position >= contents.size()) return "";
  string s = contents.substr(position, 7);
  position += 7;
  return s;
}

string Problem::readN(unsigned int n)
{
  string solution;
  if (buffer.size() >= n)
  {
    solution = buffer.substr(0, n); // fulfill completely from buffer
    buffer = buffer.substr(n);
    return solution;
  }
  n -= buffer.size();
  solution = buffer;                // fulfill partially from buffer
  buffer = "";
  for (int q = n / 7; q > 0; q--) solution += read7();
  unsigned int r = n % 7;
  if (r == 0) return solution;
  buffer = read7();
  solution += buffer.substr(0, r);  // fulfill remaining from buffer
  buffer = buffer.size() > r ? buffer.substr(r) : "";
  return solution;
}
