#include <stdio.h>

void displayHex(FILE *inputFile, FILE *outputFile);

int main() {
    char inputFileName[100];
    char outputFileName[100];
    int choice;

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    printf("Do you want to display the output (1) or write to a file (2)? Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 2) {
        printf("Enter the output file name: ");
        scanf("%s", outputFileName);
    }

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    FILE *outputFile;

    if (choice == 1) {
        outputFile = stdout;  // Output to console
    } else if (choice == 2) {
        outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Failed to open the output file.\n");
            fclose(inputFile);
            return 1;
        }
    } else {
        printf("Invalid choice.\n");
        fclose(inputFile);
        return 1;
    }

    displayHex(inputFile, outputFile);

    fclose(inputFile);

    if (choice == 2) {
        fclose(outputFile);
    }

    return 0;
}

void displayHex(FILE *inputFile, FILE *outputFile) {
    unsigned char buffer[16];
    size_t bytesRead;
    size_t offset = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        fprintf(outputFile, "%08zx  ", offset);

        // Display hexadecimal values
        for (size_t i = 0; i < bytesRead; i++) {
            fprintf(outputFile, "%02x ", buffer[i]);
            if (i == 7) {
                fprintf(outputFile, " ");  // Add extra space for better readability
            }
        }

        // Add extra spaces for alignment if needed
        if (bytesRead < sizeof(buffer)) {
            size_t remaining = sizeof(buffer) - bytesRead;
            for (size_t i = 0; i < remaining; i++) {
                fprintf(outputFile, "   ");
                if (i == 3) {
                    fprintf(outputFile, " ");  // Add extra space for better readability
                }
            }
        }

        fprintf(outputFile, " |");

        // Display ASCII characters
        for (size_t i = 0; i < bytesRead; i++) {
            unsigned char c = buffer[i];
            if (c >= 32 && c <= 126) {
                fprintf(outputFile, "%c", c);
            } else {
                fprintf(outputFile, ".");
            }
        }

        fprintf(outputFile, "|\n");

        offset += bytesRead;
    }
}
