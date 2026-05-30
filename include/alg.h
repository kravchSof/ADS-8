// Copyright 2025 NNTU-CS
#ifndef INCLUDE_ALG_H__
#define INCLUDE_ALG_H__

#include <string>
#include "bst.h"

void buildTree(BinarySearchTree<std::string>& bst, const char* filepath);
void displayFrequency(BinarySearchTree<std::string>& bst);

#endif  // INCLUDE_ALG_H__
