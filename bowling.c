#include <stdio.h>
#include <stdlib.h> // Standard Library. Includes things like random number generation
#include <time.h> // Anything to do with dates or time.
#include <string.h> // For manipulating strings
#include <ctype.h> // for reading the types of variables or changing them

// this is a comment, you can tell by the green color and the two slashes at the start

struct Player {
    char* name;
    int rolls[21];
    int roll_i;
};

int sum(int* list, int list_size) {
    int sum = 0;
    for (int i = 0; i < list_size; i++) {
        sum += list[i];
    }
    return sum;
}

void simulateRoll(int* pins) {
    for (int i = 0; i < 20; i++) {
        int x = rand() % 15;
        if (x < 10) {
            pins[x] = 1;
        }
    }
}

int calculateScore(int* rolls) {
    int score = 0;
    int frame = 1;
    int b = 1;
    for (int i = 0; i < 21; i++) {
        int pins = rolls[i];
        score += pins;
        if (b == 1) {
            if (pins == 10) {
                score += rolls[i+1] + rolls[i+2];
                frame++;
            }
            else {
                b = 2;
            }
        }
        else {
            if ((rolls[i-1] + rolls[i+1]) == 10) {
                score += rolls[i+1];
            }
            b = 1;
            frame++;
        }
        if (frame > 10) {
            break;
        }
    }
    return score;
}

void showPins(int* pins) {
    int pins_iter = 0;
    printf("\n");
    for (int row = 0; row < 4; row++) {
        for (int i = 0; i < row; i++) {
            putchar(' ');
        }
        for (int i = 0; i < 4 - row; i++) {
            int pin_value = pins[pins_iter];
            if (pin_value) {
                printf("O ");
            }
            else {
                printf("+ ");
            }
            pins_iter++;
        }
        putchar('\n');
    }
}

int main(void)
{
    srand(time(0));
    rand();
    printf("                                      Bowl\n");
    printf("\nWelcome to the alley.\n");
    printf("Bring your friends.");
    printf("Okay let's first get acquainted.\n\n");

    while (1) {
        printf("The instructions (Y/N)? ");
        char a = '\0';
        char line[80];
        char response[1];
        fgets(line, 80, stdin);
        sscanf(line, "%s", response);
        if (response[0] == 'y' || response[0] == 'Y') {
            printf("The game of bowling takes mind and skill. During the game\n");
            printf("the computer will keep score. You may compete with\n");
            printf("other players[up to four]. You will be playing ten frames.\n");
            printf("On the pin diagram 'O' means the pin is down...'+' means the\n");
            printf("pin is standing. After the game the computer will show your\n");
            printf("scores.\n");
        }
        int num_players;
        printf("First of all... How many are playing? ");
        fgets(line, 80, stdin);
        sscanf(line, "%d", &num_players);
        printf("Very good...\n");

        struct Player players[num_players];

        for (int i = 0; i < num_players; i++) {
            char name[40];
            printf("Enter name for player %i: ", i + 1);
            fgets(line, 80, stdin);
            sscanf(line, "%s", &name);
            players[i].name = strdup(name);
            players[i].roll_i = 0;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < num_players; j++) {
                int extra = 0;
                int prev_score = 0;
                int pins[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                for (int ball = 0; ball < 2; ball++) {
                    simulateRoll(pins);
                    int score = sum(pins, sizeof(pins)/sizeof(pins[0]));
                    showPins(pins);
                    int pin_count = score - prev_score;

                    int roll_i = players[j].roll_i;
                    players[j].rolls[roll_i] = pin_count;
                    players[j].roll_i += 1;
                    printf("%d for %s\n", pin_count, players[j].name);
                    if (score - prev_score == 0) {
                        printf("GUTTER!!!\n");
                    }
                    if (ball == 0) {
                        if (score == 10) {
                            printf("STRIKE!!!\n");
                            extra = 2;
                            break;
                        }
                        else {
                            printf("next roll %s\n", players[j].name);
                        }
                    }
                    else {
                        if (score == 10) {
                            printf("SPARE!\n");
                            extra = 1;
                        }
                    }
                    prev_score = score;
                }
                if (i == 9 && extra > 0) {
                    printf("Extra rolls for %s\n", players[j].name);
                    for (int l = 0; l < 10; l++) {
                        pins[l] = 0;
                    }
                    int score = 0;
                    for (int l = 0; l < extra; l++) {
                        if (score == 10); {
                            for (int p = 0; p < 10; p++) {
                                pins[p] = 0;
                            }
                        }
                        simulateRoll(pins);
                        score = sum(pins, sizeof(pins)/sizeof(pins[0]));
                    int roll_i = players[j].roll_i;
                    players[j].rolls[roll_i] = score;
                    players[j].roll_i += 1;
                    }

                }
            }
        }

        for (int player_i = 0; player_i < num_players; player_i++) {
            int player_score = calculateScore(players[player_i].rolls);
            printf("%s: total: %d\n", players[player_i].name, player_score);
        }

        printf("Do you want another game? ");
        fgets(line, 80, stdin);
        sscanf(line, "%s", response);
        if (response[0] == 'Y' || response[0] == 'y') {
            continue;
        }
        break;
    }
}
