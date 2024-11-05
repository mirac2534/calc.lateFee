#include <stdio.h>


int substractDays(int, int, int, int, int, int);
double calculateLateFee(int);


int main(void)
{


    // Below are for the date that the user borrowed the book
    int dueDay, dueMonth, dueYear;
    // Below are for the date that the user returned the book
    int returnDay, returnMonth, returnYear;
    // Day difference between two dates
    int dayDifference;
    // Late fee will be returned to lateFee variable
    double lateFee;

    printf("enter due date DD MM YY: "); // Enter dates in the following format  12 12 2023
    scanf("%d%d%d", &dueDay, &dueMonth, &dueYear);

    printf("enter return date DD MM YY: ");//Enter dates in the following format 12 5 2023
    scanf("%d%d%d", &returnDay, &returnMonth, &returnYear);

    // Call the substractDays function
    dayDifference = substractDays(dueDay, dueMonth, dueYear, returnDay, returnMonth, returnYear);
    // Call the calculateLateFee function and get the lateFee
    lateFee = calculateLateFee(dayDifference);
    // Display the output
    printf("You are late %d days and your late fee is %.3lf.", dayDifference, lateFee);
    return 0;
}

/*
    substractDays function accepts six parameters:
    the first three are for the day, month, and year of the
    first date, the last three are for the day, month and year
    of the second day.
    Your goal is to substract the second date from the first date
    and find the number of days in between.

    If you call the substractDays(10, 11, 2023, 15, 11, 2023),
    the day difference is 5.

    Suppose a month is 30 days, and a year is 360 days.
    So for call like substractDays(14, 12, 2023, 15, 10, 2025),
    dayDifference => 15 - 14 = 1
    monthDifference => 10 - 12 = -2
    yearDifference => 2025 - 2023 = 2
    total day difference is dayDifference + 30 * monthDifference + 360 * yearDifference,
    which yields to 661.

    IMPORTANT.
    Make sure that the due date is before the return date. In such an occurence, the function
    should return 0. For example, a call such as substractDays(10, 12, 2023, 8, 10, 2023) should
    return 0 because the book is returned before its due date. So, before calculating the day
    difference, check if the due date is indeed before the return date.
*/
int substractDays(int dueDay, int dueMonth, int dueYear, int returnDay, int returnMonth, int returnYear)
{
int dayDifference; 
int mounthDifference; 
int yearDifference;
int sumOfDays;
dayDifference = returnDay - dueDay;
mounthDifference = returnMonth - dueMonth;
yearDifference  =returnYear - dueYear;
sumOfDays = dayDifference + mounthDifference * 30 + yearDifference * 360;

if(sumOfDays > 0) 
{
     return sumOfDays;

}
else // sumOfDays is must be greater than zero
{
    return 0;
}

}

/*
    calculateLateFee function accepte a single paremeter and calculates
    the relevant lateFee with the folloing late fee policy.

    If a book is returned less than or equal to 5 days, the late is 10 liras for each day.
    If a book is returned more than 6 days but within 15 days (15 is included in the range),
     the late fee is 10 liras per day for the first 5 days and 15 liras per day for the remaining days.
    If a book is returned more than 16 days but within 30 days (30 is included in the range),
     the late fee is 15 liras per day for the first 15 days (including)and 20 liras per day for the remaining days.
    If a book is returned more than 30 days, the late is 20 liras for each day with no exception.

    IMPORTANT NOTE:
    daysLate parameter cannot be less than 0. if it is 0, It means that the book returned on time.
*/

double calculateLateFee (int dayslate)
{
int lateFee;
if(dayslate <= 5) // If late days is equal to 5 or less
{
    lateFee = dayslate * 10;
}
else if (dayslate > 5 && dayslate <= 15) // If greater than 5 is equal to less than 15, then
{
    lateFee = 5 * 10 + (dayslate-5) * 15; 
}
else if (dayslate > 16 && dayslate <= 30) // If greater than 16 is equal to less than 30, then
{
    lateFee = 15 * 15 + (dayslate-15) * 20;
}
else // If it is gretaer than 31
{
   lateFee = dayslate * 20;
}
return lateFee;
}
