#include <stdio.h>
#include <stdbool.h>

// Days in each month for non-leap years
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Names of months
char *months[] = {
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember",
};

// Function to input year
int inputyear(void) {
    int year;
    printf("PLEASE ENTER THE YEAR: ");
    scanf("%d", &year);
    return year;
}

// Function to determine if a year is a leap year
bool is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[2] = 29; // February has 29 days in a leap year
        return true;
    } else {
        days_in_month[2] = 28; // February has 28 days in a non-leap year
        return false;
    }
}

// Function to determine the day code for January 1st of the given year
int determine_day_code(int year) {
    int day_code;
    int d1, d2, d3;

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    day_code = (year + d1 - d2 + d3) % 7;

    return day_code;
}

// Function to display the calendar
void display_calendar(int year, int day_code) {
    int month, day;

    printf("\nCALENDAR FOR YEAR %d\n", year);

    for (month = 1; month <= 12; month++) {
        printf("%s", months[month]);
        printf("\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print leading spaces for the first row
        for (day = 0; day < day_code; day++) {
    printf("     ");
    }

        // Print all the days in the month
        for (day = 1; day <= days_in_month[month]; day++) {
            printf("%4d ", day);

            // Move to the next line after Saturday
            if ((day + day_code) % 7 == 0) {
                printf("\n");
            }
        }

        // Update day_code for the next month
        day_code = (day_code + days_in_month[month]) % 7;

        printf("\n\n");
    }
}

int main() {
    int year = inputyear();
    is_leap_year(year);
    int day_code = determine_day_code(year);
    display_calendar(year, day_code);
    return 0;
}




