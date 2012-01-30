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

class BritishCoins {
 public:
  vector <int> coins(int pence) {
    // -- main code --

    vector<int> r(3, 0);

    r[0] = pence / 240;
    pence -= r[0] * 240;
    r[1] = pence / 12;
    pence -= r[1] * 12;
    r[2] = pence;
    
    return r;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Prior to 1971, Britain used a system of coins that can be traced back to the time of Charlemagne.  The three main units of 
coinage were the penny, the shilling, and the pound.  There were 12 pennies in a shilling and 20 shillings in a pound.
Given a number pence of pennies, convert this amount into pounds, shillings, and pennies by first converting 
as many pennies as possible into pounds, and then converting as many of the remaining pennies as possible into shillings.
Return a vector <int> of size three containing the number of pounds, the number of shillings, and the number of
pennies, in that order. 


DEFINITION
Class:BritishCoins
Method:coins
Parameters:int
Returns:vector <int>
Method signature:vector <int> coins(int pence)


CONSTRAINTS
-pence is between 0 and 10000, inclusive.


EXAMPLES

0)
533

Returns: { 2,
  4,
  5 }

First, we make 2 pounds, leaving 53 pence.  Then, we make 4 shillings, leaving 5 pence.

1)
0

Returns: { 0,
  0,
  0 }

2)
6

Returns: { 0,
  0,
  6 }

3)
4091

Returns: { 17,
  0,
  11 }

4)
10000

Returns: { 41,
  13,
  4 }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 533; int Arr1[] = { 2,
  4,
  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, coins(Arg0)); }
	void test_case_1() { int Arg0 = 0; int Arr1[] = { 0,
  0,
  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, coins(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = { 0,
  0,
  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, coins(Arg0)); }
	void test_case_3() { int Arg0 = 4091; int Arr1[] = { 17,
  0,
  11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, coins(Arg0)); }
	void test_case_4() { int Arg0 = 10000; int Arr1[] = { 41,
  13,
  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, coins(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  BritishCoins test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
