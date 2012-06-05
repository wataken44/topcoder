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

class PyramidOfCubes {

 public:
  typedef long long ll;

  double surface(int K)
  {
    // -- main code --
    ll k = 0;
    ll c = 1;
    while(true) {
      k += c * c;
      if(k >= K) {
        break;
      }
      ++c;
    }

    // DUMP(c);
    double result = 0;
    if(K >= c * c) {
      result = 2 * c * c;
    }else {
      result = 2 * K;
    }
    
    DOWNTO(m, c, 1) {
      // DUMP(m);DUMP(result);DUMP(k);
      if(K >= m * m) {
        result += 4 * m;
        K -= m * m;
      }else {
        if(K >= m) {
          result += 2 * m;
        }else {
          result += 2 * K;
        }
        int l = (K % m == 0) ? K / m : K / m + 1;
        result += 2 * l;
        break;
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
// 
Consider a N-level pyramid built of unit cubes. An example for N=3 can be seen in the image below.





Formally, a pyramid of size N has N levels, where the i-th level (counting from the top) contains an i by i grid of unit cubes.



You have K cubes. First, you select a suitable pyramid size as follows: If K is exactly the number of cubes necessary to build a pyramid of size N for some N, you pick that size. Otherwise, you pick the smallest pyramid size you can not build.



Now you start building the pyramid in a systematic bottom-up way. First you build the complete bottom level, then you build the level above that, etc. When building a level, also proceed in a systematic way, starting the next row only when the previous one is full.



For example, for 21 cubes you should get the following incomplete pyramid:





Given an int K specifying the number of cubes you have, return the surface area of the possibly incomplete pyramid you will build according to the instructions above.


DEFINITION
Class:PyramidOfCubes
Method:surface
Parameters:int
Returns:double
Method signature:double surface(int K)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-The bottom sides of the cubes on the bottommost level are a part of the surface.


CONSTRAINTS
-K will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
14

Returns: 42.0

The first example from the problem statement.

1)
21

Returns: 58.0

The second example from the problem statement.

2)
1

Returns: 6.0

A single cube.

3)
2

Returns: 10.0

Two cubes next to each other.

4)
451234

Returns: 47498.0

Quite a lot of cubes.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; double Arg1 = 42.0; verify_case(0, Arg1, surface(Arg0)); }
	void test_case_1() { int Arg0 = 21; double Arg1 = 58.0; verify_case(1, Arg1, surface(Arg0)); }
	void test_case_2() { int Arg0 = 1; double Arg1 = 6.0; verify_case(2, Arg1, surface(Arg0)); }
	void test_case_3() { int Arg0 = 2; double Arg1 = 10.0; verify_case(3, Arg1, surface(Arg0)); }
	void test_case_4() { int Arg0 = 451234; double Arg1 = 47498.0; verify_case(4, Arg1, surface(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PyramidOfCubes test;

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
