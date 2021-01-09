ifeq ($(OS),Windows_NT)
  BINARY = CodeDojo.exe
else
  BINARY = ./CodeDojo.out
endif

CFLAGS  = -Wall -O2
CC      = g++
PROBLEM = 85

all : CodeDojo
	$(BINARY)

CodeDojo : main.o problem.o problemtest.o
	$(CC) $(CFLAGS) -o $(BINARY) obj/*.o

main.o :
	$(CC) $(CFLAGS) -c main.cpp -o obj/main.o

problem.o :
	$(CC) $(CFLAGS) -c problems/$(PROBLEM)/Problem.cpp -o obj/problem.o

problemtest.o :
	$(CC) $(CFLAGS) -c problems/$(PROBLEM)/ProblemTest.cpp -o obj/problemtest.o

clean :
	rm -rf obj/*