// Copyright 2025 NNTU-CS

#include <iostream>
#include <string>
#include "alg.h"

int main() {
    BinarySearchTree<std::string> wordTree;
    const char* inputFile = "war_peace.txt";

    buildTree(wordTree, inputFile);
    std::cout << "Tree height: " << wordTree.getDepth() << std::endl;
    std::cout << "pierre frequency: " << wordTree.lookup("pierre") << std::endl;
    std::cout << "natasha frequency: " << wordTree.lookup("natasha") << std::endl;
    std::cout << "andrew frequency: " << wordTree.lookup("andrew") << std::endl;

    displayFrequency(wordTree);
    return 0;
}
