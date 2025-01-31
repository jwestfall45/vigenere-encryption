CC = gcc
CFLAGS = -Wall -g

cipher: cipher.c
	$(CC) $(CFLAGS) cipher.c -o cipher
