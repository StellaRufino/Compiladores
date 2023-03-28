CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
LDFLAGS =

SRC = main.c
OBJ = $(SRC:.c=.o)
EXE = programa

.PHONY: all build clean

all: build

build: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)