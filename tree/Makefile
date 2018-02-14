CC = g++
CFLAGS = -Wall -g -std=c++11
OBJS = main.o
PREREQ = BinarySearchTree.cpp BinarySearchTree.h Node.cpp Node.h
EXE = e

all : $(OBJS)
	$(CC) $(CFLAGS) $< -o $@
$(OBJS): main.cpp $(PREREQ)
	$(CC) $(CFLAGS) $< -c -o $@ 
clean:
	rm *~ $(OBJS) $(EXE)