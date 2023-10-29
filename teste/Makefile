CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN_DIR = bin
OBJS = $(OBJ)/graph.o $(OBJ)/linkedList.o $(OBJ)/sort.o $(OBJ)/main.o
HDRS = $(INC)/graph.hpp $(INC)/linkedList.hpp $(INC)/sort.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN_DIR)/tp2.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

$(OBJ)/linkedList.o: $(HDRS) $(SRC)/linkedList.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/linkedList.o $(SRC)/linkedList.cpp

$(OBJ)/sort.o: $(HDRS) $(SRC)/sort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sort.o $(SRC)/sort.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out
