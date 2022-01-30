#include <stdio.h>

int main(void)
{
    int c, d;


    while ((c = getchar()) != EOF) {
        if (d == ' ' || d == '\t')
            ;
        else if (c == ' ' || c == '\t')
            putchar('\n');
        else
            putchar(c);
        d = c;
    }
}
