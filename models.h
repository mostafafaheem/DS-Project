//#pragma once
#include <string>
#include <map>
#include<vector>
#include<math.h>
#include <atomic>

using namespace std;

class Property {
private:
    static std::atomic<int> idCounter;
public:
    int id;
    //int beds;
    //int baths;
    //string type;
    //string description;
    //string features;
    //authorizedby??
    std::string name;
    std::string location;
    float price;
    bool approved;
    bool highlighted;

    Property(const std::string& n, const std::string& loc, float p)
        : name(n), location(loc), price(p), approved(false), highlighted(false) {
        id = ++idCounter;
    }
};

std::atomic<int> Property::idCounter{ 0 };

class User {
public:
    std::string username;
    std::string email;
    std::string password;
    std::string phoneNumber;
    //std::string name;
    //includelistedproperties??

    bool isAdmin;
    User(const std::string& username, const std::string& email, const std::string& password, const std::string& phoneNumber)
        : username(username), email(email), password(password), phoneNumber(phoneNumber) isAdmin(false) {}
};
