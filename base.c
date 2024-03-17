/* dbho64.c */

#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(unsigned long long decimal);
void decimalToHex(unsigned long long decimal);
void decimalToOctal(unsigned long long decimal);
void binaryToDecimal(unsigned long long binary);
void binaryToHex(unsigned long long binary);
void binaryToOctal(unsigned long long binary);
void hexToBinary(char *hex);
void hexToDecimal(char *hex);
void hexToOctal(char *hex);
void octalToBinary(unsigned long long octal);
void octalToDecimal(unsigned long long octal);
void octalToHex(unsigned long long octal);

int main() {
    int choice;
    unsigned long long decimal;
    char hex[16];
    unsigned long long binary;
    unsigned long long octal;

    while (1) {
        printf("\n----- Conversion Menu -----\n");
        printf("1. Decimal to Binary\n");
        printf("2. Decimal to Hexadecimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Binary to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Binary to Octal\n");
        printf("7. Hexadecimal to Binary\n");
        printf("8. Hexadecimal to Decimal\n");
        printf("9. Hexadecimal to Octal\n");
        printf("10. Octal to Binary\n");
        printf("11. Octal to Decimal\n");
        printf("12. Octal to Hexadecimal\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%llu", &decimal);
                decimalToBinary(decimal);
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%llu", &decimal);
                decimalToHex(decimal);
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%llu", &decimal);
                decimalToOctal(decimal);
                break;

            case 4:
                printf("Enter a binary number: ");
                scanf("%llu", &binary);
                binaryToDecimal(binary);
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%llu", &binary);
                binaryToHex(binary);
                break;

            case 6:
                printf("Enter a binary number: ");
                scanf("%llu", &binary);
                binaryToOctal(binary);
                break;

            case 7:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                hexToBinary(hex);
                break;

            case 8:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                hexToDecimal(hex);
                break;

            case 9:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                hexToOctal(hex);
                break;

            case 10:
                printf("Enter an octal number: ");
                scanf("%llu", &octal);
                octalToBinary(octal);
                break;

            case 11:
                printf("Enter an octal number: ");
                scanf("%llu", &octal);
                octalToDecimal(octal);
                break;

            case 12:
                printf("Enter an octal number: ");
                scanf("%llu", &octal);
                octalToHex(octal);
                break;

            case 13:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void decimalToBinary(unsigned long long decimal) {
    unsigned long long binary = 0;
    unsigned long long base = 1;

    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }

    printf("Binary: %llu\n", binary);
}

void decimalToHex(unsigned long long decimal) {
    char hex[16];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;

        if (remainder < 10)
            hex[index++] = remainder + '0';
        else
            hex[index++] = remainder - 10 + 'A';

        decimal /= 16;
    }

    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--)
        printf("%c", hex[i]);

    printf("\n");
}

void decimalToOctal(unsigned long long decimal) {
    unsigned long long octal = 0;
    unsigned long long base = 1;

    while (decimal > 0) {
        octal += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }

    printf("Octal: %llu\n", octal);
}

void binaryToDecimal(unsigned long long binary) {
    unsigned long long decimal = 0;
    unsigned long long base = 1;

    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }

    printf("Decimal: %llu\n", decimal);
}

void binaryToHex(unsigned long long binary) {
    unsigned long long decimal = 0;
    unsigned long long base = 1;

    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }

    decimalToHex(decimal);
}

void binaryToOctal(unsigned long long binary) {
    unsigned long long decimal = 0;
    unsigned long long base = 1;

    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }

    decimalToOctal(decimal);
}

void hexToBinary(char *hex) {
    unsigned long long decimal = strtoull(hex, NULL, 16);
    decimalToBinary(decimal);
}

void hexToDecimal(char *hex) {
    unsigned long long decimal = strtoull(hex, NULL, 16);
    printf("Decimal: %llu\n", decimal);
}

void hexToOctal(char *hex) {
    unsigned long long decimal = strtoull(hex, NULL, 16);
    decimalToOctal(decimal);
}

void octalToBinary(unsigned long long octal) {
    unsigned long long decimal = 0;
    unsigned long long base = 1;

    while (octal > 0) {
        decimal += (octal % 10) * base;
        octal /= 10;
        base *= 8;
    }

    decimalToBinary(decimal);
}

void octalToDecimal(unsigned long long octal) {
    unsigned long long decimal = 0;
    unsigned long long base = 1;

    while (octal > 0) {
        decimal += (octal % 10) * base;
        octal /= 10;
        base *= 8;
    }

    printf("Decimal: %llu\n", decimal);
}

void octalToHex(unsigned long long octal) {
    unsigned long long decimal = 0;
    unsigned long long base = 1;

    while (octal > 0) {
        decimal += (octal % 10) * base;
        octal /= 10;
        base *= 8;
    }

    decimalToHex(decimal);
}
