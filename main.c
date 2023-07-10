#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	BSTPtr b;
	initBST(&b);
	

	b = addElement(b, createProduct(1, "Milktea", 10, 20.00));
	b = addElement(b, createProduct(2, "Burger", 3, 35.50));
	b = addElement(b, createProduct(3, "Noodles", 20, 8.25));

	printf("In Order:\n");
	inorderBST(b);
	printf("\nPre Order:\n");
	preorderBST(b);
	printf("\nPost Order:\n");
	postorderBST(b);

	
	return 0;
}
