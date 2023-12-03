
flags?= -g -Wall -lm -lpthread

test: test.cpp
	@g++ test.cpp -o test ${flags}

test1: test1.cpp
	@g++ $< -o test ${flags}

test2: test2.cpp
	@g++ test2.cpp -o test ${flags} -std=c++11

test3: test3.cpp
	@g++ test3.cpp -o test ${flags}

test4: test4.cpp
	@g++ test4.cpp -o test ${flags}

test5: test5.cpp
	@g++ test5.cpp -o test ${flags}

BlackMagic_cracking: BlackMagic_cracking.cpp
	@g++ BlackMagic_cracking.cpp -o test ${flags}

.PHONY: clean
clean:
	@rm test