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

class TheLuckyBasesDivTwo {

 public:
  long long find(long long n)
  {
    long long result = 0;
    // -- main code --

    if(n == 4 || n == 7) return -1;

    // BASE from 5 to 7
    UPTO(b, 5, 7) {
      long long nn = n;
      bool lucky = true;
      while(nn > 0) {
        if(nn % b != 4) {
          lucky = false;
          break;
        }
        nn = nn / b;
      }
      if(lucky) ++result;
    }

    // BASE from 8
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
John and Brus believe that the digits 4 and 7 are lucky and all others are not.



Recently, they became interested in numeral systems with different bases. Normally, people use the numeral system with base 10 to represent numbers, however, there exist numeral systems with other bases. More exactly, for each integer B, B >= 2, there exists a numeral system with base B. In this system, there are B different digits, used to represent numbers from 0 to B-1, inclusive. In order to represent a positive integer A in such system, it's necessary to find such digits a[n], a[n-1], ..., a[0], that A = a[n] * B^n + a[n-1] * B^(n-1) + ... + a[0] * B^0 (here ^ denotes the power operator), and then write these digits from left to right, in this exact order. For example, 255 = 4 * 62 + 7, therefore representation of number 255 in the numeral system with base 62 consists of two digits, the leftmost digit is 4 and the rightmost digit is 7.



The base of numeral system B is called lucky for some integer number A if all digits of the number A represented in numeral system with base B are the lucky digits (i.e. 4 and 7). For example, base 62 is lucky for the number 255.




You are given a long long n. Return the total number of lucky bases for the number n. If there are infinitely many such lucky bases, return -1 instead.


DEFINITION
Class:TheLuckyBasesDivTwo
Method:find
Parameters:long long
Returns:long long
Method signature:long long find(long long n)


CONSTRAINTS
-n will be between 1 and 10^12, inclusive.


EXAMPLES

0)
255

Returns: 1

The only lucky base for the number 255 is 62.
Note that base 52 is not lucky. Representation of 255 in this base contains digits 4 and 47. The digit 47 is not lucky, even though its decimal representation contains only lucky digits. Only the digits 4 and 7 are considered to be lucky.

1)
4

Returns: -1

All bases greater than 4 are lucky.

2)
13

Returns: 0

No lucky bases here.

3)
60

Returns: 2



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 255LL; long long Arg1 = 1LL; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { long long Arg0 = 4LL; long long Arg1 = -1LL; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 0LL; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { long long Arg0 = 60LL; long long Arg1 = 2LL; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TheLuckyBasesDivTwo test;

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
