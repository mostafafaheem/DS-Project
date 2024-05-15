#include "files.h"

vector<User> Files::readUserDataFromFile(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    if (file.is_open()) {
        string username, password, email, name, phoneNumber;
        bool isAdmin;
        while (file >> username >> password >> email >> phoneNumber >> name >> isAdmin) {
            users.push_back(User(username, email, password, phoneNumber, name, isAdmin));
        }
        file.close();
    }
    return users;
}

//void Files::writeUserDataToFile(const string& filename, const vector<User>& users) {
//    ofstream file(filename);
//    if (file.is_open()) {
//        for (const auto& User : users) {
//            file << users.front().username << " " << users.front().password << " " << users.front().email << " "
//                << users.front().phoneNumber << " " << users.front().isAdmin << endl;
//            users.pop_back();
//        }
//        file.close();
//    }
//}
