CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++11 -g
SOURCES = src
EXE = ${SOURCES}/diamond

all: ${EXE}

clean:
	$(RM) ${EXE}
