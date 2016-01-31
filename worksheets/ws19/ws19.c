// ws19.c

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// struct dlink {
// 	TYPE value;
// 	struct dlink * next;
// 	struct dlink * prev;
// };

// struct linkedList {
// 	int size;
// 	struct dlink * frontSentinel;
// 	struct dlink * backSentinel;
// };


/* these functions are written for you */
void LinkedListInit (struct linkedList *q) {
	q->frontSentinel = malloc(sizeof(struct dlink));
	assert(q->frontSentinel != 0);
	q->backSentinel = malloc(sizeof(struct dlink));
	assert(q->backSentinel);
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->frontSentinal;
	q->size = 0;
}

void linkedListFree (struct linkedList *q) {
	while (q->size > 0)
		linkedListRemoveFront(q);
	free (q->frontSentinel);
	free (q->backSentinel);    // ANOTHER TYPO
	q->frontSentinel = q->backSentinel = null;
}

void LinkedListAddFront (struct linkedList *q, TYPE e) { 
	_addBefore(q, q->frontSentinel->next, e);   // THERE WAS A TYPO FROM THE BOOK, FIXED
}


void LinkedListAddback (struct linkedList *q, TYPE e) { 
	_addBefore(q, q->backSentinel, e);  
}


void linkedListRemoveFront (struct linkedList *q) {
	assert(! linkedListIsEmpty(q));
	_removeLink (q, q->frontSentinal->next);
}

void LinkedListRemoveBack (struct linkedList *q) {
	assert(! linkedListIsEmpty(q));
	_removeLink (q, q->backSentinel->prev);
}


int LinkedListIsEmpty (struct linkedList *q) {
	return q->size == 0;
}


/* write addLink and removeLink. Make sure they update the size field correctly */

/* _addBefore places a new link BEFORE the provide link, lnk */
void _addBefore (struct linkedList *q, struct dlink *lnk, TYPE e) {
	// Used by LinkedListAddFront to add an item to jsut before the front sentinel
	assert(q != NULL);
	assert (lnk != NULL);

	// Make a new link and link it's next/prev to the frontSentinel and the old front
	struct dlink* newLink = (struct dlink*) malloc(sizeof(struct dLink));
	newLink->value = e;
	newLink->next = lnk->next;
	newLink->prev = lnk;

	// Relink the front sentinel's next to point to the new link, and the old
	// front link to point it's prev to the new link
	lnk->next = newLink;
	newLink->next->prev = newLink;

	++(q->size);
}


void _removeLink (struct linkedList *q, struct dlink *lnk) {
	// Make lnk's next node's previous point to link's previous, and vice versa
	lnk->next->prev = link->prev;
	link->prev->next = link->next;

	free(lnk);

	--(q->size);
}


TYPE LinkedListFront (struct linkedList *q) {
	assert(q != NULL);
	return q->frontSentinel->next;
}


TYPE LinkedListBack (struct linkedList *q) {
	assert(q != NULL);
	return q->backSentinel->prev;
}

