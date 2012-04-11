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

class PouringWater {

 public:
  bool can(int N, int K)
  {
    int b = 0;
    
    while(N > 0) {
      b += N % 2;
      N = N / 2;
    }
    return b <= K;
  }

  int getMinBottles(int N, int K)
  {
    int n = N;
    
    while(true) {
      if(can(n, K)) return n - N;
      ++n;
    }
    
    int result = 0;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You have N bottles, each with unlimited capacity.  Initially, each bottle contains exactly 1 liter of water.  You want to carry these bottles to another location, but you can only carry K bottles at a time.  You don't want to waste any water and you don't want to make more than one trip, so you decide to redistribute the contents of the bottles until you end up with no more than K non-empty bottles.

You are only allowed to redistribute your water using the following method.  First, pick two bottles that contain an equal amount of water.  Then, pour the entire content of one of those bottles into the other.  Repeat this process as many times as necessary.

Because of this restriction, it may be impossible to end up with no more than K non-empty bottles using only the N bottles that you have initially.  Fortunately, you can also buy more bottles.  Each bottle that you buy will contain exactly 1 liter of water and have unlimited capacity.  For example, consider the case where N is 3 and K is 1.  It's impossible to get from 3 bottles to 1.  If you pour one bottle into another, you end up with one 2 liter bottle and one 1 liter bottle.  At that point, you're stuck.  However, if you then buy another bottle, you can pour that bottle into the 1 liter bottle, and pour the resulting 2 liter bottle into the other 2 liter bottle to end up with just one 4 liter bottle. 

Return the minimum number of additional bottles you must buy in order to achieve your goal.  If it's impossible, return -1 instead.

DEFINITION
Class:PouringWater
Method:getMinBottles
Parameters:int, int
Returns:int
Method signature:int getMinBottles(int N, int K)


CONSTRAINTS
-N will be between 1 and 10^7, inclusive.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
3
1

Returns: 1

The example from the problem statement.

1)
13
2

Returns: 3

If you have 13, 14, or 15 bottles, you can't end up with one or two bottles. With 16 bottles, you can end up with one bottle.

2)
1000000
5

Returns: 15808



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, getMinBottles(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinBottles(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 5; int Arg2 = 15808; verify_case(2, Arg2, getMinBottles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PouringWater test;

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
