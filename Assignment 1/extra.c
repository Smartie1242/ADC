/*file:    extra.c							   */
/*author:  Joel Kiers (email: j.k.kiers@student.rug.nl)*/
/*partner: Marten Bosma (email: m.bosma.21@student.rug.nl)*/
/*date:    5 Feb, 2020								   */
/*version: 1.0 										   */
/*Description: This program transforms a level representation	into a signal.   */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

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



	return 0;
}
