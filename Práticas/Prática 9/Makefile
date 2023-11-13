CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/pa9.out
OBJS = $(OBJ)/main.o 
CFLAGS =  -pg -g -c -I$(INC)

EXE = $(BIN)/pa9.out

all: $(TARGET)

run:  $(EXE)

$(BIN)/pa9.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/pa9.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out