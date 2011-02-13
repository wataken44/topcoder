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

class CCipher {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Julius Caesar used a system of cryptography, now known as Caesar Cipher, which shifted each letter 2 places further through the alphabet (e.g. 'A' shifts to 'C', 'R' shifts to 'T', etc.). At the end of the alphabet we wrap around, that is 'Y' shifts to 'A'.

We can, of course, try shifting by any number. Given an encoded text and a number of places to shift, decode it.

For example, "TOPCODER" shifted by 2 places will be encoded as "VQREQFGT". In other words, if given (quotes for clarity) "VQREQFGT"  and 2 as input, you will return "TOPCODER". See example 0 below.


DEFINITION
Class:CCipher
Method:decode
Parameters:string, int
Returns:string
Method signature:string decode(string cipherText, int shift)


CONSTRAINTS
-cipherText has between 0 to 50 characters inclusive
-each character of cipherText is an uppercase letter 'A'-'Z'
-shift is between 0 and 25 inclusive


EXAMPLES

0)
"VQREQFGT"
2

Returns: "TOPCODER"

1)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
10

Returns: "QRSTUVWXYZABCDEFGHIJKLMNOP"

2)
"TOPCODER"
0

Returns: "TOPCODER"

3)
"ZWBGLZ"
25

Returns: "AXCHMA"

4)
"DBNPCBQ"
1

Returns: "CAMOBAP"

5)
"LIPPSASVPH"
4

Returns: "HELLOWORLD"

*/
// END CUT HERE

 public:
  string decode(string cipherText, int shift) {
    string result = "";
    // -- main code --

    FORN(i, cipherText.size()) {
      char c = cipherText[i] - shift;
      if(c < 'A') {
        c += 26;
      }

      result += c;
    }
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "VQREQFGT"; int Arg1 = 2; string Arg2 = "TOPCODER"; verify_case(0, Arg2, decode(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arg1 = 10; string Arg2 = "QRSTUVWXYZABCDEFGHIJKLMNOP"; verify_case(1, Arg2, decode(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "TOPCODER"; int Arg1 = 0; string Arg2 = "TOPCODER"; verify_case(2, Arg2, decode(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ZWBGLZ"; int Arg1 = 25; string Arg2 = "AXCHMA"; verify_case(3, Arg2, decode(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "DBNPCBQ"; int Arg1 = 1; string Arg2 = "CAMOBAP"; verify_case(4, Arg2, decode(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "LIPPSASVPH"; int Arg1 = 4; string Arg2 = "HELLOWORLD"; verify_case(5, Arg2, decode(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CCipher test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

