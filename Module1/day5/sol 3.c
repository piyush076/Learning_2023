#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void getTimeDifference(struct Time t1, struct Time t2, struct Time *diff) {
    // Convert both time periods to seconds
    int time1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the absolute difference in seconds
    int difference = (time1 > time2) ? (time1 - time2) : (time2 - time1);

    // Convert the difference back to hours, minutes, and seconds
    diff->hours = difference / 3600;
    difference %= 3600;
    diff->minutes = difference / 60;
    diff->seconds = difference % 60;
}

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter the start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter the end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    getTimeDifference(startTime, endTime, &difference);

    printf("Time difference: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
