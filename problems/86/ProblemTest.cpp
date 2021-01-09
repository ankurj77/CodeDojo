// Copyright 2021
// Author: Ankur Jain

#include "../../catch2/catch.hpp"
#include "Problem.h"

SCENARIO( "86.Boundary conditions are tested", "[edge]" ) {
  Problem p;

  GIVEN( "Empty string is passed" )
  {
    string s("");

    WHEN( "Minimum parentheses for balance is calculated" )
    {

      THEN( "0 is returned" )
      {
        REQUIRE( p.minParentheses(s) == 0 );
      }
    }
  }
}


SCENARIO( "86.Different cases are tested", "[cases]" ) {
  Problem p;

  GIVEN( "Already balanced string is passed" )
  {
    string s("()(()())");

    WHEN( "Minimum parentheses for balance is calculated" )
    {

      THEN( "0 is returned" )
      {
        REQUIRE( p.minParentheses(s) == 0 );
      }
    }
  }

  GIVEN( "Unbalanced string is passed" )
  {
    string s(")()(");

    WHEN( "Minimum parentheses for balance is calculated" )
    {

      THEN( "0 is not returned" )
      {
        REQUIRE( p.minParentheses(s) == 2 );
      }
    }
  }
}

SCENARIO( "86.Large cases are tested", "[scale]" ) {
  Problem p;

  GIVEN( "Large balanced string is passed" )
  {
    stringstream s;
    for (unsigned int i = 0; i < 100000; i++)
    {
      s << (i <  50000 && rand() % 2 == 0 ? "(" : "(()");
      s << (i >= 50000 && rand() % 2 == 0 ? ")" : "())");
    }

    WHEN( "Minimum parentheses for balance is calculated" )
    {

      THEN( "0 is returned" )
      {
        REQUIRE( p.minParentheses(s.str()) == 0 );
      }
    }
  }

  GIVEN( "Large unbalanced string is passed" )
  {
    stringstream s;
    for (unsigned int i = 0; i < 100000; i++)
    {
      s << (i <  50000 && rand() % 2 == 0 ? "(" : "((");
      s << (i >= 50000 && rand() % 2 == 0 ? ")" : "))");
    }

    WHEN( "Minimum parentheses for balance is calculated" )
    {

      THEN( "0 is not returned" )
      {
        REQUIRE( p.minParentheses(s.str()) > 0 );
      }
    }
  }
}
