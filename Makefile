CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++11 -g
SOURCES = src
EXE = ${SOURCES}/diamond $(SOURCES)/matrixes $(SOURCES)/sort $(SOURCES)/sort_segment

all: ${EXE}

clean:
	$(RM) ${EXE}
