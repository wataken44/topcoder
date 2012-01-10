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
#define UPTO(x, a, b) for(int x = static_cast<int>(a); x <= static_cast<int>(b); ++x)
#define DOWNTO(x, a, b) for(int x = static_cast<int>(a); x >= static_cast<int>(b) ++x)

using namespace std;

class DivisorDigits {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Create a class DivisorDigits containing a method howMany which takes an int number and returns how many digits in number divide evenly into number itself.

DEFINITION
Class:DivisorDigits
Method:howMany
Parameters:int
Returns:int
Method signature:int howMany(int number)


NOTES
-No number is divisible by 0.


CONSTRAINTS
-number will be between 10000 and 999999999.


EXAMPLES

0)
12345

Returns: 3

12345 is divisible by 1, 3, and 5.

1)
661232

Returns: 3

661232 is divisible by 1 and 2.

2)
52527

Returns: 0

52527 is not divisible by 5, 2, or 7.

3)
730000000

Returns: 0

Nothing is divisible by 0.  In this case, the number is also not divisible by 7 or 3.

*/
// END CUT HERE

 public:
  int howMany(int number) {

    vector<int> v(10, 0);
    
    // -- main code --
    int n = number;
    while(n > 0) {
      int d = n % 10;

      if(d != 0 and number % d == 0) {
        v[d] += 1;
      }
      
      n = n / 10;
    }

    int result = 0;

    FORN(i, 10) result += v[i];
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12345; int Arg1 = 3; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arg0 = 661232; int Arg1 = 3; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arg0 = 52527; int Arg1 = 0; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arg0 = 730000000; int Arg1 = 0; verify_case(3, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  DivisorDigits test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

