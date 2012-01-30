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

class SuperRot {
 public:
  string decoder(string message) {
    // -- main code --

    string r = "";

    TIMES(i, message.size()) {
      /*
   A-M        N-Z
   N-Z        A-M
   a-m        n-z
   n-z        a-m
   0-4        5-9
   5-9        0-4
      */
      char c = message[i];
      if('A'<= c and c <= 'M') {
        r += c - 'A' + 'N';
      }
      if('N'<= c and c <= 'Z') {
        r += c - 'N' + 'A';
      }
      if('a'<= c and c <= 'm') {
        r += c - 'a' + 'n';
      }
      if('n'<= c and c <= 'z') {
        r += c - 'n' + 'a';
      }
      if('0'<= c and c <= '4') {
        r += c - '0' + '5';
      }
      if('5'<= c and c <= '9') {
        r += c - '5' + '0';
      }
      if(c == ' ') {
        r+= c;
      }
    }
    
    return r;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There exists a basic encryption method known as ROT13.  One property of ROT13 is that the encryption and decryption processes are exactly the same.  These processes work by doing a simple transformation from one letter of the alphabet to another.  The letters A through M become N through Z, such that A->N, B->O, ..., M->Z.   The letters N through Z become A through M, such that N->A, O->B, ..., Z->M.

One of the problems with most implementations is that everything is converted to upper case.  Another problem is that numbers are ignored completely, leaving them unencrypted.  One way to overcome these limitations is to extend ROT13 to cover lowercase letters as well as numbers.  Here is how our extended ROT transformations will work:
characters   become
   A-M        N-Z
   N-Z        A-M
   a-m        n-z
   n-z        a-m
   0-4        5-9
   5-9        0-4
  For example, the message "Uryyb 28" would become "Hello 73" after being transformed.
   U -> H        2 -> 7
   r -> e        8 -> 3
   y -> l
   y -> l
   b -> 0  Notice that the spaces were left as is.

You have intercepted a message which you believe to be encrypted using this process.  Create a class SuperRot with a method decoder that takes a string message and returns the decoded message as a string.

DEFINITION
Class:SuperRot
Method:decoder
Parameters:string
Returns:string
Method signature:string decoder(string message)


NOTES
-All spaces occuring in message are left as spaces in the decoded string.


CONSTRAINTS
-message will have between 0 and 50 characters inclusive.
-message will consist only of letters 'a' - 'z' and 'A' - 'Z', digits '0' - '9', and the space character.
-message will not contain two or more consecutive spaces.
-There will be no leading or trailing spaces.


EXAMPLES

0)
"Uryyb 28"

Returns: "Hello 73"

This is the example from above.

1)
"GbcPbqre"

Returns: "TopCoder"

G -> T
b -> o
c -> p
P -> C
b -> o
q -> d
r -> e
e -> r


2)
""

Returns: ""

Remember the empty string.

3)
"5678901234"

Returns: "0123456789"

4)
"NnOoPpQqRr AaBbCcDdEe"

Returns: "AaBbCcDdEe NnOoPpQqRr"

5)
"Gvzr vf 54 71 CZ ba Whyl 4gu bs gur lrne 7558 NQ"

Returns: "Time is 09 26 PM on July 9th of the year 2003 AD"

6)
"Gur dhvpx oebja sbk whzcf bire n ynml qbt"

Returns: "The quick brown fox jumps over a lazy dog"

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Uryyb 28"; string Arg1 = "Hello 73"; verify_case(0, Arg1, decoder(Arg0)); }
	void test_case_1() { string Arg0 = "GbcPbqre"; string Arg1 = "TopCoder"; verify_case(1, Arg1, decoder(Arg0)); }
	void test_case_2() { string Arg0 = ""; string Arg1 = ""; verify_case(2, Arg1, decoder(Arg0)); }
	void test_case_3() { string Arg0 = "5678901234"; string Arg1 = "0123456789"; verify_case(3, Arg1, decoder(Arg0)); }
	void test_case_4() { string Arg0 = "NnOoPpQqRr AaBbCcDdEe"; string Arg1 = "AaBbCcDdEe NnOoPpQqRr"; verify_case(4, Arg1, decoder(Arg0)); }
	void test_case_5() { string Arg0 = "Gvzr vf 54 71 CZ ba Whyl 4gu bs gur lrne 7558 NQ"; string Arg1 = "Time is 09 26 PM on July 9th of the year 2003 AD"; verify_case(5, Arg1, decoder(Arg0)); }
	void test_case_6() { string Arg0 = "Gur dhvpx oebja sbk whzcf bire n ynml qbt"; string Arg1 = "The quick brown fox jumps over a lazy dog"; verify_case(6, Arg1, decoder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  SuperRot test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
