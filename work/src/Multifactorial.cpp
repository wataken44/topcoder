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

class Multifactorial {

 public:
  typedef long long ll;
  
  string calcMultiFact(int n, int k)
  {
    // -- main code --

    ll ret = 1;
    ll limit = 1;
    TIMES(m, 18) {
      limit *= 10;
    }
    
    while(n > 0) {
      if(ret > limit / n) {
        return "overflow";
      }else {
        ret *= n;
        n -= k;
      }
    }

    ostringstream oss;
    oss << ret;
    return oss.str();	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
A multifactorial of a number is a generalization of the factorial function. The k-multifactorial of n is denoted by fack(n). The k-multifactorial of n is the product of every positive number of the
form n - X*k, where X is a non-negative integer. For example, the 3-multifactorial of 14 
is 14*11*8*5*2 = 12320, and the 4-multifactorial of 5 is 5*1 = 5.

A formal definition of multifactorial is:

fack(n) = n if k >= n 
fack(n) = n*fack(n-k) if k < n 


You will be given n and k and have to return the value of fack(n) as a string with no leading zeroes (this value is always a positive integer). If fack(n) is strictly greater than 1000000000000000000 (1018), return "overflow" (quotes for clarity) instead.


DEFINITION
Class:Multifactorial
Method:calcMultiFact
Parameters:int, int
Returns:string
Method signature:string calcMultiFact(int n, int k)


NOTES
-1000000000000000000 (1018) fits in a long long.


CONSTRAINTS
-n and k will each be between 1 and 2000000000 (2*109), inclusive.


EXAMPLES

0)
14
3

Returns: "12320"

The first example in the problem statement.

1)
5
4

Returns: "5"

The second example in the problem statement.

2)
1000
2

Returns: "overflow"

Way too big!

3)
2000000000
1900000000

Returns: "200000000000000000"



4)
1000
256

Returns: "84232704000"



5)
2000000000
1

Returns: "overflow"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; int Arg1 = 3; string Arg2 = "12320"; verify_case(0, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "5"; verify_case(1, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 2; string Arg2 = "overflow"; verify_case(2, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2000000000; int Arg1 = 1900000000; string Arg2 = "200000000000000000"; verify_case(3, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 256; string Arg2 = "84232704000"; verify_case(4, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2000000000; int Arg1 = 1; string Arg2 = "overflow"; verify_case(5, Arg2, calcMultiFact(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Multifactorial test;

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
