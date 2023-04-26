CC = gcc

CFLAGS = -Wall

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: lab2

lab2: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

.PHONY: clean
	rm $(OBJECTS) lab2