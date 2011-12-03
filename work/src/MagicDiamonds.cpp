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

class MagicDiamonds {

 public:
  long long minimalTransfer(long long n)
  {
    long long result = 1;
    // -- main code --

    if(n <= 3) {
      result = n;
    }else {
      if(n % 2 == 0) {
        result = 1;
      }else {
        bool prime = true;
        for(long long i = 2; i * i <= n; ++i) {
          if(n % i == 0) {
            prime = false;
            break;
          }
        }
        result = prime ? 2 : 1;
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
// You found n Magic Diamonds in the mountain. You are now thinking about transfering them to your home.
The only way you can transfer Magic Diamonds is to use Transfer Magic one or more times.


The Magic Diamonds are very strange.
For any positive integer x you can use Transfer Magic to transfer x Magic Diamonds at once. However, if x is a prime number, the Magic Diamonds will disappear instead of getting transferred. You are not allowed to lose any of the Magic Diamonds, therefore you may never use Transfer Magic on a prime number of Magic Diamonds. Your task is to transfer all Magic Diamonds using Transfer Magic as few times as possible.



You are given a long long n. Return the minimal number of Transfer Magic usages you need to transfer n Magic Diamonds.

DEFINITION
Class:MagicDiamonds
Method:minimalTransfer
Parameters:long long
Returns:long long
Method signature:long long minimalTransfer(long long n)


NOTES
-A positive integer x is a prime number if and only if it has exactly 2 divisors: 1 and x. Note that 1 is not a prime number.
-Your task can always be accomplished. For example, you can use Transfer Magic n times and transfer 1 Magic Diamond each time.


CONSTRAINTS
-n will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2

Returns: 2

We have to use Transfer Magic twice, each time we transfer 1 Magic Diamond.

1)
4294967297

Returns: 1

We just need to use Transfer Magic once, because 4294967297 is not a prime. We have 4294967297 = 641 * 6700417.

2)
2147483647

Returns: 2

This time n is a prime, so we have to use Transfer Magic at least twice. We have 2147483647 = 2147400000 + 83647 (83647 = 233 * 359, which is not a prime), thus the answer is 2.

3)
1

Returns: 1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; verify_case(0, Arg1, minimalTransfer(Arg0)); }
	void test_case_1() { long long Arg0 = 4294967297LL; long long Arg1 = 1LL; verify_case(1, Arg1, minimalTransfer(Arg0)); }
	void test_case_2() { long long Arg0 = 2147483647LL; long long Arg1 = 2LL; verify_case(2, Arg1, minimalTransfer(Arg0)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(3, Arg1, minimalTransfer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MagicDiamonds test;

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
