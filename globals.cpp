#include "trie.h"
#include "models.h"
#include "database.h"
#include "search.h"
#include "globals.h"

Trie* trie = new Trie();
vector<User*> usersList;
User* currentLoggedIn = NULL;
static atomic<int> idCounter;
unordered_map<int, Property> propertyMap;
RBTree<float, Property*> properties;
