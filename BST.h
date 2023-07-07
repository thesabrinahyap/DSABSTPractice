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
void removeElement(BST **list, int prodID); //using iterative method
BST *deleteElement(BST *list, int prodID); //using recursive method

//Adding element to BST
void addElement(BST *list, Product item); //recursive method
void insertBST(BSTPtr *list, Product item); //iterative method

//Tree traversal all in recursive method
void inorderBST(BSTPtr list);
void preorderBST(BSTPtr list);
void postorderBST(BSTPtr list);

//Other functions
BST *newBST();
void initBST(BST **list);
bool isEmpty(BST *list);
Product createProduct(int id, char *name, int qty, float price);
void displayProduct(Product prod); //use the following format {<id> | <prodName>} replacing the angular brackets with data
BST *max(BST *list);
BST *min(BST *list);
bool isMember(BST *list, int prodID);
#endif


