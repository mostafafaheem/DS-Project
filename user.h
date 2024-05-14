#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    string username;
    string email;
    string password;
    string phoneNumber;
    string name;

    bool isAdmin;

    // Constructor
    User(const std::string& username, const std::string& email, const std::string& password,
        const std::string& phoneNumber, const std::string& name, bool isAdmin = false)
        : username(username), email(email), password(password), phoneNumber(phoneNumber), name(name), isAdmin(isAdmin) {}
};

#endif // USER_H
