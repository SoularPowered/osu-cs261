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

	struct dlink* iter = frontSentinel.next;
	
	// iterate through the list until value is found or iterator points to the back sentinel
	while (iter != backSentinel) {
		if (iter.value == e) {
			return 1; // true
		}
	}

	// if reach end of list and do not see value in any node, does not contain
	return 0; // false
}

void linkedListRemove (struct linkedList *lst, TYPE e) {
	assert(lst != NULL);

	struct dlink* iter = frontSentinel.next;
	
	// iterate through the list until value is found or iterator points to the back sentinel
	while (iter != backSentinel) {
		if (iter.value == e) {
			// Remove the node
			_removeLink(lst, iter);
		}
	}

	// If doesn't exist, silently fail
}


/* 
1. What were the algorithmic complexities of the methods addLink and removeLink
that you wrote back in Chapter Q?

Chapter Q? If they meant worksheet 19, the addLink and removeLink function signatures were never provided. 

Anyway, adding/removing a link using _addlink or _removeLink with a specific value just takes
O(1) time (constant) because it's just doing a constant number of steps (several variable assignments) using the
arguments provided, regardless of the size of the data we're working on.

I do not think this is what the question really wants to know though... 

To actually *iterate* and get to the node that we want to add or remove takes O(N) time in a lniked list

So I think the answer is O(N), which is kind of the standard worste-case running time of any normal
linked list that goes through all its contents searching for something (either a value or a location to
insert/add a node, for example).


====================
2. Given your answer to the previous question, what are the algorithmic
complexities of the three principle Bag operations?
====================

add - O(1). Just put it in the first node position every time.
contains - O(n). Have to iterate through every element in the worst case.
remove - O(n). Same as above.




 */