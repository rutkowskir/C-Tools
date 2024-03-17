#include <stdio.h>

int main() {
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int charCount[256] = {0}; // Initialize an array to count each character.

    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c >= 0 && c < 256) {
            charCount[c]++;
        }
    }

    fclose(file);

    printf("Character Summary:\n");
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            printf("'%c' (%d): %d\n", i, i, charCount[i]);
        }
    }

    return 0;
}
