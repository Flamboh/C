#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_CASH 100
#define LOW_CARD 2
#define HIGH_CARD 14

int current_cash;


void initializeGame()
{
    current_cash = START_CASH;
}

void printIntro()
{
    printf("Acey-Ducey is played in the following manner\nThe dealer (computer) deals two cards face up\nYou have an option to bet or not bet depending\non whether or not you feel the card will have\na value between the first two.\nIf you do not want to bet, input a 0\n");
}

int pickRandomCard()
{
    int card = ("%i", (rand() % 13) + 2);

    return card;
}

void pickRandomCards(int* cards)
{
    cards[0] = pickRandomCard();
    do {
        cards[1] = pickRandomCard();
    } while (cards[1] == cards[0]);

    do {
        cards[2] = pickRandomCard();
    } while (cards[2] == cards[0] || cards[2] == cards[1]);
}

void printCardName(int card_value)
{
    if (card_value < 11)
        printf(" %i\n", card_value);
    else {
        switch(card_value) {
            case 11 :
                printf("Jack\n");
                break;
            case 12 :
                printf("Queen\n");
                break;
            case 13 :
                printf("King\n");
                break;
            case 14 :
                printf("Ace\n");
                break;
        }
    }
}

int getBetAmount()
{
    int x;
    printf("What is your bet? ");
    fseek(stdin,0,SEEK_END);
    scanf("%d", &x);
    return x;
}

int main(void)
{
    srand(time(0));
    initializeGame();
    printIntro();
    while (current_cash > 0) {
        printf("You now have %i dollars\n\n", current_cash);
        printf("Here are your next two cards\n");

        int cards[3];

        pickRandomCards((int*) cards);



        if (cards[0] > cards[1]) {
            cards[0] = cards[0] + cards[1];
            cards[1] = cards[0] - cards[1];
            cards[0] = cards[0] - cards[1];
        }

        printCardName(cards[0]);
        printCardName(cards[1]);

        int bet_amount;

        while (1) {
            bet_amount = getBetAmount();
            if (bet_amount > current_cash) {
                printf("Sorry, my friend but you bet too much\n");
                printf("You only have %i dollars to bet\n", current_cash);
                continue;
            }
            else if (bet_amount < 0) {
                printf("Bet must be more than zero\n");
                continue;
            }
            else if (bet_amount == 0) {
                printf("CHICKEN!!\n");
            }
            current_cash -= bet_amount;
            break;
        }

        if (bet_amount > 0) {
            printCardName(cards[2]);
            if (cards[2] < cards[0] || cards[2] > cards[1]) {
                printf("Sorry, you lose\n");
            }
            else {
                printf("You win!!!\n");
                current_cash += (bet_amount * 2);
            }

        }
    }
}
