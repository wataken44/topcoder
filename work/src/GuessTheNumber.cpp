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

class GuessTheNumber {
 public:
  int noGuesses(int upper, int answer) {
    // -- main code --
    int c = 0;
    int lower = 1;

    while(true) {
      ++c;
      int x = (lower + upper) / 2;
      if(x == answer) {
        break;
      }else if( x < answer ) {
        lower = x + 1;
      }else if( x > answer ) {
        upper = x - 1;
      }
    }
    return c;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A popular guessing game is "Guess the number", where one person selects a number in a known range, and another person tries to guess that number. After each guess, the first person reveals
whether the guess was correct, too high or too low.

Pretty soon one learns the best strategy, which is to guess the middle number among those not yet ruled out. If there is no single middle number, then there are two numbers to choose from. In that case, we choose the smallest of those numbers.

The algorithm can be described like this:


Init lower and upper bound
Repeat
  x = (lower bound + upper bound)/2  (round down if necessary)
  Make guess x
  If x is too low, set lower bound to x+1
  If x is too high, set upper bound to x-1
Until x is correct


For instance, assume that the lower and upper bound initally are 1 and 9, respectively. The middle number in this range is 5. If this is "too low", the new bounds become 6 and 9. This range contains four numbers, and there is thus no single middle number. The two numbers in the middle are 7 and 8, and the smallest of these is 7, so our next guess then becomes 7.

Create a class GuessTheNumber which contains the method noGuesses which takes an int upper, the initial upper bound of the range (the inital lower bound is always 1), and an int answer, the number selected by the first person. The method should return an int representing the total number of guesses required for the second person to guess the correct number using the method described above.

DEFINITION
Class:GuessTheNumber
Method:noGuesses
Parameters:int, int
Returns:int
Method signature:int noGuesses(int upper, int answer)


CONSTRAINTS
-upper will be between 1 and 1000, inclusive.
-answer will be between 1 and upper, inclusive.


EXAMPLES

0)
9
6

Returns: 3

The first guess will be (1+9)/2=5, which is too low. The new lower bound then becomes 5+1=6.
The second guess then becomes (6+9)/2=7, which is too high. The new upper bound then becomes 7-1=6.
The third guess is then of course (6+6)/2)=6, which is correct. So, three guesses were required, and the method thus returns 3.


1)
1000
750

Returns: 2

The first guess will be 500, the second guess 750.


2)
643
327

Returns: 7

The guesses are 322, 483, 402, 362, 342, 332 and finally 327, so the method returns 7.

3)
157
157

Returns: 8

Here the guesses are 79, 118, 138, 148, 153, 155, 156 and finally 157. The method thus returns 8.


4)
128
64

Returns: 1

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 6; int Arg2 = 3; verify_case(0, Arg2, noGuesses(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1000; int Arg1 = 750; int Arg2 = 2; verify_case(1, Arg2, noGuesses(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 643; int Arg1 = 327; int Arg2 = 7; verify_case(2, Arg2, noGuesses(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 157; int Arg1 = 157; int Arg2 = 8; verify_case(3, Arg2, noGuesses(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 64; int Arg2 = 1; verify_case(4, Arg2, noGuesses(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  GuessTheNumber test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
