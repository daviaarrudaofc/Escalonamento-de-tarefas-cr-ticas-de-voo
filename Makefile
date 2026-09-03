CC = gcc
CFLAGS = -Wall -Wextra -g

all: scheduler

scheduler: scheduler.c
	$(CC) $(CFLAGS) scheduler.c -o scheduler

clean:
	rm -f scheduler scheduler.exe *.out
