#include <stdio.h>
#include <stdlib.h>

void print_reverse(char* word){
	int size = 0;
	int i = 1; // loop counter
	char current_ch = word[0];

	do {
		current_ch = word[i];
		if (current_ch != '\0') {
			++size;
			++i;
		}
	} while (current_ch != '\0');

	for (i = size; i >= 0; i--) {
		printf("%c", word[i]);
	}
	printf("\n");
}

int main() {
	int max_size = 256;
	char word[256];

	printf("Enter a word (no spaces) of %d characters or less and I will reverse it:\n", max_size - 1);
	scanf("%s", word);

	printf("I will reverse the word \"%s\"\n", word);

	print_reverse(word);

	return 0;
}


