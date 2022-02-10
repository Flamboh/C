#include <stdio.h>
#include <math.h>
#define MAXLINE 1000 // max input line size

int findline(char line[], int maxline);
int htoi(char s[]);

int main(void)
{
    int len; // current line length
    int convertedint;
    char line[MAXLINE]; // current line

    findline(line, MAXLINE);
    convertedint = htoi(line);
    printf("%d", convertedint);
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
    // if (c == '\n')
    // {
    //     ++bound_i;
    //     s[bound_i] = c;
    //     ++i;
    // }
    s[bound_i + 1] = '\0';

    return i;
}

int htoi(char hexcode[])
{
    int i;
    int number = 0;
    for (i = 0; hexcode[i] != '\0'; ++i)
        ;
    // printf("i%d\n", i);
    for (int j = 0; j < i; ++j) {
        int intvalue = 0;
        switch(hexcode[j])
        {
            case 'A':
                intvalue = 10;
                break;
            case 'B':
                intvalue = 11;
                break;
            case 'C':
                intvalue = 12;
                break;
            case 'D':
                intvalue = 13;
                break;
            case 'E':
                intvalue = 14;
                break;
            case 'F':
                intvalue = 15;
                break;
            case 'a':
                intvalue = 10;
                break;
            case 'b':
                intvalue = 11;
                break;
            case 'c':
                intvalue = 12;
                break;
            case 'd':
                intvalue = 13;
                break;
            case 'e':
                intvalue = 14;
                break;
            case 'f':
                intvalue = 15;
                break;
            case '0':
                intvalue = 0;
                break;
            case '1':
                intvalue = 1;
                break;
            case '2':
                intvalue = 2;
                break;
            case '3':
                intvalue = 3;
                break;
            case '4':
                intvalue = 4;
                break;
            case '5':
                intvalue = 5;
                break;
            case '6':
                intvalue = 6;
                break;
            case '7':
                intvalue = 7;
                break;
            case '8':
                intvalue = 8;
                break;
            case '9':
                intvalue = 9;
                break;
        }
        int column = i - j - 1;
        // printf("c%d\nint%d\n", column, intvalue);
        number += (pow(16, column)) * intvalue ;
    }
    return number;
}