#include "trie.h"
#include "models.h"
#include "database.h"
#include "search.h"
#include "globals.h"

Trie* trie = new Trie();
vector<property> listings;
vector<User*> usersList;
User* currentLoggedIn = NULL;
RBTree<float, Property> properties;
static atomic<int> idCounter;

