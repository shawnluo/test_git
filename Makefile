
# Default flags
flags?= -g -Wall -lm -lpthread -pedantic -lncurses -std=c++14

CC=g++
suffix = .cpp
TARGET_FILE = $(addsuffix $(suffix), $(PRG))

test: ${PRG}
	${CC} ${PRG}.cpp -o test ${flags}

.PHONY: clean
clean:
	rm -f test