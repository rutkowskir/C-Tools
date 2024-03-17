#include <stdio.h>

void displayFileInBinary(const char* filename, int outputMode, const char* outputFilename) {
    FILE* inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return;
    }

    FILE* outputFile = NULL;
    if (outputMode == 2) {
        outputFile = fopen(outputFilename, "w");
        if (outputFile == NULL) {
            printf("Failed to open the output file.\n");
            fclose(inputFile);
            return;
        }
    }

    unsigned char buffer[16];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; ++i) {
            for (int j = 7; j >= 0; --j) {
                unsigned char bit = (buffer[i] >> j) & 1;
                if (outputMode == 1) {
                    printf("%u", bit);
                } else if (outputMode == 2) {
                    fprintf(outputFile, "%u", bit);
                }
            }
            if (outputMode != 0) {
                printf(" ");
            }
            if (outputMode == 2) {
                fprintf(outputFile, " ");
            }
        }
        if (outputMode != 0) {
            printf("\n");
        }
        if (outputMode == 2) {
            fprintf(outputFile, "\n");
        }
    }

    fclose(inputFile);
    if (outputFile != NULL) {
        fclose(outputFile);
    }
}

int main() {
    char filename[100];
    char outputFilename[100];
    int outputMode;

    printf("Enter the input filename: ");
    scanf("%s", filename);

    printf("Output options:\n");
    printf("0 - Do not display or write output\n");
    printf("1 - Display output on the screen\n");
    printf("2 - Write output to a file\n");
    printf("Enter the output mode: ");
    scanf("%d", &outputMode);

    if (outputMode == 2) {
        printf("Enter the output filename: ");
        scanf("%s", outputFilename);
    }

    displayFileInBinary(filename, outputMode, outputFilename);

    return 0;
}
