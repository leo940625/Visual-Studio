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
/** 
 *  Constructs a Date with the given month, day and year.   If the date is
 *  not valid, the entire program will halt with an error message.
 *  @param month is a month, numbered in the range 1...12.
 *  @param day is between 1 and the number of days in the given month.
 *  @param year is the year in question, with no digits omitted.
 *
 *  Grade: 15%
 */
Date::Date(int month, int day, int year) {  
    if (isValidDate(month,day,year)){
        Month = month;
        Year = year;
        Day = day;
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
Date::Date(const string& s) {

}


/** 
 *  Checks whether the given year is a leap year.
 *  @return true if and only if the input year is a leap year.
 *
 *  Grade: 10%
 */
bool Date::isLeapYear(int year) {
    /*if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ){
        return true;
    }
    return false;*/
    return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? true:false); 
}


/** 
 *  Returns the number of days in a given month.
 *  @param month is a month, numbered in the range 1...12.
 *  @param year is the year in question, with no digits omitted.
 *  @return the number of days in the given month.
 *
 *  Grade: 10%
 */
int Date::daysInMonth(int month, int year){
    int big[7] = {1,3,5,7,8,10,12};
    int small[4] = {4,6,9,11};
    if (find(big,big+6,month) != big+6){
        return 31;
    }
    else if (find(small,small+3,month) != small+3){
        return 30;
    }
    else{
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
bool Date::isValidDate(int month, int day, int year) {
    /*if (month >= 1 && month <= 12 && year >= 1 && daysInMonth(month,day))
    {
        return true;
    }
    return false;*/
    return((month >= 1 && month <= 12) && year >= 1 && (day <= daysInMonth(month,year) && day > 0)  ? true:false);                         
}


/** 
 *  Returns a string representation of this Date in the form month/day/year.
 *  The month, day, and year are expressed in full as integers; for example,
 *  10/17/2010 or 5/11/258.
 *  @return a String representation of this Date.
 *
 *  Grade: 20%
 */
string Date::toString() {
return "stuff";                     // replace this line with your solution
}


/** 
 *  Determines whether this Date is before the Date d.
 *  @return true if and only if this Date is before d.
 *
 *  Grade: 10%
 */
bool Date::isBefore(const Date& d) {
return true;                        // replace this line with your solution
}


/** 
 *  Determines whether this Date is after the Date d.
 *  @return true if and only if this Date is after d.
 *
 *  Grade: 10%
 */
bool Date::isAfter(const Date& d) {
return true;                        // replace this line with your solution
}


/** 
 *  Determines whether this Date is equal to the Date d.
 *  @return true if and only if this Date is the same as d.
 *
 *  Grade: 10%
 */
bool Date::isEqual(const Date& d) {
return true;                        // replace this line with your solution
}


/** 
 *  Returns the number of this Date in the year.
 *  @return a number n in the range 1...366, inclusive, such that this Date
 *  is the nth day of its year.  (366 is only used for December 31 in a leap
 *  year.)
 *
 *  Grade: 15%
 */
int Date::dayInYear() {
return 0;                           // replace this line with your solution
}


/** Determines the difference in days between d and this Date.  For example,
 *  if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
 *  If this Date occurs before d, the result is negative.
 *  @return the difference in days between d and this Date.
 *
 *  Grade: 10%
 */
int Date::difference(const Date& d) {
return 0;                           // replace this line with your solution
}

int main(){
    Date bo(6,25,2005);
    cout << bo.daysInMonth(2,2005) << endl;
    if (bo.isValidDate(7,31,2005))
    {
        cout << "good" << '\n';
    }
    else{
        cout << "bad" << '\n';
    }
   
}