/*Write functions that receive a real number parameter, and return:
cube() – its third power,
absolute() – its absolute value (there is a
fabs() library function but do not use it this time)!
Write a program that tabulates the values of a, a3,
|a| and sin(a) using 4 decimal digits after the decimal
point from a = −1 to +1, stepping by 0.1! Include math.h to use sin */

#include <stdio.h>
#include <math.h>

double cube(double x) {
    return x*x*x;
    /* or: return pow(x, 3); */
}

double absolute(double x) {
    if (x < 0)
        return -x;
    else
        return x;
    /* or: return x < 0 ? -x : x; */
}

int main() {
    for (double a = -1; a <= +1; a += 0.1)
        printf("%10.4f %10.4f %10.4f %10.4f\n", a, cube(a), absolute(a), sin(a));

    return 0;
}
