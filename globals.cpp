#include "globals.h"

Trie* trie = new Trie();
static int idCounter = 0;
vector<User*> usersList;
User* currentLoggedIn;
unordered_map<int, Property> propertyMap;
//RBTree<float, Property*> properties;
