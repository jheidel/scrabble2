CXX=g++
RM=rm -rf
CFLAGS=-g -rdynamic -Wall -Wno-unused -D__STDC_CONSTANT_MACROS -std=c++11
PKGCONFIG=`pkg-config --cflags --libs opencv`
LIBS=

SRCS=main.cc board_detector.cc

TARGET=scrabble2

all:
	$(CXX) $(CFLAGS) -o $(TARGET) $(SRCS) $(PKGCONFIG) $(LIBS)

clean:
	$(RM) $(TARGET) *~ *.dSYM
