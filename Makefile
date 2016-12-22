CC=g++
AR=ar
CPPFLAGS= -Wall -O3 -g -std=c++11
LDFLAGS=
LIBS=

CREUI_OBJS=ui.o
CREUI_HEADERS=creui.h ui.h
TEST_OBJS=test.o

all: $(CREUI_OBJS)

test: $(TEST_OBJS) $(CREUI_OBJS)
	$(LINK.cpp) $^ -o $@

$(CREUI_OBJS) $(TEST_OBJS):$(CREUI_HEADERS)

clean:
	rm *.o test
