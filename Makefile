CC = gcc
CFLAGS = -Wall -Wextra -g

all: InterQL

InterQL: *.c
	$(CC) $(CFLAGS) -o InterQL *.c

clean:
	rm -f InterQL

.PHONY: all clean