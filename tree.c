#include "tree.h"

/* Build & return a new TreeNode with "data"
*  return NULL if data is NULL
*/
TreeNode* tree_cons(void* data){
  if(data == NULL)  //Let all TreeNode be not NULL
    return NULL;
  TreeNode* rtn = malloc(sizeof(TreeNode));
  rtn->data = data;
  rtn->left = NULL;
  rtn->right = NULL;
  return rtn;
}

/* Build a TreeNode containing "data" and insert it to a proper location in "tree"
*  Returns the modified "tree" after insertion
 * comparing mechanism is defined by function *cmpd, which the USER NEEDS TO DEFINE
*/
TreeNode* tree_insert(TreeNode* tree, void* data, int (*cmpd)(void*,void*)){
  //Base Case: if tree is NULL, build TreeNode containing data & insert it here
  if(tree == NULL){
    return tree_cons(data);
  }
  //Do not insert if data is NULL
  if(data == NULL)
    return tree;
  //Do not insert if data is already in tree
  if((*cmpd)(tree->data,data) == 0){
    return tree;
  }
  //Induction:
  if((*cmpd)(data,tree->data) < 0){  //if data is less than current node, insert to left
    tree->left = tree_insert(tree->left, data, cmpd);
    return tree;
  }
  else{  //if data is greater than current node, insert to right
    tree->right = tree_insert(tree->right, data, cmpd);
    return tree;
  }
}

/* Search for TreeNode with exact match with "data" and return it
*  Return NULL if not found
* comparing mechanism is defined by function *cmpd, which the USER NEEDS TO DEFINE
*/
TreeNode* tree_getNode(TreeNode* tree, void* data, int (*cmpd)(void*,void*)){
  //Base Case:
  if(tree == NULL)  //if current node is NULL, data is not found
    return NULL;

  if((*cmpd)(tree->data,data) == 0)  //if current node match, return it
    return tree;

  //Induction:
  if((*cmpd)(data,tree->data) < 0)
    return tree_getNode(tree->left, data, cmpd);
  else
    return tree_getNode(tree->right, data, cmpd);
}

/* Frees the given tree
*/
void tree_freeTree(TreeNode* tree){
  if(tree == NULL)
    return;
  tree_freeTree(tree->left);
  tree_freeTree(tree->right);
  free(tree->data);
  free(tree);
}

/* Prints "tree" in preorder traversal to filestream "dst"
*  printing mechanism of each node's data field is defined by
*  function *dtos, which the USER NEEDS TO DEFINE
*/
void tree_printPreorder(TreeNode* tree, FILE* dst, char* (*dtos)(void*)){
  if(tree == NULL)
    return;
  char* curprt = (*dtos)(tree->data);
  fprintf(dst, "%s\n", curprt);
  free(curprt);
  tree_printPreorder(tree->left, dst, dtos);
  tree_printPreorder(tree->right, dst, dtos);
}

/* Prints "tree" in inorder traversal to filestream "dst"
*  printing mechanism of each node's data field is defined by
*  function *dtos, which the USER NEEDS TO DEFINE
*/
void tree_printInorder(TreeNode* tree, FILE* dst, char* (*dtos)(void*)){
  if(tree == NULL)
    return;
  tree_printPreorder(tree->left, dst, dtos);
  char* curprt = (*dtos)(tree->data);
  fprintf(dst, "%s\n", curprt);
  free(curprt);
  tree_printPreorder(tree->right, dst, dtos);
}

/* Prints "tree" in postorder traversal to filestream "dst"
*  printing mechanism of each node's data field is defined by
*  function *dtos, which the USER NEEDS TO DEFINE
*/
void tree_printPostorder(TreeNode* tree, FILE* dst, char* (*dtos)(void*)){
  if(tree == NULL)
    return;
  tree_printPreorder(tree->left, dst, dtos);
  tree_printPreorder(tree->right, dst, dtos);
  char* curprt = (*dtos)(tree->data);
  fprintf(dst, "%s\n", curprt);
  free(curprt);
}

/* Print the tree in elaborate format for debugging
*/
static void rcsv_prtTree(TreeNode* tree, FILE* dst, char* (*dtos)(void*)){
  if(tree == NULL)
    return;

  //Print current node
  char* curprt = (*dtos)(tree->data);
  fprintf(dst, "N: %s; ",curprt);
  free(curprt);
  //Print left node (if any)
  if(tree->left != NULL){
    curprt = (*dtos)(tree->left->data);
    fprintf(dst, "L: %s; ",curprt);
    free(curprt);
  }
  //Print right node (if any)
  if(tree->right != NULL){
    curprt = (*dtos)(tree->right->data);
    fprintf(dst, "R: %s; ",curprt);
    free(curprt);
  }

  fprintf(dst,"\n");
  //Repeat process with L & R node
  rcsv_prtTree(tree->left, dst, dtos);
  rcsv_prtTree(tree->right, dst, dtos);
}

/* Print the tree in elaborate format for debugging
*/
void tree_printTree(TreeNode* tree, FILE* dst, char* (*dtos)(void*)){
  fprintf(dst, "Tree = [\n");
  rcsv_prtTree(tree, dst, dtos);
  fprintf(dst, "]\n");
}


/* returns true if "tree" has no left or right children
*/
bool tree_isleaf(TreeNode* tree){
	if(tree == NULL){
		fprintf(stderr, "tree_isleaf(): bad input: tree is NULL\n");
		return false;
	}
	return tree->left==NULL && tree->right==NULL;
}





