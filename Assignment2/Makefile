CC = gcc

CFLAGS = -O2 -std=c99 -pedantic -Wall -o -lm

recog: mainRecog.c scanner.c recognizeExp.c
	$(CC) $(CFLAGS) $^ -o $@
