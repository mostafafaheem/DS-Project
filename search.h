// search.h
#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>
#include <iostream>
#include "globals.h"

using namespace std;

class Search {
public:
    vector<string> searchByName(std::string pre);
    vector<Property> filterByLocation(unordered_map<int, Property>& propertyMap,std::string state);
    vector<Property> filterByPrice(const std::unordered_map<int, Property>& propertyMap, float minPrice, float maxPrice);
    vector<Property> filterByBedrooms(const std::unordered_map<int, Property>& propertyMap, int minBedrooms, int maxBedrooms);
    vector<Property> filterByBathrooms(const unordered_map<int, Property>& propertyMap, int minBathrooms, int maxBathrooms);    vector<Property> filterByBathrooms(const unordered_map<int, Property>& propertyMap, int minBathrooms, int maxBathrooms);
    vector<Property> filterByType(const unordered_map<int, Property>& propertyMap,string type);
    vector<Property> compositePropertySearch(const unordered_map<int, Property>& propertyMap, int minBedrooms, int maxBedrooms, int minBathrooms, int maxBathrooms, float minPrice, float maxPrice, const string& location, const string& type) {
    };

#endif /* SEARCH_H */
