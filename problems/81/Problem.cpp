// Copyright 2020
// Author: Ankur Jain

#include "Problem.h"

/*
  Given a mapping of digits to letters (as in a phone number), and a digit string,
  return all possible letters the number could represent. You can assume each valid
  number in the mapping is a single digit.
*/

vector<string> Problem::solve(map<int, vector<string>>& digitToLettersMap, string& digits)
{
   if (digits.empty())  return vector<string>{};
   if (digits.length() == 1) return digitToLettersMap[stoi(digits)];
}
