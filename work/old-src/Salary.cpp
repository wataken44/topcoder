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

using namespace std;

class Salary {
 public:
  int howMuch(vector <string> arrival, vector <string> departure, int wage) {
    // -- main code --

    int six_am = 6 * 60 * 60;
    int six_pm = 18 * 60 * 60;

    double salary = 0;

    TIMES(i, arrival.size()) {
      int a = t_to_i(arrival[i]);
      int d = t_to_i(departure[i]);

      salary += (double)(d - a);
      if(d <= six_am or a >= six_pm) {
        salary += 0.5*(double)(d - a);
      }else if( a < six_am and d > six_am and d < six_pm ) {
        salary += 0.5*(double)(six_am - a);
      }else if( a > six_am and a < six_pm and d > six_pm ) {
        salary += 0.5*(double)(d - six_pm); 
      }else if(a < six_am and d > six_pm) {
        salary += 0.5*(double)(six_am - a);
        salary += 0.5*(double)(d - six_pm); 
      }
    }
    
    return floor(wage*salary/(double)(60*60));
  }

  int t_to_i(string& str) {
    istringstream iss(str);
    int h = 0;
    int m = 0;
    int s = 0;
    char colon;
    iss >> h >> colon >> m >> colon >> s;
    return h * 60 * 60 + m * 60 + s;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Often employees at a company time stamp their arrivals and departures, so when the month is over the boss can check how much each employee has worked. Given the time stamps for a single employee during a single day as well as his (or her) hourly wage, calculate how much the employee has earned that day.

The time stamps are given in the format "hh:mm:ss" (quotes for clarity only) where hh is the hour (between 00 and 23 inclusive), mm is the minute (between 00 and 59 inclusive) and ss is the second (between 00 and 59 inclusive). All these numbers have exactly two digits. The arrival time stamps are inclusive, and the departure time stamps are exclusive, so an employee arriving at 09:00:00 one day and departing 17:30:00 the same day has worked exactly 8 hours 30 minutes 0 seconds during that interval.

An employee working during evenings (between 18:00:00 and 23:59:59, inclusive) or nights (between 00:00:00 and 05:59:59, inclusive) gets paid one and a half times as much during that period.

Create a class Salary containing the method howMuch which takes a vector <string>, arrival, and a vector <string>, departure, the arrival and departures times of an employee, respectively, as well an int wage, the hourly wage (in cents). Your method should return an int representing the total amount (in cents) the employee earned during the time he or she worked. The amount should be rounded down to the largest integer less than or equal to the actual amount. Element i in arrival corresponds to element i in departure.

DEFINITION
Class:Salary
Method:howMuch
Parameters:vector <string>, vector <string>, int
Returns:int
Method signature:int howMuch(vector <string> arrival, vector <string> departure, int wage)


CONSTRAINTS
-arrival will contain between 1 and 10 elements, inclusive.
-departure will contain between 1 and 10 elements, inclusive.
-arrival will contain the same number of elements as departure.
-All elements in arrival and departure will be in the form "hh:mm:ss" (quotes for clarity only) satisfying the constraints given above.
-All time stamps will be strictly increasing; that is, arrival[0]<departure[0]<arrival[1]<departure[1] and so on.
-wage will be between 100 and 10000, inclusive.


EXAMPLES

0)
{"08:00:00","13:00:00","19:27:32"}
{"12:00:00","17:00:00","20:48:10"}
1000

Returns: 10015

This employee worked 4 hours, took a break and then worked 4 more hours. Later
he got back to work and worked 1 hour, 20 minutes and 38 seconds overtime.
The salary becomes (4+4)*1000 + (1+20/60+38/3600)*1000*1.5 = 10015.83333 which is
rounded down to 10015.


1)
{"01:05:47","16:48:12"}
{"09:27:30","21:17:59"}
2000

Returns: 33920

2)
{"00:00:00"}
{"23:59:59"}
10000

Returns: 299995

3)
{"10:00:00"}
{"18:00:00"}
10000

Returns: 80000

Notice that 18:00:00 is exclusive, so the last second was not overtime.


4)
{"22:19:46"}
{"23:12:46"}
5320

Returns: 7049

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"08:00:00","13:00:00","19:27:32"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"12:00:00","17:00:00","20:48:10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 10015; verify_case(0, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"01:05:47","16:48:12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"09:27:30","21:17:59"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2000; int Arg3 = 33920; verify_case(1, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"00:00:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"23:59:59"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; int Arg3 = 299995; verify_case(2, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"10:00:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"18:00:00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; int Arg3 = 80000; verify_case(3, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"22:19:46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"23:12:46"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5320; int Arg3 = 7049; verify_case(4, Arg3, howMuch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Salary test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
