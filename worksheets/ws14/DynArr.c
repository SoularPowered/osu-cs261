# ifndef TYPE
# define TYPE int
# endif

struct DynArr
{
  TYPE *data; /* pointer to the data array */
  int size; /* Number of elements in the array */
  int capacity; /* capacity ofthe array */
};

void initDynArr(struct DynArr *v, int capacity) {
  v->data = malloc(sizeof(TYPE) * capacity);
  assert(v->data != 0);
  v->size = 0;
  v->capacity = capacity;
}


void freeDynArr(struct DynArr *v) {
  if(v->data != 0)
  {
    free(v->data); /* free the space on the heap */
    v->data = 0; /* make it point to null */
  }
  v->size = 0;
  v->capacity = 0;
}

void sizeDynArr( struct DynArr *v) {
  return v->size;
}

// TODO for workshet, fill in the rest:

void addDynArr(struct DynArr *v, TYPE val) {
  /* Check to see if a resize is necessary */
  if(v->size >= v->capacity)
    _setCapacityDynArr(v, 2 * v->capacity);
  v->data[v->size] = val;
  v->size++;
}


void _setCapacityDynArr(struct DynArr *v, int newCap) {
  // Allocate memory for new data array
  TYPE *temp = malloc(sizeof(TYPE) * newCap);
  assert(temp != 0);

  // Copy the values from old array into new array
  int i = 0; // loop couner
  for (i = 0; i < capacity; i++) { // we know the old capacity is the current size
    temp[i] = v->data[i];
  }

  // free old memory, update pointers, update capacity
  free(v->data);
  v->data = temp;
  v->capacity = newCap;
}

TYPE getDynArr (struct DynArr * da, int position) {
  // Verify in range (use assert per worksheet instructions)
  assert(position >= 0 && position < da->size);
  return da->data[position];
}


void putDynArr(struct DynArr * da, int position, TYPE value) {
  // Verify in range (use assert per worksheet instructions)
  assert(position >= 0 && position < da->size);
  da->data[position] = value;
}

void swapDynArr (struct DynArr * da, int i, int j) {
  // Verify in range (using assert to be consistent) then swap
  assert(i > 0 && i < da->size && j > 0 && j < da->size);
  TYPE temp = da->data[i];
  da->data[i] = da->data[j];
  da->data[j] = temp;
}

/* Removes an element at index and shifts the rest of the elements down,
 * and reduces the size by 1
 */
void removeAtDynArr (struct DynArr * da, int index) {
  // Verify in range, then remove element by shifting rest of array over it
  assert(position >= 0 && position < da->size);

  int i; // loop counter
  for (i = index; i < da->size - 1; i++) {
    da->data[i] = da->data[i + 1];
  }
  --(da->size);
}
