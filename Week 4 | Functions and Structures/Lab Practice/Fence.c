/*Let us define a Point type to store two-dimensional coordinates (x, y)!
 Write the following functions operating on this data type:
dist(): calculates the distance between the two points received (using the Pythagorean theorem)
equal(): checks if two points are equal or not
read(): reads a point from the keyboard and returns it
In the main, define two points, and test all these functions.
When all tests are passed, solve the following task by utilizing the structure and functions defined above:
A farmer wants to surround his land with a wire fence.
Write a program to compute how much fence is required!
The program asks the farmer to enter the coordinates of
the corner points of the fence, calculates the distances,
and sums them up. Repeat these steps as long as the
new coordinates are not equal to the first one
(hence, till we return to the starting point). */




#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct Point {
    double x, y;
} Point;

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

bool equal(Point p1, Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

Point read(void) {
    Point p;
    scanf("%lf%lf", &p.x, &p.y);
    return p;
}

int main(void) {
    /* Reading the starting point, which is the ending point, too */
    printf("Starting point:\n");
    Point start;
    start = read();

    /* Summation */
    double length = 0;
    printf("Further points:\n");
    Point prev;     /* stores the previous point */
    Point current;  /* stores the new point */
    prev = start;
    do {
        current = read();
        length += dist(prev, current);
        prev = current;        /* for the next iteration */
    } while (!equal(current, start));

    /* Print the sum */
    printf("The length of the fence: %f\n", length);

    return 0;
}
