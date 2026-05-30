// Copyright 2025 NNTU-CS
#ifndef INCLUDE_BST_H__
#define INCLUDE_BST_H__

#include <string>
#include <algorithm>
#include <vector>
#include <utility>

template<typename KeyType>
class BinarySearchTree {
 private:
    struct TreeNode {
        KeyType data;
        int freq;
        TreeNode* leftChild;
        TreeNode* rightChild;
        explicit TreeNode(const KeyType& val) : data(val), freq(1), leftChild(nullptr), rightChild(nullptr) {}
    };
    TreeNode* rootNode;

    void addNode(TreeNode*& current, const KeyType& val) {
        if (!current) {
            current = new TreeNode(val);
        } else if (val < current->data) {
            addNode(current->leftChild, val);
        } else if (val > current->data) {
            addNode(current->rightChild, val);
        } else {
            current->freq++;
        }
    }

    int findNode(TreeNode* current, const KeyType& val) const {
        if (!current) return 0;
        if (val < current->data) return findNode(current->leftChild, val);
        if (val > current->data) return findNode(current->rightChild, val);
        return current->freq;
    }

    int computeHeight(TreeNode* current) const {
        if (!current) return -1;
        return 1 + std::max(computeHeight(current->leftChild), computeHeight(current->rightChild));
    }

    void deleteTree(TreeNode* current) {
        if (current) {
            deleteTree(current->leftChild);
            deleteTree(current->rightChild);
            delete current;
        }
    }

    void traverseInOrder(TreeNode* current, std::vector<std::pair<KeyType, int>>& result) const {
        if (current) {
            traverseInOrder(current->leftChild, result);
            result.emplace_back(current->data, current->freq);
            traverseInOrder(current->rightChild, result);
        }
    }

 public:
    BinarySearchTree() : rootNode(nullptr) {}
    ~BinarySearchTree() { deleteTree(rootNode); }

    void insert(const KeyType& val) { addNode(rootNode, val); }
    int lookup(const KeyType& val) const { return findNode(rootNode, val); }
    int getDepth() const { return computeHeight(rootNode); }
    std::vector<std::pair<KeyType, int>> fetchAllNodes() const {
        std::vector<std::pair<KeyType, int>> result;
        traverseInOrder(rootNode, result);
        return result;
    }
};

#endif  // INCLUDE_BST_H__
