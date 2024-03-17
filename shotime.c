#include <stdio.h>
#include <time.h>

int main() {
    // Declare variables
    time_t current_time;
    struct tm *local_time;
    char time_str[100];

    // Get the current time
    current_time = time(NULL);

    // Check if getting the current time was successful
    if (current_time == -1) {
        perror("Unable to get current time");
        return 1;
    }

    // Convert the current time to the local time zone
    local_time = localtime(&current_time);

    // Check if the conversion was successful
    if (local_time == NULL) {
        perror("Unable to convert to local time");
        return 1;
    }

    // Format the local time as a string in the desired format
    strftime(time_str, sizeof(time_str), "%A %Y:%m:%d %H:%M:%S %Z", local_time);

    // Print the formatted date, time, day of the week, and local time zone
    printf("%s\n", time_str);

    return 0;
}
