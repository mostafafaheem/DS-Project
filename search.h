// search.h

#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>
#include "models.h"
#include "globals.h"
using namespace std;

class search {
public:
    std::vector<std::string> searchByName(std::string pre);
    std::vector<property> filterByLocation(std::string state);
    std::vector<property> filterByPrice(float min, float max);
};

#endif /* SEARCH_H */
