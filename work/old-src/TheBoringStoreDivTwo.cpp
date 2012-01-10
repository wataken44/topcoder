#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
#define EACH(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(cont, it, cond, ret) \
  bool ret = true; EACH(cont, it) { if(!(cond)) {ret=false;break;} }
#define ANY(cont, it, cond, ret) \
  bool ret = false; EACH(cont, it) { if(cond) {ret=true;break;} }

using namespace std;
// debug
// BEGIN CUT HERE
#define DUMP(x) std::cerr << #x << " = " << to_s(x) << std::endl;
template<typename T> string to_s(const T& v);
template<> string to_s(const string& v);
template<> string to_s(const bool& v);
template<typename T> string to_s(const vector<T>& v);
template<typename T> string to_s(const list<T>& v);
template<typename T> string to_s(const set<T>& v);
template<typename F, typename S> string to_s(const pair<F,S>& v);
template<typename K, typename V> string to_s(const map<K,V>& v);
// END CUT HERE
#ifndef DUMP
#define DUMP(x) 
#endif

class TheBoringStoreDivTwo {

 public:
  string find(string J, string B)
  {
    string result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// John and Brus are going to open a boring store.
They would like to have a really boring name for it.
John has one wooden plate with an old store name on it.
Brus also has one.



Now they need to compose two plates with the same name (case-sensitive) for the new store.
They would like to produce these new plates as follows:


John will cut two pieces from his plate. Each of the pieces will contain a non-empty contiguous substring of the name written on the original plate and the locations of these two substrings within the plate will not overlap. For example, if the name on John's plate is "abCDeF", then he can cut pieces with "bC" and "e" or with "CDeF" and "ab", but he can't cut pieces with "aC" and "eF" ("aC" is not a contiguous substring), with "abCD" and "" (empty substring is not allowed) or with "DeF" and "CD" (locations of the substrings overlap). Let's denote the substrings on John's pieces as A and B.
Brus will cut two pieces from his plate according to the same rules. Let's denote the substrings on these pieces as C and D.
One plate for the new store will be constructed as A + C (where '+' means concatenation of two strings) and another plate will be constructed as B + D.


You are given two strings J and B - the names on John's and Brus's plates respectively.
Return the longest possible name for the new store that can be achieved as described above.
In case of a tie choose the one that comes first lexicographically.
If it is impossible to achieve the goal, return an empty string.


DEFINITION
Class:TheBoringStoreDivTwo
Method:find
Parameters:string, string
Returns:string
Method signature:string find(string J, string B)


NOTES
-If two strings A and B have the same length, then A comes before B lexicographically if it has a smaller character at the first position where the strings differ. When comparing the characters, refer to the following list of characters in ascending order: 'A', 'B', ..., 'Z', 'a', 'b', ..., 'z'.


CONSTRAINTS
-J will contain between 1 and 15 characters, inclusive.
-B will contain between 1 and 15 characters, inclusive.
-Each character of J will be an uppercase or lowercase letter ('a' - 'z', 'A' - 'Z').
-Each character of B will be an uppercase or lowercase letter ('a' - 'z', 'A' - 'Z').


EXAMPLES

0)
"StoreOfJohn"
"StoreOfBrus"

Returns: "or"

John's plate contains two 'o's, and Brus's plate contains two 'r's, so one possible solution is for each new plate to contain one 'o' from John's plate and one 'r' from Brus's plate.

1)
"JohnAndJohn"
"John"

Returns: ""

The name on both new plates must end with a character from one of Brus's pieces. However, all characters on Brus's plate are different, so it is impossible to achieve the goal.

2)
"JohnPlaysGames"
"BrusAlsoPlays"

Returns: "ays"



3)
"abacaba"
"abacabadabacaba"

Returns: "abaabacaba"

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "StoreOfJohn"; string Arg1 = "StoreOfBrus"; string Arg2 = "or"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "JohnAndJohn"; string Arg1 = "John"; string Arg2 = ""; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "JohnPlaysGames"; string Arg1 = "BrusAlsoPlays"; string Arg2 = "ays"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abacaba"; string Arg1 = "abacabadabacaba"; string Arg2 = "abaabacaba"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TheBoringStoreDivTwo test;

  if(argc == 1) {
    test.run_test(-1);
  }else {
    std::string arg(argv[1]);
    if(arg[0] != '-') {
      test.run_test(arg[0] - '0');
    }else {
      test.debug();
    }
  }
  
  return 0;
}

template<typename T> string to_s(const T& v) { ostringstream oss; oss << v; return oss.str(); }
template<> string to_s(const string& v) { ostringstream oss; oss << '"' << v << '"'; return oss.str(); }
template<> string to_s(const bool& v) { ostringstream oss; oss << ( v ? "true" : "false") ; return oss.str(); } 
template<typename T> string to_s(const vector<T>& v) { ostringstream oss; oss << "["; EACH(v,i) oss << to_s(*i) << ","; oss << "]"; return oss.str(); }
template<typename T> string to_s(const list<T>& v) { ostringstream oss; oss << "("; EACH(v,i) oss << to_s(*i) << ","; oss << ")"; return oss.str(); }
template<typename T> string to_s(const set<T>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(*i) << ","; oss << "}"; return oss.str(); }
template<typename F, typename S> string to_s(const pair<F,S>& v) { ostringstream oss; oss << "<" << to_s(v.first) << " " << to_s(v.second) << ">"; return oss.str(); }
template<typename K, typename V> string to_s(const map<K,V>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(i->first) << " => " << to_s(i->second) << ","; oss << "}"; return oss.str(); }

// END CUT HERE
