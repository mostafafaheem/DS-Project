#include "files.h"

void Files::readUserDataFromFile(const string& filename, vector<User*>& users) {
    ifstream file(filename);
    if (file.is_open()) {
        string username, password, email, name, phoneNumber;
        bool isAdmin;
        while (file >> username >> password >> email >> phoneNumber >> name >> isAdmin) {
            User* newUser = new User(username, email, password, phoneNumber, name, isAdmin);
            users.push_back(newUser);
        }
        file.close();
    }
}


void Files::writeUserDataToFile(const string& filename, const vector<User*>& users) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const User* user : users) {
            file << user->username << " "
                 << user->password << " "
                 << user->email << " "
                 << user->phoneNumber << " "
                 << user->name << " "
                 << user->isAdmin << endl;
        }
        file.close();
    }
}

void Files::writePropertyDataToFile(const std::string& filename, const std::unordered_map<int, Property>& properties) {
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

void Files::readPropertyDataFromFile(const std::string& filename, std::unordered_map<int, Property>& properties) {
    std::ifstream file(filename);
    if (file.is_open()) {
        properties.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Property prop;
            int approved, highlighted;
            if (iss >> prop.id >> prop.beds >> prop.baths >> prop.type >> prop.description
                >> prop.listedBy >> prop.location >> prop.price >> prop.approvedBy
                >> approved >> highlighted) {
                prop.approved = approved;
                prop.highlighted = highlighted;
                properties[prop.id] = prop;
            }
            else {
                std::cerr << "Error reading property data from file: " << filename << std::endl;
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}

