#include <stdio.h>

int main(void)
{
    double guess = 1;
    double delta = 0.1;
    for (int i = 1; i <= 10; i = i+1) {
        while (guess*guess < 2) {
            guess = guess + delta;
        }
        guess = guess - delta;
        delta = delta / 10;
    }
    printf("%.10f", guess);

    return 0;
}
