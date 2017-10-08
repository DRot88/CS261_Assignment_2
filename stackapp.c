/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


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
	assert(s != '\0');
	DynArr *dyn;
	dyn = newDynArr(10);
	char nextCh = nextChar(s);
	char lastAddedToStack;
	while (nextCh != '\0') {
		if (nextCh == '(' || nextCh == '[' || nextCh == '{') {

			if (nextCh == '(') {		
				pushDynArr(dyn, ')');
				lastAddedToStack = ')';
			}

			if (nextCh == '[') {
				pushDynArr(dyn, ']');
				lastAddedToStack = ']';
			}

			if (nextCh == '{') {
				pushDynArr(dyn, '}');
				lastAddedToStack = '}';
			}						
		}

		if (nextCh == ')' || nextCh == ']' || nextCh == '}') {
			if (nextCh == lastAddedToStack) {

				if (sizeDynArr(dyn) > 0) {
					popDynArr(dyn);
				} else {
						return 0;
				}

				if (sizeDynArr(dyn) > 0) {
					lastAddedToStack = topDynArr(dyn);
				}
			}	else {
					return 0;
			}				
		}		

		nextCh = nextChar(s);
	}

	if (isEmptyDynArr(dyn)) {
		return 1;
	}

	return 0;
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

