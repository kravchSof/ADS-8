// Copyright 2025 NNTU-CS
#ifndef INCLUDE_BST_H__
#define INCLUDE_BST_H__

#include <string>
#include <algorithm>
#include <vector>
#include <utility>

template<typename T>
class BST {
 private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;
        explicit Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insert(Node*& node, const T& key) {
        if (!node) {
            node = new Node(key);
        } else if (key < node->key) {
            insert(node->left, key);
        } else if (key > node->key) {
            insert(node->right, key);
        } else {
            node->count++;
        }
    }

    bool search(Node* node, const T& key) const {
        if (!node) return false;
        if (key < node->key) return search(node->left, key);
        if (key > node->key) return search(node->right, key);
        return true;
    }

    int height(Node* node) const {
        if (!node) return -1;
        return 1 + std::max(height(node->left), height(node->right));
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void inorderCollect(Node* node, std::vector<std::pair<T, int>>& vec) const {
        if (node) {
            inorderCollect(node->left, vec);
            vec.emplace_back(node->key, node->count);
            inorderCollect(node->right, vec);
        }
    }

 public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(const T& key) { ::insert(root, key); }
    bool search(const T& key) const { return search(root, key); }
    int depth() const { return height(root) + 1; }  // Возвращаем количество узлов, а не рёбер
    std::vector<std::pair<T, int>> getNodes() const {
        std::vector<std::pair<T, int>> vec;
        inorderCollect(root, vec);
        return vec;
    }
};

#endif  // INCLUDE_BST_H_
