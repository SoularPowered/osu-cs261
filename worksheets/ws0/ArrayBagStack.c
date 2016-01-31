/* CS261- Worksheet 0 */
/* Name: Shawn S Hillyer
 * Date: 01/07/2016
 * Solution description: Implementation of an array-based BagStack
 */
// #include <stdboo.h> // Would normally use this instead of int for true/false
#include <stdio.h>

/* Set all elements of the array to 0 and set count to 0 */
void initArray (struct arrayBagStack * b){
  // int i = 0;  // Loop counter
  // for (i = 0; i < 100; i++) {
  //   b->data[i] = 0;
  // }

  b->count = 0;
}


/* Bag Interface Functions */

/* Add v to BagStack and increment count
 * Preconditions: b is initialized
 * Postconditions: If count < 100, add v to data[], count incremented 1
 *                 else, silently fail??
 */
void addArray (struct arrayBagStack * b, TYPE v) {
  if (count < 100) {
    b->data[count] = v;
    count++;
  }
  else {
    // silently do nothing?
  }
}


/* Returns true (1) If v is found in the BagStack
 * Preconditions: None
 * Postconditions: Bag unchanged, returns 0 if value not found,
 *   otherwise returns 1
 */
int containsArray (struct arrayBagStack * b, TYPE v){
  int i;
  for (i = 0; i < 100; i++) {
    if (b->data[i] == v) {
      return 1;
    }
    else {
      return 0;
    }
  }
}

/* Remove value from the array
 * Preconditions: None
 * Postconditions: value removed from array (all or just first??)
 */
void removeArray (struct arrayBagStack * b, TYPE v) {
  int i; // loop counter
  int j; // inner loop counter

  for (i = 0; i < 100; i++) {
    if (b->data[i] == v) {
      // copy the remainder of array down one and decrement count
      for (j = i; j < 99; j++) {
        b->data[j] = b->data[j + 1];
      }
      --count;
    }
  }

}


int sizeArray (struct arrayBagStack * b) {
  return b->count;

}

/* Stack Interface Functions */


/* Push an item to top of stack
 * Preconditions: none
 * Postconditions: value will be on stack if size < 100, else do nothing
 */
void pushArray (struct arrayBagStack * b, TYPE v) {
  if (count < 100) {
    b->data[count] = v;
    count++;
  }
  else {
    // silently do nothing?
  }

}

/* Returns the value on the top of the array
 * Preconditions: None
 * Postconditions: Returns the value on the top of the array. Throw StackUnderflow if empty
 */
TYPE topArray (struct arrayBagStack * b) {
  if (!isEmptyArray(b)) {
    return b->data[count - 1];
  }
  else {
    // Throw stack underflow
  }
}

/* Pop the last value off of the stack
 * Preconditions: None
 * Postconditions: Removes the value at the top of the stack
 * unless empty
 */
void popArray (struct arrayBagStack * b) {
  if (!isEmptyArray(b)) {
    // Cannot safely change the value of data since we don't know the ultimate TYPE
    // but we would normally do so if we were using an array of pointers, for example
    // b->data[count - 1] = NULL;
    --count;
  }
  else {
    // Throw stack underflow
  }

}

/* Returns true if the stack is empty, false if it has any values
 * Preconditions: None
 * Postconditions: Returns true (1) if the stack is empty
 */
int isEmptyArray (struct arrayBagStack * b) {
  return b->count > 0;
}
