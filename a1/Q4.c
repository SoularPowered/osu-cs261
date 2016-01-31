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

/* sort array of struct students of size n using bubble sort
 * Preconditions: n>=0, students !=0
 * Postconditoins: array will be sorted in ascending order by student.score
 */
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
  
  /*Allocate memory for n students using malloc.*/
  struct student* studs = (struct student *) malloc(n * sizeof(struct student));

  /*Generate random IDs and scores for the n students, using rand().*/
  //srand((unsigned)time(NULL));

  enum boolean { false, true };

  int num_students = 10;
  int i,      // Counter for allocation loop
      j,      // Counter for inner loop to make sure ID not already assigned
      rand_id;    // random student ID from 1 to 10
  enum boolean is_unique_id;  // Track if ID is unique or not

  /*Generate random ID and scores for ten students*/
  for (i = 0; i < num_students; i++) {
    /* Make ID and verify it hasn't already been used */
    do {
      is_unique_id = true;
      rand_id = (rand() % 10) + 1;  // Generate the random id

      /* Compare to all students prior to current student being generated */
      j = 0;
      while (j < i && is_unique_id) {
        if (rand_id == studs[j].id) {
          is_unique_id = false;
        }
        ++j;
      }
    } while (!is_unique_id);

    studs[i].id = rand_id;
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
