#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


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
          // Create File object and open for reading
          FILE *inputFile;
          char *fileName = "todo.txt";
          // TODO: Get fileName from user instead of static

          inputFile = fopen(fileName, "r");
          if (inputFile == NULL) {
            fprintf(stderr, "Cannot open %s", fileName);
          }
          else {
            loadList(mainList, inputFile);
          }
          break; 
        }

        case 's': // "'s' to save to-do list to a file
        {
          // Create file object and open for writing
          FILE *outputFile;
          char *fileName = "newtodo.txt";
          // TODO: Get fileName from user

          outputFile = fopen(fileName, "w");
          if (outputFile == NULL) {
            fprintf(stderr, "Cannot open %s", fileName);
          }
          else {
            saveList(mainList, outputFile);
          }
          break;
        }

        case 'a': // "'a' to add a new task
        {
          break;
        }

        case 'g': // "'g' to get the first task
        {
          break;
        }

        case 'r': // "'r' to remove the first task
        {
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
