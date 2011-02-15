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

class InterestingDigits {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The digits 3 and 9 share an interesting property.  If you take any multiple of 3 and sum its digits, you get another multiple of 3.
For example, 118*3 = 354 and 3+5+4 = 12, which is a multiple of 3.  Similarly, if you take any multiple of 9 and sum its digits, 
you get another multiple of 9.  For example, 75*9 = 675 and 6+7+5 = 18, which is a multiple of 9.  Call any digit for which this 
property holds interesting, except for 0 and 1, for which the property holds trivially.



A digit that is interesting in one base is not necessarily interesting in another base.  For example, 3 is interesting in base 10
but uninteresting in base 5.  Given an int base, your task is to return all the interesting digits for that base
in increasing order.  To determine whether a particular digit is interesting or not, you need not consider all multiples of the digit.  You can be certain that, if
the property holds for all multiples of the digit with fewer than four digits, then it also holds for multiples with more digits.
For example, in base 10, you would not need to consider any multiples greater than 999.



DEFINITION
Class:InterestingDigits
Method:digits
Parameters:int
Returns:vector <int>
Method signature:vector <int> digits(int base)


NOTES
-When base is greater than 10, digits may have a numeric value greater than 9.  Because integers are displayed in base 10 by default, do not be alarmed when such digits appear on your screen as more than one decimal digit.  For example, one of the interesting digits in base 16 is 15.


CONSTRAINTS
-base is between 3 and 30, inclusive.


EXAMPLES

0)
10

Returns: { 3,  9 }

All other candidate digits fail for base=10.  For example, 2 and 5 both fail on 100, for which 1+0+0=1.  Similarly, 4 and 8 both fail on 216, for which 2+1+6=9, and 
6 and 7 both fail for 126, for which 1+2+6=9.

1)
3

Returns: { 2 }

2)
9

Returns: { 2,  4,  8 }

3)
26

Returns: { 5,  25 }

4)
30

Returns: { 29 }

*/
// END CUT HERE

 public:
  vector <int> digits(int base) {
    vector <int> result;
    // -- main code --

    FOR(y, 2, base) {
      bool passed = true;
      unsigned long long b = base;
      UPTO(i, 1, y) {
        if((b - 1) % y != 0) passed = false;
        b = (b * base) % y;
      }
      
      if(passed) {
        result.push_back(y);
      }
    }
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = { 3,  9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, digits(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = { 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, digits(Arg0)); }
	void test_case_2() { int Arg0 = 9; int Arr1[] = { 2,  4,  8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, digits(Arg0)); }
	void test_case_3() { int Arg0 = 26; int Arr1[] = { 5,  25 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, digits(Arg0)); }
	void test_case_4() { int Arg0 = 30; int Arr1[] = { 29 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, digits(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  InterestingDigits test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
