CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++11 -g
SOURCES = src
EXE = ${SOURCES}/diamond $(SOURCES)/matrixes $(SOURCES)/sort

all: ${EXE}

clean:
	$(RM) ${EXE}
