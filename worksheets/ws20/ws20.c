ws20.c
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// struct deque {
// 		TYPE * data;
// 		int capacity;
// 		int size;
// 		int start;
// };

void dequeInit (struct deque *d, int initCapacity) {
	d->size = d->beg = 0;
	d->capacity = initCapacity; 
	assert(initCapacity > 0);
	d->data = (TYPE *) malloc(initCapacity * sizeof(TYPE));
	assert(d->data != 0);
}

int dequeSize (struct deque *d) {
 return d->size; 
}


void _dequeDoubleCapacity (struct deque *d) {
	_dequeSetCapacity(d, 2 * d->capacity);
}


void dequeAddFront (struct deque *d, TYPE newValue) {
	if (d->size >= d->capacity) {
		_dequeSetCapacity(d, 2*d->capacity);
	}
	int insertIndex = d->start + d->size;
	if (insertIndex >= d->capacity) {
		insertIndex -= d->capacity;
	}
	d[insertIndex] = newValue;
}


void dequeAddBack (struct deque *d, TYPE newValue) {
	if (d->size >= d->capacity) _dequeSetCapacity(d, 2* d->capacity);
}



void _dequeSetCapacity (struct deque *d, int newCap) {
	int i;
/* Create a new underlying array*/
	TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
	assert(newData != 0);

/* copy elements to it */
	int j = v->beg;
	for(i = 0; i < v->size; i++)
	{
		newData[i] = v->data[j];
		j = j + 1;
		if(j >= v->capacity)
			j = 0;
	}
/* Delete the oldunderlying array*/
	free(v->data);
/* update capacity and size and data*/
	v->data = newData;
	v->capacity = newCap;
	v->beg = 0;
}



void dequeFree (struct deque *d) {
	free(d->data); 
	d->size = 0; 
	d->capacity = 0;
}



TYPE dequeFront (struct deque *d) {
	assert(d != NULL);

	return d[d->start];

}


TYPE dequeBack (struct deque *d) {
	int backIndex = d->start - 1 + d->size;

	if (backIndex >= d->capacity) {
		backIndex -= d->capacity;
	}

	return d[backIndex];	
}


void dequeRemoveFront (struct deque *d) {
	++(d->size);
	
}


void dequeRemoveBack (struct deque *d) {
	--(d->size);
}