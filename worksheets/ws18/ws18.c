#ifndef __TYPE
#define __TYPE
#define TYPE int
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
struct link {
	TYPE value;
	struct link * next;
};


struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
};
*/


/*
 * Initialize a queue by setting queue's first and last link's to a sentinel node
 */
void listQueueInit (struct listQueue *q) {
	struct link *lnk = (struct link *) malloc(sizeof(struct link));
	assert(lnk != 0); /* lnk is the sentinel */
	lnk->next = 0;
	q->firstLink = q->lastLink = lnk;
}


/*
 * Add an item to the back of the queue
 */
void listQueueAddBack (struct listQueue *q, TYPE e) {
	assert(q != NULL);
	
	struct link* newEnd = (struct link *) malloc(sizeof(struct link));
	assert (newEnd != NULL);
	newEnd.value = e;
	newEnd.next = NULL;

	// point the lastLink's next
	(q->lastLink)->next = newEnd; 

	q->lastLink = newEnd;
}


/*
 * Returns the value of the node at the front
 */
TYPE listQueueFront (struct listQueue *q) {
	assert(q != NULL);
	if (!listQueueIsEmpty(q) {
		struct link* firstReal = (q->firstLink)->next;
		return firstReal->value;
		/* return ((q->firstLink)->next)->value;  */  // Should also work :)
	}
	else {
		// throw an exception or return a value that signals not a valid value there
		return -1;
	}
}


void listQueueRemoveFront (struct listQueue *q) {
	assert(q != NULL);
	if (!listQueueIsEmpty(q)) {
		struct link* sentinel = q->firstLink; // not necessary, just makes code more readable! could just use parens...
		struct link* oldFirst = sentinel->next; // handle to the first actual link (non sentinel)
		struct link* newFirst = oldFirst->next;	// handle to the second link in queue - the new first link
		
		// Free the old first and point the sentinel to newFirst
		if (sentinel->next == q->lastLink) {
			// if there's only 1 node left, we need to point last back to sentinel or everything breaks if we add more later
			q->lastLink = sentinel;
		}
		free(oldFirst);
		sentinel->next = newFirst;

	}
	// if queue is empty, silently do nothing
	// Note: could throw an exception or produce some other side effect but this is just an interface, I'd rather
	// throw exception
}


int listQueueIsEmpty (struct listQueue *q) {
	assert(q != NULL);
	return (q->firstLink == q->lastLink);
}