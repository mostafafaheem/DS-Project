#pragma once
#include <string>
#include <map>
#include<vector>
using namespace std;
class property {
public:
    std::string name;
    std::map<std::string, std::string> location;
    float price;
    property(const std::string& n, const std::map<std::string, std::string>& loc, float p)
        : name(n), location(loc), price(p) {
        
    }
};

