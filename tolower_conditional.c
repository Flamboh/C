#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF) {
       c = (c >= 'A' && c <= 'Z') ? c + 32 : c;
       putchar(c);
    }
}
/* function declaration
use isupper on char test conditional
(isupper(c)) ? 
ctype.h feels like cheating because it has tolower in it but only way to do it without i can think of is cases for every letter and what to return */
