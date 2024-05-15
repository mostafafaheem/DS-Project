//#include <iostream>
//#include <string>
//#include "property.h"
//#include "user.h"
//using namespace std;
//
//enum class Color { RED, BLACK };
//
//template <typename Key, typename Value>
//class RBTree {
//private:
//    struct Node {
//        Key key;
//        multimap<float, Value> properties;
//        Node* left;
//        Node* right;
//        Color color;
//
//        Node(const Key& k, const Value& v) : key(k), left(nullptr), right(nullptr), color(Color::RED) {
//            properties.insert(make_pair(v->price, v));
//        }
//    };
//
//    Node* root;
//
//    void rotateLeft(Node*& node) {
//        Node* temp = node->right;
//        node->right = temp->left;
//        temp->left = node;
//        temp->color = node->color;
//        node->color = Color::RED;
//        node = temp;
//    }
//
//    void rotateRight(Node*& node) {
//        Node* temp = node->left;
//        node->left = temp->right;
//        temp->right = node;
//        temp->color = node->color;
//        node->color = Color::RED;
//        node = temp;
//    }
//
//    void flipColors(Node* node) {
//        node->color = Color::RED;
//        node->left->color = Color::BLACK;
//        node->right->color = Color::BLACK;
//    }
//
//    void insert(Node*& node, const Key& key, const Value& value) {
//        if (node == nullptr) {
//            node = new Node(key, value);
//            return;
//        }
//
//        if (key < node->key) {
//            insert(node->left, key, value);
//        }
//        else if (key > node->key) {
//            insert(node->right, key, value);
//        }
//        else {
//            node->properties.insert(make_pair(value->price, value));
//            return;
//        }
//
//        if (isRed(node->right) && !isRed(node->left)) {
//            rotateLeft(node);
//        }
//        if (isRed(node->left) && isRed(node->left->left)) {
//            rotateRight(node);
//        }
//        if (isRed(node->left) && isRed(node->right)) {
//            flipColors(node);
//        }
//    }
//
//    void searchSameKey(Node* node, const Key& targetKey, vector<Value>& result) {
//        if (node == nullptr) return;
//
//        if (targetKey < node->key) {
//            searchSameKey(node->left, targetKey, result);
//        }
//        else if (targetKey > node->key) {
//            searchSameKey(node->right, targetKey, result);
//        }
//        else {
//            // Found properties with the same key
//            for (const auto& prop : node->properties) {
//                result.push_back(prop.second);
//            }
//        }
//    }
//
//
//public:
//    RBTree() : root(nullptr) {}
//
//    void insert(const Key& key, const Value& value) {
//        insert(root, key, value);
//        root->color = Color::BLACK;
//    }
//    // Search function to find a node by its key
//    Node* search(const Key& key) {
//        return search(root, key);
//    }
//
//    // Remove function to remove a node by its key
//    void remove(const Key& key) {
//        root = remove(root, key);
//        if (root != nullptr) {
//            root->color = Color::BLACK; // Ensure root is black after removal
//        }
//    }
//};