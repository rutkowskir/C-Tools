#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void performEncryption(FILE *inputFile, FILE *outputFile, char *key) {
    int keyLength = strlen(key);
    int keyIndex = 0;
    int inputChar;

    while ((inputChar = fgetc(inputFile)) != EOF) {
        // Encrypt each character with the key
        int encryptedChar = inputChar ^ key[keyIndex];

        // Write the encrypted character to the output file
        fputc(encryptedChar, outputFile);

        // Move to the next character in the key
        keyIndex = (keyIndex + 1) % keyLength;
    }
}

void performDecryption(FILE *inputFile, FILE *outputFile, char *key) {
    // Decryption is the same as encryption
    performEncryption(inputFile, outputFile, key);
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char key[100];
    int option;

    // Prompt for input and output file names
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    // Prompt for encryption or decryption
    printf("Enter '1' to encrypt or '2' to decrypt: ");
    scanf("%d", &option);

    // Prompt for the encryption/decryption key
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Open the input file for reading
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Perform encryption or decryption based on the chosen option
    if (option == 1) {
        performEncryption(inputFile, outputFile, key);
        printf("File successfully encrypted.\n");
    } else if (option == 2) {
        performDecryption(inputFile, outputFile, key);
        printf("File successfully decrypted.\n");
    } else {
        printf("Invalid option. Please choose '1' or '2'.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
