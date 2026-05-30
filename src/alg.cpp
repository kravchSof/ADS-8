// Copyright 2021 NNTU-CS
#include "bst.h"
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string word;
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            // Строим слово из букв
            word.push_back(std::tolower(static_cast<unsigned char>(ch)));
        } else {
            // Если накоплено слово и оно не пустое – вставляем
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }
    // Проверяем последнее слово (если файл закончился буквой)
    if (!word.empty()) {
        tree.insert(word);
    }
    file.close();
}

void printFreq(BST<std::string>& tree) {
    auto nodes = tree.getNodes();
    // Сортируем по убыванию частоты, при равной частоте – лексикографически
    std::sort(nodes.begin(), nodes.end(),
        [](const std::pair<std::string, int>& a,
           const std::pair<std::string, int>& b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });

    // Вывод в консоль и в файл
    std::ofstream out("result/freq.txt");
    if (!out) {
        std::cerr << "Cannot create result/freq.txt" << std::endl;
        return;
    }

    for (const auto& p : nodes) {
        std::cout << p.first << ": " << p.second << std::endl;
        out << p.first << ": " << p.second << std::endl;
    }
    out.close();
}
