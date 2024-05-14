
#include <string>
#include <map>
#include<vector>
#include "models.h"
#include "globals.h"
#include "database.h"
using namespace std;

void database::addListing(float price, string name,string location) {

        Property p(name, location, price);
        for (Property i : listings) {
            if (i.name == name) {
                return;
            }
        }

        listings.push_back(p);
        trie->insert(name);
    }