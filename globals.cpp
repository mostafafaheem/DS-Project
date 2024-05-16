#include "globals.h"

Trie* trie = new Trie();
atomic<int> idCounter(0); 
vector<User*> usersList;
User* currentLoggedIn=NULL;
unordered_map<int, Property> propertyMap;
//RBTree<float, Property*> properties;
