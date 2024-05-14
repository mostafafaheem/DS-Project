// search.h
#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>
#include <iostream>
#include "globals.h"
#include "models.h"

using namespace std;

class search {
public:
    vector<std::string> searchByName(std::string pre);
    vector<Property> filterByLocation(std::string state);
    vector<Property> filterByPrice(float min, float max);
};

#endif /* SEARCH_H */
