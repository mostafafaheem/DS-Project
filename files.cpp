#include "files.h"

vector<User> Files::readUserDataFromFile(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    if (file.is_open()) {
        string username, password, email, phoneNumber;
        bool isAdmin;
        while (file >> username >> password >> email >> phoneNumber >> isAdmin) {
            users.push_back(User(username, password, email, phoneNumber, isAdmin));
        }
        file.close();
    }
    return users;
}

// Function to write user data to file stream
void Files::writeUserDataToFile(const string& filename, const vector<User>& users) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.username << " " << user.password << " " << user.email << " "
                << user.phoneNumber << " " << user.isAdmin << endl;
        }
        file.close();
    }
}
