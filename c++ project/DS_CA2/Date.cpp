/**
 * Briefly explain the function of this class.
 *
 * @author 			Your name here
 * @ID 				Your student ID here
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * Date.cpp
 * version 1.0
 */
#include "Date.h"
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/**
 *  Constructs a Date with the given month, day and year.   If the date is
 *  not valid, the entire program will halt with an error message.
 *  @param month is a month, numbered in the range 1...12.
 *  @param day is between 1 and the number of days in the given month.
 *  @param year is the year in question, with no digits omitted.
 *
 *  Grade: 15%
 */
Date::Date(int month, int day, int year)
{
    if (isValidDate(month, day, year))
    {
        Month = month;
        Year = year;
        Day = day;
    }
    else
    {
        exit(1);
    }
}

/**
 *  Constructs a Date object corresponding to the given string.
 *  @param s should be a string of the form "month/day/year" where month must
 *  be one or two digits, day must be one or two digits, and year must be
 *  between 1 and 4 digits.  If s does not match these requirements or is not
 *  a valid date, the program halts with an error message.
 *
 *  Grade: 30%
 */
Date::Date(const string &s)
{
    string str = s;
    vector<string> v;
    for (int i = 0; i < 2; i++)
    {
        v.push_back(str.substr(0, str.find("/")));
        str = str.substr(str.find("/") + 1, str.length());
    }
    v.push_back(str);
    int month = stoi(v[0]);
    int day = stoi(v[1]);
    int year = stoi(v[2]);
    if (isValidDate(month, day, year))
    {
        Month = month;
        Day = day;
        Year = year;
    }
    else
    {
        exit(1);
    }
}

/**
 *  Checks whether the given year is a leap year.
 *  @return true if and only if the input year is a leap year.
 *
 *  Grade: 10%
 */
bool Date::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? true : false);
}

/**
 *  Returns the number of days in a given month.
 *  @param month is a month, numbered in the range 1...12.
 *  @param year is the year in question, with no digits omitted.
 *  @return the number of days in the given month.
 *
 *  Grade: 10%
 */
int Date::daysInMonth(int month, int year)
{
    if (month != 2)
    {
        return data[month - 1];
    }
    else
    {
        int a = isLeapYear(year) ? 29 : 28;
        return a;
    }
}

/**
 *  Checks whether the given date is valid.
 *  @return true if and only if month/day/year constitute a valid date.
 *
 *  Years prior to A.D. 1 are NOT valid.
 *
 *  Grade: 20%
 */
bool Date::isValidDate(int month, int day, int year)
{
    return ((month >= 1 && month <= 12) && year >= 1 && (day <= daysInMonth(month, year) && day > 0) ? true : false);
}

/**
 *  Returns a string representation of this Date in the form month/day/year.
 *  The month, day, and year are expressed in full as integers; for example,
 *  10/17/2010 or 5/11/258.
 *  @return a String representation of this Date.
 *
 *  Grade: 20%
 */
string Date::toString()
{
    stringstream s;
    s << Month; // put month at the end of the string
    s << '/';
    s << Day;
    s << '/';
    s << Year;
    return s.str();
}

/**
 *  Determines whether this Date is before the Date d.
 *  @return true if and only if this Date is before d.
 *
 *  Grade: 10%
 */
bool Date::isBefore(const Date &d)
{
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
 *  Determines whether this Date is after the Date d.
 *  @return true if and only if this Date is after d.
 *
 *  Grade: 10%
 */
bool Date::isAfter(const Date &d)
{
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
 *  Determines whether this Date is equal to the Date d.
 *  @return true if and only if this Date is the same as d.
 *
 *  Grade: 10%
 */
bool Date::isEqual(const Date &d)
{
    return (!isBefore(d) && !isAfter(d)) ? true : false;
}

/**
 *  Returns the number of this Date in the year.
 *  @return a number n in the range 1...366, inclusive, such that this Date
 *  is the nth day of its year.  (366 is only used for December 31 in a leap
 *  year.)
 *
 *  Grade: 15%
 */
int Date::dayInYear()
{
    int sum = 0;
    for (int i = 0; i < Month - 1; i++)
    {
        sum += data[i];
    }
    sum += Day;
    if (isLeapYear(Year) && Month > 2)
        sum += 1;
    return sum; // replace this line with your solution
}

/** Determines the difference in days between d and this Date.  For example,
 *  if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
 *  If this Date occurs before d, the result is negative.
 *  @return the difference in days between d and this Date.
 *
 *  Grade: 10%
 */
int Date::difference(const Date &d){
    Date temp(d.Month,d.Day,d.Year);
    int sum = 0;
    if (Year == temp.Year){
        return (dayInYear() - temp.dayInYear());
    }
    else if (isAfter(temp)){
        sum = (leap(temp.Year) - temp.dayInYear()) + dayInYear();
        for (int i = temp.Year + 1; i < Year; i++){
            sum += leap(i);
        }
        return sum;  
    }
    else{
        sum = (leap(Year) - dayInYear()) + temp.dayInYear();
        for (int i = Year + 1; i < temp.Year; i++){
            sum += leap(i);
        }
        return -(sum);  
    } 
    
}

int Date::leap(int year){
    return isLeapYear(year) ? 366 : 365;
}

int main()
{
    cout << "\nTesting constructors->";
    Date* d1 = new Date(1, 1, 1);
    cout << "\nDate should be 1/1/1: " << d1->toString();
    delete d1;;
	string s1 = "2/29/2000";
    d1 = new Date(s1);
    cout << "\nDate should be 2/29/2000: " << d1->toString();
    delete d1;
	s1 = "2/29/1904";
    d1 = new Date(s1);
    cout << "\nDate should be 2/29/1904: " << d1->toString();
    delete d1;
    d1 = new Date(12, 31, 1975);
    cout << "\nDate should be 12/31/1975: " << d1->toString();
	string s2 = "1/1/1976";
    Date* d2 = new Date(s2);
    cout << "\nDate should be 1/1/1976: " << d2->toString();
	string s3 = "1/2/1976";
    Date* d3 = new Date(s3);
    cout << "\nDate should be 1/2/1976: " << d3->toString();

    string s4 = "2/27/1977";
	Date* d4 = new Date(s4);
	string s5 = "8/31/2110";
    Date* d5 = new Date(s5);
    cout << "\nTesting before, after and equal->";
    cout << "\n" << d2->toString() << " after " << d1->toString() << " should be true: " << d2->isAfter(*d1);
    cout << "\n" << d3->toString() << " after " << d2->toString() << " should be true: " << d3->isAfter(*d2);
    cout << "\n" << d1->toString() << " after " << d1->toString() << " should be false: " << d1->isAfter(*d1);
    cout << "\n" << d1->toString() << " after " << d2->toString() << " should be false: " << d1->isAfter(*d2);
    cout << "\n" << d2->toString() << " after " << d3->toString() << " should be false: " << d2->isAfter(*d3);

    cout << "\n" << d1->toString() << " before " << d2->toString() << " should be true: " << d1->isBefore(*d2);
    cout << "\n" << d2->toString() << " before " << d3->toString() << " should be true: " << d2->isBefore(*d3);
    cout << "\n" << d1->toString() << " before " << d1->toString() << " should be false: " << d1->isBefore(*d1);
    cout << "\n" << d2->toString() << " before " << d1->toString() << " should be false: " << d2->isBefore(*d1);
    cout << "\n" << d3->toString() << " before " << d2->toString() << " should be false: " << d3->isBefore(*d2);
                       
    cout << "\n" << d2->toString() << " equal " << d3->toString() << " should be false: " << d2->isEqual(*d3);
    cout << "\n" << d5->toString() << " equal " << d5->toString() << " should be true: " << d5->isEqual(*d5);
    cout << "\n" << d1->toString() << " equal " << d4->toString() << " should be false: " << d1->isEqual(*d4);

    cout << "\nTesting difference->";
    cout << "\n" << d1->toString() << " - " << d1->toString() << " should be 0: " << d1->difference(*d1);
    cout << "\n" << d2->toString() << " - " << d1->toString() << " should be 1: " << d2->difference(*d1);
    cout << "\n" << d3->toString() << " - " << d1->toString() << " should be 2: " << d3->difference(*d1);
    cout << "\n" << d3->toString() << " - " << d4->toString() << " should be -422: " << d3->difference(*d4);
    cout << "\n" << d5->toString() << " - " << d4->toString() << " should be 48762: " << d5->difference(*d4);
}