struct dlink {
	TYPE value;
	struct dlink * next;
	struct dlink * prev;
};
struct linkedList {
	struct dlink * frontSentinel;
	struct dlink * backSentinel;
	int size;
};


/* the following functions were written in earlier lessons */
void linkedlistInit (struct linkedList *lst);
void linkedListFree (struct linkedList *lst);
void _addLink (struct linkedList * lst, struct dlink * lnk, TYPE e);
void _removeLink (struct linkedList * lst, struct dlink * lnk);
void linkedListAdd (struct linkedList * lst, TYPE e) { 
	_addLink(lst, lst->frontSentinel->next, e); 
}


/* you must write the following */

int linkedListContains (struct linkedlist *lst, TYPE e) {
	assert(lst != NULL);

	struct dlink * iter = lst->frontSentinel->next; 
	while (iter != backSentinel) {
		if (iter->value == e) {
			return 1;
		}
		else iter = iter->next;
	}
	return 0;
}

void linkedListRemove (struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	assert(e != NULL);

	struct dlink * iter = lst->frontSentinel->next; 
	while (iter != backSentinel) {
		if (iter->value == e) {
			_removeLink(iter);
			return;
		}
		else iter = iter->next;
	}
	return;	
}


/* 
1. What were the algorithmic complexities of the methods addLink and removeLink
that you wrote back in Chapter Q?

Add is O(1) because you jsut add the item to the front of hte linked list. REmove is O(n).

====================
2. Given your answer to the previous question, what are the algorithmic
complexities of the three principle Bag operations?
====================
method  -  worst  - average  - best
Add - O(1) - O(1)  - O(1)
REmove O(n) - O(n/2)=O(n) - O(1)
Contains O(n) - O(n/2)=O(n) - O(1)


 */