//Compile using: gcc mort.c -lm -o mort

#include <stdio.h>
#include <math.h>

int main() {
    // Ask for input from user
    float loan_amount, interest_rate, monthly_interest_rate, monthly_mortgage_payment;
    int years, number_of_payments;

    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter the annual interest rate (%): ");
    scanf("%f", &interest_rate);
    printf("Enter the number of years for the mortgage: ");
    scanf("%d", &years);

    // Calculate monthly interest rate and number of payments
    monthly_interest_rate = interest_rate / 1200;
    number_of_payments = years * 12;

    // Calculate monthly mortgage payment
    monthly_mortgage_payment = loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, number_of_payments) / (pow(1 + monthly_interest_rate, number_of_payments) - 1);

    // Display monthly mortgage payment
    printf("Monthly Mortgage Payment: $%.2f\n", monthly_mortgage_payment);

    // Calculate and display monthly payment schedule
    float balance = loan_amount;
    float interest, principal;
    printf("Payment Schedule:\n");
    printf("Payment\t   Interest\tPrincipal\tBalance\n");
    for (int payment = 1; payment <= number_of_payments; payment++) {
        interest = balance * monthly_interest_rate;
        principal = monthly_mortgage_payment - interest;
        balance -= principal;
        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", payment, interest, principal, balance);
    }

    return 0;
}
