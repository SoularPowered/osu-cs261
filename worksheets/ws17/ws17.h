/*
// * ws17.h
 *
 *  Created on: Jan 13, 2016
 *      Author: Admin
 */

#ifndef WS17_H_
#define WS17_H_

/* Defines a link as having a value and a link to next node */
struct link {
	TYPE value;
	struct link * next;
};

/* Defines a linkedListStack as having a link to a firstLink */
struct linkedListStack {
	struct link *firstLink;
};

void linkedListStackInit (struct linkedListStack * s);
void linkedListStackFree (struct linkedListStack *s);
void linkedListStackPush (struct linkedListStack *s, TYPE d);
TYPE linkedListStackTop (struct linkedListStack *s);
void linkedListStackPop (struct linkedListStack *s);
int linkedListStackIsEmpty (struct linkedListStack *s);

#endif /* WS17_H_ */
