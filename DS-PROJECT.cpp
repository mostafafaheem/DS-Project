#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct property {
	string name;
	map<string, string> location;
	float price;
	property(const string& n, const map<string, string>& loc, float p) : name(n), location(loc), price(p) {}
};
class Node {
public:
    map<char, Node*> nodes;
    bool EndOfWord = false;

    ~Node() {
        for (auto& pair : nodes) {
            delete pair.second;
        }
    }
};

class Trie {
    Node* root = new Node();
public:
    Trie() {

    }

    ~Trie() {
        delete root;
    }

    void insert(string name) {
        Node* tmp = root;
        for (char i : name) {
            if (!(tmp->nodes.count(i))) {
                Node* n = new Node();
                tmp->nodes[i] = n;
            }
            tmp = tmp->nodes[i];
        }
        tmp->EndOfWord = true;
    }

    vector<string> searchPre(string pre) {
        vector<string> words;
        Node* tmp = root;
        for (char i : pre) {
            if (!(tmp->nodes.count(i))) return {};
            tmp = tmp->nodes[i];
        }
        searchHelper("", pre, tmp, words);
        return words;
    }

    void searchHelper(string cur, string pre, Node* tmp, vector<string>& arr) {
        if (!tmp) return;
        if (tmp->EndOfWord) {
            arr.push_back(pre + cur);
        }
        for (auto& pair : tmp->nodes) {
            searchHelper(cur + pair.first, pre, pair.second, arr);
        }
    }
};

Trie *trie= new Trie();
vector<property> listings;
vector<string> searchByName(string pre) {
    return trie->searchPre(pre);

}
vector<property> filterByLocation(string state) {
    vector<property> ans;
    for (property i : listings) {
        if (i.location["state"] == state) ans.push_back(i);
    }
    return ans;
}
vector<property> filterByPrice(float min, float max) {
    vector<property> ans;
    for (property i : listings) {
        if (i.price >= min && i.price <= max) ans.push_back(i);
    }
    return ans;
}
class database {
public:
    void addListing(float price, string name, string city, string country, string state) {
        map<string, string> location = { {"city", city}, {"country", country}, {"state", state} };

        property p(name, location, price);
        for (property i : listings) {
            if (i.name == name) {
                return;
            }
        }
        listings.push_back(p);
    }

};




int main()
{
	map<string, string> loc;
	loc["country"] = "asa";
	property p("m", loc, 1212.00);
	listings.push_back(p);
	for (property i : listings) cout << i.name;
}

