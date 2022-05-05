/*Write a program that stores the following data of students: group number, NEPTUN code, name and average of grades:

2 ABCD12 4.8 Jo King
It means that Jo King is a member of group 2, ABCD12 is the Neptun code and 4.8 is the average of grades. Names are at most 30 characters long. Write the program to read students from file! A sample file for testing: students.txt. Choose one of the data structures below:

Simpler version: build a singly linked list of students.
More difficult version: build a list of lists! The top-level list is the list of groups, then there is a simple list in each top-level node: the list of students in that group.
Test your program by printing the list! Do not forget to release the allocated memory. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* list element for one student  */
typedef struct Student {
    char neptun[6 + 1];      /* neptun code, max 6 */
    char name[30 + 1];       /* name, max 30 */
    double avg;              /* average */
    struct Student *nxt;
} Student;


/* details of a group: a student list */
typedef struct Group {
    int gr_nr;               /* group number */
    Student *st_list;        /* students */
    struct Group *nxt;
} Group;


/* reads lines from file fn.
 * returns the new Group list. */
Group *gr_list_read(const char *fn) {
    FILE *f=fopen(fn,"rt");
    if(f==NULL) return NULL;
    Group *gr_list = NULL; /* the result */
    Student temp;          /* to read one item */
    int gr;

    while (fscanf(f, "%d %s %lf ", &gr,
                 temp.neptun, &temp.avg) == 3) {
        fgets(temp.name,30,f); /*read name*/
        temp.name[strlen(temp.name)-1]='\0';  /* remove newline */
        /* find existing group */
        Group *iter = gr_list;
        while (iter != NULL && iter->gr_nr != gr)
            iter = iter->nxt;
        /* if null, new group needed */
        if (iter == NULL) {
            iter = (Group*) malloc(sizeof(Group));
            iter->gr_nr = gr;
            iter->nxt = gr_list;
            iter->st_list = NULL;
            gr_list = iter; /* at head */
        }
        Student *n_st = (Student*) malloc(sizeof(Student));
        *n_st = temp;        /* copy all data! */
        n_st->nxt = iter->st_list;
        iter->st_list = n_st; /* at head */
    }
    fclose(f);
    return gr_list;
}


/* prints groups and students. */
void gr_list_print(Group *gr_list) {
    Group *gr_iter;         /* groups iterator */
    Student *st_iter;       /* students iterator */

    for (gr_iter = gr_list; gr_iter != NULL; gr_iter = gr_iter->nxt) {
        printf("Group %2d. -- \n", gr_iter->gr_nr);
        for (st_iter = gr_iter->st_list; st_iter != NULL; st_iter = st_iter->nxt)
            printf("%6s %-30s %g\n", st_iter->neptun, st_iter->name, st_iter->avg);
    }
}


void gr_list_destroy(Group *gr_list) {
    while (gr_list != NULL) {
        Group *nxt = gr_list->nxt;     /* save */

        Student *st_list = gr_list->st_list;
        while (st_list != NULL) {
            Student *nxt = st_list->nxt;   /* save */
            free(st_list);
            st_list = nxt;
        }

        free(gr_list);
        gr_list = nxt;
    }
}


int main(void) {
    Group *gr_list = gr_list_read("students.txt");
    gr_list_print(gr_list);
    gr_list_destroy(gr_list);

    return 0;
}
