#include <stdio.h>
#include <stdlib.h> // Standard Library. Includes things like random number generation
#include <time.h> // Anything to do with dates or time.
#include <string.h> // For manipulating strings
#include <ctype.h> // for reading the types of variables or changing them

// this is a comment, you can tell by the green color and the two slashes at the start

struct Player {
    char* name;
    int rolls[21];
};

int main(void)
{
    printf("Bowl\n");
    printf("\nWelcome to the alley.\n");
    printf("Bring your friends.");
    printf("Okay let's first get acquainted.\n\n");

    while (1) {
        printf("The instructions (Y/N)? ");
        char a;
        scanf("%c", &a);
        if (a == 'y' || a == 'Y') {
            printf("The game of bowling takes mind and skill. During the game\n");
            printf("the computer will keep score. You may compete with\n");
            printf("other players[up to four]. You will be playing ten frames.\n");
            printf("On the pin diagram 'O' means the pin is down...'+' means the\n");
            printf("pin is standing. After the game the computer will show your\n");
            printf("scores.\n");
        }
        int num_players;
        printf("First of all... How many are playing? ");
        scanf("%i", &num_players);
        printf("Very good...\n");

        struct Player players[num_players];

        for (int i = 0; i < num_players; i++) {
            char name[40];
            printf("Enter name for player %i: ", i + 1);
            scanf("%s", name);
            printf("%s\n", name);
            players[i].name = strdup(name);
        }
        printf("name1: %s\nname2: %s\n", players[0].name, players[1].name);
        break;
    }
}
