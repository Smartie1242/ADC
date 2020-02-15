/*file:    equations.c							   */
/*author:  Joel Kiers (email: j.k.kiers@student.rug.nl)*/
/*partner: Marten Bosma (email: m.bosma.21@student.rug.nl)*/
/*date:    15 Feb, 2020								   */
/*version: 1.0 										   */
/*Description: This program 	   */

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "recognizeExp.h"
void evalSymbols() {
 return;
}

void evalEquations(List li) {
	int equals = 0;
		while (li != NULL) {

	    /*switch (li->tt) {
	    case Number:
	      printf("%d ", (li->t).number);
	      break;
	    case Identifier:
	      printf("%s ", (li->t).identifier);
	      break;
	    case Symbol:
				evalSymbols(li->t).symbol);
				printf("%c ", (li->t).symbol);
	      break;
	    }*/

	    li = li->next;
		}

		return;
}

void scanEquations() {
	char *ar;
  List li;
  printf("give an equation: ");
  ar = readInput();
  while (ar[0] != '!') {
    li = tokenList(ar);
    printList(li);
		evalEquations(li);
    free(ar);
    freeTokenList(li);
		printf("\ngive an equation: ");
    ar = readInput();
  }
  free(ar);
  printf("good bye\n");
}

int main(int argc, char*argv[]) {
	scanEquations();



	return 0;
}
