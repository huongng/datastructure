CC = g++
CFLAGS = -Wall -g -std=c++11
OBJS = main.o graph.o
EXE = e
$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
main.o : main.cpp
	$(CC) $(CFLAGS) $< -c -o $@
graph.o : graph.cpp
	$(CC) $(CFLAGS) $< -c -o $@
clean :
	rm *~ $(OBJS) $(EXE)
