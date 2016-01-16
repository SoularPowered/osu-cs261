#ifndef __TYPE
#define __TYPE
#define TYPE int
#endif

#ifndef __ws18
#define __ws18


struct link {
	TYPE value;
	struct link * next;
};


struct listQueue {
	struct link *firstLink;
	struct link *lastLink;
};


void listQueueInit (struct listQueue *q);
void listQueueAddBack (struct listQueue *q, TYPE e);
TYPE listQueueFront (struct listQueue *q);
void listQueueRemoveFront (struct listQueue *q);
int listQueueIsEmpty (struct listQueue *q):

#endif