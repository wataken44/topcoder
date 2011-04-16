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

class FoxPlayingGame {
 public:
  double theMax(int nA, int nB, int paramA, int paramB) {
    // -- main code --

    vector< vector< double > > dp(nB+1, vector<double>(nA+1, -100000.0));
    double sA = paramA / 1000.0;
    double sB = paramB / 1000.0;

    UPTO(a, 0, nA) {
      dp[0][a] = a * sA;
    }
    
    UPTO(b, 1, nB) {
      UPTO(a, 1, nA) {
        dp[b][a] = max(dp[b][a], dp[b][a - 1] + sA);
        UPTO(bb, 0, b) {
          dp[b][a] = max(dp[b][a], dp[0][a] * pow(sB, bb));
        }
      }
    }

    UPTO(b, 0, nB) {
      UPTO(a, 0, nA) {
        cerr << dp[b][a] << " " ;
      }
      cerr << endl;
    }
    cerr << endl;

    return dp[nB][nA];
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel was very bored, so she invented a single player game. The rules of the game are:

You start with 0 points.
You make exactly nA+nB moves.
You have two types of moves available. These are called move A and move B.
Exactly nA times you will make move A. Exactly nB times you will make move B. The moves can be in any order.
The moves affect your score in the following ways:

Each time you make move A, you add scoreA to your score.
Each time you make move B, you multiply your score by scoreB.


You are given int nA, int nB, int paramA and int paramB.  Calculate scoreA and scoreB as follows ("/" denotes exact division, without any rounding):
scoreA = paramA/1000.0
scoreB = paramB/1000.0
Return the maximum possible score after nA+nB moves.

DEFINITION
Class:FoxPlayingGame
Method:theMax
Parameters:int, int, int, int
Returns:double
Method signature:double theMax(int nA, int nB, int paramA, int paramB)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-nA will be between 0 and 50, inclusive.
-nB will be between 0 and 50, inclusive.
-paramA will be between -10000 and 10000, inclusive.
-paramB will be between -2000 and 2000, inclusive.


EXAMPLES

0)
5
4
3000
2000

Returns: 240.0

scoreA = 3000/1000 = 3
scoreB = 2000/1000 = 2
The optimal order of operations is:
(3 + 3 + 3 + 3 + 3) * 2 * 2 * 2 * 2 = 240

1)
3
3
2000
100

Returns: 6.0

scoreA = 2000/1000 = 2
scoreB = 100/1000 = 0.1
Multiplying the score by scoreB decreases its absolute value, so it's better to do all multiplications before additions. Thus, the optimal order of operations is:
0 * 0.1 * 0.1 * 0.1 + 2 + 2 + 2 = 6

2)
4
3
-2000
2000

Returns: -8.0

Multiplying the score by scoreB increases its absolute value, but given that scoreA is negative, the overall score will be negative as well, so it's better to do multiplications before additions again to keep the absolute value small.

3)
5
5
2000
-2000

Returns: 160.0

Multiplication increases the absolute value of the score, but if you do all 5 multiplications after additions, you'll end up with negative score. Thus, the optimal order of operations is:
(0 * (-2) + 2 + 2 + 2 + 2 + 2) * (-2) * (-2) * (-2) * (-2) = 160

4)
50
50
10000
2000

Returns: 5.62949953421312E17



5)
41
34
9876
-1234

Returns: 515323.9982341775



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 3000; int Arg3 = 2000; double Arg4 = 240.0; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2000; int Arg3 = 100; double Arg4 = 6.0; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = -2000; int Arg3 = 2000; double Arg4 = -8.0; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2000; int Arg3 = -2000; double Arg4 = 160.0; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 10000; int Arg3 = 2000; double Arg4 = 5.62949953421312E17; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 41; int Arg1 = 34; int Arg2 = 9876; int Arg3 = -1234; double Arg4 = 515323.9982341775; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  FoxPlayingGame test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
