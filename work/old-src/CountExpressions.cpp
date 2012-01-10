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

class CountExpressions {
 public:
  int calcExpressions(int x, int y, int val) {
    // -- main code --
    int a = min(x, y);
    int b = max(x, y);
    vector<int> n(4, 0);
    int c = 0;

    n[0] = a; n[1] = a; n[2] = b; n[3] = b;
    c += count(n, val);

    n[0] = a; n[1] = b; n[2] = a; n[3] = b;
    c += count(n, val);

    n[0] = a; n[1] = b; n[2] = b; n[3] = a;
    c += count(n, val);

    n[0] = b; n[1] = a; n[2] = a; n[3] = b;
    c += count(n, val);

    n[0] = b; n[1] = a; n[2] = b; n[3] = a;
    c += count(n, val);
    
    n[0] = b; n[1] = b; n[2] = a; n[3] = a;
    c += count(n, val);

    return c;	
  }

  int count(vector<int>& n, int& val)
  {
    int c = 0;
    if(((n[0] + n[1]) + n[2]) + n[3] == val) ++c;
    if(((n[0] + n[1]) + n[2]) - n[3] == val) ++c;
    if(((n[0] + n[1]) + n[2]) * n[3] == val) ++c;
    if(((n[0] + n[1]) - n[2]) + n[3] == val) ++c;
    if(((n[0] + n[1]) - n[2]) - n[3] == val) ++c;
    if(((n[0] + n[1]) - n[2]) * n[3] == val) ++c;
    if(((n[0] + n[1]) * n[2]) + n[3] == val) ++c;
    if(((n[0] + n[1]) * n[2]) - n[3] == val) ++c;
    if(((n[0] + n[1]) * n[2]) * n[3] == val) ++c;
    if(((n[0] - n[1]) + n[2]) + n[3] == val) ++c;
    if(((n[0] - n[1]) + n[2]) - n[3] == val) ++c;
    if(((n[0] - n[1]) + n[2]) * n[3] == val) ++c;
    if(((n[0] - n[1]) - n[2]) + n[3] == val) ++c;
    if(((n[0] - n[1]) - n[2]) - n[3] == val) ++c;
    if(((n[0] - n[1]) - n[2]) * n[3] == val) ++c;
    if(((n[0] - n[1]) * n[2]) + n[3] == val) ++c;
    if(((n[0] - n[1]) * n[2]) - n[3] == val) ++c;
    if(((n[0] - n[1]) * n[2]) * n[3] == val) ++c;
    if(((n[0] * n[1]) + n[2]) + n[3] == val) ++c;
    if(((n[0] * n[1]) + n[2]) - n[3] == val) ++c;
    if(((n[0] * n[1]) + n[2]) * n[3] == val) ++c;
    if(((n[0] * n[1]) - n[2]) + n[3] == val) ++c;
    if(((n[0] * n[1]) - n[2]) - n[3] == val) ++c;
    if(((n[0] * n[1]) - n[2]) * n[3] == val) ++c;
    if(((n[0] * n[1]) * n[2]) + n[3] == val) ++c;
    if(((n[0] * n[1]) * n[2]) - n[3] == val) ++c;
    if(((n[0] * n[1]) * n[2]) * n[3] == val) ++c;
    return c;
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
	You are helping your brother with his homework assignment.  His teacher gave him two distinct numbers x 
	and y, and asked him to use those numbers to form as many different expressions as possible.  
	Each expression must satisfy all of the following rules:

	
		The only allowed operators are '+', '-' and '*'.
	
	
		x and y must each appear exactly twice.  No other numbers are allowed.
	
	
		The result of the expression must be equal to val.
	




	In other words, each expression can be written in the form "a op1 b op2 c op3 d", where each of op1, op2 and op3 
	is '+', '-' or '*', and among the numbers a, b, c and d, exactly two are equal to x and the other two are 
	equal to y.  Please note that the unary minus is not allowed (see example 0).  Expressions are calculated from 
	left to right, and there is no operator precedence.  For example, to calculate the result of 
	"2 + 2 * 3 + 3", you would first calculate 2 + 2, then multiply the result by 3, and then add 3 to get 15.



	Return the total number of different expressions that can be formed.  Two expressions are considered 
	different if their string notations (as described in the previous paragraph) are different.  For example, 
	the expressions "2 + 3 - 2 - 3", "2 - 2 + 3 - 3" and "2 - 3 - 2 + 3" are all different.



DEFINITION
Class:CountExpressions
Method:calcExpressions
Parameters:int, int, int
Returns:int
Method signature:int calcExpressions(int x, int y, int val)


CONSTRAINTS
-x and y will each be between -100 and 100, inclusive.
-x and y will be different.
-val will be between -100000000 and 100000000, inclusive.


EXAMPLES

0)
7
8
16

Returns: 9

The possible expressions are:
8 + 8 + 7 - 7
8 + 7 + 8 - 7
7 + 8 + 8 - 7
8 + 8 - 7 + 7
8 + 7 - 7 + 8
7 + 8 - 7 + 8
8 - 7 + 8 + 7
8 - 7 + 7 + 8
7 - 7 + 8 + 8

Please note that the unary minus is not allowed, so "-7 + 7 + 8 + 8" is not a valid expression.

1)
3
5
7

Returns: 5

The possible expressions are:
3 * 5 - 3 - 5
5 * 3 - 3 - 5
3 * 5 - 5 - 3
5 * 3 - 5 - 3
5 - 3 * 5 - 3

2)
99
100
98010000

Returns: 6

3)
-99
42
-1764

Returns: 2

-99 - (-99) - 42 * 42
-99 - 42 - (-99) * 42


4)
100
-100
-100000000

Returns: 0

There are no valid expressions.

5)
1
2
5

Returns: 17



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 16; int Arg3 = 9; verify_case(0, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 7; int Arg3 = 5; verify_case(1, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 98010000; int Arg3 = 6; verify_case(2, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = -99; int Arg1 = 42; int Arg2 = -1764; int Arg3 = 2; verify_case(3, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = -100; int Arg2 = -100000000; int Arg3 = 0; verify_case(4, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 5; int Arg3 = 17; verify_case(5, Arg3, calcExpressions(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CountExpressions test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
