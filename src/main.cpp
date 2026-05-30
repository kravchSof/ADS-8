// Copyright 2021 NNTU-CS
#include "alg.h"

#include <iostream>
#include <string>

int main() {
    BST<std::string> tree;
    makeTree(tree, "src/war_peace.txt");

    std::cout << "Tree depth: " << tree.depth() << std::endl;
    std::cout << "Search 'war': " << (tree.search("war") ? "found" : "not found") << std::endl;
    std::cout << "Search 'xxx': " << (tree.search("xxx") ? "found" : "not found") << std::endl;

    printFreq(tree);

    return 0;
}
