test: test.c
	gcc test.c common.c -o test -g -Wall -lm

test1: test1.c
	gcc test1.c common.c -o test1 -g -Wall -lm

test4: test4.cpp
	@g++ test4.cpp -o test4 -g -Wall -lm

BlackMagic_cracking: BlackMagic_cracking.cpp
	@g++ BlackMagic_cracking.cpp -o BlackMagic_cracking -g -Wall -lm

.PHONY: clean
clean:
	@rm test, test1, test2, test3, test4