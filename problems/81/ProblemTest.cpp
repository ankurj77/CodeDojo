// Copyright 2020
// Author: Ankur Jain

#include "../../catch2/catch.hpp"
#include "Problem.h"

SCENARIO( "81.Boundary conditions are tested", "[edge]" ) {
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

SCENARIO( "81.Different cases are tested", "[cases]" ) {
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

    WHEN( "Few digits are passed" )
    {
      string n = "23";

      THEN( "All combinations of letters are returned" )
      {
        REQUIRE( p.solve(m, n) == vector<string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"} );
      }
    }
  }
}

SCENARIO( "81.Large cases are tested", "[scale]" ) {
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

    WHEN( "Many digits with repetitions are passed" )
    {
      string n = "42493699377835";

      THEN( "All combinations of letters are returned" )
      {
        REQUIRE( p.solve(m, n).size() == 20155392 );
      }
    }
  }
}

