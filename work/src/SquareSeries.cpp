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

class SquareSeries {

 public:
  string completeIt(string pattern, int lastLength)
  {
    int sz = pattern.size();
    int qlen = lastLength - sz + 1;

    if(qlen < 0) return "...";

    int qpos = -1;
    TIMES(i, sz) {
      if(pattern[i] == '?') qpos = i;
    }
    
    vector<int> sl(sz, 0);
    sl[0] = 1;

    FOR(i, 1, qpos) {
      if(pattern[i] != pattern[i-1]) {
        sl[i] = sl[i-1]+1;
      }else {
        sl[i] = sl[i-1]-1;
      }
      if(sl[i] == 0) return "...";
    }

    vector<int> sr(sz, 0);
    sr[sz-1] = 1;

    DOWNTO(i, sz-1, qpos+1) {
      if(pattern[i] != pattern[i-1]) {
        sr[i-1] = sr[i]-1;
      }else {
        sr[i-1] = sr[i]+1;
      }
    }

    DUMP(sl);
    DUMP(sr);

    int ls = -1;
    int lc = ' ';

    if(qpos == 0) {
      ls = 0;
      lc = '!';
    }else {
      ls = sl[qpos-1];
      lc = pattern[qpos-1];
    }

    int rs = 0;
    int rc = '@';

    if(qpos == sz - 1) {
      rs = 0;
      rc = '@';
    }else {
      rs = max(1, sr[qpos+1]);
      rc = pattern[qpos+1];
    }

    DUMP(qlen);DUMP(ls);DUMP(rs);DUMP(lc);DUMP(rc);
    
    string result;
    // -- main code --

    TIMES(i, sz) {
      if(pattern[i] != '?') {
        result += pattern[i];
      }else {

      }
    }
      
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Taro and Brus are playing a new game called Square Series. The game involves placing a non-empty sequence of black and white squares following a couple of rules:

The first square has side length 1.
For i > 1, if the color of square i (1-indexed) is different than the color of square i-1, its side length will be equal to the side length of the previous square plus 1. If the colors are the same, then the side length will be equal to the previous side length minus 1. Note that  a side length of 0 would make the shape not a square, so it is not legal to repeat the color after a length 1 square.


Taro wants to prepare new challenges for Brus and would like you to make a program that will generate valid square series such that it matches  string pattern and the length of the last square is equal to lastLength. The pattern contains 'W' and 'B' representing white and black squares respectively and exactly one '?' character. To generate a sequence of strings that matches the pattern, replace the '?' character with a (possibly empty) sequence of white and black squares.

Given the pattern and lastLength, if there is no valid sequence of squares that follows the aforementioned rules, matches the pattern and finishes with a square of side length equal to lastLength, then return "..." (quotes for clarity). Otherwise, return the shortest possible sequence that matches the pattern and finishes with a square of  the appropriate side length. In case there is more than one sequence with a length equal to the shortest possible, return the lexicographically first of them.

DEFINITION
Class:SquareSeries
Method:completeIt
Parameters:string, int
Returns:string
Method signature:string completeIt(string pattern, int lastLength)


NOTES
-The lexicographically earlier of two strings of the same length is the one that has the earlier character (using ASCII ordering) at the first position at which they differ.


CONSTRAINTS
-lastLength will be between 1 and 100, inclusive.
-pattern will contain between 1 and 50 characters, inclusive.
-Each character in pattern will be 'W', 'B' or '?'.
-pattern will contain exactly one '?' character.


EXAMPLES

0)
"W?B"
2

Returns: "WB"

It is possible to replace the '?' character with an empty sequence. The sequence "WB" is the shortest one that matches the pattern and ends with a square of length 2.

1)
"?"
5

Returns: "BWBWB"

Any sequence can match the "?" pattern. "BWBWB" and "WBWBW" are the shortest sequences possible that end with a square of size 5. "BWBWB" is the lexicographically earlier of the two.


2)
"BWBBBBW?WB"
10

Returns: "..."

Every sequence that begins with BWBBBB is invalid because it will require an invalid square of size 0 at position 6 (1-based).

3)
"BWBWBW?WBWBWBW"
15

Returns: "BWBWBWBBWBWBWBWBW"



4)
"WBWBWBWBWBWWBB?W"
1

Returns: "WBWBWBWBWBWWBBBBBBBBBBBWW"



5)
"?WBWBWBBB"
3

Returns: "..."



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "W?B"; int Arg1 = 2; string Arg2 = "WB"; verify_case(0, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "?"; int Arg1 = 5; string Arg2 = "BWBWB"; verify_case(1, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BWBBBBW?WB"; int Arg1 = 10; string Arg2 = "..."; verify_case(2, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BWBWBW?WBWBWBW"; int Arg1 = 15; string Arg2 = "BWBWBWBBWBWBWBWBW"; verify_case(3, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "WBWBWBWBWBWWBB?W"; int Arg1 = 1; string Arg2 = "WBWBWBWBWBWWBBBBBBBBBBBWW"; verify_case(4, Arg2, completeIt(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "?WBWBWBBB"; int Arg1 = 3; string Arg2 = "..."; verify_case(5, Arg2, completeIt(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SquareSeries test;

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
