#include "admin.h"

void Admin::deleteProperty(int id) {
	if (currentLoggedIn == NULL || !currentLoggedIn->isAdmin) return;
	propertyMap.erase(id);
}


void Admin::editProperty(int id) {
	if (currentLoggedIn == NULL || !currentLoggedIn->isAdmin) return;
	propertyMap.at(id).price;
}


void Admin::approveProperty(int id) {
	propertyMap[id].approved = true;
	propertyMap[id].approvedBy = currentLoggedIn->username;
	approvalQueue.pop();
}


void Admin::highlightProperty(int id) {
	propertyMap.at(id).highlighted = true;
}
//add functionality to remove highlights, include user prompts