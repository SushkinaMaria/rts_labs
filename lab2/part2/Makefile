CC = gcc

LIBS = lthreads

CFLAGS = -Wall \
	-L./threads/  \
	-Wl,-rpath=./threads/ 

LIB_CFLAGS = -Wall -fpic -shared

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

LIB_SOURCES = \
	threads/threads.c 

all: lab2

lab2: $(SOURCES) libthreads
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -$(LIBS)

libthreads: $(LIB_SOURCES)
	$(CC) $(LIB_CFLAGS) $(LIB_SOURCES) -o threads/libthreads.so

.PHONY: clean
	rm $(OBJECTS) lab2