#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HuffNode.h"

int main(){

	//test cons & toString
	printf("---Test Cons & toString---\n");
	HuffNode* hn1 = consHN(64, 2);  //@:2
	HuffNode* hn2 = consHN(64, 4);  //@:4

	char* str;
	str = HNtoString(hn1);
	printf("hn1 is: %s\n", str);
	free(str);
	str = HNtoString(hn2);
	printf("hn2 is: %s\n", str);
	free(str);

	return 0;
}
