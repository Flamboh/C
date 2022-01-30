#include <stdio.h>

#define MAXCHAR 256

int main(void)
{
    int c;
    int nchar[MAXCHAR];

    c = 0;
    for (int i = 0; i < MAXCHAR; ++i) {
        nchar[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        nchar[c]++;
    }
    for (int i = 0; i < MAXCHAR; ++i) {
        if (nchar[i] > 0) {
            printf("%3d: ", i);
            for (int j = 0; j < nchar[i]; ++j)
                putchar('=');
            putchar('\n');
        }
    }  
}