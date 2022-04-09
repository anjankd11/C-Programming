#include <stdio.h>
#include <stdlib.h>

void calculate(int a, int b, int *sum, int *product) {
    *sum = a + b;
    *product = a * b;
}


int main()
{
   int s, p;
calculate(9, 11, &s, &p);
}
