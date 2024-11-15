#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereEncrypt(const char *plaintext, const char *key, char *ciphertext) {
    int ptLength = strlen(plaintext);
    int keyLength = strlen(key);
    int keyIndex = 0;
	int i;
    for (i = 0; i < ptLength; i++) {
        char ptChar = plaintext[i];

        // Check if the character is a space
        if (ptChar == ' ') {
            ciphertext[i] = ' ';
            continue;
        }

        // Convert plaintext and key characters to decimal values
        int ptValue = (toupper(ptChar) - 64);  // A=1, B=2, ..., Z=26
        int keyValue = (toupper(key[keyIndex % keyLength]) - 64);  // Repeating key

        // Add the values from plaintext and key
        int encryptedValue = ptValue + keyValue;

        // Apply modulo 26 to wrap around
        encryptedValue = encryptedValue % 26;
        if (encryptedValue == 0) encryptedValue = 26;  // Adjust for zero wrap-around

        // Convert back to ASCII by adding 64
        ciphertext[i] = (encryptedValue + 64);

        // Move to the next character in the key
        keyIndex++;
    }

    // Null-terminate the ciphertext string
    ciphertext[ptLength] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    // Input plaintext and key
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    // Encrypt the plaintext
    vigenereEncrypt(plaintext, key, ciphertext);

    // Output the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

