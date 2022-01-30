#include <stdio.h>

int convertf(int fahr)
{
    int celsius;

    celsius = 5 * (fahr-32) / 9;

    return celsius;
}


int convertc(int celsius)
{
    int fahr;

    fahr = (celsius * 9/5) + 32;

    return fahr;
}


int main(void)
{
    int tempc;
    int tempf;
    char choice;


    printf("Choose input temperature unit (c or f): ");
    scanf("%c", &choice);
    if (choice == 'c') {
        printf("Temp in celsius: ");
        scanf("%d", &tempc);
        printf("Temperature converted to fahrenheit: %d\n", convertc(tempc));
    }
    else if (choice == 'f') {
        printf("Temp in fahrenheit: ");
        scanf("%d", &tempf);
        printf("Temperature converted to celsius: %d\n", convertf(tempf));

    }
}


/*
int main(void)
{
    int c, tempc, tempf;

    while ((c = getchar() != EOF)) {
        if (c == 'c') {
            scanf("%d", &tempc);
            printf("test %d\n", convertc(tempc));
        }
        else if (c == 'f') {
            scanf("%d", &tempf);
            printf("%d\n", convertf(tempf));

        }
    }
}
*/
