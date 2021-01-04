// Copyright 2021
// Author: Ankur Jain

#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class Problem
{
  public:
  Problem(const string& s);

  private:
  string contents;
  string buffer;
  int position;
  string read7();

  public:
  string readN(int n);
};