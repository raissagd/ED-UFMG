CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN_DIR = bin
OBJS = $(OBJ)/fibfat.o $(OBJ)/main.o $(OBJ)/clock.o
HDRS = $(INC)/fibfat.h $(INC)/clock.h
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN_DIR)/main

all: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/fibfat.o: $(HDRS) $(SRC)/fibfat.c
	$(CC) $(CFLAGS) -o $(OBJ)/fibfat.o $(SRC)/fibfat.c

$(OBJ)/clock.o: $(HDRS) $(SRC)/clock.c
	$(CC) $(CFLAGS) -o $(OBJ)/clock.o $(SRC)/clock.c

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

run: $(EXE)
	$(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out