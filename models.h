#pragma once
#include <string>
#include <map>
#include<vector>
#include<math.h>
using namespace std;
class property {
public:
    std::string name;
    int id;
    string location;
    int price;
    bool highlighted;
    bool approved;
    property(const std::string& n, string loc, float p)
        : name(n), location(loc), price(p) {
        approved = false;
        id = rand() * 10000;
        highlighted = false;
    }
};

class user
{
public:
    user(string username, string email, string password, string pnoneNumber) {
        this->email = email;
        this->password = password;
        this->username = username;
        this->phoneNumber = phoneNumber;
    }
    string username;
    string email;
    string password;
    string phoneNumber;
    bool isAdmin = false;
};