#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *suits_str[4] = {"S", "H", "D", "C"};
char *faces_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
            "10", "J", "Q", "K", "A"};


/*
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
*/

int main(void)
{
    printf("This is the card game of war. Each card is given by suit-#\n");
    printf("as S-7 for Spade 7.\n");
    

    srand(time(0));
    int score_you = 0;
    int score_computer = 0;

    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    for (int i = 0; i < 1000; i++) {
        /* shuffle by swapping cards pseudo-randomly a 1000 times */
        int from = rand() % 52;
        int to = rand() % 52;
        int card = deck[from];
        deck[from] = deck[to];
        deck[to] = card;
    }

// for rounds
// my card is deck[round]
// computer card is deck[52 - round]
// compare cards higher numeric value wins
// increment score of winner
// ask to continue
// repeat if yes end if no
// when rounds over compare scores



//        int card = deck[i];
//        int suit = card / 13;
//        int face = card % 13;
}
