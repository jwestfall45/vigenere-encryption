/*
 * File: cipher.c
 * Description: Vigenère cipher implementation
 *
 * Copyright (C) 2025 Justin Westfall
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ENCRYPTION,
    DECRYPTION
} operation_t;

static void cipher_operation(char *msg, char *key, operation_t operation) {
    // Iterate through each character in the message
    for (int i = 0; i < strlen(msg); i++) {
        // If the character is a letter
        if (isalpha(msg[i])) {
            // Determine the base for the character (A or a)
            char base = isupper(msg[i]) ? 'A' : 'a';

            // Get the corresponding character from the key
            char key_char = key[i % strlen(key)];

            // Apply the offset calculation
            if (operation == ENCRYPTION) {
                msg[i] = (msg[i] - base + (key_char - base)) % 26 + base;
            } else {
                msg[i] = (msg[i] - base - (key_char - base) + 26) % 26 + base;
            }
        }
    }
}

int main() {
    // Temp buffers for input using fixed size to prevent buffer overflow
    char tmp_msg[101];
    char tmp_key[101];

    printf("Enter message: ");
    scanf("%100s", tmp_msg);

    printf("Enter key: ");
    scanf("%100s", tmp_key);

    // Allocate memory based on the actual length of the input strings
    char *msg = malloc(strlen(tmp_msg) + 1);
    char *key = malloc(strlen(tmp_key) + 1);

    if (msg == NULL || key == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // Copy the input from the temporary buffer to the dynamically allocated memory
    strcpy(msg, tmp_msg);
    strcpy(key, tmp_key);

    operation_t operation;
    printf("Choose operation: 0 for encryption, 1 for decryption: ");
    scanf("%d", (int*)&operation);

    if ((operation != ENCRYPTION) && (operation != DECRYPTION)) {
        printf("Invalid operation selection (0 or 1)\n");
        free(msg);
        free(key);
        return -1;
    }

    cipher_operation(msg, key, operation);
    printf("Result: %s\n", msg);

    free(msg);
    free(key);

    return 0;
}
