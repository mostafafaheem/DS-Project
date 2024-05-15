#include "Admin.h"

void Admin::deleteProperty(int id) {
	if (currentLoggedIn == NULL || !currentLoggedIn->isAdmin) return;
	propertyMap.erase(id);
}


void Admin::editProperty(int id) {
	if (currentLoggedIn == NULL || !currentLoggedIn->isAdmin) return;
	propertyMap.at(id).price;
}


void Admin::approveProperty(int id) {
	if (currentLoggedIn == NULL || !currentLoggedIn->isAdmin) return;
	propertyMap.at(id).approved = true;
}


void Admin::highlightProperty(int id) {
	propertyMap.at(id).highlighted = true;
}
//add functionality to remove highlights, include user prompts