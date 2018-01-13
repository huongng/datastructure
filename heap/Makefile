CC = g++
CFLAGS = -Wall -g -std=c++11
OBJS = main.o
EXE = e
$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJS) : main.cpp ArrayHeap.h ArrayHeap.cpp HeapInterface.h
	$(CC) $(CFLAGS) $< -c -o $@
clean :
	rm *~ $(OBJS) $(EXE)
