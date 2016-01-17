#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q)  {
  	/* FIXME: you must write this */	
	assert(q != NULL);
	q->Sentinel = (struct DLink *) malloc(sizeof(struct Dlink));
	q->Sentinel->next = q->Sentinel->prev = sent;
	q->size = 0;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque() {
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val) {
	/* FIXME: you must write this */
	struct DLink * newLink = (struct DLink *) malloc(sizeof(struct DLink));
	newLink->value = val;

	/*temporary return value..you may need to change it*/
	return(newLink);	 

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v) {
	/* FIXME: you must write this */	 
	assert(q != NULL);
	assert(lnk != NULL);
	// assert(lnk is in q);
	
	struct DLink * newLink = _createLink(v);
	newLink->prev = lnk;
	newLink->next = lnk->next
	
	newLnk->next->prev = newLink;
	lnk->next = newLink
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val)  {
	/* FIXME: you must write this */	 
	assert(q != NULL);

	_addLinkAfter(q, q->Sentinel, val);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val) {
	/* FIXME: you must write this */	 
	assert(q != NULL);

	_addLinkAfter(q, q->Sentinel->prev, val);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q)  {
	/* FIXME: you must write this */	 
	assert(q != NULL);
	assert(q->size > 0);

	return(q->Sentinel->prev->value);
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	assert(q != NULL);
	assert(q->size > 0);

	return(q->Sentinel->next->value);
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk) {
	/* FIXME: you must write this */	 
	assert(q != NULL);
	assert(q->size > 0);

	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	lnk->prev = lnk->next = NULL;

	free(lnk);
	--(q->size);
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	assert(q != NULL);
	assert(q->size > 0);

	_removeLink(q, q->Sentinel->prev);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
  	assert(q != NULL);
	assert(q->size > 0);

	_removeLink(q, q->Sentinel->next);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	struct DLink * iter = q->Sentinel;
	struct DLink * garbage = iter;	// will travel in wake of iter and free memory

	iter->prev->next = NULL;        // de-link the last link's 'next' so eventually iter->next = null
	
	// Iter moves forward and garbage collector removes all links then frees links
	while (garbage != NULL) {
		iter = iter->next;
		garbage->next = garbage->prev = NULL;
		free(garbage);
		garbage = iter;
	}
	q->size = 0;
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
  	assert(q != NULL);

	return (q->size > 0);
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q) {
	/* FIXME: you must write this */	 
  	assert(q != NULL);
	assert(q->size > 0);

	struct DLink *iter = q->Sentinel->prev;
	while (iter != NULL) {
		printf("%g\n", iter->value);
		iter = iter->prev;
	}
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q) {
	/* FIXME: you must write this */
	assert(q != NULL);
	assert(q->size > 0);	 

	// start at the 'sentinel' and swap the next and previous pointers
	struct DLink * current, temporary; 
	current = q->Sentinel;

	// Iterate, starting at the Sentinel, until we arrive back at Sentinel
	do {
		// basic swap algorithm (temp = A, A = B, B = temp)
		temporary = current->next;           // temp is the next link in circle
		current->next = current->previous;   // make next point to the 'previous' link
		current->previous = temporary;       // make previous link point to the old 'next' link

		current = temporary;                 // go to the next node in the sequence
	} while (current != q->Sentinel);
}
