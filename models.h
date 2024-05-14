//#pragma once
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <atomic>

using namespace std;

class Property {
public:
    int id;
    int beds;
    int baths;
    string type;
    string description;
    User* approvedBy;
    User* listedBy;
    string location;
    float price;
    bool approved;
    bool highlighted;

    Property(const int& id, const int& beds, const int& baths, const string& type, const string& description , const string& loc, float p)
        : location(loc), price(p), beds(beds), baths(baths), type(type), description(description) {
        approved = false;
        highlighted = false;
        listedBy = currentLoggedIn;
        approvedBy = NULL;
    }
};

std::atomic<int> Property::idCounter{ 0 };

class User {
public:
    string username;
    string email;
    string password;
    string phoneNumber;
    string name;

    bool isAdmin;
    User(const string& username, const string& email, const string& password, const string& phoneNumber, const string& name)
        : username(username), email(email), password(password), phoneNumber(phoneNumber), name(name) {
        isAdmin = false;
    }
};