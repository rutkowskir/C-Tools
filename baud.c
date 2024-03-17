#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BAUD_RATE 150
#define BITS_PER_CHARACTER 8
#define DELAY ((float)BITS_PER_CHARACTER / BAUD_RATE)

void displayFile(const char *filename);

int main() {
    char filename[100];

    printf("Enter the file name: ");
    scanf("%s", filename);

    // Clear screen command based on the operating system
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    displayFile(filename);

    return 0;
}

void displayFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    int c;

    while ((c = fgetc(file)) != EOF) {
        putchar(c);
        fflush(stdout);  // Flush output to display immediately
        usleep(1000000 * DELAY);  // Delay between characters
    }

    fclose(file);
}
