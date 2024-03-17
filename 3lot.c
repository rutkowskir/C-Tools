#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and 9
int generateRandomNumber() {
    return rand() % 10;
}

int main() {
    int numDrawings;
    
    printf("Enter the number of drawings to run: ");
    scanf("%d", &numDrawings);

    srand(time(NULL)); // Seed the random number generator with the current time

    FILE *file = NULL;
    int displayOnScreen = 0, saveToFile = 0;

    // Prompt the user for display and save preferences
    printf("Do you want to display the results on the screen? (1 for yes, 0 for no): ");
    scanf("%d", &displayOnScreen);

    printf("Do you want to save the results to a file? (1 for yes, 0 for no): ");
    scanf("%d", &saveToFile);

    if (saveToFile) {
        char filename[100];
        printf("Enter the name of the file to save the results: ");
        scanf("%s", filename);
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Unable to open the file for writing.\n");
            return 1;
        }
    }

    for (int drawing = 1; drawing <= numDrawings; drawing++) {
        int lotteryNumbers[3];
        for (int i = 0; i < 3; i++) {
            lotteryNumbers[i] = generateRandomNumber();
        }

        printf("Drawing %d: %d %d %d\n", drawing, lotteryNumbers[0], lotteryNumbers[1], lotteryNumbers[2]);

        if (file != NULL) {
            fprintf(file, "Drawing %d: %d %d %d\n", drawing, lotteryNumbers[0], lotteryNumbers[1], lotteryNumbers[2]);
        }
    }

    if (file != NULL) {
        fclose(file);
        printf("Results saved to the file.\n");
    }

    return 0;
}
