/*Task: Write a program that calculates how many cans of paint must be purchased to coat every (outer)
surface of a cylindrical container. You must define variables of appropriate type, read in and print out values. */
#include <stdio.h>
int main(void) {
    double diameter, height;
    printf("Container paining\n\n");
    printf("Enter height: ");
    scanf("%lf", &height);
    printf("Enter diameter: ");
    scanf("%lf", &diameter);

    double radius = diameter/2;
    double cans = (2*radius*radius*3.14159265 + height*2*radius*3.14159265) / 2;

    printf("\nNumber of cans to buy: %f\n", cans);

    return 0;
}
