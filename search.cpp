#include "search.h"

using namespace std;

vector<string> Search::searchByName(string pre) {
    return trie->searchPre(pre);

}

vector<Property> Search::filterByLocation(unordered_map<int, Property>& propertyMap, std::string state)
{
    std::vector<Property> ans;
    for (const auto& pair : propertyMap) {
        const Property& prop = pair.second;
        if (prop.location == state) {
            ans.push_back(prop);
        }
    }
    return ans;
}

std::vector<Property> Search::filterByPrice(const std::unordered_map<int, Property>& propertyMap, float minPrice, float maxPrice) {
    std::vector<Property> ans;
    for (const auto& pair : propertyMap) {
        const Property& prop = pair.second;
        if (prop.price >= minPrice && prop.price <= maxPrice) {
            ans.push_back(prop);
        }
    }
    return ans;
}
vector<Property> Search::filterByBedrooms(const std::unordered_map<int, Property>& propertyMap, int minBedrooms, int maxBedrooms) {
    std::vector<Property> ans;
    for (const auto& pair : propertyMap) {
        const Property& prop = pair.second;
        if (prop.beds >= minBedrooms && prop.beds <= maxBedrooms) {
            ans.push_back(prop);
        }
    }
    return ans;
}

vector<Property> Search::filterByBathrooms(const unordered_map<int, Property>& propertyMap, int minBathrooms, int maxBathrooms) {
    std::vector<Property> ans;
    for (const auto& pair : propertyMap) {
        const Property& prop = pair.second;
        if (prop.baths >= minBathrooms && prop.baths <= maxBathrooms) {
            ans.push_back(prop);
        }
    }
    return ans;
}

vector<Property> Search::filterByType(const unordered_map<int, Property>& propertyMap, string type)
{
    vector<Property> ans;
    for (const auto& pair : propertyMap) {
        const Property& prop = pair.second;
        if (prop.type == type) {
            ans.push_back(prop);
        }
    }
    return ans;
}
vector<Property> Search::compositePropertySearch(const unordered_map<int, Property>& propertyMap, int minBedrooms, int maxBedrooms, int minBathrooms, int maxBathrooms, float minPrice, float maxPrice, const string& location, const string& type) {
    vector<Property> ans;
    for (const auto& pair : propertyMap) {
        const Property& prop = pair.second;
        // Check each criterion
        if (prop.beds >= minBedrooms && prop.beds <= maxBedrooms &&
            prop.baths >= minBathrooms && prop.baths <= maxBathrooms &&
            prop.price >= minPrice && prop.price <= maxPrice &&
            prop.location == location && prop.type == type) {
            ans.push_back(prop);
        }
    }
    return ans;
}
