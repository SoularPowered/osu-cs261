struct linkedlistIterator {
	struct linkedList * lst;
	struct dlink * currentLink;
}; // The worksheet was missing this semicolon


void linkedListIteratorInit (struct linkedList *lst, struct linkedListIterator * itr) {
	// Set up an iterator for lst by initialize arg2, itr, to point to the lst and the frontSentinel's next
	itr->lst = lst;
	itr->currentLink = lst->frontSentinel->next;
}


void _removeLink (struct linkedList * lst, struct dlink *lnk) {
	// Make lnk's next node's previous point to link's previous, and vice versa
	lnk->next->prev = link->prev;
	link->prev->next = link->next;

	lnk->next = NULL;
	lnk->prev = NULL;
	free(lnk);

	--(lst->size);
}

int linkedListIteratorHasNext (struct linkedListIterator *itr) {
	// Because we set currentLink to the firstSentinel's next, we check the
	// currentLink. In the case of an empty list, this will correctly return
	// false on the first hasNext() call and will halt once the iterator has moved
	// to point to the backSentinel
	if (itr->currentLink != iter->lst->backSentinel) {
		return 1; // true
	}
	else {
		return 0; // false
	} 
}




TYPE linkedListIteratorNext (struct linkedListIterator *itr) {
	// On first call, will correctly grab the currentLink's value. Assuming the list
	// is empty, this wouldn't work, but we are assuming client code will call hasNext()
	// before calling next()
	TYPE returnVal = itr->currentLink->value;
	itr->currentLink = itr->currentLink->next; // move iterator forward one in the ll
	return returnVal;
}

/* think about the next one carefully. Draw a picture. what should itr->currentLink be pointing to
after the remove operation ? */
void linkedListIteratorRemove (struct linkedListIterator *itr) {
	// Get a handle to the node after the the link we're removing
	// Remember, in OUR implementation, our iterator moves forward when we call next(), not when we
	// call hasNext(). Suppose we just called hasNext(), there's another (non-backSentinel) link,
	// and then we call next. Now the iterator is pointing at this new node that we have not actually used yet.
	// If we remove the link we're currently at, we move forward to the next link. Then, when we call hasNext(),
	// our implementation will check if the currentLink pointer points to the backSentinel or not. Assuming it does
	// not, it will return true. If we moved backwards instead, we'd end up pointing at a node that we've already
	// iterated over and done something with.
	struct dlink * temp = itr->currentLink->next;

	_removeLink(itr->lst, itr->currentLink);

	// assign the handle to iter - next() call would grab the next node in list we haven't iterated before
	iter = temp;
}



