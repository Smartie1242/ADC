/* recognizeExp.c, Gerard Renardel, 29 January 2014
 *
 * In this file a recognizer acceptExpression is definined that can recognize
 * arithmetical expressions generated by the following BNF grammar:
 *
 * <expression>  ::= <term> { '+'  <term> | '-' <term> }
 *
 * <term>       ::= <factor> { '*' <factor> | '/' <factor> }
 *
 * <factor>     ::= <number> | <identifier> | '(' <expression> ')'
 *
 * Input for the recognizer is the token list constructed by the scanner (in scanner.c).
 * For the recognition of a token list the method of *recursive descent* is used.
 * It relies on the use of three functions for the recognition and processing of
 * terms, factors and expressions, respectively.
 * These three functions are defined with mutual recursion, corresponding with the
 * structure of the BNF grammar.
 */

#include <stdio.h>  /* getchar, printf */
#include <stdlib.h> /* NULL */
#include "scanner.h"
#include "recognizeExp.h"

/* The functions acceptNumber, acceptIdentifier and acceptCharacter have as
 * (first) argument a pointer to an token list; moreover acceptCharacter has as
 * second argument a character. They check whether the first token
 * in the list is a number, an identifier or the given character, respectively.
 * When that is the case, they yield the value 1 and the pointer points to the rest of
 * the token list. Otherwise they yield 0 and the pointer remains unchanged.
 */

int acceptNumber(List *lp) {
  if (*lp != NULL && (*lp)->tt == Number) {
    *lp = (*lp)->next;
    return 1;
  }
  return 0;
}

int acceptIdentifier(List *lp) {
  if (*lp != NULL && (*lp)->tt == Identifier) {
    *lp = (*lp)->next;
    return 1;
  }
  return 0;
}

int acceptCharacter(List *lp, char c) {
  if (*lp != NULL && (*lp)->tt == Symbol && ((*lp)->t).symbol == c) {
    *lp = (*lp)->next;
    return 1;
  }
  return 0;
}

int acceptDegree(List *lp) {
  if (*lp != NULL && (*lp)->tt == Number) {
    *lp = (*lp)->next;
    return 1;
  }
  return 0;
}

int acceptTerm(List *lp) {
  if ( !acceptNumber(lp) ) {
    if ( !acceptIdentifier(lp) ) {
      return 0;
    }
    if ( acceptCharacter(lp, '^') && acceptDegree(lp) ) {
			return 1;
    }
    return 1;
  }
  if ( acceptIdentifier(lp) ) {
    if ( acceptCharacter(lp, '^') && acceptDegree(lp) ) {
      return 1;
    }
    return 1;
  }
  return 1;
}

int acceptExpression(List *lp) {
	if ( !acceptCharacter(lp, '-') ) {
		if ( !acceptTerm(lp) ) {
			return 0;
		}
		while ( acceptCharacter(lp, '+') || acceptCharacter(lp, '-') ) {
			if ( !acceptTerm(lp) ) {
				return 0;
			}
		}
		return 1;
	}
	if ( !acceptTerm(lp) ) {
		return 0;
	}
	while ( acceptCharacter(lp, '+') || acceptCharacter(lp, '-') ) {
		if ( !acceptTerm(lp) ) {
			return 0;
		}
	}
	return 1;
}

int acceptEquation(List *lp) {
	if(!acceptExpression(lp)) {
		return 0;
	}
	if(!acceptCharacter(lp, '=')) {
		return 0;
	}
	if (!acceptExpression(lp)) {
		return 0;
	}
	return 1;
}

void recognizeEquations() {
  char *ar;
  List li, li1;

  printf("give an equation: ");
  ar = readInput();
  while (ar[0] != '!') {
    li = tokenList(ar);
    printList(li);
    li1 = li;

    if (acceptEquation(&li1) && li1 == NULL) {
			printf("this is an equation, but not in 1 variable\n");
		/*} else if() {
			printf("this is an equation in 1 variable of degree %d\n", degree);*/
		} else {
      printf("this is not an equation\n");
    }
    free(ar);
		freeTokenList(li);
    printf("\ngive an equation: ");
    ar = readInput();
  }
  free(ar);
  printf("good bye\n");
}
