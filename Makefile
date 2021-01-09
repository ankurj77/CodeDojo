ifeq ($(OS),Windows_NT)
  BINARY = CodeDojo.exe
else
  BINARY = ./CodeDojo.out
endif

CFLAGS  = -Wall -O2
CC      = g++
PROBLEM = 86

all : CodeDojo
	$(BINARY)

CodeDojo : problem.o problemtest.o
	$(CC) $(CFLAGS) -o $(BINARY) obj/problem.o obj/problemtest.o obj/main_linux.o

problem.o :
	$(CC) $(CFLAGS) -c problems/$(PROBLEM)/Problem.cpp -o obj/problem.o

problemtest.o :
	$(CC) $(CFLAGS) -c problems/$(PROBLEM)/ProblemTest.cpp -o obj/problemtest.o

clean :
	rm -rf obj/problem*
