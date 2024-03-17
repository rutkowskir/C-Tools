#include <stdio.h>

int main() {
    int hours, minutes, seconds;
    int addHours, addMinutes, addSeconds;
    int daysAdded = 0;
    
    // Input the original time
    printf("Enter the original time (hh:mm:ss): ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    // Input the amount to add
    printf("Enter the amount of hours to add: ");
    scanf("%d", &addHours);
    printf("Enter the amount of minutes to add: ");
    scanf("%d", &addMinutes);
    printf("Enter the amount of seconds to add: ");
    scanf("%d", &addSeconds);

    // Add the time
    seconds += addSeconds;
    minutes += addMinutes;
    hours += addHours;

    // Handle overflow
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        daysAdded = hours / 24;
        hours %= 24;
    }

    // Display the result
    if (daysAdded > 0) {
        printf("+%d %02d:%02d:%02d\n", daysAdded, hours, minutes, seconds);
    } else {
        printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    }

    return 0;
}
