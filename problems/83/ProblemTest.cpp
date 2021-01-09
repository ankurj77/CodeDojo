// Copyright 2021
// Author: Ankur Jain

#include "../../catch2/catch.hpp"
#include "Problem.h"

SCENARIO( "83.Boundary conditions are tested", "[edge]" ) {
  Problem<char> p;

  GIVEN( "Empty tree is used as input" )
  {
    char values[0] = {};
    auto root = p.createBinaryTree(values, -1, 0);
    REQUIRE( root == nullptr );

    WHEN( "Tree is inverted" )
    {
      p.invertBinaryTree(root);

      THEN( "Empty tree is returned" )
      {
        REQUIRE( root == nullptr );
      }
    }
  }

  GIVEN( "Sigle node tree is used as input" )
  {
    char values[1] = {'a'};
    auto root = p.createBinaryTree(values, 0, 1);
    REQUIRE( root->value == 'a' );
    REQUIRE( root->left  == nullptr );
    REQUIRE( root->right == nullptr );

    WHEN( "Tree is inverted" )
    {
      p.invertBinaryTree(root);

      THEN( "Same tree is returned" )
      {
        REQUIRE( root->value == 'a' );
        REQUIRE( root->left  == nullptr );
        REQUIRE( root->right == nullptr );
      }
    }
  }
}


SCENARIO( "83.Different cases are tested", "[cases]" ) {
  Problem<char> p;

  GIVEN( "Sample tree is used as input" )
  {
    char values[7] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
    auto root = p.createBinaryTree(values, 0, 7);
    REQUIRE( root->value == 'a' );
    REQUIRE( root->left->left->value == 'd' );
    REQUIRE( root->right->right == nullptr );

    WHEN( "Tree is inverted" )
    {
      p.invertBinaryTree(root);

      THEN( "Inverted tree is returned" )
      {
        REQUIRE( root->value == 'a' );
        REQUIRE( root->left->left == nullptr );
        REQUIRE( root->right->right->value == 'd' );
      }
    }
  }
}

SCENARIO( "83.Large cases are tested", "[scale]" ) {

  Problem<int> p;

  GIVEN( "Large tree is used as input" )
  {
    int values[1023];
    for (int i = 0; i < 1023; i++) values[i] = i;
    auto root = p.createBinaryTree(values, 0, 1023);
    REQUIRE( root->left->right->left->right->value == 20 );
    REQUIRE( root->left->left->right->right->value == 18 );
    REQUIRE( root->right->right->left->left->value == 27 );

    WHEN( "Tree is inverted" )
    {
      p.invertBinaryTree(root);

      THEN( "Inverted tree is returned" )
      {
        REQUIRE( root->right->left->right->left->value == 20 );
        REQUIRE( root->right->right->left->left->value == 18 );
        REQUIRE( root->left->left->right->right->value == 27 );
      }
    }
  }
}
