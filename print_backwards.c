#include <stdio.h>
#define MAXLINE 1000 // max input line size

int findline(char line[], int maxline);

int main(void)
{
    int len; // current line length
    char line[MAXLINE]; // current line

    while (( len = findline(line, MAXLINE)) > 0)
    {
        for (int j = len - 2; j >= 0; --j) {
            putchar(line[j]);
        }

        printf("\n");
    }
    return 0;
}

int findline(char s[], int lim)
{
    int c,i,bound_i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < lim-1) {
            s[i] = c;
        }
        bound_i = i;
    }
    if (bound_i > lim)
        bound_i = lim;
    if (c == '\n')
    {
        ++bound_i;
        s[bound_i] = c;
        ++i;
    }
    s[bound_i + 1] = '\0';

    return i;
}
