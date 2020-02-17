/*file:    recognizeEq.c							   */
/*author:  Joel Kiers (email: j.k.kiers@student.rug.nl)*/
/*date:    16 Feb, 2019								   */
/*version: 1.0 										   */
/*Description: This file contains functions used in mainRecogEq.c  */

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "recognizeEq.h"

char vari = '\0';

int acceptNumber(List *lp) {
  if (*lp != NULL && (*lp)->tt == Number) {
    *lp = (*lp)->next;
    return 1;
  }
  return 0;
}

int acceptIdentifier(List *lp) {
  if (*lp != NULL && (*lp)->tt == Identifier) {
		if(vari == 0) {
			vari = (*lp)->t.identifier;
			printf("%c\n", vari);
		}
		printf("%s\n", (*lp)->t.identifier); //Testing
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

int acceptDegree(List *lp) { //idea
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
			printf("Power 1\n");
			return 1;
    }
    return 1;
  }
  if ( acceptIdentifier(lp) ) {
    if ( acceptCharacter(lp, '^') && acceptDegree(lp) ) {
			printf("Power 2\n");
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
  if ( !acceptExpression(lp) ) {
    return 0;
  }
  if ( !acceptCharacter(lp, '=') ) {
    return 0;
  }
  if ( !acceptExpression(lp) ) {
    return 0;
  }
  return 1;
}

int checkVariables(List *lp) {

	return 1;
}

int findDegree(List *lp) {
  //int degree = 0;

  return 0;
}
