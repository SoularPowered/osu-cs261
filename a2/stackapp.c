/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"
#include "assert.h" // added for assertions

/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	assert(s != NULL);
	/* Set up a stack for the parens */
	struct DynArr* paren_stack = newDynArr(10);

	int is_still_balanced = 1;  // bool. true until we find a mismatch
	char next_char = nextChar(s);
	char match_char;

	while(next_char != '\0' && is_still_balanced) {
		/* push opening parens/brackets */
		if (next_char == '(' ||
			next_char == '{' ||
			next_char == '[') {
			// push )
			pushDynArr(paren_stack, next_char);
		}

		/* Check closing parens */
		else if (next_char == ')' ||
				 next_char == '}' ||
				 next_char == ']') {
			/* pop and see next_char matches top  */
			match_char = topDynArr(paren_stack);
			if (next_char != match_char) {
				is_still_balanced = 0; // not balanced
			}
			/* if it does, remove the last element from array for next round */
			else {
				popDynArr(paren_stack);
			}
		}
	}

	return is_still_balanced;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

