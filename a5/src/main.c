/*
Author: Shawn S Hillyer
Date: 02/15/2016
Class: CS 261-400
Assignment: Assignment 5  Heap Implementation of a To-Do List

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"
#define FILE_NAME_SIZE 128

int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
      switch (cmd) {
        case 'l': // "'l' to load to-do list from a file
        {
          // Create File object and open for reading based on filename entered by user
          FILE *inputFile;
          char fileName[FILE_NAME_SIZE];
          printf("Please enter the filename: ");
          scanf("%s", fileName);

          inputFile = fopen(fileName, "r");
          if (inputFile == NULL) {
            // If error, print error message
            fprintf(stderr, "Cannot open %s\n\n", fileName);
          }
          else {
            // Else load the list into the heap and close file
            printf("The list has been loaded from file successfully.\n\n");
            loadList(mainList, inputFile);
            fclose(inputFile);
          }
          while (getchar() != '\n'); // Clear trailing newline
          break; 
        }

        case 's': // "'s' to save to-do list to a file
        {
          // Create file object and open for writing
          FILE *outputFile;
          char fileName[FILE_NAME_SIZE];
          printf("Please enter the filename: ");
          scanf("%s", fileName);

          outputFile = fopen(fileName, "w");
          if (outputFile == NULL) {
            // If error, print error message
            fprintf(stderr, "Cannot open %s\n\n", fileName);
          }
          else {
            // Else save the list to file and close file
            printf("The list has been saved into the file successfully.\n\n");
            saveList(mainList, outputFile);
            fclose(outputFile);
          }
          while (getchar() != '\n'); // Clear trailing newline
          break;
        }

        case 'a': // "'a' to add a new task
        {
          printf("Please enter the task description: ");
          char description[TASK_DESC_SIZE];
          fgets(description, TASK_DESC_SIZE, stdin);
          // Strip the newline if one is leftover from fgets(). Most elegant solution I could find.
          // Source of this one line of code: http://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
          description[strcspn(description, "\n")] = 0; 

          // Prompt for task priority until get a valid integer
          int priority;
          do {
            printf("Please enter the task priority (0-999): ");
            scanf("%d", &priority);
            while (getchar() != '\n'); // Clear trailing newline
          } while (priority < 0 || priority > 999);

          TaskP newTask = createTask(priority, description);
          addHeap(mainList, newTask, compare);
          printf("The task \'%s\' has been added to your to-do list.\n\n", description);
          break;
        }

        case 'g': // "'g' to get the first task
        {
          TaskP firstTask = getMinHeap(mainList);
          printf("Your first task is: %s\n\n", firstTask->description);
          break;
        }

        case 'r': // "'r' to remove the first task
        {
          TaskP firstTask = getMinHeap(mainList);
          printf("Your first task \'%s\' has been removed from the list.\n\n", firstTask->description);
          removeMinHeap(mainList, compare);
          break;
        }

        case 'p': // "'p' to print the list
        {
          printList(mainList);
          break;
        }

        case 'e':
        {
          printf("Exiting program.");
          break;
        }
        default: // Invalid selection
        {
          printf("Invalid Selection\n");
          break;
        }
      }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
