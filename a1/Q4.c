/* CS261- Assignment 1 - Q.4*/
/* Name: Shawn S Hillyer
* Date: 01/03/2016
* Solution description: Sort student records based on score.
*/

#include <stdio.h>
#include <stdlib.h>

struct student{
  int id;
  int score;
};

void sort(struct student* students, int n){
  /*Sort the n students based on their score*/
  int i;  // Loop counter

  /* Bubble Sort implementation */
  enum boolean { false, true };

  enum boolean swapped;

  do {
    swapped = false;

    /* Check pairs and swap if any students at index i is greater than the value at i+1 */
    for (i = 0; i < n - 1; i++) {

      if (students[i].score > students[i+1].score) {
        /* Swap the values */
        struct student temp = students[i];
        students[i] = students[i + 1];
        students[i + 1] = temp;

        swapped = true;
      }
    }
  } while (swapped);
}

int main(){
  /*Declare an integer n and assign it a value.*/
  int n = 7; // number of student records
  int i;  // Loop counter

  /*Allocate memory for n students using malloc.*/
	struct student* studs = (struct student *) malloc(n * sizeof(struct student));

  /*Generate random IDs and scores for the n students, using rand().*/
  srand((unsigned)time(NULL));

	for (i = 0; i < n; i++) {
		studs[i].id = rand() + 1;
		studs[i].score = rand() % 101;
	}

  /*Print the contents of the array of n students.*/
  for (i = 0; i < n; i++) {
    printf("ID%d score%d\n", studs[i].id, studs[i].score);
  }

  /*Pass this array along with n to the sort() function*/
  sort(studs, n);

  /*Print the contents of the array of n students.*/
  printf("\nStudent records after sorting:\n");
  for (i = 0; i < n; i++) {
    printf("ID%d score%d\n", studs[i].id, studs[i].score);
  }

  return 0;
}
