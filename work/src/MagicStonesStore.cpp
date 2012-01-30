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

class MagicStonesStore {

 public:
  string ableToDivide(int n)
  {
    // -- main code --

    if(n == 1) return "NO";
    
    int all = 2 * n;
    int sz = 2 * n;

    vector<bool> sieve(sz + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    
    for(int i = 2; i * i <= sz; ++i) {
      if(!sieve[i]) continue;
      for(int j = 2; j * i <= sz; ++j) {
        sieve[i * j] == false;
      }
    }

    for(int k = 2; k < all; ++k) {
      int r = all - k;
      if(sieve[k] && sieve[r]) return "YES";
    }
    
    return "NO";	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world celebrate this 
holiday. The following story takes place in the land of reindeer, where Santa Claus resides.



The currency in the land of reindeer are magic stones. Santa's reindeer have 2n magic stones (i.e., an even number of them). They want to divide the stones into two piggy banks. Santa's reindeer are very fond of primes, therefore they want each piggy bank to contain a prime number of magic stones.



You are given an int n. If it is possible to divide 2n magic stones into two piggy banks, each containing a prime number of stones, return "YES", otherwise return "NO" (quotes for clarity).

DEFINITION
Class:MagicStonesStore
Method:ableToDivide
Parameters:int
Returns:string
Method signature:string ableToDivide(int n)


NOTES
-A positive integer is prime if and only if it has exactly two positive integer divisors. The first few prime numbers are 2, 3, 5, 7, 11, ...
-The number zero is not a prime number, hence you are not allowed to leave any piggy bank empty.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.


EXAMPLES

0)
1

Returns: "NO"

As n=1, we are dividing 2 magic stones into two piggy banks. In this case is impossible to have a prime number of stones in each piggy bank.

1)
2

Returns: "YES"

The only valid way of dividing the stones in this case is to put 2 magic stones into each of the piggy banks.

2)
3

Returns: "YES"

Now the only way is to put 3 magic stones into each of the piggy banks.

3)
5

Returns: "YES"

For 2n=10 stones we have two valid ways of dividing them: either as 5 + 5 or as 7 + 3.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "NO"; verify_case(0, Arg1, ableToDivide(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "YES"; verify_case(1, Arg1, ableToDivide(Arg0)); }
	void test_case_2() { int Arg0 = 3; string Arg1 = "YES"; verify_case(2, Arg1, ableToDivide(Arg0)); }
	void test_case_3() { int Arg0 = 5; string Arg1 = "YES"; verify_case(3, Arg1, ableToDivide(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MagicStonesStore test;

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
