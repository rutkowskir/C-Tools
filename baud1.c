#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BITS_PER_CHARACTER 8
#define DELAY ((float)BITS_PER_CHARACTER / baudRate)

void displayFile(const char *filename, int baudRate);

int main() {
    char filename[100];
    int baudRate;

    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("Enter the baud rate: ");
    scanf("%d", &baudRate);

    // Clear screen command based on the operating system
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    displayFile(filename, baudRate);

    return 0;
}

void displayFile(const char *filename, int baudRate) {
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
