/*Write a program to store the parameters of a circle on a 2D plane:
the x and y coordinates of the center point and r, the radius.
All three parameters are real (floating point) numbers.
Define a type to store the parameters of a circle.
Write a function that receives the parameters of two circles as function parameters,
 and returns a whether the two circles overlap or not. (Two circles overlap if the distance
between their center points - computed by the Pythagorean theorem - is less than the sum of their radii.)
Write a function that asks the user to enter the parameters of a circle, creates the circle, and returns it.
Expand the type definition and the functions to a program that reads the data of the two circles,
decides if they overlap, and displays a message accordingly. */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct Circle {
    double x, y, r;
} Circle;

Circle circle_read() {
    Circle c;
    scanf("%lf %lf %lf", &c.x, &c.y, &c.r);
    return c;
}

bool circle_overlap(Circle c1, Circle c2) {
    return sqrt(pow(c1.x-c2.x, 2)+pow(c1.y-c2.y, 2)) < c1.r+c2.r;
}

int main() {
    Circle a, b;
    a = circle_read();
    b = circle_read();
    printf("%s\n", circle_overlap(a, b) ? "They overlap." : "They do not overlap.");
    return 0;
}
