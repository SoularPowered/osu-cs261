/* CS261- Worksheet 0 */
/* Name: Shawn S Hillyer
 * Date: 01/07/2016
 * Solution description: Implementation of an array-based BagStack
 */

# ifndef ArrayBagStack
# define ArrayBagStack
# define TYPE int
# define EQ(a, b) (a == b)

struct arrayBagStack {
  TYPE data [100];
  int count;
};

void initArray(struct arrayBagStack * b);
void addArray (struct arrayBagStack * b, TYPE v);
int containsArray (struct arrayBagStack * b, TYPE v);
void removeArray (struct arrayBagStack * b, TYPE v);
int sizeArray (struct arrayBagStack * b);
void pushArray (struct arrayBagStack * b, TYPE v);
TYPE topArray (struct arrayBagStack * b);
void popArray (struct arrayBagStack * b);
int isEmptyArray (struct arrayBagStack * b);

# endif
