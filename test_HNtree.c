#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "HNtree.h"

int main(){
	
	//test cons & print
	TreeNode* hnt1 = HNtree_cons(65, 90);  //A:90
	HNtree_printTree(hnt1, stdout);
	fprintHNT(stdout, hnt1);

	//test merge
	printf("---Test Merge---\n");
	TreeNode* hnt2 = HNtree_cons(97, 100); //a:100
	TreeNode* hnt3 = HNtree_cons(64, 10);  //@:10

        TreeNode* hnt13 = mergeHNT(hnt1, hnt3);
        HNtree_printTree(hnt13, stdout);

        TreeNode* hnt31 = mergeHNT(hnt3, hnt1);
        HNtree_printTree(hnt31, stdout);
	free(hnt31->data);
	free(hnt31);

	TreeNode* hnt123 = mergeHNT(hnt13, hnt2);
        HNtree_printTree(hnt123, stdout);
	fprintHNT(stdout, hnt123);

	//test compare
	printf("---Test Compare---\n");
	char* str1 = HNtoString((HuffNode*)(hnt1->data));
	char* str2 = HNtoString((HuffNode*)(hnt2->data));
	char* str3 = HNtoString((HuffNode*)(hnt3->data));
	char* str13 = HNtoString((HuffNode*)(hnt13->data));
	printf("cmp %s %s ==> %d\n", str2, str3, cmpHNT(hnt2, hnt3));
	printf("cmp %s %s ==> %d\n", str3, str1, cmpHNT(hnt3, hnt1));
	printf("cmp %s %s ==> %d\n", str13, str2, cmpHNT(hnt13, hnt2));


	return 0;
}
