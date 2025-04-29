# vigenere-encryption
A lightweight C implementation of the Vigenère cipher.

## Features
- Encrypts and decrypts messages using the Vigenère cipher.
- Handles both uppercase and lowercase letters.
- Ignores non-alphabetic characters in the message.

## Usage
1. Compile the code
    ```sh
    make vigenere_cipher
    ```

2. Run the compiled program:
    ```sh
    ./vigenere_cipher
    ```

3. Follow the prompts to enter the message and the key, and choose the operation (encryption or decryption).

## Example
```sh
 ./vigenere_cipher
Enter message: information
Enter key: foo
Choose operation: 0 for encryption, 1 for decryption: 0
Result: nbttfafhwtb
```
```sh
 ./vigenere_cipher
Enter message: nbttfafhwtb
Enter key: foo
Choose operation: 0 for encryption, 1 for decryption: 1
Result: information
```
