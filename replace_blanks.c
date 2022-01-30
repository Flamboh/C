#include <stdio.h>

int main(void)
{
    int c, d;


    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        else if (d == ' ')
            ;
        else
            putchar(c);
        d = c;
    }
}
