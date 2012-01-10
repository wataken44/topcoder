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

class Substitute {
 public:
  int getValue(string key, string code) {
    // -- main code --

    int r = 0;
    TIMES(i, code.size()) {
      TIMES(j, key.size()) {
        if(code[i] == key[j]) {
          r = r * 10 + ((j + 1) % 10);
        }
      }
    }
    
    return r;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A simple, easy to remember system for encoding integer amounts can be very useful.
For example, dealers at flea markets put the information about an item on a card 
that they let potential buyers see.  They find it advantageous to encode the 
amount they originally paid for the item on the card.

A good system is to use a substitution code, in which each digit is encoded by a 
letter.  An easy to remember 10-letter word or phrase, the key, is chosen. Every
'1' in the value is replaced by the first letter of the key, every '2' is replaced by the
second letter of the key, and so on. Every '0' is replaced by the last letter of
the key.  Letters that do not appear in the key can be inserted anywhere without affecting the value represented by the code..  This
helps to make the resulting code much harder to break (without knowing the key).

Create a class Substitute that contains the method getValue that is given the 
strings key and code as input and that returns the decoded value.



DEFINITION
Class:Substitute
Method:getValue
Parameters:string, string
Returns:int
Method signature:int getValue(string key, string code)


CONSTRAINTS
-code contains between 1 and 9 characters inclusive, all uppercase letters 'A'-'Z'
-code contains at least one letter that is found in key
-key contains exactly 10 uppercase letters 'A'-'Z', all distinct from each other


EXAMPLES

0)
"TRADINGFEW"
"LGXWEV"

Returns: 709

 

The L,X, and V are ignored since they do not appear in the key. G is the
seventh letter in the key, W is the 10th letter, and E is the 9th letter.

 

1)
"ABCDEFGHIJ"
"XJ"

Returns: 0

2)
"CRYSTALBUM"
"MMA"

Returns: 6

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TRADINGFEW"; string Arg1 = "LGXWEV"; int Arg2 = 709; verify_case(0, Arg2, getValue(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJ"; string Arg1 = "XJ"; int Arg2 = 0; verify_case(1, Arg2, getValue(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "CRYSTALBUM"; string Arg1 = "MMA"; int Arg2 = 6; verify_case(2, Arg2, getValue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Substitute test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
