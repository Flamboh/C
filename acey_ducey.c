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

void printDollarAmount()
{

}

void printChosenCards()
{

}

int* getCardName(int card_value)
{

}

int getBetAmount()
{   
    int x;
    printf("What is your bet? ");
    scanf("%d", &x);
    return x;
}

int handleBet(int bet_amount)
{
    if (bet_amount > current_cash) {
        printf("Sorry, my friend but you bet too much\n");
        printf("You only have %i dollars to bet\n", current_cash);
        return 0;
    }
    if (bet_amount == 0) {
        printf("CHICKEN!!\n\n");
        
    }
    if (bet_amount < 0) {
        current_cash -= bet_amount;
        return 1;
    }
}

void handleWin(int bet_amount)
{

}

void handleLose(int bet_amount)
{

}

void restartGame()
{

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

        printf(" %i\n", cards[0]);
        printf(" %i\n", cards[1]);
 
        int bet_amount;

        do {
            bet_amount = getBetAmount();
        } while (!handleBet(bet_amount));

        break;
    }
}
