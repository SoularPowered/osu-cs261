
// Pre Written In Worksheet
void swap (struct dyArray * v, int i, int j) { 
	/* swap elements i j */
	TYPE temp = dyArrayGet(v, i);
	dyArrayPut(v, i, dyArrayGet(v, j));
	dyArrayPut(v, j, temp);
}

// Pre Written In Worksheet
int indexSmallest (struct dyArray * v, int i, int j) {
	/* return index of smallest element */
	if (LT(dyArrayGet(v, i), dyArrayGet(v, j))
		return i;
	return j;
}


// Pre Written In Worksheet	
TYPE heapGetFirst (struct dyArray *heap) {
	assert(dyArraySize(heap) > 0);
	return dyArrayGet(heap, 0);
}


// Pre Written In Worksheet
void HeapRemoveFirst(struct dyArray *heap) {
	int last = dyArraySize(heap)-1;
	assert (last != 0); /* make sure we have at least one element */
	
	/* Copy the last element to the first position */
	dyArrayPut(heap, 0, dyArrayrGet(heap, last));
	dyArrayRemoveAt(heap, last); /* Remove last element.*/
	adjustHeap(heap, last, 0);/* Rebuild heap */
}


// Need to write
// This function will percelate down any value until it is below any value that is comparatively higher than it
void _adjustHeap (struct dyArray * heap, int max, int pos) {
	int leftChild = 2 * pos + 1;  // INDEX of the left child
	int rightChild = 2 * pos + 2; // INDEX of the right child

	/* we have two children */
	if (rightChild < max) {   // if the index of the right child is less than max
		//get index of smallest child
		int smallestChild = indexSmallest(heap, rightChild, leftChild);
		// if value at pos > value of smallest child
		if (heap->data[pos] > heap->data[smallestChild]) {
			// swap with smallest child, call adjustHeap (max, index of smallest child)
			swap(heap, pos, smallestChild);
			_adjustHeap(heap, max, smallestChild);
		}
	
	/* we have one child */
	else if (leftChild < max) { 
		// if value at pos > value of child
		if (heap->data[pos] > heap->data[leftChild]) {
			// swap with smallest child, call adjustHeap (max, index of left child)
			swap(heap, pos, leftChild);
			_adjustHeap(heap, max, leftChild);	
		}
	}
	/* else no children, done */
}


void heapAdd (struct dyArray * heap, TYPE newValue) {
	assert(heap != NULL);
	assert(newValue != NULL);
	dyArrayAdd(heap, newValue); /* adds to end – now need to adjust position */
	
	int newValueIndex = dyArraySize(heap) - 1; // newValueIndex is the last position
	int parent = (newValueIndex - 1) / 2;            // index of the parent -- calculated during do-while loop

	// As long as the newly inserted value is smaller than its parent, bubble it up.
	// This will also stop if the parent index is ever less than 0, which is an invalid index
	while (indexSmallest(heap, newValueIndex, parent) && parent >= 0) {
		swap(heap, parent, newValue); // swaps the values
		newValue = parent;
		parent = (newValueIndex - 1) / 2;
	} // Ends once the new node is in its correct place --> it's >= to its parent, which means its parent is a min-heap

}


// START WORKSHEET 34 HERE

/*
Simulate execution of the Heap sort algorithm on the following values:
9 3 2 4 5 7 8 6 1 0
First make the values into a heap (the graphical representation is probably easier to work
with than the vector form). Then repeatedly remove the smallest value, and rebuild the
heap.
*/

Step 1: Fill in the tree (visually) with the values from the vector
         9
       /  \  
      /    \
     3       2
    / \     / \
   4   5   7   8
  / \  /  /\  / \
 6  1  0

 Step 2: Start with the "heapify" operation - book calls it buildHeap
         9
       /  \  
      /    \
     3       2
    / \     / \
   4   0*  7   8
  / \  /  /\  / \
 6  1  5* 

5 percolates down

         9
       /  \  
      /    \
     3       2
    / \     / \
   1*  0   7   8
  / \  /  /\  / \
 6  4* 5 
4 percolates down
         9
       /  \  
      /    \
     3       2*
    / \     / \
   1   0   7   8
  / \  /  /\  / \
 6  4  5 

 2 does not need to perculate, so we move on to 3

         9
       /  \  
      /    \
     0*      2
    / \     / \
   1   3*  7   8
  / \  /  /\  / \
 6  4  5 

3 swaps with 0 and is now in position

         0*
       /  \  
      /    \
     1*      2
    / \     / \
   4*  3   7   8
  / \  /  /\  / \
 6  9* 5 

 Finally we perculate 9 down, swapping with the least value at each node it get sswapped into

 Note that each node now is greater than both of its child nodes at every point

 THe next step is to continually take the smallest value and rebuild the heap using our removal algorithm 
 that swaps values into the last position of the array.
----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [0]
---------------------------------------- 

        1
       /  \  
      /    \
     3       2
    / \     / \
   4   5*  7   8
  / \  /  /\  / \
 6  9  *

 0 is removed, 5 goes to top and perculates back down. 

 ----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [1] [0]
---------------------------------------- 

        2
       /  \  
      /    \
     3       7
    / \     / \
   4   5*  9   8
  / \  /  /\  / \
 6  *  *
 1 is removed, 9 perculates down

  ----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [2] [1] [0]
---------------------------------------- 

        3
       /  \  
      /    \
     4       7
    / \     / \
   6*  5   9   8
  / \  /  /\  / \
 *  *  *

 2 is removed, 6 perculates down


----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [ ] [ ] [ ] [ ] [3] [2] [1] [0]
---------------------------------------- 

        4
       /  \  
      /    \
     5       7
    / \     / \
   6*  8   9   *
  / \  /  /\  / \
 *  *  *

 3 is removed, 8 perculates down

 ----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [ ] [ ] [5] [4] [3] [2] [1] [0]
---------------------------------------- 

        5
       /  \  
      /    \
     6       7
    / \     / \
   9  8    *   *
  / \  /  /\  / \
 *  *  *

 4 is removed, 9 perculates down


----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [ ] [ ] [5] [4] [3] [2] [1] [0]
---------------------------------------- 

        6
       /  \  
      /    \
     8       7
    / \     / \
   9   *   *   *
  / \  /  /\  / \
 *  *  *

 5 is removed, 8 perculates down

 ----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [ ] [6] [5] [4] [3] [2] [1] [0]
---------------------------------------- 

        7
       /  \  
      /    \
     8       9
    / \     / \
   *   *   *   *
  / \  /  /\  / \
 *  *  *

 6 is removed, 9 perculates down

 ----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [ ] [ ] [7] [6] [5] [4] [3] [2] [1] [0]
---------------------------------------- 

        8
       /  \  
      /    \
     9       *
    / \     / \
   *   *   *   *
  / \  /  /\  / \
 *  *  *

 7 is removed, 9 perculates down

----------------------------------------
i=0   1   2   3   4   5   6   7   8   9 
 [9] [8] [7] [6] [5] [4] [3] [2] [1] [0]
---------------------------------------- 

        9
       /  \  
      /    \
     *       *
    / \     / \
   *   *   *   *
  / \  /  /\  / \
 *  *  *

 8 is removed, 9 perculates down... well it doesn't need to! We're done.

 Once i == 0, the algorithm is complete. Note that a min-heap sorts into a descending array
 and a max-heap sorts into an ascending array.

 
