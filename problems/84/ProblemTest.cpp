// Copyright 2021
// Author: Ankur Jain

#include "../../catch2/catch.hpp"
#include "Problem.h"

SCENARIO( "84.Boundary conditions are tested", "[edge]" ) {
  Problem p;

  GIVEN( "All land is passed" )
  {
    vector<bool> matrix(30, true);

    WHEN( "Number of islands is calculated" )
    {
      auto islands = p.numIslands(matrix, 5, 6);

      THEN( "1 is returned" )
      {
        REQUIRE( islands == 1 );
      }
    }
  }

  GIVEN( "All water is passed" )
  {
    vector<bool> matrix(30, false);

    WHEN( "Number of islands is calculated" )
    {
      auto islands = p.numIslands(matrix, 5, 6);

      THEN( "0 is returned" )
      {
        REQUIRE( islands == 0 );
      }
    }
  }
}


SCENARIO( "84.Different cases are tested", "[cases]" ) {
  Problem p;

  GIVEN( "Four islands are passed" )
  {
    vector<bool> matrix
    {
       true, false, false, false, false,
      false, false,  true,  true, false,
      false,  true,  true, false, false,
      false, false, false, false, false,
       true,  true, false, false,  true,
       true,  true, false, false,  true
    };

    WHEN( "Number of islands is calculated" )
    {
      auto islands = p.numIslands(matrix, 5, 6);

      THEN( "4 is returned" )
      {
        REQUIRE( islands == 4 );
      }
    }
  }
}

SCENARIO( "84.Large cases are tested", "[scale]" ) {
  Problem p;

  GIVEN( "Diagonal is filled with islands" )
  {
    vector<bool> matrix(10000, false);
    for (unsigned int i = 0; i < 100; i++) matrix[101*i] = true;

    WHEN( "Number of islands is calculated" )
    {
      auto islands = p.numIslands(matrix, 100, 100);

      THEN( "Diagonal size is returned" )
      {
        REQUIRE( islands == 100 );
      }
    }
  }
}
