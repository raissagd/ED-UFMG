CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN_DIR = bin
OBJS = $(OBJ)/stacks.o $(OBJ)/expEvaluator.o $(OBJ)/binaryTree.o $(OBJ)/main.o
HDRS = $(INC)/stacks.hpp $(INC)/expEvaluator.hpp $(INC)/binaryTree.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN_DIR)/tp1.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/stacks.o: $(HDRS) $(SRC)/stacks.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/stacks.o $(SRC)/stacks.cpp

$(OBJ)/expEvaluator.o: $(HDRS) $(SRC)/expEvaluator.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/expEvaluator.o $(SRC)/expEvaluator.cpp

$(OBJ)/binaryTree.o: $(HDRS) $(SRC)/binaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/binaryTree.o $(SRC)/binaryTree.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out