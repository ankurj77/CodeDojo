// Copyright 2021
// Author: Ankur Jain

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "Problem.h"

SCENARIO( "Boundary conditions are tested", "[edge]" ) {

  GIVEN( "Empty string is passed" )
  {
    Problem p("");

    WHEN( "N characters are read" )
    {
      int n = 4;

      THEN( "Empty string is returned" )
      {
        REQUIRE( p.readN(n) == "" );
        REQUIRE( p.readN(n) == "" );
        REQUIRE( p.readN(n) == "" );
      }
    }
  }
}

SCENARIO( "Different cases are tested", "[cases]" ) {

  GIVEN( "Sample string is passed" )
  {
    Problem p("this is a medium size string");

    WHEN( "Less than 7 characters are requested" )
    {
      int n = 5;

      THEN( "N<7 characters are returned" )
      {
        REQUIRE( p.readN(n) == "this " );
        REQUIRE( p.readN(n) == "is a " );
        REQUIRE( p.readN(n) == "mediu" );
        REQUIRE( p.readN(n) == "m siz" );
        REQUIRE( p.readN(n) == "e str" );
        REQUIRE( p.readN(n) == "ing" );
        REQUIRE( p.readN(n) == "" );
        REQUIRE( p.readN(n) == "" );
      }
    }

    WHEN( "Exactly 7 characters are requested" )
    {
      int n = 7;

      THEN( "7 characters are returned" )
      {
        REQUIRE( p.readN(n) == "this is" );
        REQUIRE( p.readN(n) == " a medi" );
        REQUIRE( p.readN(n) == "um size" );
        REQUIRE( p.readN(n) == " string" );
        REQUIRE( p.readN(n) == "" );
        REQUIRE( p.readN(n) == "" );
      }
    }

    WHEN( "More than 7 characters are requested" )
    {
      int n = 9;

      THEN( "N>7 characters are returned" )
      {
        REQUIRE( p.readN(n) == "this is a" );
        REQUIRE( p.readN(n) == " medium s" );
        REQUIRE( p.readN(n) == "ize strin" );
        REQUIRE( p.readN(n) == "g" );
        REQUIRE( p.readN(n) == "" );
        REQUIRE( p.readN(n) == "" );
      }
    }
  }
}

SCENARIO( "Large cases are tested", "[scale]" ) {

  GIVEN( "Large string is passed" )
  {
    Problem p("This is a decently large string in the context of this test.");

    WHEN( "Many characters are read" )
    {
      int n = 100000;

      THEN( n + "characters are returned" )
      {
        REQUIRE( p.readN(n) == "This is a decently large string in the context of this test." );
        REQUIRE( p.readN(n) == "" );
        REQUIRE( p.readN(n) == "" );
      }
    }
  }
}
