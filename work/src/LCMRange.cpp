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

class LCMRange {
 public:
  int lcm(int first, int last) {
    // -- main code --

    int l = first;
    UPTO(i, first + 1, last) {
      l = l * i / gcd(l, i);
    }
    
    return l;
  }

  int gcd(int a, int b)
  {
    if(a == 0) {
      return b;
    }else if(b == 0) {
      return a;
    }else if(a == b) {
      return a;
    }else if(a > b) {
      return gcd(a % b, b);
    }else if(a < b) {
      return gcd(a, b % a);
    }
    return -1;//never reach
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The least common multiple of a group of integers is the smallest number that can be evenly divided by all the integers in the group.  Given two ints, first and last, find the least common multiple of all the numbers between first and last, inclusive.

DEFINITION
Class:LCMRange
Method:lcm
Parameters:int, int
Returns:int
Method signature:int lcm(int first, int last)


CONSTRAINTS
-first will be between 1 and 12, inclusive.
-last will be between first and 12, inclusive.


EXAMPLES

0)
1
5

Returns: 60

The following statements show how 60 can be divided by all numbers from 1 to 5:
1*60 = 60
2*30 = 60
3*20 = 60
4*15 = 60
5*12 = 60

1)
4
5

Returns: 20

Although 60 would be a common multiple for 4 and 5, 20 is the least common multiple.

2)
1
12

Returns: 27720

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 60; verify_case(0, Arg2, lcm(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 20; verify_case(1, Arg2, lcm(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 12; int Arg2 = 27720; verify_case(2, Arg2, lcm(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  LCMRange test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
