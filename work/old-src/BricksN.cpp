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

class BricksN {
 private:
  static const int modulo = 1000000007;
 public:
  vector< vector< vector<int> > > memo;

  int countStructures(int w, int h, int k)
  {
    
    memo.clear();
    memo = vector< vector< vector<int> > >
        (w + 1, vector< vector<int> >
         (h + 1, vector<int>(k + 1, -1)));
                                            
    
    // -- main code --
    
    return go(w, h, k);	
  }

  int go(int w, int h, int k)
  {
    if(memo[w][h][k] != -1) {
      return memo[w][h][k];
    }

    if(h == 1) {
      if(w == 0) {
        memo[w][h][k] = 1;
        return memo[w][h][k];
      }
      if(k == 1) {
        memo[w][h][k] = (1LL << w) % modulo;
        return memo[w][h][k];
      }
      if(w >= k) {
        memo[w][h][k] = 1 % modulo;
      }
    }
    
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet. 

We have a set of many construction bricks. It contains exactly one base which is simply a special kind of brick of dimensions 1x1xw. We also have a infinite amount of bricks of k different kinds: 1x1x1, 1x1x2, ..., 1x1xk. Formally, for each i between 1 and k, inclusive, we have as many 1x1xi bricks as we need. For simplicity, we will call these bricks "bricks of length i". The following image shows the situation for w=9 and k=3: there is a base of length 9, and three brick types of lengths 1, 2, and 3.


We can stack bricks on top of other bricks (including the base) to form different structures. The design of the bricks forces us to place the bricks at integer positions only. To ensure stability, each brick other than the base must rest completely on a surface composed of other bricks or the base. The following image shows a structure that is invalid for four reasons:


The height of a structure is the number of layers of bricks it contains. The base is not counted into the height of the structure.

Two structures are different if there is a position where they differ in any way. (There are two ways in which two given structures may differ: First, there may be a position where one structure has a brick and the other does not. Second, there may be a position where both structures have bricks, but the bricks are of different types.)

Given are three ints: w, the length of the base, k, the maximum length of your bricks, and h, the maximum height of your structure. Find the total number of different valid structures you can make. Return the total modulo 1000000007.

For example, the following image shows all 83 different valid structures when w = 3, k = 3 and h = 2.



DEFINITION
Class:BricksN
Method:countStructures
Parameters:int, int, int
Returns:int
Method signature:int countStructures(int w, int h, int k)


CONSTRAINTS
-w and h will each be between 1 and 50, inclusive.
-k will be between 1 and w, inclusive.


EXAMPLES

0)
3
1
3

Returns: 13

The leftmost column in the picture above shows the 13 different structures of height at most 1.

1)
3
2
3

Returns: 83

This is the example from the statement.

2)
1
5
1

Returns: 6



3)
10
10
3

Returns: 288535435



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 13; verify_case(0, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 3; int Arg3 = 83; verify_case(1, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 6; verify_case(2, Arg3, countStructures(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 3; int Arg3 = 288535435; verify_case(3, Arg3, countStructures(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BricksN test;

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
