/*file:    mainRecogEq.c							   */
/*author:  Joel Kiers (email: j.k.kiers@student.rug.nl)*/
/*date:    16 Feb, 2019								   */
/*version: 1.0 										   */
/*Description: This program scans a line of input and determines if it is in fact an equation	   */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scanner.h"
#include "recognizeEq.h"

int main(int argc, char*argv[]) {
	char *ar;
	List li;
	printf("give an equation: ");
	ar = readInput();
	while (ar[0] != '!') {
		li = tokenList(ar);
		printList(li);

		List lp = li;
		if (acceptEquation(&lp) && lp == NULL) {
			lp = li;
			if (checkOneVariable(&lp)) {
				lp = li;
				int degree = findDegree(&lp);
				printf("this is an equation in 1 variable of degree %d", degree);
			}
			else {
				printf("this is an equation, but not in 1 variable");
			}
		}
		else {
			printf("this is not an equation\n");
		}

		free(ar);
		freeTokenList(li);
		printf("\nGive an equation: ");
		ar = readInput();
	}
	free(ar);
	printf("Program finished!\n");
	return 0;
}
