// ws20.h
#ifndef __TYPE
#define __TYPE
#define TYPE int
#endif

#ifndef __ws20
#define __ws20


struct deque {
	TYPE * data;
	int capacity;
	int size;
	int start;
};

void dequeInit (struct deque *d, int initCapacity);
int dequeSize (struct deque *d);
void _dequeDoubleCapacity (struct deque *d);
void dequeAddFront (struct deque *d, TYPE newValue); 
void dequeAddBack (struct deque *d, TYPE newValue);
void _dequeSetCapacity (struct deque *d, int newCap);
void dequeFree (struct deque *d);
TYPE dequeFront (struct deque *d);
TYPE dequeBack (struct deque *d);
void dequeRemoveFront (struct deque *d);
void dequeRemoveBack (struct deque *d);