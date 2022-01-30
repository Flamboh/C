#include <stdio.h>
#define MAXLINE 1000 // max input line size

int etline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len; // current line length
    int max; // max length seen
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // longest line save

    max = 0;
    while (( len = etline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("%d:\n%s", max, longest);
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
        s[bound_i] = c;
        ++i;
        ++bound_i;
    }
    s[bound_i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while (( to[i] = from[i]) != '\0')
    {
        ++i;
    }
}