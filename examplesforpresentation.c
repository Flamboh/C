#include <stdio.h>



int myFunction(char letter) {
    // code goes here
}

int main(void)
{
int number;
char letter = 'L';
number = myFunction(letter);
if (number == 3) {
    letter = 'D';
    number = myFunction(letter);
}
else {
    letter = 'A';
    number = 3;
}
    // code here
}

// int number;
// char letter = 'L';
// number = myFunction(letter);
// if (number == 3) {
//     letter = 'D';
//     number = myFunction(letter);
// }
// else {
//     letter = 'A';
//     number = 3;
// }
#include <stdlib.h> // Standard Library. Includes lots of different things
#include <time.h> // Anything to do with dates or time
#include <string.h> // For manipulating strings
#include <ctype.h> // for reading the types of variables or changing them
