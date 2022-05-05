/*Draw a new table with modified activities.
The task of the new program is not to count smileys but to
replace all smileys by a „uniform face” character O.
The text read from input must be printed to the output almost unaltered,
except for the replacement of :-( and :-) by an O in the output.
Like Nice :-) one→Nice O one, Sad:-(?→SadO?,
but (-)→(-) remains unaltered, and :--), and :) too should remain unaltered*/

#include <stdio.h>
typedef enum states {base, was_col, was_col_min} states;

int main() {
    int c;
    states st=base;
    while((c=getchar())!=EOF) {
        switch(st) {
        case base:
            if(c==':') st=was_col;
            else putchar(c);
            break;
        case was_col:
            if(c=='-') st=was_col_min;
            else {
                putchar(':');
                if (c!=':') {putchar(c);st=base;}
            }
            break;
        case was_col_min:
            if(c==')'||c=='(') {
                putchar('O');
                st=base;
            } else {
                putchar(':');putchar('-');
                if(c==':') st=was_col;
                else {putchar(c);st=base;}
            }
            break;
        }
    }
    return 0;
}
