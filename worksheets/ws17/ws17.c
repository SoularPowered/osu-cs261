#ifndef __TYPE
#define __TYPE
#define TYPE	 int
#endif


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ws17.h"




/* "constructor"
 * sets first link to point to null  */
void linkedListStackInit (struct linkedListStack * s) {
	assert(s != NULL);
	s->firstLink = NULL;
}


/* Frees the memory for a stack by popping values.
 * Free should be called inside of linkedListStackPop(), though
 */
void linkedListStackFree (struct linkedListStack *s) {
	while (! linkedListStackIsEmpty(s)) {
		linkedListStackPop(s);
	}

}


/* Push a value onto the stack */
void linkedListStackPush (struct linkedListStack *s, TYPE d) {
	assert(s != NULL);

	struct link * newLink = (struct link *) malloc(sizeof(struct link));
	assert (newLink != NULL); // makes sure memory allocation didn't fail

	// Initialize the newLink and put it on top of old firstLink, move firstLink to point to newLink
	newLink->value = d;
	newLink->next = s->firstLink;  // newLink points "down" to the element beneath it, or null if stack was empty
	s->firstLink = newLink; // makes newLink the "top"
}

TYPE linkedListStackTop (struct linkedListStack *s) {
	assert(s != NULL);
	if (!linkedListStackIsEmpty(s))
		return (s->firstLink)->value;
	else
		return -1; // or fail silently? throw expception?
}


void linkedListStackPop (struct linkedListStack *s) {
	// get a handle to the new top of stack, free the old top, then point firstLink to new top
	struct link* newTop = (s->firstLink)->next;
	free(s->firstLink); // free the memory
	s->firstLink = newTop;
}


// returns
int linkedListStackIsEmpty (struct linkedListStack *s) {
	assert(s != NULL);
	// List is empty if firstLink points to NULL
	if (s->firstLink == NULL)
		return 1;
	else
		return 0;
}



int main(void) {
	printf("yoyo\n");
	struct linkedListStack* stack = (struct linkedListStack*) malloc(sizeof(struct linkedListStack));
	linkedListStackInit(stack);

	printf("Stack empty (true?): %d\n", linkedListStackIsEmpty(stack));
	linkedListStackPush(stack, 5);
	printf("Checking top for 5...: %d\n", linkedListStackTop(stack));
	printf("Stack empty (false): %d\n", linkedListStackIsEmpty(stack));
	linkedListStackPop(stack);
	printf("Stack empty (true): %d\n", linkedListStackIsEmpty(stack));

	linkedListStackFree(stack);

	return EXIT_SUCCESS;
}
