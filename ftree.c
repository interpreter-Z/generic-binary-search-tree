#include "ftree.h"

int cmpf(void* data1, void* data2){
  float* d1 = (float*) data1;
  float* d2 = (float*) data2;
  if(*d1 > *d2)
    return 1;
  else if(*d1 < *d2)
    return -1;
  else
    return 0;
}

char* ftoString(void* data){
  char* str = malloc(sizeof(char) * 309);
  float num = *((float*) data);
  snprintf(str, 309, "%lf", num);
  return str;
}

TreeNode* ftree_cons(float val){
  float* data = malloc(sizeof(float));
  *data = val;
  return tree_cons((void*)data);
}

TreeNode* ftree_insert(TreeNode* tree, float val){
  float* data = malloc(sizeof(float));
  *data = val;
  return tree_insert(tree, (void*)data, cmpf);
}

float ftree_valOf(TreeNode* node){
  if(node == NULL)
    fprintf(stderr, "ftree_valOf: node to get val of is NULL.");
  return *((float*)(node->data));
}

TreeNode* ftree_getNode(TreeNode* tree, float val){
  float* data = malloc(sizeof(float));
  *data = val;
  TreeNode* rtn = tree_getNode(tree, (void*)data, cmpf);

  free(data);
  return rtn;
}
