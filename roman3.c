#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal number to Roman numeral */
char* decimalToRoman(int decimal) {
    int decimalNums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* romanNums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char* roman = (char*)malloc(100 * sizeof(char));
    roman[0] = '\0';

    int i = 0;
    while (decimal > 0) {
        if (decimal >= decimalNums[i]) {
            strcat(roman, romanNums[i]);
            decimal -= decimalNums[i];
        } else {
            i++;
        }
    }

    return roman;
}

/* Function to convert Roman numeral to decimal number */
int romanToDecimal(char* roman) {
    int romanNums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int len = strlen(roman);

    int decimal = 0;
    int i = 0;
    while (i < len) {
        int j;
        for (j = 0; j < 13; j++) {
            if (strncmp(&roman[i], romanSymbols[j], strlen(romanSymbols[j])) == 0) {
                decimal += romanNums[j];
                i += strlen(romanSymbols[j]);
                break;
            }
        }
        if (j == 13) {
            printf("Invalid Roman numeral: %s\n", roman);
            exit(1);
        }
    }

    return decimal;
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Convert decimal number to Roman numeral\n");
    printf("2. Convert Roman numeral to decimal number\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int decimal;
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);

        char* roman = decimalToRoman(decimal);
        printf("Roman numeral: %s\n", roman);
        free(roman);
    } else if (choice == 2) {
        char romanNumeral[100];
        printf("Enter a Roman numeral: ");
        scanf("%s", romanNumeral);

        int decimalNum = romanToDecimal(romanNumeral);
        printf("Decimal number: %d\n", decimalNum);
    } else {
        printf("Invalid choice! Please choose either 1 or 2.\n");
    }

    return 0;
}
