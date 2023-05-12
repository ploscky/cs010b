#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

// isLeapYear private function
bool Date::isLeap(unsigned y) const {
   bool isLeapYear = false;
   if (y % 4 == 0 && y % 100 != 0) {
      isLeapYear = true;
   }
   if (y % 400 == 0) {
      isLeapYear = true;
   }
   return isLeapYear;
} 

// calculates days per month private function
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   unsigned numOfDays;
   if (m == 2) {
      if (isLeap(y)) {
         numOfDays = 29;
      }
      else {
         numOfDays = 28;
      }
   }
   else if (m <= 7 && m % 2 != 0) {
      numOfDays = 31;
   }
   else if (m <= 7 && m % 2 == 0) {
      numOfDays = 30;
   }
   else if (m > 7 && m % 2 == 0) {
      numOfDays = 31;
   }
   else if (m > 7 && m % 2 != 0) {
      numOfDays = 30;
   }
   return numOfDays;
}

//number of named month private function
unsigned Date::number(const string &mn) const {
   unsigned m;
   if (mn == "January" || mn == "january") {m = 1;}

   else if (mn == "February" || mn == "february") {m = 2;}

   else if (mn == "March" || mn == "march") {m = 3;}

   else if (mn == "April" || mn == "april") {m = 4;}

   else if (mn == "May" || mn == "may") {m = 5;}

   else if (mn == "June" || mn == "june") {m = 6;}

   else if (mn == "July" || mn == "july") {m = 7;}

   else if (mn == "August" || mn == "august") {m = 8;}

   else if (mn == "September" || mn == "september") {m = 9;}

   else if (mn == "October" || mn == "october") {m = 10;}

   else if (mn == "November" || mn == "november") {m = 11;}

   else {m = 12;}

   return m;
}

//name of month private function
string Date::name(unsigned m) const {
   string mn;
   if (m == 1) {mn = "January";}

   else if (m == 2) {mn = "February";}

   else if (m == 3) {mn = "March";}

   else if (m == 4) {mn = "April";}

   else if (m == 5) {mn = "May";}

   else if (m == 6) {mn = "June";}

   else if (m == 7) {mn = "July";}

   else if (m == 8) {mn = "August";}

   else if (m == 9) {mn = "September";}

   else if (m == 10) {mn = "October";}

   else if (m == 11) {mn = "November";}

   else if (m == 12) {mn = "December";}

   return mn;
}

//constructor 1
Date::Date() {
   month = 1;
   monthName = "January";
   day = 1;
   year = 2000;
}

//constructor 2
Date::Date(unsigned m, unsigned d, unsigned y) {
   if (m > 12) {
      month = 12;
      year = y;
      day = d;
      if (d > daysPerMonth(m, y)) {
         day = daysPerMonth(m, y);
      }
      else if (d == 0) {
         day = 1;
      }
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
   }
   else if (m <= 12 && m != 0) {
      month = m;
      year = y;
      if (d > daysPerMonth(m, y)) {
         day = daysPerMonth(m, y);
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
      else if (d == 0) {
         day = 1;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
      else {
         day = d;
      }
   }
   else if (m == 0) {
      year = y;
      if (d > daysPerMonth(m, y)) {
         day = daysPerMonth(1, y);
         month = 1;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
      else if (d == 0) {
         day = 1;
         month = 1;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
      else {
         day = d;
      }
   }
}

//constructor 3
Date::Date(const string &mn, unsigned d, unsigned y) {
   vector<string> lowerMonthNames = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
   bool isFound = false;
   string monthName = mn;
   for (unsigned int i = 0; i < monthName.size(); ++i) {
      monthName.at(i) = tolower(monthName.at(i));
   }
   for (unsigned int i = 0; i < lowerMonthNames.size() && !isFound; ++i) {
      if (monthName == lowerMonthNames.at(i)) {
         isFound = true;
      }
   }
   if (!isFound) {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      month = 1;
      day = 1;
      year = 2000;
   }
   else if (isFound) {
      if (d > daysPerMonth(number(mn), y)) {
         day = daysPerMonth(number(mn), y);
         month = number(mn);
         year = y;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
      else if (d == 0) {
         day = 1;
         month = number(mn);
         year = y;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }
      else if (d <= daysPerMonth(number(mn), y)) {
         day = d;
         month = number(mn);
         year = y;
      }
   }
}

//printNumeric function
void Date::printNumeric() const {
   cout << month << '/' << day << '/' << year;
}

//printAlpha function
void Date::printAlpha() const {
   cout << name(month) << ' ' << day << ", " << year;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
