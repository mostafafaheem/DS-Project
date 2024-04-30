
#include <string>
#include <iostream>
#include <map>

#include<vector>
#include "search.h"
#include "database.h"
using namespace std;






int main()
{
	
	database* db = new database();
	search* se = new search();
	db->addListing(122.0f, "aaa", "aaaa", "aaaa", "aaaa");
	db->addListing(122.0f, "aaab", "aaaa", "aaaa", "aaaa");
	db->addListing(122.0f, "aaac", "aaaa", "aaaa", "aaaa");
	db->addListing(122.0f, "aaas", "aaaa", "aaaa", "aaaa");
	vector<string> s = se->searchByName("a");
	for (string i : s) cout << i << endl;
}

