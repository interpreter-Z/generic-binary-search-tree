#include "tree.h"

int cmpf(void* data1, void* data2);
char* ftoString(void* data);

TreeNode* ftree_cons(float val);
TreeNode* ftree_insert(TreeNode* tree, float val);
float ftree_valOf(TreeNode* node);
TreeNode* ftree_getNode(TreeNode* tree, float val);
