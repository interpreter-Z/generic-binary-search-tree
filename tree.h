#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct TreeNode{
  void* data;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

TreeNode* tree_cons(void* data);
TreeNode* tree_insert(TreeNode* tree, void* data, int (*cmpd)(void*,void*));
TreeNode* tree_getNode(TreeNode* tree, void* data, int (*cmpd)(void*,void*));
void tree_freeTree(TreeNode* tree);
void tree_printPreorder(TreeNode* tree, FILE* dst, char* (*dtos)(void*));
void tree_printInorder(TreeNode* tree, FILE* dst, char* (*dtos)(void*));
void tree_printPostorder(TreeNode* tree, FILE* dst, char* (*dtos)(void*));
void tree_printTree(TreeNode* tree, FILE* dst, char* (*dtos)(void*));
