#include<iostream>
#include "trie.h"
#include "models.h"
#include "database.h"
#include "search.h"
#include "globals.h"
using namespace std;

Trie* trie = new Trie();
vector<property> properties;
vector<User*> usersList;
User* currentLoggedIn = NULL;
RBTree<float, Property> properties;
