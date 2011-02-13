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

class CeyKaps {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The keycaps on a keyboard have been switched around, and the user is now trying to remember what he was trying to type.

Create a class CeyKaps containing the method decipher that takes a string typed, representing the visible message on the screen, and a vector <string> switched, representing the keycap switches.  The method should return the original intended message (what keys the user thought he was pressing).

A keycap can be switched around more than once.  For example, if someone switched around 'A' and 'S', then switched around 'S' and 'D', then 'D' would be where 'A' originally was, 'S' where 'D' was, and 'A' where 'S' was.

The elements of switches will be formatted as (quotes added for clarity) "*:*", where the *'s represent the keycaps to be switched.  The above example would be represented as:
{"A:S","S:D","D:A"}, or alternately as
{"S:A","D:S","A:D"} or any other such combination.  The order of the keycaps doesn't matter, but the order of the switches does.



DEFINITION
Class:CeyKaps
Method:decipher
Parameters:string, vector <string>
Returns:string
Method signature:string decipher(string typed, vector <string> switches)


NOTES
-There is no restriction on how many times keycaps can be switched.  It is perfectly possible to return to the original keyboard configuration.


CONSTRAINTS
-typed will be between 1 and 50 characters in length, inclusive.
-each character of typed will be an uppercase letter ('A'-'Z').
-switches will contain between 1 and 50 elements, inclusive.
-each element of switched will be formatted as (quotes added for clarity) "*:*" where each * represents a single uppercase letter ('A'-'Z'), inclusive, but both *'s do not represent the same letter.


EXAMPLES

0)
"AAAAA"
{"A:B","B:C","A:D"}

Returns: "CCCCC"

At first, all keys look right.  After the A:B switch, A looks like B and B looks like A.  After the B:C switch, A looks like C, B looks like A, and C looks like B.  The third switch is irrelevant.  Since "AAAAA" is what comes out, Timmy must have been pressing "CCCCC".


1)
"ABCDE"
{"A:B","B:C","C:D","D:E","E:A"}

Returns: "AEBCD"

2)
"IHWSIOTCHEDMYKEYCAPSARWUND"
{"W:O","W:I"}

Returns: "WHOSWITCHEDMYKEYCAPSAROUND"

*/
// END CUT HERE

 public:
  string decipher(string typed, vector <string> switches) {
    string result = "";
    // -- main code --

    vector<char> keymap;

    FORN(i, 26) keymap.push_back((char)(i + 'A'));

    FORN(i, switches.size()) {
      char a = switches[i][0];
      char b = switches[i][2];

      int ai = -1;
      int bi = -1;
      FORN(j, 26) {
        if(keymap[j] == a) ai = j;
        if(keymap[j] == b) bi = j;
      }

      keymap[ai] = b;
      keymap[bi] = a;
    }

    FORN(i, typed.size()) {
      char c = typed[i] - 'A';
      result += keymap[c];
    }
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAA"; string Arr1[] = {"A:B","B:C","A:D"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CCCCC"; verify_case(0, Arg2, decipher(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDE"; string Arr1[] = {"A:B","B:C","C:D","D:E","E:A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AEBCD"; verify_case(1, Arg2, decipher(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "IHWSIOTCHEDMYKEYCAPSARWUND"; string Arr1[] = {"W:O","W:I"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "WHOSWITCHEDMYKEYCAPSAROUND"; verify_case(2, Arg2, decipher(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CeyKaps test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

