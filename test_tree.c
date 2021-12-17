#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ftree.h"

int main(){
	
	//test cons
	printf("---Test cons---\n");
	TreeNode* tr = ftree_cons(12.34);
	tree_printTree(tr, stdout, ftoString);

	//test insert
	printf("---Test insert---\n");
	ftree_insert(tr, 00.00);
	ftree_insert(tr, 22.33);
	ftree_insert(tr, 11.11);
	ftree_insert(tr, 13.14);
	tree_printTree(tr, stdout, ftoString);
	
	//test print
	printf("---Test print---\n");
	printf("> pre-order\n");
	tree_printPreorder(tr, stdout, ftoString);
	printf("> in-order\n");
	tree_printInorder(tr, stdout, ftoString);
	printf("> post-order\n");
	tree_printPostorder(tr, stdout, ftoString);
	
	//test getNode & valOf
	printf("---Test get---\n");
	TreeNode* grabbed = ftree_getNode(tr, 22.33);
	printf("grabbing 22.33: %f\n", ftree_valOf(grabbed));
	printf("Is it a leaf? %d\n", tree_isleaf(grabbed));

	grabbed = ftree_getNode(tr, 11.11);
        printf("grabbing 11.11: %f\n", ftree_valOf(grabbed));
	printf("Is it a leaf? %d\n", tree_isleaf(grabbed));

	grabbed = ftree_getNode(tr, 55.55);
        printf("grabbing 55.55: ...is NULL? %d\n", grabbed==NULL);
	printf("Is it a leaf? %d\n", tree_isleaf(grabbed));

	//test free
	tree_freeTree(tr);

	return 0;
}
