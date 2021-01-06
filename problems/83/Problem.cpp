// Copyright 2021
// Author: Ankur Jain

#include "Problem.h"

/*
  Invert a binary tree.
*/

template <typename T>
Node<T>* Problem<T>::createBinaryTree(T* values, int rootIndex, int size)
{
  if (size == 0 || rootIndex >= size) return nullptr;
  if (is_same<T, char>::value && values[rootIndex] == '\0')    return nullptr;
  if (is_same<T, int>::value  && values[rootIndex] == INT_MIN) return nullptr;
  auto root  = new Node<T>(values[rootIndex]);
  root->left  = createBinaryTree(values, 2*rootIndex + 1, size);
  root->right = createBinaryTree(values, 2*rootIndex + 2, size);
  return root;
}

template <typename T>
void Problem<T>::invertBinaryTree(Node<T>* root)
{
  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;
  invertBinaryTree(root->right);
  invertBinaryTree(root->left);
  auto leftPtr = root->left;
  root->left   = root->right;
  root->right  = leftPtr;
}

template class Problem<char>;
template class Problem<int>;
