
test: test.cpp
	@g++ test.cpp -o test -g -Wall -lm

test1: test1.cpp
	@g++ $< -o test -g -Wall -lm

test2: test2.cpp
	@g++ test2.cpp -o test -g -Wall -lm

test3: test3.cpp
	@g++ test3.cpp -o test -g -Wall -lm

test4: test4.cpp
	@g++ test4.cpp -o test -g -Wall -lm

test5: test5.cpp
	@g++ test5.cpp -o test -g -Wall -lm

BlackMagic_cracking: BlackMagic_cracking.cpp
	@g++ BlackMagic_cracking.cpp -o test -g -Wall -lm

.PHONY: clean
clean:
	@rm test