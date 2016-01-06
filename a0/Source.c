#include <stdio.h>
#include <stdlib.h>

void main() {
	int max_size = 256;
	char word[256];

	printf("Enter a word (no spaces) of %d characters or less and I will reverse it:\n", max_size - 1);
	scanf("%s", word);
	
	printf("I will reverse the word \"%s\"\n");


	return 0;
}


