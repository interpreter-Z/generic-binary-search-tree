#include "HNtree.h"

// Construct a HNtree Node containing the HuffNode specified by symbol "lb" and freq "fr"
TreeNode* HNtree_cons(int lb, long fr){
	HuffNode* hn = consHN(lb, fr);
	return tree_cons((void*)hn);
}

// Print the Tree for debug
void HNtree_printTree(TreeNode* tree, FILE* dst){
	tree_printTree(tree, dst, HNtoString);
}

// Returns a copy of the HuffNode held by hnt->data
HuffNode valOf(TreeNode* hnt){
	return *( (HuffNode*)(hnt->data) );
}

// Compares HNtree1 to HNtree2 according to their weight
int cmpHNT(void* hnt1, void* hnt2){
	//check for NULL input
	if(hnt1==NULL || hnt2==NULL)
		fprintf(stderr, "cmpHNT(): bad input: at least one input is NULL\n");

	TreeNode* tree1 = (TreeNode*) hnt1;
	TreeNode* tree2 = (TreeNode*) hnt2;

	//Start Compare: (just the root is enough)
	//1. smaller root weight (data->fr) is smaller tree
	int cmp1 = valOf(tree1).fr;
	int cmp2 = valOf(tree2).fr;
	if(cmp1 != cmp2)
		return cmp1 - cmp2;

	//2. single-node tree is smaller tree
	if     (tree_isleaf(tree1) && !tree_isleaf(tree2))
		return -1;
	else if(!tree_isleaf(tree1) && tree_isleaf(tree2))
		return 1;

	//3. smaller root ASCII value (data->lb) is smaller tree
	cmp1 = valOf(tree1).lb;
	cmp2 = valOf(tree2).lb;
	return cmp1 - cmp2;
}

// Combines 2 HNtrees into a single HNtree with a root holding them as L & R child
TreeNode* mergeHNT(TreeNode* hnt1, TreeNode* hnt2){
        //check for NULL input
        if(hnt1==NULL || hnt2==NULL)
        	fprintf(stderr, "mergeHNT(): bad input: at least one input is NULL\n");
	
	//determine value of root
	//1. root's freq is sum of the 2 tree's freq
	int frr = valOf(hnt1).fr + valOf(hnt2).fr;
	//2. root's label is the smallest of the 2 tree's label
	int lbr;
	int lb1 = valOf(hnt1).lb;
	int lb2 = valOf(hnt2).lb;
	if(lb1 < lb2)
		lbr = lb1;
	else //there should not be 2 HuffNodes with the same label
		lbr = lb2;

	//merge tree:
	TreeNode* root = HNtree_cons(lbr, frr);
	//root's left children is the smaller tree
	if( cmpHNT((void*)hnt1, (void*)hnt2) < 0 ){
		root->left  = hnt1;
		root->right = hnt2;
	}
	else{ //there should not be equivalent HNtrees
		root->left  = hnt2;
		root->right = hnt1;
	}

	return root;
}

// Prints HNtree "hnt" to file stream "dst" in pre-order traversal
// format: lb:route. ONLY leaves are printed
static void rcsv_fprintHNT(FILE* dst, TreeNode* hnt, char* route, int len){
	//Base: do nothing if tree is NULL
	if(hnt == NULL)
		return;

	//Base: if hnt is leaf, terminate route & print hnt->data (in format lb:route)
	if(tree_isleaf(hnt)){
		route[len] = '\0';
		fprintf(dst, "%c:%s\n", (char)(valOf(hnt).lb), route);
		return;
	}

	//Induction: print left
	route[len] = '0';
	rcsv_fprintHNT(dst, hnt->left, route, len+1);
	//Induction: print right
	route[len] = '1';
	rcsv_fprintHNT(dst, hnt->right, route, len+1);

}

void fprintHNT(FILE* dst, TreeNode* hnt){
	//allocate path string (of 1s & 0s)
	//max possible depth is amount of ASCII characters existing
	char* route = malloc(sizeof(char) * ASCII_SIZE);
	int len = 0;

	rcsv_fprintHNT(dst, hnt, route, len);
	free(route);
}




