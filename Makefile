test: test.c
	gcc test.c common.c -o test -g -Wall -lm

.PHONY: clean
clean:
	rm test