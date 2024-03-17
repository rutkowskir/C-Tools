#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

int main() {
    char filename[MAX_LINE_LENGTH];
    char searchStr[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *file;
    int lineNum = 0;
    int count = 0;
    int ignoreCase = 0;
    int totalLines = 0;

    printf("Enter the file name: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter the search string: ");
    fgets(searchStr, MAX_LINE_LENGTH, stdin);
    searchStr[strcspn(searchStr, "\n")] = '\0';

    printf("Ignore case? (0 - No, 1 - Yes): ");
    scanf("%d", &ignoreCase);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Count the total number of lines in the file
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        totalLines++;
    }

    // Reset the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    // Search for the string
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        lineNum++;

        // Convert line to lowercase if ignore case is enabled
        if (ignoreCase) {
            char lowerLine[MAX_LINE_LENGTH];
            strcpy(lowerLine, line);
            for (int i = 0; lowerLine[i]; i++) {
                lowerLine[i] = tolower(lowerLine[i]);
            }

            if (strstr(lowerLine, searchStr) != NULL) {
                printf("Line %d: %s", lineNum, line);
                count++;
            }
        } else {
            if (strstr(line, searchStr) != NULL) {
                printf("Line %d: %s", lineNum, line);
                count++;
            }
        }
    }

    // Close the file
    fclose(file);

    printf("Total occurrences: %d\n", count);
    printf("Total lines: %d\n", totalLines);

    return 0;
}
