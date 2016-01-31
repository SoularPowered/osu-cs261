struct dynArrayIterator {
	struct dynArray * da;
	int currentIndex;
};


void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
	assert(da != NULL);
	assert(itr != NULL);

	itr->da = da; // store a reference to the original dynamic array in the iterator
	itr->currentIndex = 0; // set the initial position to 0

}


int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {
	assert(itr != NULL);

	// return true if the current index is less than the size of the dynamic array.
	// Proof: Suppose we have an array of size 1 and we have just initalized our iterator.
	// The the currentIndex is 0. Calling hasNext cwill compare 0 to 1. 0 is less, so
	// hasNext() should return true. In next(), we'd return the value at currentIndex, which is the first
	// index. Then currentIndex will be incremented to 1. Then if we call again, we compare currentIndex < size
	// again. But 1 < 1 is not true, so the algorithm correctly indicates that the array does not hasNext()
	
	if (itr->currentIndex + 1 < itr->da->size) {
		return 1; // true
	}
	else {
		return 0; // false
	}
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
	assert(itr != NULL);

	// In this version of next(), we first return the value at current index
	// then we increment that index afterwards. This kind of goes against the way
	// the iterator was built in the lecture videos.

	// if (dynArrayIteratorHasNext(itr)) {
		// Return the value at the current index then increment it using postfix
		return itr->da[itr->currentIndex++];
	// }
	// else {
	// 	// EXPLOSIONS! AHH
	// 	return NULL; // Hmm?? Mebbe..
	// 	// throw IndexOutOfRangeException;
	// }
}


void dynArrayIteratorRemove (struct dynArrayIterator *itr) {
	assert(itr != NULL);

	// Use the helper function that was wrote previously... trivial!
	dynArrayRemoveAt(itr->da, itr->currentIndex);
}