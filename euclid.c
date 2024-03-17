#include <stdio.h>
#include <time.h>

// Function to find the GCD using Euclid's Algorithm
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    clock_t start_time, end_time;

    // Input two numbers from the user
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Start measuring time
    start_time = clock();

    // Calculate and display the GCD
    int gcd = findGCD(num1, num2);

    // End measuring time
    end_time = clock();

    // Calculate the processing time in seconds
    double processing_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("The GCD of %d and %d is %d\n", num1, num2, gcd);
    printf("Processing time: %.6f seconds\n", processing_time);

    return 0;
}
