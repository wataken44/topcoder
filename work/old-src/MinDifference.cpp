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

class MinDifference {
 public:
  int closestElements(int A0, int X, int Y, int M, int n) {
    // -- main code --

    vector<int> a(n, 0);
    a[0] = A0;

    FOR(i, 1, n) {
      a[i] = (a[i - 1] * X + Y) % M;
    }

    int d = abs(a[0] - a[1]);
    TIMES(y, n) {
      FOR(x, y+1, n) {
        d = min(d, abs(a[y] - a[x]));
      }
    }
    
    return d;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
	You are given numbers A0, X, Y, M and n. 
	Generate a list A of length n according to the following recurrence relation:
	A[0] = A0
	A[i] = (A[i - 1] * X + Y) MOD M, for 0 < i < n



	Return the minimal absolute difference between any two elements of A.



DEFINITION
Class:MinDifference
Method:closestElements
Parameters:int, int, int, int, int
Returns:int
Method signature:int closestElements(int A0, int X, int Y, int M, int n)


CONSTRAINTS
-A0, X, Y, M will each be between 1 and 10000, inclusive.
-n will be between 2 and 10000, inclusive.


EXAMPLES

0)
3
7
1
101
5

Returns: 6

The elements of the list are {3, 22, 54, 76, 28}. The minimal difference is between elements 22 and 28.

1)
3
9
8
32
8

Returns: 0

All elements are the same.

2)
67
13
17
4003
23

Returns: 14



3)
1
1221
3553
9889
11

Returns: 275



4)
1
1
1
2
10000

Returns: 0



5)
1567
5003
9661
8929
43

Returns: 14

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 1; int Arg3 = 101; int Arg4 = 5; int Arg5 = 6; verify_case(0, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 9; int Arg2 = 8; int Arg3 = 32; int Arg4 = 8; int Arg5 = 0; verify_case(1, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 67; int Arg1 = 13; int Arg2 = 17; int Arg3 = 4003; int Arg4 = 23; int Arg5 = 14; verify_case(2, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1221; int Arg2 = 3553; int Arg3 = 9889; int Arg4 = 11; int Arg5 = 275; verify_case(3, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10000; int Arg5 = 0; verify_case(4, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 1567; int Arg1 = 5003; int Arg2 = 9661; int Arg3 = 8929; int Arg4 = 43; int Arg5 = 14; verify_case(5, Arg5, closestElements(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  MinDifference test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
