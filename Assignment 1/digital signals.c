/*file:    digital signals.c							   */
/*author:  Joel Kiers (email: j.k.kiers@student.rug.nl)*/
/*partner: Marten Bosma (email: m.bosma.21@student.rug.nl)*/
/*date:    4 Feb, 2020								   */
/*version: 1.0 										   */
/*Description: This program transforms a signal into a level representation	   */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <libstack.h>

typedef struct Stack {
	int *array;
	int top;
	int size;
} Stack;

Stack newStack(int s) {
	Stack st;
	st.array = malloc(s * sizeof(int));
	assert(st.array != NULL);
	st.top = 0;
	st.size = s;
	return st;
}

void doubleStackSize(Stack *stp) {
	int  newSize = 2 * stp ->size;
	stp ->array = realloc(stp ->array , newSize * sizeof(int));
	assert(stp ->array  != NULL);
	stp ->size = newSize;
}

void push(int value, Stack *stp) {
	if (stp ->top == stp ->size) {
		doubleStackSize(stp);
	}
	stp ->array[stp ->top] = value;
	stp ->top ++;
}

int isEmptyStack(Stack st) {
	return (st.top == 0);
}

void stackEmptyError() {
	printf("stack empty\n");
	abort();
}

int pop(Stack *stp) {
	if (isEmptyStack (*stp)) {
		stackEmptyError();
	}
	stp ->top --;
	return (stp ->array)[stp ->top];
}

void freeStack(Stack st) {
	free(st.array);
}

int main(int argc, char*argv[]) {
	int n, z;
	z = scanf("%d", &n);
	for (int i = 0; i < n; i++) { // One loop for every signal

		int l;
		z = scanf("%d", &l);
		Stack stack = newStack(10);
		for (int j = 0; j < l; j++) { //Loops for every number in the signal
			int value;
			z = scanf("%d", &value);
			while (value < stack.top) { //If true the end of an interval is found and printed.
				printf("[%d,%d)@%d ",pop(&stack) , j, stack.top);
			}
			while (value > stack.top) { //If true no end of interval has been found
				push(j, &stack);
			}
		}
		while (stack.top > 0) { //Continues until all intervals have been printed.
			printf("[%d,%d)@%d ",pop(&stack) , l, stack.top);
		}
		freeStack(stack);

	}
	printf("\n");
	return 0;
}
