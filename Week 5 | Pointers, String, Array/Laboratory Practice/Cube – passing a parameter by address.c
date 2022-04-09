/*Write a function that receives the length of an edge of a cube as a parameter.
The function should return the volume and the surface area of the cube in two further
parameters passed by address. (The return type of the function is void.) Call this function from
the main to calculate the volume and the surface area of a cube of 2.7 edge length, then print the results in main!*/



#include <stdio.h>
#include <math.h>

void cube(double edge, double *parea, double *pvolume) {
    *parea = pow(edge, 2) * 6;
    *pvolume = pow(edge, 3);
}

int main(void) {
    double a, v;
    cube(2.7, &a, &v);
    printf("V=%f A=%f\n", v, a);

    return 0;
}
