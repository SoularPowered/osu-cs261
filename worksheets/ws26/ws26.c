/* 
On Your Own
Fill in the following Chart with the big-oh execution times for the simple unordered
dynamic array bag (Lesson X), the linked list bag (Lesson x) and the ordered dynamic
array bag (this worksheet).

		Dynamic Array Bag 	LinkedListBag 	Ordered Array Bag
Add		O(1)				O(1)			O(log n)
Contains O(N) 				O(N)			O(log n)
Remove  O(N)				O(N)			O(log n)

Short Answers
======================================================================================
1. What is the algorithmic complexity of the binary search algorithm?
--------------------------------------------------------------------------------------
O(log n)

======================================================================================
2. Using your answer to the previous question, what is the algorithmic complex of
the method contains for an OrderedArrayBag?
--------------------------------------------------------------------------------------
O(log n)

======================================================================================
3. What is the algorithmic complexity of the method addAt?
--------------------------------------------------------------------------------------
[Note: this is the dynamic array method that adds an item at a specified index]
If capacity is big enough, it's just O(n) in the worst case. This is because if you have
to add the value at the first index, every other element needs to be shifted down, for n
total operations. But suppose you had a full array. You'd need to do a doubling, which is
n operations, and another n operations for the shift. Is that 2n, or n^2?? 

======================================================================================
4. Using your answer to the previous question, what is the algorithmic complexity of
the method add for an OrderedArrayBag?
--------------------------------------------------------------------------------------
It would take O(log n) time to find the index to insert + n time to shift the elements
out of the way and possibly n more time to copy the array in the event of full capacity

======================================================================================
5. What is the complexity of the method removeAt? of the method remove?
--------------------------------------------------------------------------------------
THis is the same as answer 4, removing an item takes the same time as adding one in a sorted array.

*/


/*Assume you have access to all existing dynArr functions */
/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue);

/* These are the new functions to take advantage of the ordered dynamic array
and available to the end user , so they will be declared in the .h file */

int dyArrayBinarySearch (struct dyArray * dy, TYPE testValue) {

}

void orderedArrayAdd (struct dyArray *dy, TYPE newElement) {
}


/* you must complete the following */
int orderedArrayContains (struct dyArray *dy, TYPE testElement) {
	int result = _binarySearch(dy->data, dy->size, testElement);

	if (result >= 0 && result < dy->size) {
		return 1;
	} else return 0;
}


void orderedArrayRemove (struct dyArray *dy, TYPE testElement) {
	int result = _binarySearch(dy->data, dy->size, testElement);

	if (result >= 0 && result < dy->size) {
		_dynArrRemoveAt(dy, result);
	} else return 0;	
}