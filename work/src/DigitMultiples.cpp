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

class DigitMultiples {

 public:
  string multiply(string s, int n)
  {
    bool ok = true;
    TIMES(i, s.size()) {
      int a = n * (s[i] - '0');
      if(a >= 10) {
        ok = false;
      }
      if(ok) {
        s[i] = (char)(a + '0');
      }else {
        s[i] = '.';
      }
    }
    return s;
  }

  int getLongest(string single, string multiple)
  {
    // -- main code --

    int sz = single.size();
    DOWNTO(n, sz, 1) {
      UPTO(k, 0, sz - n) {
        TIMES(i, 10) {
          string sub = multiply(single.substr(k, n), i);
          if(multiple.find(sub) != string::npos) {
            return n;
          }
        }
      }
    }
    return 0;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
You are given two strings of digits, single and multiple. Your job is to find the length of the longest substring (which may be the whole string) of digits in single such that there is a corresponding substring (of the same length) in multiple which satisfies the following constraint.
Each digit in the substring of multiple is the same exact integer multiple of the corresponding digit in the substring of single. So "48" is a multiple (4) of "12",  but "72" is not a multiple of "36".  Multiplication factors from 0 to 9 are possible. Leading zeros are *allowed* in single and multiple and all substrings.


For example: in "3211113321571"  and "5555266420",  here are a few (but not all) of the multiples:

"3211113321571"        "5555266420"
"-----------7-"  x 0 = "---------0"
"--------2----"  x 1 = "----2-----"
"--11---------"  x 6 = "-----66---"
"321----------"  x 2 = "------642-"
"--1111-------"  x 5 = "5555------"
"-----13321---"  x 2 = "----26642-"


The answer is 5, the length of the longest string with a multiple, "13321".


DEFINITION
Class:DigitMultiples
Method:getLongest
Parameters:string, string
Returns:int
Method signature:int getLongest(string single, string multiple)


NOTES
-Each digit multiple must be exactly a single digit.  For example: '3' x 4 never matches.


CONSTRAINTS
-single will have between 1 and 50 characters inclusive.
-multiple will have between 1 and 50 characters inclusive.
-each character of single will be between '0' and '9' inclusive.
-each character of multiple will be between '0' and '9' inclusive.


EXAMPLES

0)
"3211113321571"
"5555266420"

Returns: 5

The example from above. Longest multiple = "13321" x 2 = "26642"

1)
"100200300"
"100400600"

Returns: 8

"00200300" x 2 = "00400600"

2)
"111111111100000000000000000000000000000000000"
"122333444455555666666777777788888888999999999"

Returns: 9

3)
"000000000000"
"000000000000"

Returns: 12

Any integer multiple works here.

4)
"11111111111"
"11111111111"

Returns: 11

The factor is one.

5)
"89248987092734709478099"
"00000000000000000000000"

Returns: 23

The factor is zero.

6)
"11111111111111111111111111111111111111111111111111"
"00000000000000000000000001111111111111111111111111"

Returns: 25

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "3211113321571"; string Arg1 = "5555266420"; int Arg2 = 5; verify_case(0, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "100200300"; string Arg1 = "100400600"; int Arg2 = 8; verify_case(1, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "111111111100000000000000000000000000000000000"; string Arg1 = "122333444455555666666777777788888888999999999"; int Arg2 = 9; verify_case(2, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "000000000000"; string Arg1 = "000000000000"; int Arg2 = 12; verify_case(3, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "11111111111"; string Arg1 = "11111111111"; int Arg2 = 11; verify_case(4, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "89248987092734709478099"; string Arg1 = "00000000000000000000000"; int Arg2 = 23; verify_case(5, Arg2, getLongest(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "11111111111111111111111111111111111111111111111111"; string Arg1 = "00000000000000000000000001111111111111111111111111"; int Arg2 = 25; verify_case(6, Arg2, getLongest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DigitMultiples test;

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
