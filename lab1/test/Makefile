build_dir = build

CC = gcc

LIBS = lauthor

CFLAGS = -Wall -$(LIBS) \
	-L../release/ \
	-Wl,-rpath=../release/


SOURCES = test.c
OBJECTS = $(SOURCES.c:.o)

all: test

test: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -$(LIBS)

.PHONY: clean
clean:
	rm $(OBJECTS) test
