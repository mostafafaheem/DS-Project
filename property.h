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
    string listedBy;  
    string location;
    float price;
    
    string approvedBy;
    bool approved;
    bool highlighted;

    Property() : id(0), beds(0), baths(0), type(""), description(""), listedBy(""), location(""), price(0.0f), approvedBy(""),approved(false), highlighted(false) {}
    // Constructor
    Property(int id, int beds, int baths, const std::string& type, const std::string& description,  const std::string& listedBy,
        const std::string& loc, float p)
        : id(id), beds(beds), baths(baths), type(type), description(description),  listedBy(listedBy),
        location(loc), price(p), approved(false), highlighted(false) {
    }

  
};

#endif // PROPERTY_H
