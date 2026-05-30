// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <algorithm>

template<typename T>
class BST {
 private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;
        Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    int depthHelper(Node* node) const {
        if (!node) return 0;
        return 1 + std::max(depthHelper(node->left), depthHelper(node->right));
    }

    Node* insertHelper(Node* node, const T& value, bool& inserted) {
        if (!node) {
            inserted = true;
            return new Node(value);
        }
        if (value < node->key) {
            node->left = insertHelper(node->left, value, inserted);
        } else if (value > node->key) {
            node->right = insertHelper(node->right, value, inserted);
        } else {
            // ключ уже существует
            node->count++;
            inserted = false;
        }
        return node;
    }

    bool searchHelper(Node* node, const T& value) const {
        if (!node) return false;
        if (value == node->key) return true;
        if (value < node->key) return searchHelper(node->left, value);
        return searchHelper(node->right, value);
    }

    void inorderCollect(Node* node, std::vector<std::pair<T, int>>& vec) const {
        if (!node) return;
        inorderCollect(node->left, vec);
        vec.push_back({node->key, node->count});
        inorderCollect(node->right, vec);
    }

 public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(const T& value) {
        bool inserted = false;
        root = insertHelper(root, value, inserted);
    }

    bool search(const T& value) const {
        return searchHelper(root, value);
    }

    int depth() const {
        return depthHelper(root);
    }

    // Получить все узлы в виде пар (ключ, частота) для сортировки по частоте
    std::vector<std::pair<T, int>> getNodes() const {
        std::vector<std::pair<T, int>> vec;
        inorderCollect(root, vec);
        return vec;
    }
};

#endif  // INCLUDE_BST_H_
