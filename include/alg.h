// Copyright 2025 NNTU-CS
#ifndef INCLUDE_ALG_H__
#define INCLUDE_ALG_H__

#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

#endif  // INCLUDE_ALG_H__
