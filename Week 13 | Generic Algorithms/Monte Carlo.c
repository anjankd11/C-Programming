/*What is the probability…

to get a 6 when you roll a die? (1/6)
that a random pont in (-1…1; -1…1) is in the circle of unit radius? (π/4)
to get heads or tails when flipping a coin? (1/2)

Let us calculate them using Monte-Carlo method! Carry out the experiment e.g. 1000 times and count how many experiments resulted in the desired outcome (like 6 for rolling the die, or heads for flipping the coin). In the program we can use the random number generator to see what is the result of an action.

Solve two of the problems separately first then compare the code and conclude to a generic solution! */

double die_montecarlo(void) {
    int times = 0;
    for (int i = 0; i < 1000; ++i)
        if (rand() % 6 + 1 == 6)
            times += 1;
    return times / 1000.0; /* not integer division! */
}

bool (*experiment)(void);

double montecarlo(bool (*experiment)(void)) {
    int times = 0;
    for (int i = 0; i < 1000; ++i)
        if (experiment())
            times += 1;
    return times / 1000.0; /* not integer division! */
}


bool unitcircle(void) {
    double x = rand() / (double)RAND_MAX;
    double y = rand() / (double)RAND_MAX;
    return x*x + y*y < 1;
}
