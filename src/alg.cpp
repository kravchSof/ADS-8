// Copyright 2025 NNTU-CS
#include "alg.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

void buildTree(BinarySearchTree<std::string>& bst, const char* filepath) {
    std::ifstream inputFile(filepath);
    if (!inputFile) {
        std::cerr << "Cannot open file: " << filepath << std::endl;
        return;
    }

    std::string buffer;
    char symbol;
    while (inputFile.get(symbol)) {
        if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
            symbol = std::tolower(static_cast<unsigned char>(symbol));
            buffer.push_back(symbol);
        } else {
            if (!buffer.empty()) {
                bst.insert(buffer);
                buffer.clear();
            }
        }
    }
    if (!buffer.empty()) {
        bst.insert(buffer);
    }
    inputFile.close();
}

void displayFrequency(BinarySearchTree<std::string>& bst) {
    auto entries = bst.fetchAllNodes();
    std::sort(entries.begin(), entries.end(),
        [](const std::pair<std::string, int>& first,
           const std::pair<std::string, int>& second) {
            if (first.second != second.second) return first.second > second.second;
            return first.first < second.first;
        });

    for (const auto& item : entries) {
        std::cout << item.first << " " << item.second << std::endl;
    }

    std::ofstream output("result/freq.txt");
    if (!output) {
        std::cerr << "Failed to create result/freq.txt" << std::endl;
        return;
    }
    for (const auto& item : entries) {
        output << item.first << " " << item.second << std::endl;
    }
    output.close();
}
