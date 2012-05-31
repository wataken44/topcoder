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

class PipeCuts {

 public:
  double probability(vector <int> weld, int L)
  {
    int sz = weld.size();

    sort(weld.begin(), weld.end());
    
    int cnt = 0;
    int all = 0;

    TIMES(a, sz) {
      FOR(b, a+1, sz) {
        int l0 = weld[a];
        int l1 = weld[b] - weld[a];
        int l2 = 100 - weld[b];

        ++all;
        if(l0 > L || l1 > L || l2 > L) {
          // DUMP(a);DUMP(b);DUMP(l0);DUMP(l1);DUMP(l2);
          ++cnt;
        }
      }
    }
    
    return 1.0 * cnt / all;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A 100 meter long pipe must be cut in two places.  It can only be cut at certain places, where it was originally welded from smaller pipes.  If the two cut locations are chosen at random (each potential location has equal probability of being chosen), find the probability of a resulting pipe being longer than L meters.


Create a method named probability that accepts a int[] weldLocations and int L as parameters.  It should calculate the probability of one or more resulting pipes being strictly longer than L if the two cut locations are chosen at random from weldLocations.  Each element in weldLocations represents the number of meters from the left end of the pipe.

DEFINITION
Class:PipeCuts
Method:probability
Parameters:vector <int>, int
Returns:double
Method signature:double probability(vector <int> weldLocations, int L)


NOTES
-Your return value must have a relative or absolute error less than 1e-9.


CONSTRAINTS
-weldLocations will have between 2 and 50 elements, inclusive.
-Each element in weldLocations will be between 1 and 99, inclusive.
-weldLocations will not contain duplicate elements.
-L will be between 1 and 100, inclusive.


EXAMPLES

0)
{25, 50, 75}
25

Returns: 1.0

Any random set of cuts results in a pipe being longer than 25 meters.

1)
{25, 50, 75}
50

Returns: 0.0

This time, it is impossible to cut the pipe such that some resulting pipe is longer than 50 meters.

2)
{25, 50, 75}
24

Returns: 1.0

3)
{99, 88, 77, 66, 55, 44, 33, 22, 11}
50

Returns: 0.7222222222222222

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25, 50, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; double Arg2 = 1.0; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {25, 50, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.0; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {25, 50, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; double Arg2 = 1.0; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {99, 88, 77, 66, 55, 44, 33, 22, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.7222222222222222; verify_case(3, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PipeCuts test;

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
