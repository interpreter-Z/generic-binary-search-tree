#include "tree.h"

int cmpf(void* data1, void* data2);
char* toString(void* data);

TreeNode* ftree_cons(float val);
TreeNode* ftree_insert(TreeNode* tree, float val);
float ftree_valOf(TreeNode* node);
