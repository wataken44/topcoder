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

class PrefixCode {
 public:
  string isOne(vector <string> words) {
    // -- main code --

    TIMES(i, words.size()) {
      TIMES(j, words.size()) {
        if(i == j) continue;
        if(words[j].size() < words[i].size()) continue;
        if(words[j].substr(0, words[i].size()) == words[i] ) {
          return "No, " + to_s(i);
        }
      }
    }
    
    return "Yes";	
  }

  string to_s(const int& i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A prefix code is a set of words in which no word is a prefix of another word in the set.
A word v is said to be a prefix of a word w if w starts with v.

An important property of prefix codes is that they are uniquely decodable.
Prefix codes are commonly used - telephone numbers are an everyday example (as you probably don't
want a stranger to pick up the phone call you make just because his number is a prefix of the
number you intend to dial). Prefix codes are also very popular in computer science, the Huffman code
used for data compression being a famous example.

Given a vector <string> words, return the string "Yes" if that set of words
is a prefix code or return the string "No, i" if it is not, where i is replaced by
the lowest 0-based index of a string in words that is a prefix of another string in words.
(That index should have no extra leading zeros.)

DEFINITION
Class:PrefixCode
Method:isOne
Parameters:vector <string>
Returns:string
Method signature:string isOne(vector <string> words)


NOTES
-Letters are case sensitive (e.g. "No" is not a prefix of "not").
-Do not forget the single space between the comma and i in "No, i"


CONSTRAINTS
-words contains between 1 and 50 elements, inclusive.
-Each element of words contains between 1 and 50 characters, inclusive.
-Each element of words consists only of characters '0'-'9', 'A'-'Z' and 'a'-'z', inclusive.
-No two elements of words are equal (as the input represents a set).


EXAMPLES

0)
{"trivial"}

Returns: "Yes"

As there is only one word, no word can be the prefix of another, so this is a trivial example of a prefix code.

1)
{"10001", "011", "100", "001", "10"}

Returns: "No, 2"

"100" (at index 2) and "10" (at index 4) are both a prefix of "10001" and "10" is also a prefix of "100", therefore it is no prefix code. "100" is the prefix with the lowest index.

2)
{"no", "nosy", "neighbors", "needed"}

Returns: "No, 0"

3)
{"1010", "11", "100", "0", "1011"}

Returns: "Yes"

4)
{"No", "not"}

Returns: "Yes"

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"trivial"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, isOne(Arg0)); }
	void test_case_1() { string Arr0[] = {"10001", "011", "100", "001", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No, 2"; verify_case(1, Arg1, isOne(Arg0)); }
	void test_case_2() { string Arr0[] = {"no", "nosy", "neighbors", "needed"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No, 0"; verify_case(2, Arg1, isOne(Arg0)); }
	void test_case_3() { string Arr0[] = {"1010", "11", "100", "0", "1011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(3, Arg1, isOne(Arg0)); }
	void test_case_4() { string Arr0[] = {"No", "not"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, isOne(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PrefixCode test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
