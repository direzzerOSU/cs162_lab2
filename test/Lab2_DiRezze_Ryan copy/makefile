
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = countLetters.o main.o menu.o

SRCS = countLetters.cpp main.cpp menu.cpp

HEADERS = countLetters.hpp menu.hpp

#target: dependencies
#	rule to build
#

countLetters: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o countLetters

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
