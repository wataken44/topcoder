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

class FoxIntegerLevelThree {

 public:
  typedef long long ll;

  ll fs(ll n)
  {
    ll r = 0;
    while(n > 0) {
      r += n % 10;
      n /= 10;
    }
    return r;
  }

  ll fd(ll n)
  {
    ll r = n;
    while(r >= 10) r = fs(r);
    return r;
  }

  long long count(long long min, long long max)
  {
    long long result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Fox Jiro likes to ponder integers. Today he thought about the following things. 

First, he defines a function s(n) for positive integers n. s(n) indicates the sum of all digits of n in base 10. For example, s(58) = 5+8 = 13.

Next, he defines another function d(n) for positive integers n. d(n) applies function s for n repeatedly until the result has only one digit. For example, consider d(58). First, we calculate s(58) and get 13. 13 has two digits, so we calculate s(13) and get 4. So, d(58) = 4.

He says an integer x is representable if and only if there is at least one positive integer y such that y * d(y) = x. You are given a long long min, a long long max. Return the number of representable integers between min and max, inclusive.

DEFINITION
Class:FoxIntegerLevelThree
Method:count
Parameters:long long, long long
Returns:long long
Method signature:long long count(long long min, long long max)


CONSTRAINTS
-min will be between 1 and 10,000,000,000 (10^10), inclusive.
-max will be between min and 10,000,000,000 (10^10), inclusive.


EXAMPLES

0)
10
16

Returns: 2

The representable numbers are 10 (= 10 * d(10)) and 16 (= 4 * d(4)).

1)
123
123

Returns: 0

123 is not representable.

2)
160
160

Returns: 1

160 can be represented by two ways:

160 = 40 * d(40)
160 = 32 * d(32)


3)
47
58

Returns: 4



4)
123456789
9876543210

Returns: 2618024258



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 16LL; long long Arg2 = 2LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 123LL; long long Arg1 = 123LL; long long Arg2 = 0LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 160LL; long long Arg1 = 160LL; long long Arg2 = 1LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 47LL; long long Arg1 = 58LL; long long Arg2 = 4LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 123456789LL; long long Arg1 = 9876543210LL; long long Arg2 = 2618024258LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxIntegerLevelThree test;

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
