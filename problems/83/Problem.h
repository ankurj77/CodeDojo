// Copyright 2021
// Author: Ankur Jain

#pragma once
#include <climits>
#include <vector>
#include <string>
#include <map>

using namespace std;

template <typename T>
struct Node
{
  Node<T>(char v): value(v), left(nullptr), right(nullptr){};
  T value;
  Node<T> *left;
  Node<T> *right;
};

template <typename T>
class Problem
{
  public:
  Node<T>* createBinaryTree(T* values, int start, int size);
  void invertBinaryTree(Node<T>* root);
};
