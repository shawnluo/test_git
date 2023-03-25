test: test.c
	gcc test.c common.c -o test -g -Wall -lm

test1: test1.c
	gcc test1.c common.c -o test1 -g -Wall -lm

.PHONY: clean
clean:
	rm test, test1