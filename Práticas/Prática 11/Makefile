CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/pa11.out
OBJS = $(OBJ)/main.o $(OBJ)/AVLTree.o 
HDRS =  $(INC)/AVLTree.hpp
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/pa11.out

all: $(TARGET)

run:  $(EXE)

$(BIN)/pa11.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/pa11.out $(OBJS) $(LIBS)

$(OBJ)/AVLTree.o: $(HDRS) $(SRC)/AVLTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/AVLTree.o $(SRC)/AVLTree.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
