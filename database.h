// database.h

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>
#include "globals.h"
#include "models.h"

class database {
public:
    void addListing(float price, std::string name, std::string city, std::string country, std::string state);


};

#endif 
