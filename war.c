#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *suits_str[4] = {"S", "H", "D", "C"};
char *faces_str[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
            "10", "J", "Q", "K", "A"};


int main(void)
{
    printf("This is the card game of war. Each card is given by suit-#\n");
    printf("as S-7 for Spade 7.\n");
    printf("Do you want directions ");
    char answer;
    if((answer=getchar()) == 'y'|| answer != 'Y') {
        printf("\nThe computer gives you and it a 'card'. The higher card\n");
        printf("(numerically) wins. The game ends when you choose not to\n");
        printf("continue or when you have finished the pack.\n\n");

    }

    srand(time(0));
    int you_score = 0;
    int computer_score = 0;
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

    for (int i = 0; i < 26; i++) {
        int you_card = deck[i];
        int cp_card = deck[51 - i];
        int you_card_pt = you_card % 13;
        int cp_card_pt = cp_card % 13;
        printf("You: %s-%s  Computer: %s-%s\n", suits_str[you_card / 13], faces_str[you_card_pt], suits_str[cp_card / 13], faces_str[cp_card_pt]);
        if (you_card_pt > cp_card_pt) {
            you_score += 1;
            printf("You win. You have %d and the computer has %d\n\n", you_score, computer_score);
        }
        else if (you_card_pt < cp_card_pt) {
            computer_score +=1;
            printf("The computer wins!!! You have %d and the computer has %d\n\n", you_score, computer_score);

        }
        else {
            printf("Tie. No score change.\n\n");
        }

    }
    printf("\nYou have run out of cards. ");
    printf("Final score: You:%d Computer:%d", you_score, computer_score);

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
