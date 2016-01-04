/* CS261- Assignment 1 - Q.2*/
/* Name: Shawn S Hillyer
 * Date: 01/03/2016
 * Solution description: Pass several arguments into a function and compare results.
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a *= 2;

    /*Set b to half its original value*/
	*b /= 2;

    /*Assign a+b to c*/
	c = (*a) + (*b);

    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5,
		y = 6,
		z = 7;

    /*Print the values of x, y and z*/
	printf("x: %d, y: %d, z: %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
	int return_value = foo(&x, &y, z);

    /*Print the value returned by foo*/
	printf("return_value: %d\n", return_value);

    /*Print the values of x, y and z again*/
	printf("x: %d, y: %d, z: %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/

	/* Yes, its' different because we are passing the third argument in by value,
	 * not by reference. Any changes to argument c happen only to the local copy.
	 * The other values are updated (arguments 1 and 2) because they are passed by
	 * reference.
	 */

    return 0;
}
