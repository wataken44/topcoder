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

class BinaryPolynomialDivOne {

 public:
  int findCoefficient(vector <int> a, long long m, long long k)
  {
    int n = a.size();
    vector<int> mb;

    int mm = m;
    while(m > 0) {
      mb.push_back(m % 2);
      m /= 2;
    }

    int result = 0;
    // -- main code --

    TIMES(d, mb.size()) {
      if(mb[0] == 0) continue;
      
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

In this problem we will consider binary polynomials. A binary polynomial P of degree n, where n is a nonnegative integer, is given by a sequence of coefficients: n+1 zeroes and ones a[0], a[1], ..., a[n], where a[n] = 1. They represent the following:

P(x) = a[0] * x0 + a[1] * x1 + ... + a[n] * xn

Binary polynomials can be evaluated in points 0, 1 and multiplied by each other just like ordinary polynomials, with one exception: all calculations take place modulo 2. For example, we assume that (x + x3) * (1 + x2) = x + 2 * x3 + x5 = x + x5. Since we can multiply binary polynomials, we can also raise them to positive integer powers; for example, if P = 1 * x0 + 0 * x1 + 1 * x2 and m = 3, then Pm = 1 * x0 + 0 * x1 + 1 * x2 + 0 * x3 + 1 * x4 + 0 * x5 + 1 * x6.


You are given integers m, k and a binary polynomial P as the array a of its coefficients. Return the coefficient that stands by xk in the binary polynomial Pm.

DEFINITION
Class:BinaryPolynomialDivOne
Method:findCoefficient
Parameters:vector <int>, long long, long long
Returns:int
Method signature:int findCoefficient(vector <int> a, long long m, long long k)


CONSTRAINTS
-The degree of P will be between 0 and 49, inclusive.
-a will contain exactly n+1 elements, where n is the degree of P.
-Each element of a will be either 0 (zero) or 1 (one).
-a[n] will be equal to 1 (one).
-m will be between 1 and 1016, inclusive.
-k will be between 0 and n * m, inclusive.


EXAMPLES

0)
{1, 0, 1}
3
4

Returns: 1

This corresponds to the example from the problem statement. Pm equals 1 + x2 + x4 + x6. The coefficient by x4 is hence 1.

1)
{1, 0, 1}
3
5

Returns: 0

This is the same polynomial as in the previous example.

2)
{0, 0, 1, 1, 0, 1}
7
15

Returns: 1



3)
{1}
1
0

Returns: 1



4)
{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0,
 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1}
2229508454872453
96130299655104846

Returns: 1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; long long Arg2 = 4LL; int Arg3 = 1; verify_case(0, Arg3, findCoefficient(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; long long Arg2 = 5LL; int Arg3 = 0; verify_case(1, Arg3, findCoefficient(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; long long Arg2 = 15LL; int Arg3 = 1; verify_case(2, Arg3, findCoefficient(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; long long Arg2 = 0LL; int Arg3 = 1; verify_case(3, Arg3, findCoefficient(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0,
 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2229508454872453LL; long long Arg2 = 96130299655104846LL; int Arg3 = 1; verify_case(4, Arg3, findCoefficient(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BinaryPolynomialDivOne test;

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
