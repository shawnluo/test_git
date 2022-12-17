test: test.c
	gcc test.c -o test -g -Wall -lm

.PHONY: clean
clean:
	rm test