// database.h

#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <string>
#include <map>
#include "models.h"
#include "globals.h"

using namespace std;

class database {
public:
    void addListing(float price, std::string name, std::string location);
};

#endif 
