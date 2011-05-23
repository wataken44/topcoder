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

class TheTicketsDivOne {
 public:
  vector<vector< double > > dp;
  
  double find(int n, int m) {
    // -- main code --

    dp =  vector<vector< double > >(n+1, vector<double>(n+1,-1));
    dp[1][1] = 1.0;
    dp[0][0] = 1.0;
    
    return go(n, m);
  }

  double go(int n, int m) {
    if(dp[n][m] >= 0) {
      return dp[n][m];
    }

    if(m == n) {
      double p = pow(0.5, n - 1);
      // double pp = 1.0 / 6.0 * p / (1 - p / 2);
      // cerr << p << " " << pp << endl;
      double q = 0.5 * go(n-1, m-1);
      dp[n][m] = q;
      TIMES(i, 100) dp[n][m] += 0.5 * q * pow(p / 2, i + 1);
      return dp[n][m];
    }
    
    if(m == 1) {
      dp[n][m] = 1.0 / 6.0 + 0.5 * go(n, n);
    }else {
      dp[n][m] = 0.5 * go(n, m - 1) + 1.0 / 3.0 * go(n - 1, m - 1);
    }

    return dp[n][m];
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John has two tickets for the basketball game - one for himself and one for a friend.
However, he has n friends who want to go with him.
He decides to use the following strategy to choose one of them.
First, he tells his friends to form a straight single file line.
Then, he repeats the following step until he has made a choice.
If there is only one friend in line, John chooses him.
Otherwise, he throws a standard six-sided die.
If the number 4 is on top, he chooses the friend who is currently first in line.
Otherwise, if the number is odd, the first friend in line must move to the end of the line, and if the number is even, the first friend in line must leave the line and go home.

You are given an int m, the 1-based index of a friend in the initial line.
The index of the first friend is 1, and the index of the last friend is n.
Return the probability that the m-th friend in the initial line is ultimately chosen by John.

DEFINITION
Class:TheTicketsDivOne
Method:find
Parameters:int, int
Returns:double
Method signature:double find(int n, int m)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.
-m will be between 1 and n, inclusive.


EXAMPLES

0)
2
1

Returns: 0.4444444444444444

John will throw the dice and thus six outcomes are possible:

1: The first friend will go to the end of the line and John will repeat the action.
2: The first friend will go home and John will choose the second friend.
3: The first friend will go to the end of the line and John will repeat the action.
4: John will choose the first friend.
5: The first friend will go to the end of the line and John will repeat the action.
6: The first friend will go home and John will choose the second friend.



1)
2
2

Returns: 0.5555555555555556

2)
1
1

Returns: 1.0

Only?one?friend?here.

3)
3
2

Returns: 0.31746031746031744

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; double Arg2 = 0.4444444444444444; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.5555555555555556; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 1.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; double Arg2 = 0.31746031746031744; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  TheTicketsDivOne test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
