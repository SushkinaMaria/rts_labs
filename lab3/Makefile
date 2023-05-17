CC = gcc

CFLAGS = -Wall 

all: server client

server: server.c
	$(CC) $(CFLAGS) server.c -o server

client: client.c 
	$(CC) $(CFLGAS) client.c -o client

.PHONY: clean
	rm server client
