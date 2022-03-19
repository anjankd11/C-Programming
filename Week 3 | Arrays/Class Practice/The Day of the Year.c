/*Write a program that asks the user to enter a date (year, month, day),
and prints which day it is in the given year (from 1 to 365 or to 366).
Reading the year, too, is necessary, since the leap years also have to be taken into account.
Every fourth year is a leap year, but every one hundredth is not, but every 400th still is. Year 2000 was a leap year. */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    /* the array with the lengths of the months */
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    /* auxiliary variables */
    int which, i;
    bool leapyear;
    /* this is the date for which the day of the year is calculated */
    int year = 2018, month = 9, day = 21;

    /* For the given month the length of the month does not have to be added,
       hence the limit of the loop is i<month. However, the array is indexed
       from 0, hence we have to subtract 1 from the index! If we currently
       consider January, index 0 is taken. */
    which = 0;
    for (int i = 1; i <month; i += 1)
        which += which[i-1];
    /* It is a leap year if the year is divisible by 400 or it is divisible
       by 4 and not by 100. If we have a leap year and the month is beyond
       February, we add +1 extra day. */
    leapyear = year%400==0 || (year%100!=0 && year%4==0);
    if (leapyear && month > 2)
        which += 1;
    /* finally, add the days */
    which += day;

    printf("%4d.%02d.%02d. is the %d th day of the year.\n", year, month, day, which);

    return 0;
}
