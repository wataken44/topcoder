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

class EllysXors {

 public:
  typedef long long ll;

  long long getXor(long long L, long long R)
  {
    if( L == R) return L;

    long long result = 0;
    // -- main code --

    ll c = R - L + 1;
    
    if( L % 2 == 1 ) {
      result ^= L;
      --c;
    }
    if( R % 2 == 0 ) {
      result ^= R; 
      --c;
    }
    if(c >= 0) {
      result ^= ((c / 2) % 2);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// XOR problems became very popular in TopCoder recently. (If you do not know the bitwise operation XOR, see the Notes section for an explanation.) That's why Elly decided to invent one of her own. Fortunately for you, the one she came up with is quite simple. You are given two long longs L and R. She wants you to find the XOR of all numbers between L and R, inclusive.

DEFINITION
Class:EllysXors
Method:getXor
Parameters:long long, long long
Returns:long long
Method signature:long long getXor(long long L, long long R)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
-One of the ways to calculate the XOR of more than two numbers A1, A2, ..., An is "A1 XOR (A2 XOR (... XOR An))..))". Since the function is commutative and associative, you can also express it as "A1 XOR A2 XOR ... XOR An" and group the operands in any way you like.
-It can be proved that the answer is always less than 2*R for the given constraints.


CONSTRAINTS
-L and R will be between 1 and 4,000,000,000, inclusive.
-L will be less than or equal to R.


EXAMPLES

0)
3
10

Returns: 8


((((((3 XOR 4) XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 =
        (((((7 XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 = 
                ((((2 XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 = 
                        (((4 XOR 7) XOR 8) XOR 9) XOR 10 = 
                                ((3 XOR 8) XOR 9) XOR 10 =
                                       (11 XOR 9) XOR 10 =
                                                2 XOR 10 = 8.


1)
5
5

Returns: 5

The XOR of a single number is the number itself.

2)
13
42

Returns: 39

A bit larger example.

3)
666
1337

Returns: 0

The answer can be zero.

4)
1234567
89101112

Returns: 89998783



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 10LL; long long Arg2 = 8LL; verify_case(0, Arg2, getXor(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 5LL; long long Arg2 = 5LL; verify_case(1, Arg2, getXor(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 42LL; long long Arg2 = 39LL; verify_case(2, Arg2, getXor(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 666LL; long long Arg1 = 1337LL; long long Arg2 = 0LL; verify_case(3, Arg2, getXor(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1234567LL; long long Arg1 = 89101112LL; long long Arg2 = 89998783LL; verify_case(4, Arg2, getXor(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  EllysXors test;

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
