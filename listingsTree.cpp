#include "listingsTree.h"
#include "models.h"

//listingNode::listingNode(property *prop) {
//	this->id = id;
//	height = 1;
//	this->p = prop;
//	left = right = NULL;
//	id = listingsTree->size + 1;
//
//}
//void listingNode::updateHeight() {
//	int left = (this->left) == NULL ? 0 : (this->left->height);
//	int right = (this->right) == NULL ? 0 : (this->right->height);
//	this->height =  1 + max(left, right);
//}
//
//int listingNode::balanceFactor() {
//	int left = (this->left) == NULL ? 0 : (this->left->height);
//	int right = (this->right) == NULL ? 0 : (this->right->height);
//	return left - right;
//}
//listingsTree::listingsTree() {
//	this->size = 0;
//	root = new listingNode();
//}
//listingNode* listingsTree::insert(listingNode* root, int id, property* prop) {
//	if (!root)  { 
//		size++;
//		return new listingNode(id, prop); }
//	if (root->p->name == prop->name) return root;
//
//	if (root->id > id) root->left = insert(root, id, prop);
//	if (root->id < id) root->right = insert(root, id, prop);
//
//	root->updateHeight();
//	root = balance(root);
//	return root;
//
//}
//listingNode* listingsTree::balance(listingNode* root) {
//	if (root->height == 2) {
//		if (root->right->height == -1) {
//			root->left = leftRotation(root->left);
//
//		}
//		root = rightRotation(root);
//	}
//	else if (root->height == -2) {
//		if (root->right->height == 1) {
//			root->right = rightRotation(root->right);
//
//		}
//		root = leftRotation(root);
//	}
//	return root;
//}
//listingNode* listingsTree::leftRotation(listingNode* root) {
//	listingNode* p = root->right;
//	root->right = p->left;
//	p->left = root;
//	p->updateHeight();
//	root->updateHeight();
//	return p;
//}
//listingNode* listingsTree::rightRotation(listingNode* root) {
//	listingNode* p = root->left;
//	root->left = p->right;
//	p->right = root;
//	p->updateHeight();
//	root->updateHeight();
//	return p;
//}