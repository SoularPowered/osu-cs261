struct dynArrayIterator {
	struct dynArray * da;
	int currentIndex;
};


void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
	assert(da != NULL);

	iter->da = da;
	itr->currentIndex = 0;
}


int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {

	if (itr->currentIndex < size) {
		return 1;
	} else return 0;
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
	return itr->da->data[itr->currentIndex++];
}


void dynArrayIteratorRemove (struct dynArrayIterator *itr) {
	dynArrayRemoveAt(itr->da, --(itr->currentIndex) );	
}