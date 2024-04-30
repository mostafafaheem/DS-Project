#include <iostream>
#include<vector>
#include "search.h"
#include "models.h"
#include "globals.h"

using namespace std;


    vector<string> search::searchByName(string pre) {
        return trie->searchPre(pre);

    }
    vector<property> search::filterByLocation(string state) {
        vector<property> ans;
        for (property i : listings) {
            if (i.location["state"] == state) ans.push_back(i);
        }
        return ans;
    }
    vector<property> search::filterByPrice(float min, float max) {
        vector<property> ans;
        for (property i : listings) {
            if (i.price >= min && i.price <= max) ans.push_back(i);
        }
        return ans;
    }
