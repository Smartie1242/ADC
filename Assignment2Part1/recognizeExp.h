/* recognizeExp.h, Gerard Renardel, 29 January 2014 */

#ifndef RECOGNIZEEXP_H
#define RECOGNIZEEXP_H

int acceptNumber(List *lp);
int acceptIdentifier(List *lp);
int acceptCharacter(List *lp, char c);
int acceptDegree(List *lp);
int acceptExpression(List *lp);
int acceptEquation(List *lp);
void recognizeEquations();

#endif
