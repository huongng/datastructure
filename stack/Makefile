CC = g++
CFLAGS = -Wall -g -std=c++11
OBJS = main.o
EXE = e
$(EXE) : main.o
	$(CC) $^ $(CFLAGS) -o $@
main.o : main.cpp LinkedStack.h LinkedStack.cpp ArrayStack.h ArrayStack.cpp
	$(CC) $(CFLAGS) $< -c -o $@
clean :
	rm *~ $(OBJS) $(EXE)
