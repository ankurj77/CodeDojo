// Copyright 2021
// Author: Ankur Jain

#pragma once
#include <climits>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Problem
{
  private:
    void floodVisit(vector<bool>& matrix, vector<bool>& visited, unsigned int iRow, unsigned int iCol, unsigned int& maxCols, unsigned int& maxRows);
    void print(vector<bool>& m, unsigned int cols, unsigned int rows);
  public:
    unsigned int numIslands(vector<bool>& matrix, unsigned int cols, unsigned int rows);
};
