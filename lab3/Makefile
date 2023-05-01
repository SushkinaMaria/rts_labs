CC = gcc

CFLAGS = -Wall 

all: server client

server: server.c
	$(CC) $(CFLAGS) -o server

client: client.c 
	$(CC) $(CFLGAS) -o client

.PHONY: clean
	rm server client