#include <stdio.h>

// takes in temp in fahrenheit and returns it in celsius
int convertf(int fahr)
{
    int celsius;
    // equation for changing fahrenheit to celsius
    celsius = 5 * (fahr-32) / 9;

    return celsius;
}

// takes in temp in celsius and returns it in fahrenheit
int convertc(int celsius)
{
    int fahr;
    // equation for changing celsius to fahrenheit
    fahr = (celsius * 9/5) + 32;

    return fahr;
}

int main(void)
{
    int tempc;
    int tempf;
    char choice;
    // variables for input

    printf("Choose input temperature unit (c or f): ");
    // getting user choice
    scanf("%c", &choice);
    // if chose celsius
    if (choice == 'c') {
        printf("Temp in celsius: ");
        // gets temp from user in celsius
        scanf("%d", &tempc);
        // converts to fahrenheit and prints the output
        printf("Temperature converted to fahrenheit: %d\n", convertc(tempc));
    }
    // if chose fahrenheit
    else if (choice == 'f') {
        printf("Temp in fahrenheit: ");
        // gets temp from user in fahrenheit
        scanf("%d", &tempf);
        // converts to celsius and prints the output
        printf("Temperature converted to celsius: %d\n", convertf(tempf));

    }
}

