// Copyright 2025 NNTU-CS
#ifndef INCLUDE_BST_H__
#define INCLUDE_BST_H__

#include <string>
#include <algorithm>
#include <vector>
#include <utility>

template<typename DataType>
class BST {
 private:
    struct TreeNode {
        DataType value;
        int occurrences;
        TreeNode* leftBranch;
        TreeNode* rightBranch;
        explicit TreeNode(const DataType& val) : value(val), occurrences(1), leftBranch(nullptr), rightBranch(nullptr) {}
    };
    TreeNode* top;

    void addNode(TreeNode*& current, const DataType& val) {
        if (!current) {
            current = new TreeNode(val);
        } else if (val < current->value) {
            addNode(current->leftBranch, val);
        } else if (val > current->value) {
            addNode(current->rightBranch, val);
        } else {
            current->occurrences++;
        }
    }

    int findNode(TreeNode* current, const DataType& val) const {
        if (!current) return 0;
        if (val < current->value) return findNode(current->leftBranch, val);
        if (val > current->value) return findNode(current->rightBranch, val);
        return current->occurrences;
    }

    int calcHeight(TreeNode* current) const {
        if (!current) return -1;
        return 1 + std::max(calcHeight(current->leftBranch), calcHeight(current->rightBranch));
    }

    void eraseTree(TreeNode* current) {
        if (current) {
            eraseTree(current->leftBranch);
            eraseTree(current->rightBranch);
            delete current;
        }
    }

    void collectInOrder(TreeNode* current, std::vector<std::pair<DataType, int>>& container) const {
        if (current) {
            collectInOrder(current->leftBranch, container);
            container.emplace_back(current->value, current->occurrences);
            collectInOrder(current->rightBranch, container);
        }
    }

 public:
    BST() : top(nullptr) {}
    ~BST() { eraseTree(top); }

    void add(const DataType& val) { addNode(top, val); }
    int search(const DataType& val) const { return findNode(top, val); }
    int depth() const { return calcHeight(top); }
    std::vector<std::pair<DataType, int>> getAllNodes() const {
        std::vector<std::pair<DataType, int>> container;
        collectInOrder(top, container);
        return container;
    }
};

#endif  // INCLUDE_BST_H__
