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

class DivisibleByDigits {

 public:
  typedef long long ll;
  
  long long getContinuation(int n)
  {
    // -- main code --
    ll nl = nlcm(n);

    ll b = 1;
    
    while(true) {
      ll lb = n * b;
      ll ub = (n + 1) * b - 1;

      ll ld = lb / nl;
      ll c = nl * (lb % nl == 0 ? ld : ld + 1);

      //DUMP(lb);DUMP(ub);DUMP(c);
      if(c <= ub) {
        return c;
      }
      b *= 10;
    }
    
    long long result = -1;
    
    return result;	
  }

  ll nlcm(int n)
  {
    ll r = 1;
    while(n > 0) {
      ll k = n % 10;
      n /= 10;
      if(k == 0) continue;
      r = r * k / gcd(r, k);
    }
    return r;
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
// Given an integer n, find the smallest integer that starts with n and is divisible by every non-zero digit of n (all in decimal notation).

DEFINITION
Class:DivisibleByDigits
Method:getContinuation
Parameters:int
Returns:long long
Method signature:long long getContinuation(int n)


NOTES
-An integer A starts with an integer B if the string representation of B is a prefix of the string representation of A (both in decimal notation with no leading zeroes).


CONSTRAINTS
-n will be between 1 and 1000000000, inclusive.


EXAMPLES

0)
13

Returns: 132

We need a number that starts with 13 and is divisible by 1 (always true) and by 3. The smallest one is 132.


1)
648

Returns: 648

If n is divisible by all its non-zero digits, the answer to the problem is n itself.

2)
566

Returns: 56610

The resulting number must be divisible by 5, so it should end either with 0 or with 5. But a number ending with 5 is odd and can't be divisible by 6. So the last digit of the answer must be 0. In order to make the number divisible by 6, we need to put something before this 0, and the smallest appropriate digit is 1.

3)
1000000000

Returns: 1000000000



4)
987654321

Returns: 987654321360



5)
83

Returns: 8304



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; long long Arg1 = 132LL; verify_case(0, Arg1, getContinuation(Arg0)); }
	void test_case_1() { int Arg0 = 648; long long Arg1 = 648LL; verify_case(1, Arg1, getContinuation(Arg0)); }
	void test_case_2() { int Arg0 = 566; long long Arg1 = 56610LL; verify_case(2, Arg1, getContinuation(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; long long Arg1 = 1000000000LL; verify_case(3, Arg1, getContinuation(Arg0)); }
	void test_case_4() { int Arg0 = 987654321; long long Arg1 = 987654321360LL; verify_case(4, Arg1, getContinuation(Arg0)); }
	void test_case_5() { int Arg0 = 83; long long Arg1 = 8304LL; verify_case(5, Arg1, getContinuation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DivisibleByDigits test;

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
