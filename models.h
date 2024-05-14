//#pragma once
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include <atomic>

using namespace std;

class Property {
private:
    static std::atomic<int> idCounter;
public:
    int id;
    int beds;
    int baths;
    string type;
    string description;
    string features;
    User* approvedBy;
    User* listedBy;
    string name;
    string location;
    float price;
    bool approved;
    bool highlighted;

    Property(const int& beds, const int& baths, const string& n, const string& type, const string& description, const string& features, const string& loc, float p)
        : name(n), location(loc), price(p), beds(beds), baths(baths), type(type), description(description), features(features) {
        id = ++idCounter;
        approved = false;
        highlighted = false;
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
