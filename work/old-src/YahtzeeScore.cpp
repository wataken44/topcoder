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
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

// -- utility --
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define FORN(x,n) FOR(x, 0, n)

using namespace std;

class YahtzeeScore {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// This task is about the scoring in the first phase of the die-game Yahtzee, where five dice are used. The score is determined by the values on the upward die faces after a roll. The player gets to choose a value, and all dice that show the chosen value are considered active. The score is simply the sum of values on active dice.

Say, for instance, that a player ends up with the die faces showing 2, 2, 3, 5 and 4. Choosing the value two makes the dice showing 2 active and yields a score of 2 + 2 = 4, while choosing 5 makes the one die showing 5 active, yielding a score of 5.

Your method will take as input a vector <int> toss, where each element represents the upward face of a die, and return the maximum possible score with these values.



DEFINITION
Class:YahtzeeScore
Method:maxPoints
Parameters:vector <int>
Returns:int
Method signature:int maxPoints(vector <int> toss)


CONSTRAINTS
-toss will contain exactly 5 elements.
-Each element of toss will be between 1 and 6, inclusive.


EXAMPLES

0)
{ 2, 2, 3, 5, 4 }

Returns: 5

The example from the text.

1)
{ 6, 4, 1, 1, 3 }

Returns: 6

Selecting 1 as active yields 1 + 1 = 2, selecting 3 yields 3, selecting 4 yields 4 and selecting 6 yields 6, which is the maximum number of points.

2)
{ 5, 3, 5, 3, 3 }

Returns: 10

*/
// END CUT HERE

 public:
  int maxPoints(vector <int> toss) {
    int result = 0;
    // -- main code --

    FOR(d, 1, 7) {
      int points = 0;
      FORN(i, toss.size()) {
        if(d == toss[i]) {
          points += d;
        }
      }
      result = max(result, points);
    }
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 2, 2, 3, 5, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxPoints(Arg0)); }
	void test_case_1() { int Arr0[] = { 6, 4, 1, 1, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maxPoints(Arg0)); }
	void test_case_2() { int Arr0[] = { 5, 3, 5, 3, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, maxPoints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  YahtzeeScore test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

