#include <iostream>
#include <string>
#include <atomic>
#include "models.h"
using namespace std;


atomic<int> Property::idCounter(0);

enum class Color { RED, BLACK };

template <typename Key, typename Value>
class RBTree {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        Color color;

        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr), color(Color::RED) {}
    };

    Node* root;

    void rotateLeft(Node*& node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        temp->color = node->color;
        node->color = Color::RED;
        node = temp;
    }

    void rotateRight(Node*& node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        temp->color = node->color;
        node->color = Color::RED;
        node = temp;
    }

    void flipColors(Node* node) {
        node->color = Color::RED;
        node->left->color = Color::BLACK;
        node->right->color = Color::BLACK;
    }

    bool isRed(Node* node) {
        if (node == nullptr) return false;
        return node->color == Color::RED;
    }

    void insert(Node*& node, const Key& key, const Value& value) {
        if (node == nullptr) {
            node = new Node(key, value);
            return;
        }

        if (key < node->key) {
            insert(node->left, key, value);
        }
        else if (key > node->key) {
            insert(node->right, key, value);
        }
        else {
            node->value = value;
            return;
        }

        // Fix any violations
        if (isRed(node->right) && !isRed(node->left)) {
            rotateLeft(node);
        }
        if (isRed(node->left) && isRed(node->left->left)) {
            rotateRight(node);
        }
        if (isRed(node->left) && isRed(node->right)) {
            flipColors(node);
        }
    }

public:
    RBTree() : root(nullptr) {}

    void insert(const Key& key, const Value& value) {
        insert(root, key, value);
        root->color = Color::BLACK; // Root must always be black
    }

    // Other functions like search, remove, etc. can be implemented here
};


