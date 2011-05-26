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

class AdditionGame {
 public:
  int getMaximumPoints(int A, int B, int C, int N) {
    // -- main code --

    vector<int> arr;
    arr.push_back(A);
    arr.push_back(B);
    arr.push_back(C);

    sort(arr.begin(), arr.end());

    int score = 0;

    TIMES(n, N) {
      score += arr[2];
      if(arr[2] > 0) --arr[2];
      sort(arr.begin(), arr.end());
    }
    
    return score;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel is playing a game called Addition Game.

Three numbers A, B and C are written on a blackboard, and Ciel initially has 0 points. She repeats the following operation exactly N times: She chooses one of the three numbers on the blackboard. Let X be the chosen number. She gains X points, and if X >= 1, the number X on the blackboard becomes X-1. Otherwise, the number does not change.

Return the maximum number of points she can gain if she plays optimally.


DEFINITION
Class:AdditionGame
Method:getMaximumPoints
Parameters:int, int, int, int
Returns:int
Method signature:int getMaximumPoints(int A, int B, int C, int N)


CONSTRAINTS
-A, B and C will each be between 1 and 50, inclusive.
-N will be between 1 and 150, inclusive.


EXAMPLES

0)
3
4
5
3

Returns: 13

The three numbers written on the blackboard are (3, 4, 5).  One possible optimal strategy is as follows:

Ciel chooses 5.  She gains 5 points, and the numbers become (3, 4, 4).
Ciel chooses 4.  She gains 4 points, and the numbers become (3, 3, 4).
Ciel chooses 4.  She gains 4 points, and the numbers become (3, 3, 3).

She gains a total of 5+4+4=13 points.


1)
1
1
1
8

Returns: 3

One optimal strategy is to choose a 1 in each of the first three turns, for a total of 3 points.  The numbers then become (0, 0, 0).  After that, she won't be able to gain any more points.


2)
3
5
48
40

Returns: 1140

The only optimal strategy is to choose the following numbers: 48, 47, 46, ..., 11, 10, 9.


3)
36
36
36
13

Returns: 446



4)
8
2
6
13

Returns: 57



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 5; int Arg3 = 3; int Arg4 = 13; verify_case(0, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 8; int Arg4 = 3; verify_case(1, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 48; int Arg3 = 40; int Arg4 = 1140; verify_case(2, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 36; int Arg1 = 36; int Arg2 = 36; int Arg3 = 13; int Arg4 = 446; verify_case(3, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 6; int Arg3 = 13; int Arg4 = 57; verify_case(4, Arg4, getMaximumPoints(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  AdditionGame test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
