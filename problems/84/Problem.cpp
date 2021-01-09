// Copyright 2021
// Author: Ankur Jain

#include "Problem.h"

/*
  Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A
  1 represents land and 0 represents water, so an island is a group of 1s that
  are neighboring whose perimeter is surrounded by water.
*/

void Problem::floodVisit(vector<bool>& matrix, vector<bool>& visited, unsigned int iRow, unsigned int iCol, unsigned int& maxCols, unsigned int& maxRows)
{
  if (iCol >= maxCols || iRow >= maxRows) return;
  auto current = iRow*maxCols + iCol;
  if (!matrix[current] || visited[current]) return; // encountered water, we are done
  visited[current] = true;
  floodVisit(matrix, visited, iRow,   iCol+1, maxCols, maxRows); // flood right
  floodVisit(matrix, visited, iRow,   iCol-1, maxCols, maxRows); // flood left
  floodVisit(matrix, visited, iRow+1, iCol,   maxCols, maxRows); // flood down
}

void Problem::print(vector<bool>& m, unsigned int cols, unsigned int rows)
{
  if (m.size() > 100) return;

  for (unsigned int iRow = 0; iRow < rows; iRow++)
  {
    cout << "  ";
    for (unsigned int iCol = 0; iCol < cols; iCol++)
    {
      cout << (m[iRow*cols + iCol] ? "1" : "0") << (iCol == cols-1 ? "\n" : ", ");
    }
  }
  cout << endl;
}

unsigned int Problem::numIslands(vector<bool>& matrix, unsigned int cols, unsigned int rows)
{
  vector<bool> visited(matrix.size(), false);
  unsigned int count = 0;

  cout << "====================" << endl;
  print(matrix, cols, rows);
  cout << "====================" << endl;
  for (unsigned int iRow = 0; iRow < rows; iRow++)
  {
    for (unsigned int iCol = 0; iCol < cols; iCol++)
    {
      auto current = iRow*cols + iCol;
      if (matrix[current] && !visited[current])
      {
        count++;
        floodVisit(matrix, visited, iRow, iCol, cols, rows);
        print(visited, cols, rows);
      }
    }
  }
  return count;
}
