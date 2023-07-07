#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "BST.h"

//Delete element in the BST based on the product ID

//using iterative method
void removeElement(BST **list, int prodID){
	BST* temp, **trav1, **trav2;
	
	for(trav1 = list; *trav1 != NULL && (*trav1)->data.prodID != prodID){
		trav1 = (prodID < (*trav1)->data.prodID)? &(*trav1)->left :  &(*trav1)->right;
	}
	
		if((*trav1) != NULL){
			if((*trav)->left == NULL){
				temp = *trav1;
				*trav1 = temp->right;
				free(temp);
			} else if((*trav)->right == NULL){
				temp = *trav1;
				*trav1 = temp->left;
				free(temp);
			} else{
				trav2 = &(*trav1)->right;
				while((*trav1)->left != NULL){
					trav2 = &(*trav1)->left;
			}
			temp = *trav2;
			*trav2 = temp->right;
			(*trav1)->data	= temp->data;
			free(temp);
		}
	}
}
//using recursive method, use min or max function
BST *deleteElement(BST *list, int prodID){
	BST *deletedBST = list;
	if(isEmpty(deletedBST)){
		deletedBST = NULL;
	} else if(prodID < deletedBST->data.prodID){
		deletedBST->left = deleteElement(deletedBST->left, prodID);
	} else if(prodID > deletedBST->data.prodID){
		deletedBST->right = deleteElement(deletedBST->right, prodID);
	} else{
		// element is found, perform deletion
		if(isEmpty(deletedBST->left) && isEmpty(deletedBST->right)){
			//leaf node deletion
			free(list);
			deletedBST = NULL;
		} else if(isEmpty(deletedBST->left)){
			//right child deletion
			BST *temp = deletedBST;
			deletedBST = deletedBST->right;
			free(temp);
		} else if(isEmpty(deletedBST->right)){
			BST *temp = deletedBST;
			deletedBST = deletedBST->left;
			free(temp);
		} else{
			//left and right child deletion
			BST *minRight = min(deletedBST->right);
			deletedBST->data = minRight->data;
			deletedBST->right = deleteElement(deletedBST->right, minRight->data.prodID);
		}
	}
	return deletedBST;
} 

//Adding element to BST based on the productID

//recursive method
void addElement(BST *list, Product item){
	if(isEmpty(list)){
		list = malloc(sizeof(BST));
		if(*list != NULL){
			(*list)->data = item;
			(*list)->left = (*list)->right = NULL;
		}
	}else{
		if(item.prodID < list->data.prodID){
			addElement(&((*list)->left), item);
		}else{
			addElement(&((*list)->right), item);
		}
	}
} 
//iterative method
void insertBST(BSTPtr *list, Product item){
	while(*list != NULL && (*list)->data.prodID != item.prodID){
		list = (item.prodID < (*list)->data.prodID)? &(*list)->left: &(*list)->right;
	}
	if(isEmpty(list)){
		list = malloc(sizeof(BST));
		if(*list != NULL){
			(*list)->data = item;
			(*list)->left = (*list)->right = NULL;
		}
	}
} 

//Tree traversal all in recursive method
void inorderBST(BSTPtr list){
	if(!isEmpty(list)){
		inorderBST(list->left);
		displayProduct(list->data);
		inorderBST(list->right);
	}
}
void preorderBST(BSTPtr list){
	if(!isEmpty(list)){
		displayProduct(list->data);
		preorderBST(list->left);
		preorderBST(list->right);
	}
}
void postorderBST(BSTPtr list){
	if(!isEmpty(list)){
		postorderBST(list->left);
		postOrderBST(list->right);
		displayProduct(list->data);
	}
}

//Other functions
BST *newBST(){
	BST *b;
	
	b->left = NULL;
	b->right = NULL;
	
	return b;
}
void initBST(BST **list){
	(**list)->left = NULL;
	(**list)->right = NULL;
}
bool isEmpty(BST *list){
	return(*list == NULL)? true: false;
}
Product createProduct(int id, char *name, int qty, float price){
	Product prod;
	
	prod.prodID = id;
	strcpy(prod.prodName, name);
	prod.prodQty = qty;
	prod.prodPrice = price;
	
	return prod;
}
//use the following format {<id> | <prodName>} replacing the angular brackets with data
void displayProduct(Product prod){
	printf("{ %5d | %10s}", prod.prodID, prod.prodName);
} 
BST *max(BST *list){
	BST *biggest;
	
	if(isEmpty(list)){
		biggest = NULL;
	}else if(isEmpty(list->right)){
		biggest = list;
	}else{
		biggest = max(list->right);
	}
	return biggest;
}
BST *min(BST *list){
	BST *smallest;
	
	if(isEmpty(list)){
		smallest = NULL;
	}else if(isEmpty(list->left)){
		smallest = list;
	}else{
		smallest = min(list->left);
	}
	return smallestt;
}
}
bool isMember(BST *list, int prodID){
	bool b = false;
	if(!isEmpty(list)){
		if(list->data.prodID = prodID){
			b = true;
		}else{
			b=(prodID < list->data)? isMember(list->left, prodID): isMember(list->right, prodID);
		}
	}
	return b;
}
