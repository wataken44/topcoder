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

class ShortPalindromes {
 public:
  vector< vector<string> > memo;
  vector< vector<bool> > found;

  string shortest(string base) {
    // -- main code --
    int sz = base.size();

    if(sz <= 1) return base;
    
    memo = vector< vector<string> >(sz, vector<string>(sz, ""));
    found = vector< vector<bool> >(sz, vector<bool>(sz, false));
    
  }

  string go(string& base, int pos, int len) {
    if(found[pos][len] == true) {
      return memo[pos][len];
    }

    if(isPalindrome(base)) {
      found[pos][len] = true;
      memo[pos][len] = base;
      return base;
    }else if(base[0] == base[base.size() - 1]) {

    }else {
      
    }
    
  }
  
  bool isPalindrome(string& s) {
    TIMES(i, s.size()/2) {
      if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A palindrome is a string that is spelled the same forward and backwards.  Given a string 
base that may or may not be a palindrome, we can always force base to be a palindrome by adding
letters to it.  For example, given the word "RACE", we could add the letters "CAR" to its back to get "RACECAR" (quotes for clarity only).  However, we are not restricted to adding letters at the back.  For example, we
could also add the letters "ECA" to the front to get "ECARACE".  In fact, we can add letters anywhere in the word, so we 
could also get "ERCACRE" by adding an 'E' at the beginning, a 'C' after the 'R', and another 'R' before the final 'E'. 
Your task is to make base into a palindrome by adding as few letters 
as possible and return the resulting string.  When there is more than one palindrome of minimal length that can be made, return the lexicographically earliest (that is, the one that occurs first in alphabetical order).




DEFINITION
Class:ShortPalindromes
Method:shortest
Parameters:string
Returns:string
Method signature:string shortest(string base)


CONSTRAINTS
-base contains between 1 and 25 characters, inclusive.
-Every character in base is an uppercase letter ('A'-'Z').


EXAMPLES

0)
"RACE"

Returns: "ECARACE"

To make "RACE" into a palindrome, we must add at least three letters.  However, there are
eight ways to do this by adding exactly three letters:

    "ECARACE"  "ECRARCE"  "ERACARE"  "ERCACRE"
    "RACECAR"  "RAECEAR"  "REACAER"  "RECACER"

Of these alternatives, "ECARACE" is the lexicographically earliest.


1)
"TOPCODER"

Returns: "REDTOCPCOTDER"

2)
"Q"

Returns: "Q"

3)
"MADAMIMADAM"

Returns: "MADAMIMADAM"

4)
"ALRCAGOEUAOEURGCOEUOOIGFA"

Returns: "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RACE"; string Arg1 = "ECARACE"; verify_case(0, Arg1, shortest(Arg0)); }
	void test_case_1() { string Arg0 = "TOPCODER"; string Arg1 = "REDTOCPCOTDER"; verify_case(1, Arg1, shortest(Arg0)); }
	void test_case_2() { string Arg0 = "Q"; string Arg1 = "Q"; verify_case(2, Arg1, shortest(Arg0)); }
	void test_case_3() { string Arg0 = "MADAMIMADAM"; string Arg1 = "MADAMIMADAM"; verify_case(3, Arg1, shortest(Arg0)); }
	void test_case_4() { string Arg0 = "ALRCAGOEUAOEURGCOEUOOIGFA"; string Arg1 = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"; verify_case(4, Arg1, shortest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ShortPalindromes test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
