// Copyright 2025 NNTU-CS

#include <iostream>
#include <string>
#include "alg.h"

int main() {
    BST<std::string> tree;
    const char* filename = "war_peace.txt";

    makeTree(tree, filename);
    std::cout << "Depth: " << tree.depth() << std::endl;
    std::cout << "pierre: " << tree.search("pierre") << std::endl;
    std::cout << "natasha: " << tree.search("natasha") << std::endl;
    std::cout << "andrew: " << tree.search("andrew") << std::endl;

    printFreq(tree);
    return 0;
}
