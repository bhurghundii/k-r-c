#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int year, month, day;

    year = 1988;
    month = 2;
    day = 3;

    printf("the day of year is: %d\n", day_of_year(year, month, day));

    month_day(1988, 60, &month, &day);

    printf("m %d and d %d", month, day);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if ((year < 1) || (month < 1 || month > 12) || (day > daytab[leap][month]))
    {
        return -1;
    }

    p = daytab[leap];
    while (month > 0)
    {
        day += *++p; // go through the day tab array, get the value and increment until
        month--;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = ((year % 4 == 0) && year % 100 != 0 || year % 400 == 0);

    // for (i = 1; yearday > daytab[leap][i]; i++){
    //     yearday -= daytab[leap][i];
    // }

    // step 1: get the current day 
    char *p;

    p = daytab[leap];

    i = 1;

    // step 2: keep minusing days until its too small
    while (yearday > *p)
    {
        yearday -= *p;
        i++;
        p++;
    }

    *pmonth = i;
    *pday = yearday;
}