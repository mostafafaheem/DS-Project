#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "user.h" // Include user.h for User class

class Property {
public:
    int id;
    int beds;
    int baths;
    string type;
    string description;
    string approvedBy; 
    string listedBy;  
    string location;
    float price;
    bool approved;
    bool highlighted;

    // Constructor
    Property(int id, int beds, int baths, const std::string& type, const std::string& description, const std::string& approvedBy, const std::string& listedBy,
        const std::string& loc, float p)
        : id(id), beds(beds), baths(baths), type(type), description(description), approvedBy(approvedBy), listedBy(listedBy),
        location(loc), price(p), approved(false), highlighted(false) {}

    // Overloaded Constructor with approvedBy parameter
  
};

#endif // PROPERTY_H
