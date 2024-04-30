#pragma once
#include "models.h"
class listingNode {
public:
    int id;
    int height;
    property* p;
    listingNode* left, * right;
    listingNode();
    listingNode(property *prop);
    void updateHeight();
    
    int balanceFactor();
   
   


};

class listingsTree
{
public:
	static int size;
	listingNode* root;
    listingsTree();
    listingNode* balance(listingNode* root);
    listingNode* insert(listingNode* root,property* prop);
    listingNode* leftRotation(listingNode* root);
    listingNode* rightRotation(listingNode* root);

	

};

