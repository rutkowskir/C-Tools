#include <stdio.h>
#include <time.h>

int main() {
    // Declare a variable to store the current time
    time_t current_time;

    // Get the current time
    current_time = time(NULL);

    // Check if getting the current time was successful
    if (current_time == -1) {
        perror("Unable to get current time");
        return 1;
    }

    // Convert the current time to a string representation
    char *time_str = ctime(&current_time);

    // Print the current date and time
    printf(time_str);

    return 0;
}

