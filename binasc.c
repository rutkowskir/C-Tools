#include <stdio.h>

int main() {
    FILE *file;
    char fileName[100];
    int choice;

    // Get the file name from the user
    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    // Open the file in binary read mode ("rb")
    file = fopen(fileName, "rb");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    // Menu for conversion options
    printf("Choose an option:\n");
    printf("1. Convert to Text (1's and 0's)\n");
    printf("2. Convert to Binary (Original Format)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Convert to Text (1's and 0's)
        FILE *textFile;
        char outputFileName[100];
        unsigned char byte;

        // Get the output text file name from the user
        printf("Enter the name of the output text file: ");
        scanf("%s", outputFileName);

        // Open the output text file for writing
        textFile = fopen(outputFileName, "w");
        if (textFile == NULL) {
            perror("Error opening the output file");
            fclose(file);
            return 1;
        }

        // Read the binary file byte by byte and write 1's and 0's to the text file
        while (fread(&byte, sizeof(unsigned char), 1, file) == 1) {
            for (int i = 7; i >= 0; i--) {
                fprintf(textFile, "%d", (byte >> i) & 1);
            }
        }

        // Close the files
        fclose(file);
        fclose(textFile);

        printf("Conversion to text complete.\n");
    } else if (choice == 2) {
        // Convert to Binary (Original Format)
        FILE *binaryFile;
        char outputFileName[100];
        char bitStr[9]; // To store 8 bits at a time

        // Get the output binary file name from the user
        printf("Enter the name of the output binary file: ");
        scanf("%s", outputFileName);

        // Open the output binary file for writing
        binaryFile = fopen(outputFileName, "wb");
        if (binaryFile == NULL) {
            perror("Error opening the output file");
            fclose(file);
            return 1;
        }

        // Read the text file containing 1's and 0's and convert back to binary
        while (fscanf(file, "%8s", bitStr) == 1) {
            unsigned char byte = 0;
            for (int i = 0; i < 8; i++) {
                byte = (byte << 1) | (bitStr[i] - '0');
            }
            fwrite(&byte, sizeof(unsigned char), 1, binaryFile);
        }

        // Close the files
        fclose(file);
        fclose(binaryFile);

        printf("Conversion to binary complete.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
