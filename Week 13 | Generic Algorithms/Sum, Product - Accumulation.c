/*Write a function that takes two integer parameters (a and b), and sums up the numbers in the interval (including a-t és b-t is). */


int sumup(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i += 1)
        sum = sum + i;

    return sum;
}

int accumulate(int a, int b, int (*accum)(int, int), int init) {
   int acc = init;
   for (int i = a; i <= b; i += 1)
      acc = accum(acc, i);

   return acc;
}

int add(int a, int b) {
    return a + b;
}

int multiple(int a, int b) {
    return a * b;
}

int main(void) {
    printf("Sum from 1 to 6: %d\n", accumulate(1, 6, add, 0));
    printf("Product from 1 to 6: %d\n", accumulate(1, 6, multiple, 1));
}
