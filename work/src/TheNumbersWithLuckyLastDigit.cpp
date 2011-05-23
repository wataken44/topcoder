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

class TheNumbersWithLuckyLastDigit {
 public:
  int find(int n) {
    // -- main code --

    vector<int> table(281, INT_MAX);

    TIMES(i, 281) {
      TIMES(b, 40) {
        TIMES(c, 70) {
          if(b * 7 + c * 4 > 290) break;
          if(b + c == 0) continue;
          TIMES(m, i / 10 + 1) {
            if(i - m * 10 == b * 7 + c * 4) {
              table[i - m * 10] = min(table[i - m * 10], b + c);
            }
          }
        }
      }
    }

    int k = n % 280;
    if(k == 0) k = 280;
    
    return table[k] == INT_MAX ? -1 : table[k];
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John believes that the digits 4 and 7 are lucky, and all other digits are unlucky.
A positive integer is called a lucky number if its last digit is lucky.
For example, 4, 14 and 207 are lucky numbers, while 40, 741 and 3 are not lucky numbers.
John would like to represent the int n as a sum of only lucky numbers, and he would like to do this using the minimal possible number of summands.
Return the number of summands in the representation, or -1 if it is impossible to achieve the goal.



DEFINITION
Class:TheNumbersWithLuckyLastDigit
Method:find
Parameters:int
Returns:int
Method signature:int find(int n)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
99

Returns: 4

One?of?the?possible?representations?is?99=14+24+27+34.

1)
11

Returns: 2

11=4+7.

2)
13

Returns: -1

It is impossible to achieve the goal.

3)
1234567

Returns: 1

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 99; int Arg1 = 4; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = -1; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 1234567; int Arg1 = 1; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  TheNumbersWithLuckyLastDigit test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
