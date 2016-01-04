/* CS261- Assignment 1 - Q.1*/
/* Name: Shawn S Hillyer
* Date: 01/03/2016
* Solution description: Program to generate 10 random student's. Each student has
* a random id from 1-10 and a score from 0 to 100. Program prints the
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct student{
  int id;
  int score;
};

struct student* allocate(){
  int num_students = 10;

  /*Allocate memory for ten students*/
  struct student* students = (struct student *) malloc(num_students * sizeof(struct student));

  /*return the pointer*/
  return students;
}

void generate(struct student* students){
  enum boolean { false, true };

  int num_students = 10;
  int i,			// Counter for allocation loop
      j,			// Counter for inner loop to make sure ID not already assigned
      rand_id;    // random student ID from 1 to 10
  enum boolean is_unique_id;	// Track if ID is unique or not

  /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
  for (i = 0; i < num_students; i++) {
    /* Make ID and verify it hasn't already been used */
    do {
      is_unique_id = true;
      rand_id = (rand() % 10) + 1;	// Generate the random id

      /* Compare to all students prior to current student being generated */
      j = 0;
      while (j < i && is_unique_id) {
        if (rand_id == students[j].id) {
          is_unique_id = false;
        }
        ++j;
      }
    } while (!is_unique_id);

    students[i].id = rand_id;
    students[i].score = rand() % 101;
  }
}

void output(struct student* students){
  /*Output information about the ten students in the format:
  ID1 Score1
  ID2 score2
  ID3 score3
  ...
  ID10 score10*/
  int num_students = 10,
  i; // loop counter

  for (i = 0; i < num_students; i++) {
    printf("ID%d score%d\n", students[i].id, students[i].score);
  }

}

void summary(struct student* students){
  /*Compute and print the minimum, maximum and average scores of the ten students*/
  int min,	// Minimum score
  max,	// Maximum score
  accumulator, // total of all scores
  i;	// loop counter
  double average = 0;	// Average score
  int num_students = 10;

  if (students == NULL) {
    printf("There are no students for which to calculate statistics.\n");
  }

  else {
    /* Set student to have min, max and average score, then iterate over rest to calc */
    accumulator = min = max = students[0].score;

    for (i = 1; i < num_students; i++) {
      if (students[i].score < min) {
        min = students[i].score;
      }
      else if (students[i].score > max) {
        max = students[i].score;
      }
      accumulator += students[i].score;
    }
    /* Calculate the average */
    average = (double)accumulator / num_students;

    printf("\nSummary for the %d students:\n", num_students);
    printf("Minimum score: %d\n", min);
    printf("Maximum score: %d\n", max);
    printf("Average score: %f\n\n", average);
  }
}

void deallocate(struct student* stud){
  /*Deallocate memory from stud*/
  if (stud != NULL) {
    free(stud);
  }

}

int main(){
  struct student* stud = NULL; // Pointer to students

  /*call allocate*/
  stud = allocate();

  /*call generate*/
  generate(stud);

  /*call output*/
  output(stud);

  /*call summary*/
  summary(stud);

  /*call deallocate*/
  deallocate(stud);

  return 0;
}
