/* CS261- Assignment 1 - Q.3*/
/* Name: Shawn S Hillyer
 * Date: 01/03/2016
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h> // to use malloc - getting warnings/errors without this.

void sort(int* number, int n){
    /*Sort the given array number , of length n*/
    int i;  // Loop counter

	/* Bubble Sort implementation */
	enum boolean { false, true };

	enum boolean swapped;

	do {
		swapped = false;

		/* Check pairs and swap if any number at index i is greater than the value at i+1 */
		for (i = 0; i < n - 1; i++) {

			if (number[i] > number[i+1]) {
				/* Swap the values */
				int temp = number[i];
				number[i] = number[i + 1];
				number[i + 1] = temp;

				swapped = true;
			}
		}
	} while (swapped);
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	int i; // counter for loops

    /*Allocate memory for an array of n integers using malloc.*/
	int* values = (int *)malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++) {
		values[i] = rand();
	}

    /*Print the contents of the array.*/
	for (i = 0; i < n; i++) {
		printf("%d\n", values[i]);
	}

    /*Pass this array along with n to the sort() function of part a.*/
	sort(values, n);

    /*Print the contents of the array.*/
	printf("\nValues after sorting:\n");

	for (i = 0; i < n; i++) {
		printf("%d\n", values[i]);
	}
    return 0;
}
