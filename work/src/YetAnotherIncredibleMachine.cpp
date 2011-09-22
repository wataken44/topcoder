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

class YetAnotherIncredibleMachine {

 public:
  int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls)
  {
    const int modulo = 1000000009;
    // -- main code --

    unsigned long long result = 1;

    sort(balls.begin(), balls.end());
    
    TIMES(i, platformMount.size()) {
      int mount = platformMount[i];
      int length = platformLength[i];

      int lmin = mount - length;
      int lmax = mount;

      TIMES(k, balls.size()) {
        int x = balls[k];

        if(x < mount - length || x > mount + length) {
          // do nothing;
        }else if(mount == x) {
          result = 0;
        }else if(x < mount) {
          lmin = max(lmin, x + 1);
        }else if(x > mount) {
          lmax = min(lmax, x - length - 1);
        }
      }
      
      if(lmax - lmin < 0) {
        result = 0;
      }else {
        result = (result * (lmax - lmin + 1)) % modulo;
      }
    }
    
    return result % modulo;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You may remember an old computer game called "The Incredible Machine". It was a game where you could simulate simple processes like balls falling, lasers shooting, or cats pursuing mice.
Manao is faced with the following problem in this game.

The game is 2-dimensional. To make solving the problem easier, Manao introduced the cartesian coordinates on the screen. The OX axis goes from left to right and coincides with the ground. The OY axis goes from bottom to top.

There are N horizontal platforms mounted at different heights. The length of the i-th platform is platformLength[i] and it is mounted at point (platformMount[i], i + 1). Each platform can be moved horizontally in such a way that it does not disconnect from its mount, i.e., the mount resides between its ends or on one of them. In other words, the leftmost possible position of the i-th platform is when its left end is at (platformMount[i] - platformLength[i], i + 1) and the rightmost position is when its right end is at (platformMount[i] + platformLength[i], i + 1). The platforms may only be moved by integer distances, so both left and right ends of a platform are always located at points with integer coordinates.

Several balls will simultaneously fall downwards to the ground from a height that is above all platforms. All balls will fall vertically and the i-th of them will fall at X-coordinate balls[i]. The balls are very small and can be considered as points. Manao should set the platforms' placement in such a way that no ball falls on a platform. Falling on an end of a platform counts as falling on a platform. Manao is not allowed to move the platforms once the balls start falling.

Count the number of ways to place the platforms so that all of the balls miss them. Return this number modulo 1,000,000,009. Two placements are different if there's a platform that has different positions in these placements.

DEFINITION
Class:YetAnotherIncredibleMachine
Method:countWays
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls)


CONSTRAINTS
-platformMount will contain between 1 and 50 elements, inclusive.
-Each element of platformMount will be between -10000 and 10000, inclusive.
-platformLength will contain the same number of elements as platformMount.
-Each element of platformLength will be between 1 and 10000, inclusive.
-balls will contain between 1 and 50 elements, inclusive.
-Each element of balls will be between -10000 and 10000, inclusive.
-All elements of balls will be distinct.


EXAMPLES

0)
{7}
{10}
{3,4}

Returns: 3

A platform of length 10 is mounted at point (7, 1). Two balls will fall at coordinates 3 and 4. There are three placements of the platform which let the ball miss it: setting the platform's left end at X-coordinate 5, 6 and 7.

1)
{1,4}
{3,3}
{2,7}

Returns: 1

The only placement which ensures that balls land aside the platforms is when platform 0's right end is at point (1, 1) and platform 1's left end is at (3, 2).

2)
{4,4,4}
{10,9,8}
{1,100}

Returns: 27

There are 3 possible placements for each of the platforms.

3)
{0}
{1}
{0}

Returns: 0

There is no way to move the platform away from the ball's trajectory.

4)
{100, -4215, 251}
{400, 10000, 2121}
{5000, 2270, 8512, 6122}

Returns: 250379170



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,9,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 27; verify_case(2, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {100, -4215, 251}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {400, 10000, 2121}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5000, 2270, 8512, 6122}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 250379170; verify_case(4, Arg3, countWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  YetAnotherIncredibleMachine test;

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
