#include "HuffNode.h"
#define PRTSZ 35

// Constructs & returns a pointer to HuffNode holding symbol "lb" with frequency "fr"
HuffNode* consHN(int lb, long fr){
	HuffNode* newHN = malloc(sizeof(HuffNode));
	newHN->lb = lb;
	newHN->fr = fr;
	return newHN;
}

// Compares two HuffNodes (recieved as void*) by returning an integer
int cmpHN(void* hn1, void* hn2){
	//check for NULL input
	if(hn1==NULL || hn2==NULL)
		fprintf(stderr, "cmpHN: bad input: at least one input is NULL\n");

	HuffNode* node1 = (HuffNode*) hn1;
	HuffNode* node2 = (HuffNode*) hn2;
	
	//Start comparing
	//1. HuffNode with lower occurance frequency is smaller
	if(node1->fr != node2->fr){
		return node1->fr - node2->fr;
	}
	//2. HuffNode with smaller ASCII code (label) is smaller
	else{
		return node1->lb - node2->lb;
	}
}

// Returns string format of HuffNode "hn"; format: ch:fr
char* HNtoString(void* hn){
	char* str = malloc(sizeof(char)*PRTSZ);
	HuffNode* node = (HuffNode*) hn;
	snprintf(str, PRTSZ, "%c:%ld", (char)(node->lb), node->fr);
	return str;
}

//prints HuffNode "hn" in string format to file stream "dst"
void fprintHN(FILE* dst, HuffNode* hn){
	char* str = HNtoString( (void*)hn );
	fprintf(dst, "%s\n", str);
	free(str);
}
