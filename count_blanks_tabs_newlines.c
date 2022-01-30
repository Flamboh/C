#include <stdio.h>

int main(void)
{
    int c, n1, n2, n3;

    n1 = 0;
    n2 = 0;
    n3 = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++n1;
        else if (c == '\t')
            ++n2;
        else if (c == '\n')
            ++n3;
    printf("\n %d\n %d\n %d\n", n1, n2, n3);
}
