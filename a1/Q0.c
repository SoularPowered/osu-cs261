/* CS261- Assignment 1 - Q. 0*/
/* Name: Shawn S Hillyer
 * Date: 01/03/2016
 * Solution description: Practice using pointers and checking addresses
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("Value pointed to by iptr: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
	printf("The address pointed to by iptr: %04x\n", iptr);

     /*Print the address of iptr itself*/
	printf("The address of iptr itself: %04x\n", &iptr);
}

int main(){

    /*declare an integer x*/
	int x = 1;

    /*print the address of x*/
	printf("The address of x: %04x\n", &x);

    /*Call fooA() with the address of x*/
	fooA(&x);

    /*print the value of x*/
	printf("Value of x after fooA(x): %d\n", x);

    return 0;
}
