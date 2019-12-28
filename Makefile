CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++11 -g
SOURCES = src
EXE = ${SOURCES}/diamond $(SOURCES)/matrixes $(SOURCES)/sort $(SOURCES)/sort_segment $(SOURCES)/pancakes

all: ${EXE}

clean:
	$(RM) ${EXE}
