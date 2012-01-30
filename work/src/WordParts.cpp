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

class WordParts {
 public:

  vector< vector<int> > memo;
  static const int INF = 1000000000;
  
  int partCount(string original, string compound) {
    // -- main code --

    int csz = compound.size();
    memo = vector< vector<int> >(csz,  vector<int>(csz, 0));


    int r = recursive(original, compound, 0, csz-1);	

    return r == INF ? -1 : r;
  }

  int recursive(string& orig, string& comp, int x, int y) {
    if(y < 0) {
      return 0;
    }
    
    if(memo[y][x] != 0) {
      return memo[y][x];
    }

    if(x >= y) {
      if(orig.substr(0, 1) == comp.substr(x, 1) or
         orig.substr(orig.size()-1, 1) == comp.substr(x, 1)) { 
        memo[y][x] = 1;
        return 1;
      }else {
        memo[y][x] = INF;
        return INF;
      }
    }

    int len = y - x + 1;
    if(len <= (int)orig.size()) {
      if(orig.substr(0, len) == comp.substr(x, len) or
         orig.substr(orig.size()-len, len) == comp.substr(x, len)) {
        memo[y][x] = 1;
        return 1;
      }
    }
    
    int m = INF;
    UPTO(i, 0, y - x - 1) {
      m = min(m,
              recursive(orig, comp, x , x + i) +
              recursive(orig, comp, x + i + 1, y));
    }
    memo[y][x] = m;
    return m;
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given a base word, original, and a compound word, compound, decide if the compound word is valid.  A compound word is valid if and only if it is comprised solely of a concatenation of prefixes and/or suffixes of original.  That is, if the compound word can be partitioned into N parts, such that each part is equal to either a prefix or a suffix of original, then it is valid.  If the word is invalid, return -1.  Otherwise, return the minimum value of N for which this is possible.

DEFINITION
Class:WordParts
Method:partCount
Parameters:string, string
Returns:int
Method signature:int partCount(string original, string compound)


NOTES
-The entire base word original is considered a valid prefix/suffix of itself.  See example 3.


CONSTRAINTS
-original will contain between 1 and 50 characters, inclusive.
-original will consist only of uppercase letters (A-Z).
-compound will contain between 0 and 50 characters, inclusive.
-compound will consist only of uppercase letters (A-Z).


EXAMPLES

0)
"ANTIDISESTABLISHMENTARIANISM"
"ANTIDISIANISMISM"

Returns: 3

"ANTIDISIANISMISM" can be split into "ANTIDIS", "IANISM", and "ISM", all of which are substrings from the beginning or end of the base word.

1)
"ANTIDISESTABLISHMENTARIANISM"
"ESTABLISHMENT"

Returns: -1

While "ESTABLISHMENT" is contained in "ANTIDISESTABLISHMENTARIANISM", it neither starts at the beginning nor ends at the end of that string.  Furthermore, "ESTABLISHMENT" cannot be broken into any number of parts which satisfy this rule.

2)
"TOPCODERDOTCOM"
"TOMTMODERDOTCOM"

Returns: 5

The five strings are "TO", "M", "T", "M", and "ODERDOTCOM".

3)
"HELLO"
"HELLOHEHELLOLOHELLO"

Returns: 5

Note that the entire original word is considered a valid prefix/suffix.

4)
"DONTFORGETTHEEMPTYCASE"
""

Returns: 0

5)
"BAAABA"
"BAAABAAA"

Returns: 2

6)
"ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB"
"BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA"

Returns: 17

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ANTIDISESTABLISHMENTARIANISM"; string Arg1 = "ANTIDISIANISMISM"; int Arg2 = 3; verify_case(0, Arg2, partCount(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ANTIDISESTABLISHMENTARIANISM"; string Arg1 = "ESTABLISHMENT"; int Arg2 = -1; verify_case(1, Arg2, partCount(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "TOPCODERDOTCOM"; string Arg1 = "TOMTMODERDOTCOM"; int Arg2 = 5; verify_case(2, Arg2, partCount(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "HELLO"; string Arg1 = "HELLOHEHELLOLOHELLO"; int Arg2 = 5; verify_case(3, Arg2, partCount(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "DONTFORGETTHEEMPTYCASE"; string Arg1 = ""; int Arg2 = 0; verify_case(4, Arg2, partCount(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "BAAABA"; string Arg1 = "BAAABAAA"; int Arg2 = 2; verify_case(5, Arg2, partCount(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB"; string Arg1 = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA"; int Arg2 = 17; verify_case(6, Arg2, partCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  WordParts test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
