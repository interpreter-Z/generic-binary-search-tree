#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ASCII_SIZE 256

typedef struct HuffNode{
	int  lb;  //label (in this case ASCII code) carried by HuffNode
	long fr;  //frequency of ch occurance (this is true only for LEAF HuffNodes)
} HuffNode;

HuffNode* consHN(int lb, long fr);
int cmpHN(void* hn1, void* hn2);  //is this actually necessary? (since we compare 
char* HNtoString(void* hn);
void fprintHN(FILE* dst, HuffNode* hn);

