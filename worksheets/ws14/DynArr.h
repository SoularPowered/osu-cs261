# ifndef TYPE
# define TYPE int
# endif
struct DynArr
{
TYPE *data; /* pointer to the data array */
int size; /* Number of elements in the array */
int capacity; /* capacity ofthe array */
};
void initDynArr(struct DynArr *v, int capacity)
{
v->data = malloc(sizeof(TYPE) * capacity);
assert(v->data != 0);
v->size = 0;
v->capacity = capacity;
}
void freeDynArr(struct DynArr *v)
{
if(v->data != 0)
{
free(v->data); /* free the space on the heap */
v->data = 0; /* make it point to null */
}
v->size = 0;
v->capacity = 0;
}

void sizeDynArr( struct DynArr *v)
{
return v->size;
}

// TODO for workshet, fill in the rest:

void addDynArr(struct DynArr *v, TYPE val)
{
/* Check to see if a resize is necessary */
if(v->size >= v->capacity)
_setCapacityDynArr(v, 2 * v->capacity);
v->data[v->size] = val;
v->size++;
}


void _setCapacityDynArr(struct DynArr *v, int newCap)
{
}

TYPE getDynArr (struct DynArr * da, int position) {
}


void putDynArr(struct DynArr * da, int position, TYPEvalue) {
}

void swapDynArr (struct DynArr * da, int i, int j) {
  int temp = da->data[i];
  da->data[i] = da->data[j];

}

void removeAtDynArr (struct DynArr * da, int index) {
}
