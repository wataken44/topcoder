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

class Underprimes {

 public:
  int howMany(int A, int B)
  {
    const int N = B + 20;
    vector<bool> sieve(N, true);

    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i * i <= N; ++i) {
      if(!sieve[i]) continue;
      for(int j = 2; j * i < N; ++j) {
        sieve[j * i] = false;
      }
    }

    vector<int> prime;
    TIMES(i, N) {
      if(sieve[i]) prime.push_back(i);
    }

    
    int result = 0;
    // -- main code --

    UPTO(i, A, B) {
      if(sieve[i]) continue;

      int c = 0;
      int n = i;
      int k = 0;
      while(n > 1) {
        int p = prime[k];
        if(n % p == 0) {
          while(n % p == 0) {
            ++c;
            n /= p;
          }
        }else {
          k += 1;
        }
      }
      if(sieve[c]) ++result;
                                
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// The prime factorization of a number X is the list of prime numbers that multiply together to form X.  For example, the prime factorization of 12 is 2 * 2 * 3.  Note that 1 is not a prime number.
An underprime is a number whose prime factorization contains a prime number of elements.  For example, 12 is an underprime because its prime factorization contains 3 elements, and 3 is a prime number.  Given ints A and B, return the number of underprimes between A and B, inclusive.

DEFINITION
Class:Underprimes
Method:howMany
Parameters:int, int
Returns:int
Method signature:int howMany(int A, int B)


NOTES
-A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-All prime factorizations of the same integer always contain the same prime numbers and can only differ by the order of primes within them.


CONSTRAINTS
-A will be between 2 and 100000, inclusive.
-B will be between A and 100000, inclusive.


EXAMPLES

0)
2
10

Returns: 5

The underprimes in this interval are: 4, 6, 8, 9, 10.

1)
100
105

Returns: 2

The underprimes in this interval are 102 = 2 * 3 * 17 and 105 = 3 * 5 * 7.

2)
17
17

Returns: 0

17 is a prime number, so its prime factorization contains one element. 1 is not a prime, so 17 is not an underprime.

3)
123
456

Returns: 217



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 105; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 217; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Underprimes test;

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
