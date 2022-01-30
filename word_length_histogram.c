#include <stdio.h>

#define IN 1 
#define OUT 0

int main(void)
{
    int c, nc, state;
    int wordlength[12];

    state = OUT;
    nc = 0;
    for (int i = 0; i < 12; ++i)
        wordlength[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0)
                wordlength[nc - 1]++;
            nc = 0;
        }
        else if (state == OUT) {
            state = IN;
            ++nc;
        }
        else if (state == IN) {
            ++nc;
        }
    }
    for (int i = 0; i < 12; ++i) {
        printf("%2d: ", i + 1);
        for (int j = 0; j < wordlength[i]; ++j)
            putchar('=');
        putchar('\n');
    }
}