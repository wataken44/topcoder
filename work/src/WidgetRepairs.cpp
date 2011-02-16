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

class WidgetRepairs {
 public:
  int days(vector <int> arrivals, int numPerDay) {
    // -- main code --
    int rest = 0;

    int d = 0;
    TIMES(i, arrivals.size()) {
      rest += arrivals[i];
      if(rest > 0) {
        ++d;
      }
      rest = max(0, rest - numPerDay);
    }

    if(rest > 0) {
      d += ceil(rest * 1.0 / numPerDay);
    }
    
    return d;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
When a widget breaks, it is sent to the widget repair shop, which is capable of repairing at most numPerDay widgets per day.
Given a record of the number of widgets that arrive at the shop each morning, your task is to determine how many days the shop must
operate to repair all the widgets, not counting any days the shop spends entirely idle.



For example, suppose the shop is capable of repairing at most 8 widgets per day, and over a stretch of 5 days, it receives 10, 0, 0, 4, and 20 widgets, respectively.  The shop would operate on days 1 and 2, sit idle on day 3, and operate again on days 4 through 7.  In total, the shop would operate for 6 days to repair all the widgets.



Create a class WidgetRepairs containing a method days that takes a sequence of arrival counts arrivals (of type
vector <int>) and an int numPerDay, and calculates the number of days of operation.


DEFINITION
Class:WidgetRepairs
Method:days
Parameters:vector <int>, int
Returns:int
Method signature:int days(vector <int> arrivals, int numPerDay)


CONSTRAINTS
-arrivals contains between 1 and 20 elements, inclusive.
-Each element of arrivals is between 0 and 100, inclusive.
-numPerDay is between 1 and 50, inclusive.


EXAMPLES

0)
{ 10, 0, 0, 4, 20 }
8

Returns: 6

The example above.

1)
{ 0, 0, 0 }
10

Returns: 0

2)
{ 100, 100 }
10

Returns: 20

3)
{ 27, 0, 0, 0, 0, 9 }
9

Returns: 4

4)
{ 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 }
3

Returns: 15

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10, 0, 0, 4, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 6; verify_case(0, Arg2, days(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 0, 0, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 0; verify_case(1, Arg2, days(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, days(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 27, 0, 0, 0, 0, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 4; verify_case(3, Arg2, days(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 15; verify_case(4, Arg2, days(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  WidgetRepairs test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
