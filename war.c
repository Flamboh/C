#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pickRandomCardNumber()
{
    int card = (rand() % 13) + 2;

    return card;
}

char pickRandomCardSuit()
{
    char suit;
    int rand_int;

    rand_int = (rand() % 4) + 1;

    switch(rand_int) {
        case 1 :
            suit = 'S';
            break;
        case 2 :
            suit = 'C';
            break;
        case 3 :
            suit = 'H';
            break;
        case 4 :
            suit = 'D';
            break;
    }
    return suit;
}


int main(void)
{
    printf("This is the card game of war. Each card is given by suit-#\n");
    printf("as S-7 for Spade 7.\n");
    

    srand(time(0));
    printf("%i\n%c\n", pickRandomCardNumber(), pickRandomCardSuit());
}
