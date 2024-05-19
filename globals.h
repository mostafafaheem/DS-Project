#pragma once
#include <iostream>
#include <unordered_map>
#include "trie.h"
#include "property.h"
#include "user.h"
#include "search.h"

using namespace std;
extern Trie* trie;
extern atomic<int> idCounter;

extern vector<User*> usersList;
extern User* currentLoggedIn;
extern unordered_map<int, Property> propertyMap;
