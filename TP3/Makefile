CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN_DIR = bin
OBJS = $(OBJ)/intArray.o $(OBJ)/matrix.o $(OBJ)/segTree.o $(OBJ)/main.o
HDRS = $(INC)/intArray.hpp $(INC)/matrix.hpp $(INC)/segTree.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN_DIR)/tp3.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/intArray.o: $(HDRS) $(SRC)/intArray.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/intArray.o $(SRC)/intArray.cpp

$(OBJ)/matrix.o: $(HDRS) $(SRC)/matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matrix.o $(SRC)/matrix.cpp

$(OBJ)/segTree.o: $(HDRS) $(SRC)/segTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/segTree.o $(SRC)/segTree.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out
