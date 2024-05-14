#pragma once
#include <iostream>
#include <atomic>
#include <unordered_map>
#include "trie.h"
#include "models.h"
#include "rbtree.cpp"
#include "database.h"
#include "search.h"
#include "globals.h"

using namespace std;
extern Trie* trie;
extern vector<Property> listings;
extern vector<User*> usersList;
extern User* currentLoggedIn;
extern RBTree<float, Property*> properties;
extern unordered_map<int, Property> propertyMap;
