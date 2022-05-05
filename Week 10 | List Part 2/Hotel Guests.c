/*The room occupations of an eight-story hotel (it has 8 floors) are stored in a structure that stores the room number as integer and the name of the guest in a string of at most 50 characters. The rooms are numbered in the usual way: the hundreds give the floor, and the last two digits define the room number on that floor. (6 means room 6 on the ground floor, 715 means room 15 on the top floor.)

Write a function that receives a file name, reads the list of guests from the file into a linked list. The file contains one guest in each line: the room number, then the name of the guest. (You can use "%d %[^\n]" for the format string to read an integer and a string till newline.)
Write a function that receives two parameters: the list of guests and an integer array for the floors. The function should processall entries of the list and count the guests on the different floors (using the floor information extracted from the room number to index the counter array)
Write a function that receives this counter array and returns the number of the most crowded floor (where the most people live currently)!
Complete the program that processes the file reserv.txt, reads a name of a person and decides

if the given person is currently a guest of the hotel
if so then checks if he lives on the most crowded floor. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Guest {
    int room;
    char name[51];
    struct Guest *nxt;
} Guest;

Guest *read(char const *fn) {
    Guest *list = NULL, *new_e, tmp;
    FILE *file;

    file = fopen(fn, "rt");
    while (fscanf(file, "%d %[^\n]", &tmp.room, tmp.name) == 2) {
        new_e = (Guest *) malloc(sizeof(Guest));
        new_e->room = tmp.room;
        strcpy(new_e->name, tmp.name);       /* or *new_e = tmp */
        new_e->nxt = list;
        list = new_e;
    }
    fclose(file);

    return list;
}

void occupancy(Guest *list, int *floors) {
    Guest *iter;
    int i;
    for (i = 0; i < 8; ++i)
        floors[i] = 0;
    for (iter = list; iter != NULL; iter = iter->nxt)
        floors[iter->room / 100] += 1;
}

int most_Guest(int *floors) {
    int i, max = 0;
    for (i = 1; i < 8; ++i)
        if (floors[i] > floors[max])
            max = i;
    return max;
}

Guest *find(Guest *list, char const *name) {
    Guest *iter;
    for (iter = list; iter != NULL; iter = iter->nxt)
        if (strcmp(iter->name, name) == 0)
            break;
    return iter;
}

int main(void) {
    char Guestname[51];
    Guest *list = read("reserv.txt");

    scanf("%[^\n]", Guestname);
    Guest *found = find(list, Guestname);

    if (found == NULL)
        printf("This person is not a guest.\n");
    else {
        int floors[8];
        occupancy(list, floors);
        int crowded = most_Guest(floors);
        if (crowded == found->room / 100)
            printf("The guest lives on the most crowded floor.\n");
        else
            printf("The guest does not live on the most crowded floor.\n");
    }

    while (list != NULL) {
        Guest *temp = list->nxt;
        free(list);
        list = temp;
    }

    return 0;
}
