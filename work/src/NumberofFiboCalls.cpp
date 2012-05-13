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

class NumberofFiboCalls {

 public:
  vector <int> fiboCallsMade(int n)
  {
    vector <int> result(2, 0);
    // -- main code --

    vector< vector<int> > dp(n + 4, vector<int>(2, 0));

    dp[0][0] = 1;
    dp[1][1] = 1;

    UPTO(i, 2, n) {
      TIMES(k, 2) dp[i][k] = dp[i - 1][k] + dp[i - 2][k];
    }

    result[0] = dp[n][0];
    result[1] = dp[n][1];
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Look at the following pseudo-code, which computes the n-th Fibonacci number:

int fibonacci(int n)
	begin
	if n equals 0
		begin
		print(0)
		return 0
		end
	if n equals 1
		begin
		print(1)
		return 1
		end
	return fibonacci(n - 1) + fibonacci(n - 2)
	end


For example, if one calls fibonacci(3), then the following will happen:

fibonacci(3) calls fibonacci(2) and fibonacci(1) (the first call).
fibonacci(2) calls fibonacci(1) (the second call) and fibonacci(0).
The second call of fibonacci(1) prints 1 and returns 1.
fibonacci(0) prints 0 and returns 0.
fibonacci(2) gets the results of fibonacci(1) and fibonacci(0) and returns 1.
The first call of fibonacci(1) prints 1 and returns 1.
fibonacci(3) gets the results of fibonacci(2) and fibonacci(1) and returns 2.

In total, '1' will be printed twice and '0' will be printed once.


We want to know how many times '0' and '1' will be printed for a given n. You are to return a vector <int> which contains exactly two elements. The first and second elements of the return value must be equal to the number of times '0' and '1', respectively, will be printed during a fibonacci(n) call.


DEFINITION
Class:NumberofFiboCalls
Method:fiboCallsMade
Parameters:int
Returns:vector <int>
Method signature:vector <int> fiboCallsMade(int n)


CONSTRAINTS
-n will be between 0 and 40, inclusive.


EXAMPLES

0)
0

Returns: {1, 0 }

If I call the Fibonacci function with n = 0, it just calls the 1st base case. Hence, the result is {1,0}.

1)
3

Returns: {1, 2 }

The test case given in the problem statement.

2)
6

Returns: {5, 8 }

3)
22

Returns: {10946, 17711 }

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arr1[] = {1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, fiboCallsMade(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, fiboCallsMade(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {5, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, fiboCallsMade(Arg0)); }
	void test_case_3() { int Arg0 = 22; int Arr1[] = {10946, 17711 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, fiboCallsMade(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  NumberofFiboCalls test;

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
