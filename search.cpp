#include <iostream>
#include <vector>
#include "search.h"
#include "models.h"
#include "globals.h"

using namespace std;

    vector<string> search::searchByName(string pre) {
        return trie->searchPre(pre);
    }

    vector<Property> search::filterByLocation(string state) {
        vector<Property> ans;
        for (Property i : listings) {
            if (i.location == state) ans.push_back(i);
        }
        return ans;
    }

    vector<Property> search::filterByPrice(float min, float max) {
        vector<Property> ans;
        for (Property i : listings) {
            if (i.price >= min && i.price <= max) ans.push_back(i);
        }
        return ans;
    }