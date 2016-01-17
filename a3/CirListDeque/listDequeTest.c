#include "cirListDeque.h"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque(); 
	printf("Made a list. \n");
	addBackCirListDeque(q, (TYPE)1);
	printf("addBack(1) \n");
	addBackCirListDeque(q, (TYPE)2);
	printf("addBack(2) \n");
	addBackCirListDeque(q, (TYPE)3);
	printf("addBack(3) \n");
	addFrontCirListDeque(q, (TYPE)4);
	printf("addFront(4) \n");
	addFrontCirListDeque(q, (TYPE)5);
	printf("addFront(5) \n");
	addFrontCirListDeque(q, (TYPE)6);
	printf("addFront(6) \n");
	printf("Calling print. Expect: 6 5 4 1 2 3 \n");
	printCirListDeque(q);

	printf("\nFront of Queue should be 6: \n");
	printf("%g\n", frontCirListDeque(q));
	printf("\nBack of Queue should be 3: \n");
	printf("%g\n", backCirListDeque(q));
	printf(" \n");

	removeFrontCirListDeque(q);
	printf("Removing value from front (6)... \n");
	removeBackCirListDeque(q);
	printf("Removing value from back (3)... \n");
	printCirListDeque(q);
	printf("Calling print. Expect: 5 4 1 2 \n");
	printf("Now reversing the list... \n");
	reverseCirListDeque(q);
	printf(" \n");
	printf("Calling print. Expect: 2 1 4 5\n");
	printCirListDeque(q);
	printf(" \n");

	// free(q);
	return 0;
}
