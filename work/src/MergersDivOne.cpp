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

class MergersDivOne {

 public:
  double findMaximum(vector <int> revenues)
  {
    sort(revenues.begin(), revenues.end());

    if(revenues.size() == 0) return revenues[0];
    
    double result = (revenues[0] + revenues[1]) / 2.0;
    // -- main code --

    FOR(k, 2, revenues.size()) {
      result = (result + revenues[k]) / 2; 
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

The candy industry is going through a hard time in Byteland. Some of the biggest companies in the business have decided to perform a series of mergers so as to become one company in the end. Surprisingly, empirical studies conducted by the economists of Byteland have shown that for any m >= 2 the revenue of a company that is created by simultainously merging m companies with revenues equal to r0, r1, ..., rm - 1 is equal to the average of these revenues, that is (r0 + r1 + ... + rm - 1) / m.


You are given a vector <int> revenues. The revenue of the i-th of the companies that want to merge is equal to revenues[i]. Return the maximum possible revenue of the final company that can be created in any series of mergers that joins all the companies. In each of the mergers, we may merge as many of the currently existing companies as we wish.

DEFINITION
Class:MergersDivOne
Method:findMaximum
Parameters:vector <int>
Returns:double
Method signature:double findMaximum(vector <int> revenues)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-Please note that the revenue of a company may be negative; this means that the company is actually losing money.
-It is always possible to merge all companies into a single one: for example, by merging all of them in a single step.


CONSTRAINTS
-revenues will contain between 2 and 50 elements, inclusive.
-Each element of revenues will be between -1,000 and 1,000, inclusive.


EXAMPLES

0)
{5, -7, 3}

Returns: 1.5

The optimal way is to first merge companies 1 and 2, obtaining a company with total revenue -2, and then merge that company with company 0.

1)
{10, -17}

Returns: -3.5



2)
{12, 12, 12, 12, 12}

Returns: 12.0

We can just merge all the companies at once.

3)
{0, 0, 0, 0, 0, 100}

Returns: 50.0

We may first merge companies 0 through 4 and then merge the resulting company with company 5.

4)
{10, -10, 100, -100, 1000, -1000}

Returns: 491.25



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, -7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(0, Arg1, findMaximum(Arg0)); }
	void test_case_1() { int Arr0[] = {10, -17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -3.5; verify_case(1, Arg1, findMaximum(Arg0)); }
	void test_case_2() { int Arr0[] = {12, 12, 12, 12, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 12.0; verify_case(2, Arg1, findMaximum(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 0, 0, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 50.0; verify_case(3, Arg1, findMaximum(Arg0)); }
	void test_case_4() { int Arr0[] = {10, -10, 100, -100, 1000, -1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 491.25; verify_case(4, Arg1, findMaximum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MergersDivOne test;

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
