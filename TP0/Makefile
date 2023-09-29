CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN_DIR = bin
OBJS = $(OBJ)/stacks.o $(OBJ)/stringVector.o $(OBJ)/expEvaluator.o $(OBJ)/quantifierEvaluator.o $(OBJ)/main.o
HDRS = $(INC)/stacks.hpp $(INC)/stringVector.hpp $(INC)/expEvaluator.hpp $(INC)/quantifierEvaluator.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN_DIR)/main

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/stacks.o: $(HDRS) $(SRC)/stacks.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/stacks.o $(SRC)/stacks.cpp

$(OBJ)/stringVector.o: $(HDRS) $(SRC)/stringVector.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/stringVector.o $(SRC)/stringVector.cpp

$(OBJ)/expEvaluator.o: $(HDRS) $(SRC)/expEvaluator.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/expEvaluator.o $(SRC)/expEvaluator.cpp

$(OBJ)/quantifierEvaluator.o: $(HDRS) $(SRC)/quantifierEvaluator.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/quantifierEvaluator.o $(SRC)/quantifierEvaluator.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out