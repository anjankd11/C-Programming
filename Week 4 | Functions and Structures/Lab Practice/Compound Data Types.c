/*The results of a running competition are shown in the table below.

Index	Name	Birthdate	Rank
0	Am, Erica	1984. 05. 06.	1
1	Abnorm, Al	1982. 09. 30.	3
2	Pri, Mary	1988. 08. 25.	2
3	Duck, Ling	1979. 06. 10.	5
4	Mac, Donald	1992. 04. 05.	4
Find an unfinished program below that contains the appropriate types and the above data in an array. Complete the program, step-by-step, according to the comments.

#include <stdio.h>

typedef struct Date {
    int year, month, day;
} Date;

typedef struct Competitor {
    char name[31];
    Date birth;
    int rank;
} Competitor;

void Date_print(Date d);

void Competitor_print(Competitor c);

int main() {
    Competitor competitors[5] = {
        { "Am, Erica", {1984, 5, 6}, 1 },
        { "Abnorm, Al", {1982, 9, 30}, 3 },
        { "Pri, Mary", {1988, 8, 25}, 2 },
        { "Duck, Ling", {1979, 6, 10}, 5 },
        { "Mac, Donald", {1992, 4, 5}, 4 },
    };

    /* name of competitor 0 - printf %s */
    /* rank of competitor 2 */
    /* birth date of competitor 4, use the given function */
    /* the first letter of the name of competitor 1 (a string is an array of characters) */
    /* is competitor 1 among the best three? yes/no, may use ?: operator */
    /* is competitor 4 faster than competitor 3? */
    /* was competitor 1 born in the same year as competitor 2? */
    /* complete the Competitor_print() function,
     * then print all data of competitor 1 */
    /* at last print all data of all competitors.

    return 0;
}

void Date_print(Date d) {
    /* print year, month and da
}

void Competitor_print(Competitor c) {
    /* print all data of the competitor
}
*/







#include <stdio.h>

typedef struct Date {
    int year, month, day;
} Date;

typedef struct Competitor {
    char name[31];
    Date birth;
    int rank;
} Competitor;

void Date_print(Date d);

void Competitor_print(Competitor c);

int main() {
    Competitor competitors[5] = {
        { "Am, Erica", {1984, 5, 6}, 1 },
        { "Abnorm, Al", {1982, 9, 30}, 3 },
        { "Pri, Mary", {1988, 8, 25}, 2 },
        { "Duck, Ling", {1979, 6, 10}, 5 },
        { "Mac, Donald", {1992, 4, 5}, 4 },
    };

    /* name of competitor 0 - printf %s */
    printf("%s\n", competitors[0].name);
    /* rank of competitor 2 */
    printf("%d\n", competitors[2].rank);
    /* birth date of competitor 4, use the given function */
    Date_print(competitors[4].birth);
    /* the first letter of the name of competitor 1 (a string is an array of characters) */
    printf("%c\n", competitors[1].name[0]);
    /* is competitor 1 among the best three? yes/no, may use ?: operator */
    printf("%s\n", competitors[1].rank <= 3 ? "yes" : "no");
    /* is competitor 4 faster than competitor 3? */
    printf("%s\n", competitors[4].rank < competitors[3].rank ? "yes" : "no");
    /* was competitor 1 born in the same year as competitor 2? */
    printf("%s\n", competitors[1].birth.year == competitors[2].birth.year ? "yes" : "no");
    /* complete the Competitor_print() function,
     * then print all data of competitor 1 */
     Competitor_print(competitors[1]);
    /* at last print all data of all competitors. */
    for (int i = 0; i < 5; ++i) {
        printf("%d. ", i);
        Competitor_print(competitors[i]);
    }

    return 0;
}

void Date_print(Date d) {
    printf("%d.%d.%d.\n", d.year, d.month, d.day);
}

void Competitor_print(Competitor c) {
    printf("%s, %d.%d.%d., %d\n", c.name, c.birth.year, c.birth.month, c.birth.day, c.rank);
}
