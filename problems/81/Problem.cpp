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

   string firstDigit = string(1, digits[0]);
   string restDigits = digits.substr(1);
   auto solution1 = solve(digitToLettersMap, firstDigit);
   auto solution2 = solve(digitToLettersMap, restDigits);
   vector<string> solution;
   for (auto it1 = solution1.begin(); it1 != solution1.end(); it1++)
   {
     for (auto it2 = solution2.begin(); it2 != solution2.end(); it2++)
     {
       solution.emplace_back(*it1 + *it2);
     }
   }
   return solution;
}
