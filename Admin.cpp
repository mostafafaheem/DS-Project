#include<iostream>
#include "Admin.h"
#include "globals.h"
using namespace std;

void Admin::deleteProperty(int id) {
	if (!isAdmin()) return;
	for (int i = 0; i < listings.size();i++) {
		if (listings[i].id == id) listings.erase(listings.begin()+i);
	}
}


void Admin::editProperty(int id, string editName, string edit) {
	if (!isAdmin()) return;
	for (property i : listings) {
		if (i.id == id) {
			if (editName == "name") i.name = edit;
			if (editName == "price" && isdigit(stoi(edit))) i.price = stoi( edit);
		}
	}
}


void Admin::approveProperty(int id) {
	if (!isAdmin()) return;
	for (property i : listings) {
		if (i.id == id) 
			i.approved = true;
	}
}


void Admin::highlight(int id) {
	if (!isAdmin()) return;
	for (property i : listings) {
		if (i.id == id) i.highlighted = true;
	}
}
//add functionality to remove highlights, include user prompts

bool Admin::isAdmin() {
	return (currentLoggedIn != NULL && currentLoggedIn->isAdmin);
}