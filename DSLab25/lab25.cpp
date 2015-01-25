#include <iostream>
#include <string>
#include <map>
using namespace std;

class Date {
public:
	Date(string m, int d) :month(m), day(d) {}

 string getM()const{ return month; } // for << overload operator
 int getD()const{return day;} //for << overload operator
 void setD(const int&num){
	 day = day + num; 
 }

 friend istream & operator>>(istream & in, Date &dat){
	 in >> dat.month >> dat.day;
	 return in;
 }

friend ostream & operator<<(ostream & out,  Date &dat) {
	 out << dat.month << "-";
	 out << dat.day << endl;
	 return out;
 }


private:
	string month;//3 letter abbreviation of month, Jan Feb, Mar, etc.  
	//you may assume that the constructor and >> overload are always given valid months
	int day;

};


Date & operator+( Date &left, const int &right) { left.setD(right);
return left;
}
Date & operator+(const int & left,  Date &right) {right.setD(left);
return right; 
}

bool operator==(const Date &left, const Date &right){
	return (left.getD() == right.getD()  && left.getM() == right.getM());
}

bool operator<(const Date &left, const Date &right){
	std::map<string, int> cal; 
	cal["Jan"] = 1;
	cal["Feb"] = 2;
	cal["Mar"] = 3;
	cal["Apr"] = 1;
	cal["May"] = 2;
	cal["Jun"] = 3;
	cal["Jul"] = 1;
	cal["Aug"] = 2;
	cal["Sep"] = 3;
	cal["Oct"] = 1;
	cal["Nov"] = 2;
	cal["Dec"] = 3;
	std::map<string, int>::iterator it1 = cal.find(left.getM() );
	std::map<string, int>::iterator it2 = cal.find(right.getM() );
	
	if (it1 == it2){
		return left.getD() < right.getD();
	}
	return (*it1 > *it2); 

}


bool operator>(const Date &left, const Date &right){return !(left < right) && !(left == right);  }


bool operator!=(const Date &left, const Date &right){return !(left == right); }

bool operator <=(const Date &left, const Date &right){ return !(right < left); }

bool operator >=(const Date & left, const Date &right){ return !(right > left); }

/* You need to implement operator overloads for the above Date class to do comparisons, >>, <<, and + int

The overload << for cout should print  month-day
where month and day are the current values including the - but no spaces or endl.
Eg.
Date t1 ("Oct",17);
cout <<t1;  //should print exactly 6 characters: Oct-17
Date t2 ("May",7);
cout <<t2;  //should print exactly 5 characters: May-7

The overload >> for cin should read one string and one int as the month and day.

To add an integer and a Date treat the integer as a number of days to add to the date.
You may assume the addition will not exceed the number of days in the month.

Two Dates are == if they have the same month and day values

t1 < t2 iff month1 < month2 or (month1==month2 and day1 < day2).  So compare month first, then day.
note months should be compared as their ordinal values, not alphabetical
to accomplish this, set up a map that goes from string to int so that
map of Jan is 1, map of Feb is 2, etc.

You may add additional public methods as needed to Date.  You will also need
to add functions outside the class.

You should implement overloads for all 6 comparisons == != < <= > >=
Only == and < should have any mention of month or day
(as we did inclass the other overloads should use == and < intelligently)
The other overloads must have exactly 1 and only 1 call to either == or <, but not both.
They shouldn't use the other overloaded comparisons.

Extra credit 1:
When adding an int to a date, you handle rolling over to the next month, but not 2 months.
Eg: Jan-20 + 15 should result in Feb-4. You don't have to handle Jan-20 + 50 (which would be 2 months over)
Extra credit 2:
You can add any number of days (rolling many months)
*/

void compare(const Date &lhs, const Date &rhs) {//just saves some space and typing for my tests
	if (lhs < rhs) cout << "less\n";
	else if (lhs == rhs) cout << "equal\n";
	else if (lhs > rhs) cout << "greater\n";
}
//
void compare2(const Date &lhs, const Date &rhs) {//just saves some space and typing for my tests
	if (lhs != rhs) cout << "not equal and  ";
	else cout << "equal and ";

	if (lhs >= rhs) cout << "greater=\n";
	else if (lhs <= rhs) cout << "less=\n";
}
void main() {
	Date current("Dec", 3), previous("Nov", 15), later("Dec", 5), later2("Dec", 5);
	cout << current << endl;  //Dec-03
	cout << later << endl;	  //Dec-5
	cout << previous << endl; //Nov-15
	cout << endl;
	compare(current, later);
	compare(current, previous);
	compare(later, current);
	compare(previous, current);
	cout << endl;

	compare(later, later2);
	compare2(later, later2); //equal and 
	compare2(previous, current);// not equal and less 
	compare2(later, current); // not equal and greater 

	cout << endl;
	cout << endl; 
	current = current + 4;
	cout << current << endl;//Dec-7
	current = 20 + current;
	cout << current << endl;//Dec-27

	cin >> current;
	cout << current << endl;//whatever is typed in above
}