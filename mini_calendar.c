#include <stdio.h>
#include <stdbool.h>

// list of how many days are in each month
int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
  // formula for finding if a given year is a leap year
  return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
  int days_left_in_month;
  // runs while there are still days left to add
  while (days_left_to_add > 0) {
    // calculates how many days are left in the month we started in
    days_left_in_month = days_in_month[*mm] - *dd;
    if (*mm == 2 && is_leap_year(*yy)) {
      // if it is february and it is a leap year then one extra day is added
      days_left_in_month++;
    }
    // if there are more days to add than there are in the month
    if (days_left_to_add > days_left_in_month) {
      // added all days in this month so remove them from days left to add
      days_left_to_add -= days_left_in_month + 1;
      // first day of next month
      *dd = 1;
      if (*mm == 12) {
        // set to january
        *mm = 1;
        // if it is december and you overflow it is now january of the next year
        *yy += 1;
      }
      else {
        // if it is not december just set it to the next month
        *mm += 1;
      }
    }
    // when there are less days to add then there are in the month
    else {
      // then the day is the same as days left to add
      *dd += days_left_to_add;
      // resets to 0 so the loop ends
      days_left_to_add = 0;
    }
  }
}

int main() {
  // variables to store input
  int mm;
  int dd;
  int yy;
  int days_left_to_add;

  // asking for input
  printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date:");
  // getting console input from the user and assigning it to the previously created variables
  scanf("%i%i%i%i", &mm, &dd, &yy, &days_left_to_add);
  // calls the function with inputs from the user
  add_days_to_date(&mm, &dd, &yy, days_left_to_add);

  // printing the results to the console
  printf("%i %i %i\n", mm, dd, yy);
}

