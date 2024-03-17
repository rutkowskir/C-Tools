#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a single character to Morse code
const char* charToMorse(char c) {
    switch (toupper(c)) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        case ' ': return " "; // Space character
        default: return ""; // For non-alphanumeric characters, return an empty string
    }
}

int main() {
    char text[256];
    
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);

    printf("Morse code representation:\n");

    for (int i = 0; i < strlen(text); i++) {
        const char* morse = charToMorse(text[i]);
        if (strcmp(morse, "") != 0) {
            printf("%s ", morse);
        } else {
            printf(" "); // Print space for non-alphanumeric characters
        }
    }

    printf("\n\n\n");

    return 0;
}
