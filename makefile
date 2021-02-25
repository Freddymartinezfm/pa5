TARGET = pa5
FLAGS = -g #-fno-stack-protector
CC = g++
TYPE = l

HEADER =  Edge.h  Edge.h Graph.h Node.h Graph.h list.h IntFiniteQueue.h
OBJ = main.o  Edge.o  Node.o list.o Graph.o IntFiniteQueue.o

$(TARGET): $(OBJ) 
	$(CC) $(FLAGS)  $(OBJ) -o $(TARGET)
main.o: main.cpp list.h 
	$(CC) $(FLAGS) -c main.cpp
Edge.o: Edge.cpp Edge.h
	$(CC) $(FLAGS) -c Edge.cpp 
Node.o: Node.cpp Node.h Edge.h
	$(CC) $(FLAGS) -c Node.cpp 

Graph.o: Graph.h Graph.cpp IntFiniteQueue.h
	$(CC) $(FLAGS) -c  Graph.cpp
list.o: list.h list.cpp
	$(CC) $(FLAGS) -c  list.cpp
IntFiniteQueue.o: IntFiniteQueue.h IntFiniteQueue.cpp
	$(CC) $(FLAGS) -c IntFiniteQueue.cpp


clean:
ifeq ($(TYPE), w)
	del $(TARGET).exe
	del *.o

else
	rm  *.o
	rm  $(TARGET)
endif 
