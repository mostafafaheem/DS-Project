// trie.cpp

#include "trie.h"

Trie::Trie() {
    root = new Node();
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(string name) {
    Node* tmp = root;
    for (char i : name) {
        if (!(tmp->nodes.count(i))) {
            Node* n = new Node();
            tmp->nodes[i] = n;
        }
        tmp = tmp->nodes[i];
    }
    tmp->EndOfWord = true;
}

vector<string> Trie::searchPre(string pre) {
    vector<string> words;
    Node* tmp = root;
    for (char i : pre) {
        if (!(tmp->nodes.count(i))) return {};
        tmp = tmp->nodes[i];
    }
    searchHelper("", pre, tmp, words);
    return words;
}

void Trie::searchHelper(string cur, string pre, Node* tmp, vector<string>& arr) {
    if (!tmp) return;
    if (tmp->EndOfWord) {
        arr.push_back(pre + cur);
    }
    for (auto& pair : tmp->nodes) {
        searchHelper(cur + pair.first, pre, pair.second, arr);
    }
}
