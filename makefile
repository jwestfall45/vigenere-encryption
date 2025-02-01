CC = gcc
CFLAGS = -Wall -g

vigenere_cipher: src/vigenere_cipher.c
	$(CC) $(CFLAGS) src/vigenere_cipher.c -o vigenere_cipher
