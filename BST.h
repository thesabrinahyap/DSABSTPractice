#ifndef BST_H
#define BST_H

#include<stdbool.h>
typedef struct{
	int prodID;
	char prodName[20];
	int prodQty;
	float prodPrice;
}Product;

typedef struct node{
	Product data;
	struct node *left;
	struct node *right;
} NodeType, *NodePtr, BST, *BSTPtr;

//Delete element in the BST based on the product ID
void removeElement(BSTPtr* list, int prodID); //using iterative method
BSTPtr deleteElement(BSTPtr list, int prodID); //using recursive method

//Adding element to BST
BSTPtr addElement(BSTPtr list, Product item); //recursive method
void insertBST(BSTPtr *list, Product item); //iterative method

//Tree traversal all in recursive method
void inorderBST(BSTPtr list);
void preorderBST(BSTPtr list);
void postorderBST(BSTPtr list);

//Other functions
BSTPtr newBST();
void initBST(BSTPtr *list);
bool isEmpty(BSTPtr list);
Product createProduct(int id, char *name, int qty, float price);
void displayProduct(Product prod); //use the following format {<id> | <prodName>} replacing the angular brackets with data
BSTPtr max(BSTPtr list);
BSTPtr min(BSTPtr list);
bool isMember(BSTPtr list, int prodID);
#endif


