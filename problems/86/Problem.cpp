// Copyright 2021
// Author: Ankur Jain

#include "Problem.h"

/*
  Given a string of parentheses, write a function to compute the minimum number
  of parentheses to be removed to make the string valid (i.e. each open parenthesis
  is eventually closed).
*/

unsigned int Problem::minParentheses(string p)
{
  stack<char> pStack;
  for (auto it = p.begin(); it != p.end(); it++)
  {
    char ch = *it;
    if (ch == '(')
    {
      pStack.push(ch);
    }
    else if (ch == ')')
    {
        if (pStack.size() > 0 && pStack.top() == '(')
          pStack.pop();
        else
          pStack.push(ch);
    }
  }
  return pStack.size();
}
