// Copyright 2025 NNTU-CS
#include "alg.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

void makeTree(BST<std::string>& bstStructure, const char* filePath) {
    std::ifstream sourceFile(filePath);
    if (!sourceFile.is_open()) {
        std::cerr << "Error: Unable to open " << filePath << std::endl;
        return;
    }

    std::string currentWord;
    char currentChar;
    while (sourceFile.get(currentChar)) {
        if (std::isalpha(static_cast<unsigned char>(currentChar))) {
            currentChar = std::tolower(static_cast<unsigned char>(currentChar));
            currentWord.push_back(currentChar);
        } else {
            if (!currentWord.empty()) {
                bstStructure.add(currentWord);
                currentWord.clear();
            }
        }
    }
    if (!currentWord.empty()) {
        bstStructure.add(currentWord);
    }
    sourceFile.close();
}

void printFreq(BST<std::string>& bstStructure) {
    auto items = bstStructure.getAllNodes();
    std::sort(items.begin(), items.end(),
        [](const std::pair<std::string, int>& firstItem,
           const std::pair<std::string, int>& secondItem) {
            if (firstItem.second != secondItem.second) 
                return firstItem.second > secondItem.second;
            return firstItem.first < secondItem.first;
        });

    for (const auto& entry : items) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    std::ofstream outputFile("result/freq.txt");
    if (!outputFile) {
        std::cerr << "Warning: Could not write to result/freq.txt" << std::endl;
        return;
    }
    for (const auto& entry : items) {
        outputFile << entry.first << " " << entry.second << std::endl;
    }
    outputFile.close();
}
