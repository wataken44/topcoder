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

class EllysFractions {

 public:
  typedef long long ll;

  vector<bool> sieve;
  vector<int> prime;

  void makeSieve(int N)
  {
    sieve = vector<bool>(N+1, true);
    prime.clear();

    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i * i <= N+1; ++i) {
      if(!sieve[i] ) continue;
      for(int j = 2; j * i < N+1; ++j) {
        sieve[i * j] = false;
      }
    }
    

    TIMES(i, N+1) {
      if(sieve[i]) prime.push_back(i);
    }
  }
  
  long long getCount(int N)
  {
    makeSieve(N);
    
    long long result = 0;
    int np = 0;
    
    for(int k = 2; k<=N; ++k) {
      if(sieve[k]) {
        ++np;
        DUMP(k);
      }
      result += (1LL << (np-1));
    }
    // -- main code --
    
    return result;	
  }

  template<typename T>
  T gcd(T a, T b)
  {
    if(a > b) swap(a, b);
    while(a != 0) {
      T t = b % a;
      b = a;
      a = t;
    }
    return b;
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A positive common fraction is a fraction of the form A/B, where A and B are positive integers.
An irreducible fraction is a positive common fraction such that A and B are relatively prime. (In other words, the only positive integer that divides both A and B is 1.)
Elly recently invented the factor fractions: A factor fraction is an irreducible fraction such that the product A*B is a factorial number (see Notes for definition). We will only be interested in factor fractions that lie strictly between 0 and 1. (That is, A must be strictly smaller than B.)

Examples:

2/3, 4/6, 4/7, 7/7, 6/1, 42/49 are six positive common fractions
Out of those six, the following three are irreducible: 2/3, 4/7, 6/1.
The fraction 2/3 is a factor fraction, because 2*3 = 6 and that is a factorial number.
The fraction 4/7 is not a factor fraction, because 4*7 = 28 and that is not a factorial number.
The fraction 6/1 is a factor fraction, because 6*1 = 6 and that is a factorial number. However, as 6/1 does not lie strictly between 0 and 1, we are not interested in this fraction.
Note that 4/6 is not a factor fraction. (We do have 4*6=24, but a factor fraction has to be irreducible.)



You are given an int N.
Compute and return the number of factor fractions A/B such that 0 < A/B < 1 and A*B is one of the factorial numbers from 1! to N! (inclusive).

DEFINITION
Class:EllysFractions
Method:getCount
Parameters:int
Returns:long long
Method signature:long long getCount(int N)


NOTES
-The factorial of X, denoted X!, is the product of the first X positive integers. For example, 6! is 1*2*3*4*5*6 = 720. The factorial numbers are the numbers of the form X! for positive integer X. The smallest few: 1, 2, 6, 24, 120, 720, ...
-The answer will always fit in a 64-bit signed integer.


CONSTRAINTS
-N will be between 1 and 250, inclusive.


EXAMPLES

0)
1

Returns: 0

We are interested in factor fractions such that A*B = 1. The only positive common fraction with this property is the fraction 1/1. However, this fraction is not strictly between 0 and 1.

1)
2

Returns: 1

Here the only valid factor fraction is 1/2.

2)
3

Returns: 3

The three fractions are 1/2, 1/6, and 2/3. (We have 1*2 = 2! and 1*6 = 2*3 = 3!.)

3)
5

Returns: 9



4)
100

Returns: 177431885

Plenty of fractions here.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 0LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 1LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 3LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { int Arg0 = 5; long long Arg1 = 9LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { int Arg0 = 100; long long Arg1 = 177431885LL; verify_case(4, Arg1, getCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  EllysFractions test;

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
