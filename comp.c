#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void compareFiles(FILE *file1, FILE *file2);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: comp file1 file2\n");
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    compareFiles(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}

void compareFiles(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int lineNum = 1;
    int differentLines = 0;

    while (fgets(line1, MAX_LINE_LENGTH, file1) != NULL && fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            printf("Difference at line %d:\n", lineNum);
            printf("< %s", line1);
            printf("> %s", line2);
            differentLines++;
        }
        lineNum++;
    }

    // Check if one file has more lines than the other
    while (fgets(line1, MAX_LINE_LENGTH, file1) != NULL) {
        printf("Difference at line %d:\n", lineNum);
        printf("< %s", line1);
        differentLines++;
        lineNum++;
    }

    while (fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
        printf("Difference at line %d:\n", lineNum);
        printf("> %s", line2);
        differentLines++;
        lineNum++;
    }

    if (differentLines == 0) {
        printf("Files are identical.\n");
    } else {
        printf("Total differences: %d\n", differentLines);
    }
}
