/*The stops of an underground line are stored in a text file: one stop in each line of the file. The names of stops are at most 50 characters. Write a program that reads the stops of metro lines into linked lists, then decides whether changing from a given line to another given line is possible or not. If so then the program should print the name of the stop where you can change.

Write a function that receives a file name parameter and returns a list of the stops of the metro line (list of strings). (You can use fgets to read the file line by line.)
Write a function that receives two lists and checks if there is a common stop name in them. The function should return the name of the common stop. (What shall the function return if there is no common stop?)
Complete the program that reads the files m2.txt and m3.txt and checks if changing is possible. If so then print the name of the stop otherwise print that it is not possible! Do not forget to release the allocated memory.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stops {
    char name[51];
    struct Stops *nxt;
} Stops;

Stops *read(char const *fn) {
    Stops *list = NULL, *new_e;
    FILE *file;
    char tmp[51];

    file = fopen(fn, "rt");
    while (fscanf(file, " %[^\n]", tmp) == 1) {
        new_e = (Stops *) malloc(sizeof(Stops));
        strcpy(new_e->name, tmp);
        new_e->nxt = list;
        list = new_e;
    }
    fclose(file);

    return list;
}

char* change_at_stop(Stops *line1, Stops *line2) {
    Stops *iter1, *iter2;
    char *found=NULL;
    for (iter1 = line1; found == NULL && iter1 != NULL; iter1 = iter1->nxt)
        for (iter2 = line2; found == NULL && iter2 != NULL; iter2 = iter2->nxt)
            if(strcmp(iter1->name, iter2->name)==0)
                found=iter1->name;
    return found;
}

void destroy(Stops *mx)
{
    while (mx != NULL) {
        Stops *temp = mx->nxt;
        free(mx);
        mx = temp;
    }
}

int main(void) {
    Stops *m2 = read("m2.txt"),
          *m3 = read("m3.txt");

    char *change=change_at_stop(m2,m3);

    if (change == NULL)
        printf("Changing from M2 to M3 is not possible.\n");
    else {
        printf("Changing from M2 to M3 is possible at %s.\n",change);
    }

    destroy(m2);
    destroy(m3);

    return 0;
}
