struct linkedlistIterator {
	struct linkedList * lst;
	struct dlink * currentLink;
}; // The worksheet was missing this semicolon


void linkedListIteratorInit (struct linkedList *lst, struct linkedListIterator * itr) {
	// assertions first then..

	itr->lst = lst;
	iter->currentLink = lst->frontSentinel->next;
}


void _removeLink (struct linkedList * lst, struct dlink *lnk) {

}

int linkedListIteratorHasNext (struct linkedListIterator *itr) {
	if (iter->currentLink != iter->lst->backSentinel) {
		return 1;
	} else {
		return 0;
	}
}




TYPE linkedListIteratorNext (struct linkedListIterator *itr) {
	iter->currentLink = iter->currentLink->next;
	return itr->currentLink->prev->value;
}

/* think about the next one carefully. Draw a picture. what should itr->currentLink be pointing to
after the remove operation ? */
void linkedListIteratorRemove (struct linkedListIterator *itr) {
	_removeLink(iter->lst, iter->currentLink->prev);
}



