#include <math.h >
#include <stdio.h>

int main(void) {
    double a, b, c;
    printf("a=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("c=");
    scanf("%lf", &c);

    /* the discriminant is: b² - 4ac */
    double discr;
    discr = b * b - 4 * a * c;

    /* if <0, both roots are complex numbers */
    if (discr < 0) {
        printf("No real roots!\n");
    }
    /* if the discriminant is 0, there is exacty one root */
    if (discr == 0) {
        printf("One real root: %f\n", -b / (2 * a));
    }
    /* if >0, there are two real roots */
    if (discr > 0) {
        printf("Two roots: %f, %f\n",
               (-b + sqrt(discr)) / (2 * a),
               (-b - sqrt(discr)) / (2 * a));
    }

    return 0;
}
