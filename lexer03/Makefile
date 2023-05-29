CC = gcc
CFLAGS = -Wall -Wextra

all: lexer03

lexer: lexer03.c
	$(CC) $(CFLAGS) lexer.c -o lexer

clean:
	rm -f lexer

run: lexer03
	./lexer03

.PHONY: all clean run