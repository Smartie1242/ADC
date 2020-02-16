CC = gcc

CFLAGS = -O2 -std=c99 -pedantic -Wall -o -lm

recog: mainRecog.c scanner.c recognizeEq.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean debug-scan

clean:
	rm -f eval recog
