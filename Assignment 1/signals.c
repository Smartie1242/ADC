/*file:    signals.c							   */
/*author:  Joel Kiers (email: j.k.kiers@student.rug.nl)*/
/*partner: Marten Bosma (email: m.bosma.21@student.rug.nl)*/
/*date:    4 Feb, 2020								   */
/*version: 1.0 										   */
/*Description: This program transforms a signal into a level representation	   */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "LibStack.h"


int main(int argc, char*argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { // One loop for every signal

		int l;
		scanf("%d", &l);
		Stack stack = newStack(10);
		for (int j = 0; j < l; j++) { //Loops for every number in the signal
			int value;
			scanf("%d", &value);
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
		printf("\n");
		freeStack(stack);

	}
	printf("\n");
	return 0;
}
