CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/pa10.out
OBJS = $(OBJ)/main.o $(OBJ)/Set.o 
HDRS =  $(INC)/Set.hpp
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/pa10.out

all: $(TARGET)

run:  $(EXE)

$(BIN)/pa10.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/pa10.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Set.o: $(HDRS) $(SRC)/Set.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Set.o $(SRC)/Set.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
