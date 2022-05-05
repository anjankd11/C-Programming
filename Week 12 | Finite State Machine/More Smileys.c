/*Extend the capabilities of your program a little more. Modify your state machine to treat :) and :( smileys.

Furthermore <3 should be changed to the text "heart". Draw the state transition graph or table for the FSM. */

#include <stdio.h>
typedef enum states {base, was_col, was_col_min, was_less} states;

int main() {
    int c;
    states st=base;
    while((c=getchar())!=EOF) {
        switch(st) {
        case base:
            if(c==':') st=was_col;
            else if(c=='<') st=was_less;
            else putchar(c);
            break;
        case was_col:
            if(c=='-') st=was_col_min;
            else if(c==')'||c=='(') {
                putchar('O');
                st=base;
            } else {
                putchar(':');
                if(c=='<') st=was_less;
                else if (c!=':') {
                    putchar(c);st=base;}
            }
            break;
        case was_col_min:
            if(c==')'||c=='(') {
                putchar('O');
                st=base;
            } else {
                putchar(':');putchar('-');
                if(c==':') st=was_col;
                else if(c=='<') st=was_less;
                else {putchar(c);st=base;}
            }
            break;
        case was_less:
            if(c=='3') {printf("heart"); st=base;}
            else{
                putchar('<');
                if(c==':') st=was_col;
                else if (c!='<'){
                    putchar(c); st=base;}
            }
        }
    }
    return 0;
}

