CC = gcc

CFLAGS = -O2 -std=c99 -pedantic -Wall -o -lm

recog: mainRecogEq.c scanner.c recognizeEq.c
	$(CC) $(CFLAGS) $^ -o $@
