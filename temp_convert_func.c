#include <stdio.h>

int convertf(int fahr) // takes in temp in fahrenheit and returns it in celsius
{
    int celsius;

    celsius = 5 * (fahr-32) / 9; // equation for changing fahrenheit to celsius

    return celsius;
}


int convertc(int celsius) // takes in temp in celsius and returns it in fahrenheit
{
    int fahr;

    fahr = (celsius * 9/5) + 32; // equation for changing celsius to fahrenheit

    return fahr;
}


int main(void)
{
    int tempc;
    int tempf;
    char choice;
    // variables for input

    printf("Choose input temperature unit (c or f): ");
    scanf("%c", &choice); // getting user choice
    if (choice == 'c') { // chose celsius
        printf("Temp in celsius: ");
        scanf("%d", &tempc); // gets temp from user in celsius
        printf("Temperature converted to fahrenheit: %d\n", convertc(tempc)); // converts to fahrenheit and prints the output
    }
    else if (choice == 'f') { // chose fahrenheit
        printf("Temp in fahrenheit: ");
        scanf("%d", &tempf); // gets temp from user in fahrenheit
        printf("Temperature converted to celsius: %d\n", convertf(tempf)); // converts to celsius and prints the output

    }
}

