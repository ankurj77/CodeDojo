// Copyright 2021
// Author: Ankur Jain

#include "../../catch2/catch.hpp"
#include "Problem.h"

SCENARIO( "85.Different cases are tested", "[cases]" ) {
  Problem p;

  GIVEN( "X=INT_MIN and Y=INT_MAX are passed" )
  {
    int32_t X = INT_MIN;
    int32_t Y = INT_MAX;

    WHEN( "b is 1" )
    {
      int32_t b = 1;

      THEN( "INT_MIN is returned" )
      {
        REQUIRE( p.getXorY(X, Y, b) == INT_MIN );
      }
    }
  }

  GIVEN( "X=INT_MIN and Y=INT_MAX are passed" )
  {
    int32_t X = INT_MIN;
    int32_t Y = INT_MAX;

    WHEN( "b is 0" )
    {
      int32_t b = 0;

      THEN( "INT_MAX is returned" )
      {
        REQUIRE( p.getXorY(X, Y, b) == INT_MAX );
      }
    }
  }
}
