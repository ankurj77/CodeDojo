// Copyright 2020
// Author: Ankur Jain

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "Problem.h"

SCENARIO( "Boundary conditions are satisfied", "[edge]" ) {
  Problem p;

  GIVEN( "Digit to letters mapping" )
  {
    map<int, vector<string>> m;
    m[2] = vector<string>{"a", "b", "c"};
    m[3] = vector<string>{"d", "e", "f"};
    m[4] = vector<string>{"g", "h", "i"};
    m[5] = vector<string>{"j", "k", "l"};
    m[6] = vector<string>{"m", "n", "o"};
    m[7] = vector<string>{"p", "q", "r", "s"};
    m[8] = vector<string>{"t", "u", "v"};
    m[9] = vector<string>{"w", "x", "y", "z"};

    WHEN( "Empty number string is passed" )
    {
      string n = "";
      
      THEN( "Empty list is returned" )
      {
        REQUIRE( p.solve(m, n) == vector<string>{} );
      }
    }
  }
}

SCENARIO( "Different cases are tested", "[cases]" ) {
  Problem p;

  GIVEN( "Digit to letters mapping" )
  {
    map<int, vector<string>> m;
    m[2] = vector<string>{"a", "b", "c"};
    m[3] = vector<string>{"d", "e", "f"};
    m[4] = vector<string>{"g", "h", "i"};
    m[5] = vector<string>{"j", "k", "l"};
    m[6] = vector<string>{"m", "n", "o"};
    m[7] = vector<string>{"p", "q", "r", "s"};
    m[8] = vector<string>{"t", "u", "v"};
    m[9] = vector<string>{"w", "x", "y", "z"};

    WHEN( "Single digit is passed" )
    {
      string n = "5";
      
      THEN( "Letters corresponding to that digit are returned" )
      {
        REQUIRE( p.solve(m, n) == vector<string>{"j", "k", "l"} );
      }
    }
  }
}