#include "ftree.h"

int cmpf(void* data1, void* data2){
  float* d1 = (float*) data1;
  float* d2 = (float*) data2;
  return *d1 - *d2;
}

char* toString(void* data){
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
  return *((float*)(node->data));
}
