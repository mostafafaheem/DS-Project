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

void writePropertyDataToFile(const std::string& filename, const std::unordered_map<int, Property>& properties) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : properties) {
            const Property& prop = pair.second;
            file << prop.id << " " << prop.beds << " " << prop.baths << " "
                << prop.type << " " << prop.description << " "
                << prop.listedBy << " " << prop.location << " "
                << prop.price << " " << prop.approvedBy << " "
                << (prop.approved ? "1" : "0") << " "
                << (prop.highlighted ? "1" : "0") << std::endl;
        }
        file.close();
    }
}

