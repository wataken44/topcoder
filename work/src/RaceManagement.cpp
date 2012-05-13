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

class RaceManagement {

 public:
  double getPayoutFactor(vector <int> probability, vector <int> amounts, int minimumMoney)
  {
    int sz = probability.size();
    int w = 1 << sz;
    
    double ea = 0;
    double pa = 0;

    TIMES(k, w) {
      double prob = 1.0;
      double earn = 0;
      double pay = 0;

      int ws = 0;
      TIMES(i, sz) {
        if( 1 == ( 1 & (k >> i) ) ) {
          ++ws;
        }
      }

      TIMES(i, sz) {
        if( 1 == ( 1 & (k >> i) ) ) {
          if(ws == 1) {
            pay += amounts[i];
          }else {
            earn += amounts[i];
          }
          prob *= 0.01 * probability[i];
        } else {
          earn += amounts[i];
          prob *= (1.0 - 0.01 * probability[i]);
        }
      }

      ea += prob * earn;
      pa += prob * pay; 
    }

    // total = ea - pa * P;

    if(ea < minimumMoney) {
      return -1.0;
    }else if(pa == 0.0) {
      return -2.0;
    }else {
      return (- minimumMoney + ea) / pa;
    }
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Your company runs a horse race betting service. Each person bets on a horse, and if that horse wins outright (i.e., it wins alone and doesn't tie for the win with any other hose), the person will win back their money plus a multiple of the amount they bet.  This multiple is called a payout factor. In all other cases your company keeps the money.  You are given a vector <int> probability and a vector <int> amounts.  The ith element of probability is the percentage chance of the ith horse winning the race, and the ith element of amounts is the amount bet on the ith horse. 
These probabilities are independent (see example 1 for clarification).
Return the highest payout factor such that the expected earnings of the company is minimumMoney or higher. If you can not achieve minimumMoney with a non-negative payout factor, then return -1. If you can achieve minimumMoney with any payout factor, then return -2.

DEFINITION
Class:RaceManagement
Method:getPayoutFactor
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double getPayoutFactor(vector <int> probability, vector <int> amounts, int minimumMoney)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-probability will contain between 1 and 5 elements, inclusive.
-Each element of probability will be between 0 and 100, inclusive.
-Each element of amounts will be between 0 and 1000, inclusive.
-amounts will contain the same number of elements as probability.
-The sum of all the elements in probability will be at most 100.
-minimumMoney will be between 0 and 1000, inclusive.


EXAMPLES

0)
{30}	
{100}
10

Returns: 2.0

Horse 1 has a 30% chance of winning.  If it wins, the company has to pay out 100*P dollars, where P is the payout factor, and if it doesn't win, the company gains 100 dollars.  Thus, the expected earnings of the compay is 70-30*P.  The highest payout factor that ensures  this is at least 10 is 2.

1)
{50,40}
{300,200}
100

Returns: 2.076923076923077

Horse A has a 50% chance of winning and horse B has a 40% chance of winning. But this also means that there is a 20% chance they tie and a remaining 30% chance neither of them wins.


Thus, in this scenario, 4 cases arise

Horse A wins 30% chance => The company loses 300*P dollars and gains 200 dollars

Horse B wins 20% chance => The company loses 200*P dollars and gains 300 dollars

Horse A & B both win (tie) 20% chance => The company loses 0*P dollars and gains 500 dollars

Neither Horse A nor horse B wins (No result) 30% chance => The company loses 0*P dollars and gains 500 dollars


To ensure the expected earnings are at least 100, the payout factor P can be at most approximately 2.077.

2)
{50}	
{100}
1000

Returns: -1.0

Return -1 because the payout factor in this case will be negative. 

3)
{0}
{100}	
100

Returns: -2.0

The payout factor is irrelevant. The company always gains 100 dollars.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {30}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; double Arg3 = 2.0; verify_case(0, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {50,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {300,200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = 2.076923076923077; verify_case(1, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = -1.0; verify_case(2, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}	; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = -2.0; verify_case(3, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RaceManagement test;

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
