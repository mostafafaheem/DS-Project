#pragma once
#include<iostream>
#include "trie.h"
#include "models.h"
#include "rbtree.cpp"
using namespace std;
extern Trie* trie;
extern vector<Property> listings;
extern vector<User*> usersList;
extern User* currentLoggedIn;
extern RBTree<float, Property> properties;

