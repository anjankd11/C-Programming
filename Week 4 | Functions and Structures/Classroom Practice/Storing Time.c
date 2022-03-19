/*Write a C program that stores time points in a structure: hour and minute.
Write the following functions operating on the time points
print_time(i): prints the time point in format hour:minute.
add_to_time(i, p): adds p minutes to time point i and returns
 with the new time point. For instance, 15:15 + 45 = 16:00.
elapsed_time(i1, i2): returns how many minutes have elapsed
between the two time points. For instance, 16:30-15:15 = 75 minutes.
(The order of the parameters is: i1 is the later, i2 is the earlier time point)
subtract_from_time(i, p): subtracts p minutes from time point i and returns with the new time point. For instance, 15:45 - 30 = 15:15. */

#include <stdio.h>

    /* Structure to store time points */
    typedef struct Time {
        int hour, min;
    } Time;

    /* Prints the time point received as a function argument. */
    void print_time(Time i) {
        printf("%02d:%02d", i.hour, i.min);
    }

    /* Adds p minutes to time point i and returns the increased time point.
     * p must be positive. */
    Time add_to_time(Time i, int p) {
        int frommidnight = i.hour * 60 + i.min + p;
        Time newtime;
        newtime.min = frommidnight % 60;
        newtime.hour = frommidnight / 60 % 24;
        return newtime;
    }

    /* Computes how many minutes have elapsed from i1 to i2
     * assuming that i2 is later than i1 and they fall to the same day. */
    int elapsed_time(Time i2, Time i1) {
        return i2.hour*60-i1.hour*60 + i2.min-i1.min;
    }

    /* Subtracts p minutes from time point i and returns the resulting time point
     * assuming that p is positive. */
    Time subtract_from_time(Time i, int p) {
        Time newtime;
        newtime.min = i.min-p;
        newtime.hour = i.hour;
        while (newtime.min < 0) {
            newtime.min += 60;
            newtime.hour -= 1;
        }
        while (newtime.hour < 0)
            newtime.hour += 24;
        return newtime;
    }


    int main(void) {
        Time i1 = { 11, 50 }, i2 = { 12, 10 }, i3 = { 3, 30 };

        printf("i1 = "); print_time(i1); printf("\n");
        printf("i2 = "); print_time(i2); printf("\n");
        printf("i3 = "); print_time(i3); printf("\n");

        printf("i2-i1 = %d\n", elapsed_time(i2, i1));
        printf("i1+195 = "); print_time(add_to_time(i1, 195)); printf("\n");
        printf("i2-195 = "); print_time(subtract_from_time(i2, 195)); printf("\n");
        printf("i3-240 = "); print_time(subtract_from_time(i3, 240)); printf("\n");

        return 0;
    }
