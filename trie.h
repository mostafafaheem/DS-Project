// trie.h

#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <map>
#include <string>
using namespace std;

class Node {
public:
    map<char, Node*> nodes;
    bool EndOfWord = false;

    ~Node() {
        for (auto& pair : nodes) {
            delete pair.second;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie();

    ~Trie();

    void insert(string name);

    vector<string> searchPre(string pre);

private:
    void searchHelper(string cur, string pre, Node* tmp, vector<string>& arr);
};

#endif /* TRIE_H */
