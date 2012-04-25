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

class MaximumScoredNumber {

 public:
  int getNumber(int lowerBound, int upperBound)
  {
    map<int, int> score;

    TIMES(a, 110) {
      FOR(b, a, 110) {
        int n = a * a + b * b;
        if(score.find(n) == score.end()) score[n] = 0;
        ++score[n];
      }
    }

    int ms = -1;
    int mn = -1;

    UPTO(n, lowerBound, upperBound) {
      if(ms <= score[n]) {
        ms = score[n];
        mn = n;
      }
    }
    
    // -- main code --
    
    return mn;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In her favorite Math class, Little Bonnie learned that some non-negative integers can be represented as the sum of the squares of two non-negative integers. For example, 13 can be represented as 2*2 + 3*3.


Bonnie later discovered that some of those integers can even be represented by more than one possible pair.  For example, 25 can be represented as 0*0 + 5*5, and it can also be represented as 3*3 + 4*4.


She has defined the score of an integer as the number of different ways it can be represented as the sum of the squares of two non-negative integers.  The order of the two squared integers is not important.  In other words, a*a + b*b is equivalent to b*b + a*a, so they should only count once in the score.  So, 25 has a score of 2, 2 has a score of 1 (2 = 1*1 + 1*1), 1 also has a score of 1 (1 = 0*0 + 1*1) and 3 has a score of 0.


Bonnie needs your help in solving the following problem. She wants to find the integer between lowerBound and upperBound, inclusive, with the maximum score.  If multiple integers have the same highest score, return the largest among them.

DEFINITION
Class:MaximumScoredNumber
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int lowerBound, int upperBound)


CONSTRAINTS
-upperBound will be between 0 and 10000, inclusive.
-lowerBound will be between 0 and upperBound, inclusive.


EXAMPLES

0)
0
2

Returns: 2

In the range 0 to 2, the numbers have the following scores:

0 has a score of 1: 0 = 0*0 + 0*0 
1 has a score of 1: 1 = 0*0 + 1*1 
2 has a score of 1: 2 = 1*1 + 1*1 

All of them have the same score. Number 2 is the biggest so it is returned.

1)
0
30

Returns: 25

25 is the only number between 0 and 30 having a score of 2.

2)
0
0

Returns: 0



3)
5
99

Returns: 85



4)
0
10000

Returns: 9425



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 30; int Arg2 = 25; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 99; int Arg2 = 85; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 10000; int Arg2 = 9425; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MaximumScoredNumber test;

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
