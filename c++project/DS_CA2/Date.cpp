/**
 * class Date contains month, day, and year. It can perform operations like checking if a year is a leap year or
 * calculating the difference between two dates.
 *
 * @author           ��?�� Hsieh Wu Chao
 * @ID               B12505023
 * @Department       Engineering Science and Ocean Engineering
 * @Affiliation      National Taiwan University
 *
 * Date.h9
 * version 1.0
 */

#include "Date.h"
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

/**
 * Constructor that creates a Date object with the given month, day, and year.
 * If the date is not valid, the program will exit with an error.
 * @param month represents the month, in the range of 1...12.
 * @param day represents the day, within the valid range for the given month.
 * @param year represents the full year, with no digits omitted.
 *
 * Grade: 15%
 */
Date::Date(int month, int day, int year)
{
    // Check if the date is valid
    if (isValidDate(month, day, year))
    {
        Month = month;
        Year = year;
        Day = day;
    }
    else
    {
        // Exit the program if the date is invalid
        exit(0);
    }
}

/**
 * Constructor that creates a Date object from a string in the format "month/day/year".
 * If the string is not formatted correctly or represents an invalid date, the program will exit.
 * @param s should be a string formatted as "month/day/year".
 *
 * Grade: 30%
 */
Date::Date(const string &s)
{
    string str = s;
    string v[3];
    // Split the input string by "/" to extract month, day, and year
    for (int i = 0; i < 2; i++)
    {
        v[i] = (str.substr(0, str.find("/")));
        str = str.substr(str.find("/") + 1, str.length());
    }
    v[2] = str;
    // Convert strings to integers
    int month = stoi(v[0]);
    int day = stoi(v[1]);
    int year = stoi(v[2]);
    // Check if the date is valid
    if (v[0].length() < 3 && v[1].length() < 3 && v[2].length() < 5 && isValidDate(month, day, year))
    {
        Month = month;
        Day = day;
        Year = year;
    }
    else
    {
        // Exit the program if the date is invalid
        exit(0);
    }
}

/**
 * Checks whether the given year is a leap year.
 * @param year represents the year to check.
 * @return true if the year is a leap year, false otherwise.
 *
 * Grade: 10%
 */
bool Date::isLeapYear(int year)
{
    // A year is a leap year if divisible by 4 but not 100, or divisible by 400
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? true : false);
}

/**
 * Returns the number of days in a given month.
 * @param month is the month (1-12).
 * @param year is the year, which is used to check for leap years.
 * @return the number of days in the given month.
 *
 * Grade: 10%
 */
int Date::daysInMonth(int month, int year)
{
    // If not February, return the number of days from the data array
    if (month != 2)
    {
        return data[month - 1];
    }
    // For February, return 29 if leap year, otherwise 28
    return isLeapYear(year) ? 29 : 28;
}

/**
 * Checks if the provided month/day/year constitutes a valid date.
 * @param month, day, year represent the date to validate.
 * @return true if the date is valid, false otherwise.
 *
 * Grade: 20%
 */
bool Date::isValidDate(int month, int day, int year)
{
    // Check if the month is valid (1-12), year is positive, and the day is valid for the given month and year
    return ((month >= 1 && month <= 12) && year >= 1 && (day <= daysInMonth(month, year) && day > 0) ? true : false);
}

/**
 * Returns the string representation of the Date in the form "month/day/year".
 * @return a string representing the date.
 *
 * Grade: 20%
 */
string Date::toString()
{
    stringstream s;
    s << Month;  // Add month to string
    s << '/';
    s << Day;    // Add day
    s << '/';
    s << Year;   // Add year
    return s.str();
}

/**
 * Checks if this date is before another Date object.
 * @param d represents the date to compare with.
 * @return true if this date is before d, false otherwise.
 *
 * Grade: 10%
 */
bool Date::isBefore(const Date &d)
{
    // Compare year, then month, then day to determine if this date is earlier
    if (Year < d.Year || (Year == d.Year && Month < d.Month) || (Year == d.Year && Month == d.Month && Day < d.Day))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Checks if this date is after another Date object.
 * @param d represents the date to compare with.
 * @return true if this date is after d, false otherwise.
 *
 * Grade: 10%
 */
bool Date::isAfter(const Date &d)
{
    // Compare year, then month, then day to determine if this date is later
    if (Year > d.Year || (Year == d.Year && Month > d.Month) || (Year == d.Year && Month == d.Month && Day > d.Day))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Checks if this date is equal to another Date object.
 * @param d represents the date to compare with.
 * @return true if both dates are the same, false otherwise.
 *
 * Grade: 10%
 */
bool Date::isEqual(const Date &d)
{
    // The date is equal if it's not before or after the given date
    return (!isBefore(d) && !isAfter(d)) ? true : false;
}

/**
 * Returns the day number of this Date in the current year (1-366).
 * @return the day number of this Date in the year.
 *
 * Grade: 15%
 */
int Date::dayInYear()
{
    int sum = 0;
    // Sum up the days from all previous months
    for (int i = 0; i < Month - 1; i++)
    {
        sum += data[i];
    }
    sum += Day;
    // If it's a leap year and past February, add 1 extra day
    if (isLeapYear(Year) && Month > 2) sum += 1;
    return sum;
}
/**
 * Determines the difference in days between this Date and another Date d.
 * @param d represents the date to compare with.
 * @return the difference in days between this Date and d.
 *
 * Grade: 10%
 */
int Date::difference(const Date &d)
{
    Date temp(d.Month, d.Day, d.Year);
    int sum = 0;

    // If the years are the same, return the difference in days within the year
    if (Year == temp.Year)
    {
        return (dayInYear() - temp.dayInYear());
    }
    // If this date is after the compared date, calculate the total days difference
    else if (isAfter(temp))
    {
        sum = (leap(temp.Year) - temp.dayInYear()) + dayInYear();
        for (int i = temp.Year + 1; i < Year; i++)
        {
            sum += leap(i);
        }
        return sum;
    }
    // If this date is before the compared date, return the negative difference
    else
    {
        sum = (leap(Year) - dayInYear()) + temp.dayInYear();
        for (int i = Year + 1; i < temp.Year; i++)
        {
            sum += leap(i);
        }
        return -(sum);
    }
}

/**
 * Returns the number of days in the year (365 or 366) depending on whether it's a leap year.
 * @param year represents the year to check.
 * @return 366 if leap year, otherwise 365.
 */
int Date::leap(int year)
{
    return isLeapYear(year) ? 366 : 365;
}
