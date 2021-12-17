#include "tree.h"
#include "HuffNode/HuffNode.h"

//Interface
TreeNode* HNtree_cons(int lb, long fr);
void HNtree_printTree(TreeNode* tree, FILE* dst);
HuffNode valOf(TreeNode* hnt);

//Special
int cmpHNT(void* hnt1, void* hnt2);
TreeNode* mergeHNT(TreeNode* hnt1, TreeNode* hnt2);
void fprintHNT(FILE* dst, TreeNode* hnt);
