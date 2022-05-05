#include <stdio.h>

typedef enum states {base, was_col, was_col_min} states;

int main() {
    int c, ct=0;
    states st=base;
    while((c=getchar())!=EOF) {
        switch(st) {
        case base:
            if(c==':') st=was_col;
            break;
        case was_col:
            if(c=='-') st=was_col_min;
            else if (c!=':') st=base;
            break;
        case was_col_min:
            if(c==')'||c=='(') {
                ++ct;
                st=base;
            } else if(c==':') st=was_col;
            else st=base;
            break;
        }
    }
    printf("%d\n",ct);
    return 0;
}
