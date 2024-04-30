#include <string>
#include <map>
#include<vector>
#include "models.h"
#include "globals.h"
#include "database.h"
using namespace std;


    

void database::addListing(float price, string name, string city, string country, string state) {
        map<string, string> location = { {"city", city}, {"country", country}, {"state", state} };

        property p(name, location, price);
        for (property i : listings) {
            if (i.name == name) {
                return;
            }
        }
        listings.push_back(p);
        trie->insert(name);


    }

