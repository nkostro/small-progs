CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++11 -g -Iinclude
SOURCES = src
EXE = ${SOURCES}/diamond $(SOURCES)/matrixes $(SOURCES)/sort $(SOURCES)/sort_segment $(SOURCES)/pancakes

all: ${EXE}

$(SOURCES)/sort $(SOURCES)/sort_segment $(SOURCES)/pancakes: ${SOURCES}/utils
	$(CXX) $(CXXFLAGS) -o $@ $@.cc $<

${SOURCES}/utils:
	$(CXX) $(CXXFLAGS) -c ${SOURCES}/utils.cc -o $@

clean:
	$(RM) ${EXE}
