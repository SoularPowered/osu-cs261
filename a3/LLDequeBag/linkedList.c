#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList {
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
  /* FIXME: you must write this */
	assert(lst != NULL);

	// Allocate memory for the links
	list->firstLink = malloc(sizeof(struct DLink));
	assert(list->firstLink != 0);
	list->lastLink = malloc(sizeof(struct DLink));
	assert(list->lastLink);
	
	// Point Head sentinel's next to the tail, tail's prev to the head, and other sto null
	list->firstLink->next = list->lastLink;
	list->lastLink->prev = list->firstLink;
	list->lastLink->next = list->firstLink->prev = NULL;
	list->size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList() {
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v) {
	/* FIXME: you must write this */

	// Used by LinkedListAddFront to add an item to jsut before the front sentinel
	assert(lst != NULL);
	assert (l != NULL);

	// Make a new link and link it's next/prev to the firstLink and the old front
	struct DLink* newLink = (struct DLink*) malloc(sizeof(struct DLink));
	assert(newLink != NULL);

	newLink->value = v;
	newLink->next = l->next;
	newLink->prev = l;

	// Relink the front sentinel's next to point to the new link, and the old
	// front link to point it's prev to the new link
	l->next = newLink;
	newLink->next->prev = newLink;

	++(lst->size);
}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e) {

	/* FIXME: you must write this */
	assert(lst != NULL);

	_addLinkBefore(lst, lst->firstLink, e);   // THERE WAS A TYPO FROM THE BOOK, FIXED
	// Note --> Sisze is incremented in the helper function
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
	/* FIXME: you must write this */

	_addLinkBefore(lst, lst->lastLink->prev, e);  
	// Note --> Sisze is incremented in the helper function
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */

	assert(lst != NULL);
	assert(lst->size > 0);

	return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst) {
	/* FIXME: you must write this */

	assert(lst != NULL);
	assert(lst->size > 0);

	return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the link to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l) {

	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(l != NULL);

	// Make lnk's next node's previous point to link's previous, and vice versa
	l->next->prev = lnk->prev;
	lnk->prev->next = lnk->next;

	l->next = NULL;
	lnk->prev = NULL;
	free(l);

	--(lst->size);
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(lst.size > 0);

   	_removeLink(lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst) {	
	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(lst->size > 0);

	_removeLink(lst, lst->lastLink->prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	assert(lst != NULL);

	return (lst->size == 0);
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst) {
	/* FIXME: you must write this */
	assert(lst != NULL);
	
	printf("Contents of list (Front to Back):\n");

	struct DLink *iter = lst->firstLink->next; // iterator
	while (iter != lst->lastLink) {
		printf("%d\n", iter->value);
		iter = iter->next;
	}
}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v) {
	/* FIXME: you must write this */
	assert(lst != NULL);

	addFrontList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(lst->size > 0);

	struct DLink *iter = lst->firstLink->next; // iterator
	while (iter != lst->lastLink) {
		if (iter->value == e) {
			return 1;
		}

		iter = iter->next;
	}
	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(lst->size > 0);

	int valFound = 0; // boolean substitute

	struct DLink *iter = lst->firstLink->next; // iterator
	while (iter != lst->lastLink && valFound == 0) {
		if (iter->value == e) {
			// remove value
			_removeLink(lst, iter);

			--(list->size);
			valFound = 1;
		}

		iter = iter->next;
	}
}