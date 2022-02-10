#include <stdio.h>

int main(void)
{
    int i, lim, c;
    char s[1000];

    lim = 1000;

//    for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//        s[i] = c;
    for (i=0; i<lim-1; ++i) {
        if ((c=getchar()) != '\n') {
            if (c!=EOF) {
                s[i] = c;
            }
            else
                return 0;
        }
        else
            return 0;        
    }
}
