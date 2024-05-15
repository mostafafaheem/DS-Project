#pragma once
#include <iostream>
#include <unordered_map>
#include "trie.h"
#include "property.h"
#include "user.h"
#include "rbtree.cpp"
#include "search.h"

using namespace std;
extern  int idCounter;
extern Trie* trie;
extern vector<User*> usersList;
extern User* currentLoggedIn;
//extern RBTree<float, Property*> properties;
extern unordered_map<int, Property> propertyMap;
