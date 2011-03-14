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

class HourGlass {
 public:
  vector <int> measurable(int glass1, int glass2) {
    // -- main code --

    int mg = max(glass1, glass2);
    vector< int > m(mg*10+1,0);
    vector< int > g(mg*10+1,0);

    UPTO(i, 1, 10) {
      m[glass1*i] = abs(glass2-glass1);
      g[glass1*i] = 1;
      m[glass2*i] = abs(glass2-glass1);
      g[glass1*i] = 2;
    }

    TIMES(i, m.size()) {
      if(m[i] != 0) {
        m[i + m[i]] = 
      }
    }

    vector<int> r;

    TIMES(i, 10) {
      r.push_back(m[i]);
    }
    return r;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Before mechanical clocks were common, people used hourglasses to measure time. An hourglass has two sections connected with a thin passage, where sand trickles through. If all the sand is at the bottom section, you may flip the glass and the sand will start trickling from the top section to the bottom section. After some time (the duration of that specific hourglass) all sand will have reached the bottom section again.

Having only one hourglass limits you to measuring times that are multiples of the duration of the hourglass, but with two hourglasses, one can measure many more times. For instance, if one hourglass has duration 5 minutes and the other 7 minutes, you can measure 9 minutes by the following procedure (at time 0, both hourglasses have all their sand at the bottom): Flip both hourglasses at time 0; after 5 minutes turn the 5-minute glass; after another 2 minutes (when the 7-minute glass is done) turn the 5 minute glass again, which will then run for 2 minutes, thus totalling 9 minutes.

Given the duration of the two hourglasses, calculate the 10 shortest time periods you can measure with these two hourglasses using only the following rules:


At time 0, both hourglasses have all their sand in one side.
An hourglass may only be flipped at time 0, or precisely when one of the hourglasses have run out of sand.
Measurable times include all times when an hourglass has just run out of sand.


Create a class HourGlass containing the method measurable taking an int glass1 and an int glass2, the duration of the hourglasses, and returns a vector <int> containing the 10 shortest positive measurable times. The return value should contain no duplicates and the times should be sorted in ascending order.


DEFINITION
Class:HourGlass
Method:measurable
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> measurable(int glass1, int glass2)


NOTES
-You may not turn an hourglass on its side.


CONSTRAINTS
-glass1 will be between 1 and 50, inclusive.
-glass2 will be between 1 and 50, inclusive.


EXAMPLES

0)
5
7

Returns: { 5,  7,  9,  10,  11,  12,  13,  14,  15,  16 }


5, 7, 10, 14 and 15 can of course be measured since these times are just multiples of single hourglasses, and 12 is the sum of the two hourglasses, so it's also easy to measure.


9, 11 and 13 can be measured according to the following scheme:


Time   Sand    Action         Sand
0      0  0    Flip both      7  5
5      2  0    Flip 5-min     2  5
7      0  3    Flip both      7  2
9      5  0    Flip both      2  5
11     0  3    Flip both      7  2
13     5  0



1)
13
5

Returns: { 5,  10,  13,  15,  16,  17,  18,  19,  20,  21 }

2)
23
23

Returns: { 23,  46,  69,  92,  115,  138,  161,  184,  207,  230 }


Since the hourglasses are identical, it's not possible to measure times other than those that are multiples of the duration of the hourglasses.



3)
24
30

Returns: { 24,  30,  36,  42,  48,  54,  60,  66,  72,  78 }

4)
1
50

Returns: { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 7; int Arr2[] = { 5,  7,  9,  10,  11,  12,  13,  14,  15,  16 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, measurable(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 5; int Arr2[] = { 5,  10,  13,  15,  16,  17,  18,  19,  20,  21 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, measurable(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 23; int Arr2[] = { 23,  46,  69,  92,  115,  138,  161,  184,  207,  230 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, measurable(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 24; int Arg1 = 30; int Arr2[] = { 24,  30,  36,  42,  48,  54,  60,  66,  72,  78 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, measurable(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 50; int Arr2[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, measurable(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  HourGlass test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
