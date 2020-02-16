/* recognizeExp.h, Gerard Renardel, 29 January 2014 */

#ifndef RECOGNIZEEQ_H
#define RECOGNIZEEQ_H

int acceptNumber(List *lp);
int acceptIdentifier(List *lp);
int acceptCharacter(List *lp, char c);
int acceptEquation(List *lp);
int checkOneVariable(List *lp);
int findDegree(List *lp);

#endif
