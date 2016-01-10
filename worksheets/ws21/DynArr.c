# ifndef TYPE
# define TYPE int
# endif

# ifndef EQ
# define EQ(a, b) (a == b)
# endif


struct DynArr {
  TYPE * data;
  int size;
  int capacity;
};


/* the following were written in earlier lessons */
void initDynArr (struct DynArr * da, int initCap)
  da->data = malloc(sizeof(TYPE) * initCap);
  assert(da->data != 0);
  da->size = 0;
  da->capacity = capacity;
}


void addDynArr(struct DynArr * da, TYPE e);
  /* Check to see if a resize is necessary */
  if(da->size >= da->capacity)
    _setCapacityDynArr(da, 2 * da->capacity);

  da->data[da->size] = val;
  da->size++;
}

void _setCapacityDynArr(struct DynArr *da, int newCap) {
  // Allocate memory for new data array
  TYPE *temp = malloc(sizeof(TYPE) * newCap);
  assert(temp != 0);

  // Copy the values from old array into new array
  int i = 0; // loop couner
  for (i = 0; i < capacity; i++) { // we know the old capacity is the current size
    temp[i] = da->data[i];
  }

  // free old memory, update pointers, update capacity
  free(v->data);
  da->data = temp;
  da->capacity = newCap;
}


/* remove was shown earlier, to use removeAt */
void removeDynArr (struct DynArr * da, TYPE test) {
  int i;
  for (i = 0; i < dy->size; i++) {
    if (EQ(test, dy->data[i])) { /* found it */
      _dynArrayRemoveAt(dy, i);
      return;
    }
  }
}


/* you must write the following */
int containsDynArr (struct DynArr * da, TYPE e) {
  int i;
  for (i = 0; i < da->size; i++) {
    if EQ(e, da->data[i]) {
      return 1; // true
    }
  }
  // return false if e not in da->data[]
  return false;
}

/*
1. What should the removeAt method do if the index given as argument is not in
range?
Eitehr fail silently, throw exception, or end program using an assertion

2. What is the algorithmic complexity of the method removeAt?
Although you pass the index of the location you're removing a value from, and that only takes
1 unit of time, you still have to shift the rest of the array up. In the worst case, if you removeAt(0),
complexity is O(n). Best case is if you removeAt(size-1), in which case it only takes O(1) time.


3. Given your answer to the previous question, what is the worst-case complexity of
the method remove?

the remove method will iterate at most one time through the n elements of the array making a comparison,
so that is just n operations. The inner loop will take O(n) operations in the worst case. But if you
iterate from array[0] and then call removeAt(0), then it takes n operations. And if you remove a value at
[size-1] index, then it takes n-1 operations to find the value and 1 more operation, so n + 1 - 1 total
units. So It's still O(n)

4. What are the algorithmic complexities of the operations add and contains?

Contains is easy ... at worst, it will search O(n) (element not present), at best O(1), and average O(n/2) (if all searched values were in the array)


*/
