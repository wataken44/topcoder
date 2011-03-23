#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
// debug
#define DUMP(x) std::cout << #x << " = " << x << std::endl;

using namespace std;

class CalendarRecycle {
 public:
  int useAgain(int year) {
    // -- main code --
    bool l = isLeap(year); 

    int d = 0;

    do {
      ++year;
      bool ll = isLeap(year);
      d = (d + (ll ? 2 : 1)) % 7;

      if(d == 0 and l == ll) break;
    }while(true) ;
    
    return year;	
  }

  bool isLeap(const int year) {
    if(year % 4 == 0) {
      if(year % 100 == 0) {
        if(year % 400 == 0) {
          return true;
        }else {
          return false;
        }
      }else {
        return true;
      }
    }else {
      return false;
    }
    
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Jane is visiting your cubicle when she spies the Elvis calendar hanging on your wall.


"That's not right, is it?" she asks rhetorically.


Your Elvis calendar says that September 8 is a Sunday, but it's actually a Monday. Elvis Presley, the King of Rock 'n' Roll, is no liar. It's just that you bought the calendar last year. This is a 2002 calendar, whereas the current year is 2003. The dates no longer match the days of the week! But there will come a year when every date falls on the same day of the week as in 2002, and the King will reign again.


Given an int representing a year between 2002 and 9999, return the closest future year with which it shares a calendar. Jane reminds you that there are 30 days in April, June, September, and November. The remaining months, with the exception of February, have 31 days. February has 29 days in leap years, and 28 days otherwise. Leap years are divisible by four, and not divisible by 100 unless they are also divisible by 400. For example, 2004 and 2400 are leap years, but 2003 and 2100 are not. Jane also points out that there are only 14 possible calendars.


DEFINITION
Class:CalendarRecycle
Method:useAgain
Parameters:int
Returns:int
Method signature:int useAgain(int year)


CONSTRAINTS
-year is between 2002 and 9999, inclusive


EXAMPLES

0)
2002

Returns: 2013

Your 2002 Elvis calendar will be valid again in 2013.
The following table shows the day of the week that September 8th falls on each year from 2002 to 2013.

Year | Day
-----+-----
2002 | Sunday
2003 | Monday
2004 | Wednesday
2005 | Thursday
2006 | Friday
2007 | Saturday
2008 | Monday
2009 | Tuesday
2010 | Wednesday
2011 | Thursday
2012 | Saturday
2013 | Sunday


1)
2013

Returns: 2019

After 2013, your 2002 Elvis calendar will next be valid in 2019.

2)
2008

Returns: 2036

3)
9999

Returns: 10010

4)
2525

Returns: 2531

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2002; int Arg1 = 2013; verify_case(0, Arg1, useAgain(Arg0)); }
	void test_case_1() { int Arg0 = 2013; int Arg1 = 2019; verify_case(1, Arg1, useAgain(Arg0)); }
	void test_case_2() { int Arg0 = 2008; int Arg1 = 2036; verify_case(2, Arg1, useAgain(Arg0)); }
	void test_case_3() { int Arg0 = 9999; int Arg1 = 10010; verify_case(3, Arg1, useAgain(Arg0)); }
	void test_case_4() { int Arg0 = 2525; int Arg1 = 2531; verify_case(4, Arg1, useAgain(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CalendarRecycle test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
