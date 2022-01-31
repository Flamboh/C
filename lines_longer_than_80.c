#include <stdio.h>
#define MAXLINE 1000 // max input line size

int etline(char line[], int maxline);

int main(void)
{
    int len; // current line length
    char line[MAXLINE]; // current line

    while (( len = etline(line, MAXLINE)) > 0)
    {
        if (len > 80)
            printf("%d:\n%s", len, line);
    }
    return 0;
}

int etline(char s[], int lim)
{
    int c,i,bound_i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < lim-1) {
            s[i] = c;
        }
        bound_i = i;
        // if (i == lim-1)
        //     ++bound_i;
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