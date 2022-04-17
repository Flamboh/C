#include <stdio.h>
#include <stdbool.h>

int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // list of how many days are in each month

bool is_leap_year(int year) {
  return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)); // formula for finding if a given year is a leap year
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
  int days_left_in_month;

  while (days_left_to_add > 0) { // runs while there are still days left to add
    days_left_in_month = days_in_month[*mm] - *dd; // calculates how many days are left in the month we started in
    if (*mm == 2 && is_leap_year(*yy)) {
      days_left_in_month++; // if it is february and it is a leap year then one extra day is added
    }
    if (days_left_to_add > days_left_in_month) { // if there are more days to add than there are in the month
      days_left_to_add -= days_left_in_month + 1; // added all days in this month so remove them from days left to add
      *dd = 1; // first day of next month
      if (*mm == 12) {
        *mm = 1; // set to january
        *yy += 1; // if it is december and you overflow it is now january of the next year
      }
      else {
        *mm += 1; // if it is not december just set it to the next month
      }
    }
    else { // when there are less days to add then there are in the month
      *dd += days_left_to_add; // then the day is the same as days left to add
      days_left_to_add = 0; // resets to 0 so the loop ends
    }
  }
}

int main() {

  int mm;
  int dd;
  int yy;
  int days_left_to_add;
  // variables to store input
  printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date:"); // asking for input
  scanf("%i%i%i%i", &mm, &dd, &yy, &days_left_to_add); // getting console input from the user and assigning it to the previously created variables

  add_days_to_date(&mm, &dd, &yy, days_left_to_add); // calls the function with inputs from the user

  printf("%i %i %i\n", mm, dd, yy); // printing the results to the console

}

