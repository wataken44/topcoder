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

class ReversalChain {

  typedef pair<int, int> pii;
  typedef pair<string, pii> psii;

  map<psii, int> memo;

  static const int INF = 1234567;
  
 public:
  int minReversal(string init, string goal)
  {

    memo.clear();

    if(init.size() != goal.size()) return -1;
    
    int i0 = 0;
    int g0 = 0;

    TIMES(k, init.size()) {
      if(init[k] == '0') ++i0;
      if(goal[k] == '0') ++g0;
    }

    if(i0 != g0) return -1;

    int l = 0;
    TIMES(k, init.size()) {
      if(init[k] != goal[k]) {
        l = k;
        break;
      }
    }

    int r = init.size();
    DOWNTO(k, init.size() - 1, 0) {
      if(init[k] != goal[k]) {
        r = k;
        break;
      }
    }

    if(l > r) return -1;
    
    int result = INF;
    // -- main code --

    UPTO(i, l, r) {
      UPTO(j, i + 1, r) {
        result = min(result, go(init, goal, i, j));
      }
    }

    //DUMP(memo);
    
    return result == INF ? -1 : result;	
  }

  int go(string from, const string& goal, int i, int j)
  {
    if(from == goal) return 0;

    psii key = make_pair(from, make_pair(i, j));
    
    if(memo.find(key) != memo.end()) {
      return memo[key];
    }

    reversal(from, i, j);
    if(from == goal) return 1;

    int r = INF;

    FOR(k, 0, i) {
      if(from[k] != goal[k]) {
        memo[key] = INF;
        return memo[key];
      }
    }

    FOR(k, j + 1, goal.size()) {
      if(from[k] != goal[k]) {
        memo[key] = INF;
        return memo[key];
      }
    }
    
    UPTO(jj, i, j) {
      UPTO(ii, i, j) {
        if(ii >= jj || (ii == i && jj == j)) continue;
        r = min(r, 1 + go(from, goal, ii, jj));
      }
    }

    memo[key] = r;
    return memo[key];
  }
  
  void reversal(string& s, int i, int j)
  {
    while(i < j) {
      swap(s[i], s[j]);
      ++i;
      --j;
    }
  }
  
// BEGIN CUT HERE
  void debug()
  {
    string s = "101010";
    DUMP(s);
    reversal(s, 1, 4);
    DUMP(s);
  }
/*
// PROBLEM STATEMENT
// 
Given a string, the reversal operation r(i, j) reverses the substring of the string from the i-th character to the j-th character (0-indexed, inclusive).  A reversal chain is a sequence of reversals where the range of each reversal is included in the range of the previous reversal.  Formally, the sequence r(i1, j1), r(i2, j2), ..., r(im, jm) is a reversal chain if i1 <= i2 <= ... <= im, and j1 >= j2 >= ... >= jm.


You are given a string init which contains only '0' (zero) and '1' (one) characters.  You want to transform this string into the string goal using a reversal chain. Return the minimum possible length of a reversal chain that transforms init into goal. Return -1 if it is impossible.


DEFINITION
Class:ReversalChain
Method:minReversal
Parameters:string, string
Returns:int
Method signature:int minReversal(string init, string goal)


CONSTRAINTS
-init will contain between 1 and 50 characters, inclusive.
-init and goal will contain the same number of characters.
-Each character of init and goal will be '0' (zero) or '1' (one).


EXAMPLES

0)
"1100"
"0110"

Returns: 1

r(0, 2) transforms "1100" into "0110".

1)
"111000"
"101010"

Returns: 2

r(1, 4) and r(2, 3) transforms "111000" into "101010".

2)
"0"
"1"

Returns: -1

It is impposible to transform "0" into "1" by a reversal chain.

3)
"10101"
"10101"

Returns: 0

You do not have to do anything.

4)
"111000111000"
"001100110011"

Returns: 4



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1100"; string Arg1 = "0110"; int Arg2 = 1; verify_case(0, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "111000"; string Arg1 = "101010"; int Arg2 = 2; verify_case(1, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0"; string Arg1 = "1"; int Arg2 = -1; verify_case(2, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "10101"; string Arg1 = "10101"; int Arg2 = 0; verify_case(3, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "111000111000"; string Arg1 = "001100110011"; int Arg2 = 4; verify_case(4, Arg2, minReversal(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ReversalChain test;

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
