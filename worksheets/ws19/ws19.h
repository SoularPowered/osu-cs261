// ws19.h

#ifndef __TYPE
#define __TYPE
#define TYPE int
#endif

#ifndef __ws19
#define __ws19

struct dlink {
	TYPE value;
	struct dlink * next;
	struct dlink * prev;
};

struct linkedList {
	int size;
	struct dlink * frontSentinel;
	struct dlink * backSentinel;
};

void LinkedListInit (struct linkedList *q);
void linkedListFree (struct linkedList *q);
void LinkedListAddFront (struct linkedList *q, TYPE e);
void LinkedListAddback (struct linkedList *q, TYPE e);
void linkedListRemoveFront (struct linkedList *q);
void LinkedListRemoveBack (struct linkedList *q);
int LinkedListIsEmpty (struct linkedList *q);
void addLink(struct linkedList *q, struct dlink *lnk, TYPE e);
void removeLink(struct linkedList *q, struct dlink *lnk, TYPE e);
void _addBefore (struct linkedList *q, struct dlink *lnk, TYPE e);
void _removeLink (struct linkedList *q, struct dlink *lnk);
TYPE LinkedListFront (struct linkedList *q);
TYPE LinkedListBack (struct linkedList *q);







#endif