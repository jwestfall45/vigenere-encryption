CC = gcc
CFLAGS = -Wall -g

vigenere_cipher: vigenere_cipher.c
	$(CC) $(CFLAGS) vigenere_cipher.c -o vigenere_cipher
