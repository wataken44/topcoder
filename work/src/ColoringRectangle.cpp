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

class ColoringRectangle {

 public:
  int chooseDisks(int width, int height, vector <int> red, vector <int> blue)
  {
    double eps = 1e-5;

    int rsz = red.size();
    sort(red.begin(), red.end(), greater<int>());

    int bsz = blue.size();
    sort(blue.begin(), blue.end(), greater<int>());
    
    int result = INT_MAX;
    // -- main code --

    int hh = height * height;
    
    int i = 0;
    double x = 0.0;
    int c = 0;
    while(true) {

      if(i >= rsz) break;
      if(height > red[i]) break;

      x += sqrt(red[i] * red[i] - hh);
      ++c;
      
      if(x >= width + eps) {
        result = min(result, c);
        break;
      }
      
      if(i >= bsz) break;
      if(height > blue[i]) break;

      x += sqrt(blue[i] * blue[i] - hh);
      ++c;

      if(x >= width + eps) {
        result = min(result, c);
        break;
      }
      ++i;
    }

    i = 0;
    x = 0.0;
    c = 0;
    while(true) {

      if(i >= bsz) break;
      if(height > blue[i]) break;

      x += sqrt(blue[i] * blue[i] - hh);
      ++c;
      
      if(x >= width + eps) {
        result = min(result, c);
        break;
      }
      
      if(i >= rsz) break;
      if(height > red[i]) break;

      x += sqrt(red[i] * red[i] - hh);
      ++c;

      if(x >= width + eps) {
        result = min(result, c);
        break;
      }
      ++i;
    }
    
    return result == INT_MAX ? -1 : result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


You are given a white rectangle of size width by height. A green horizontal line (parallel to the width of the rectangle) is drawn through the middle of the rectangle so that it divides the rectangle into two congruent rectangles. This line extends infinitely out of the rectangle. You are asked to place red and blue disks (a disk is a circle and its interior) on the rectangle so that the entire rectangle is covered. The center of every disk must be placed on the green line, not necessarily within the rectangle bounds. Disks are placed sequentially from left to right, i.e., the center of each next placed disk must lie strictly to the right of the center of the last previously placed disk. Each disk is placed on top of all previously placed disks, i.e., when a disk is placed it covers any parts of previously placed disks that overlap. To challenge yourself, you have decided to only allow disk placements that satisfy the following additional constraint.


Every point covered by a newly placed disk must either

 not be covered by any previous disk or
 if covered by some previous disk then the topmost previous disk covering this point must be a different color than the newly placed disk.

You are given vector <int> red and vector <int> blue. The number of elements in red and blue corresponds to the number of red and blue disks you have, respectively. Each element of red or blue is the diameter of a red or blue disk, respectively. Note that each disk can only be used at most once. Find the smallest number of disks that can be placed as described above such that every point in the rectangle is covered by at least one disk. Return -1 if this is not possible.

DEFINITION
Class:ColoringRectangle
Method:chooseDisks
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int chooseDisks(int width, int height, vector <int> red, vector <int> blue)


CONSTRAINTS
-width and height will be between 1 and 10000, inclusive.
-red will contain between 1 and 50 elements, inclusive.
-blue will contain between 1 and 50 elements, inclusive.
-Every element of red will be between 1 and 10000, inclusive.
-Every element of blue will be between 1 and 10000, inclusive.
-To avoid precision problems, if the answer for an input is X >= 1, then it will be possible to cover a rectangle with height of height and width of width + 1e-5 with X disks (given the same set of disks). Furthermore, for any input with answer X, it will not be possible to cover a rectangle with height of height and width of width - 1e-5 using fewer than X disks from the same set (or using any amount of disks if X is -1).


EXAMPLES

0)
11
3
{5,5}
{2,5}

Returns: 3

A possible placement is as follows:


1)
30
5
{4,10,7,8,10}
{5,6,11,7,5}

Returns: 4



2)
16
4
{6,5,7}
{5}

Returns: -1

There are not enough blue disks.

3)
4
4
{5}
{6}

Returns: 1

The blue disk alone is enough to cover the rectangle.

4)
6
2
{6,6}
{2}

Returns: 3



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 3; int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 30; int Arg1 = 5; int Arr2[] = {4,10,7,8,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,6,11,7,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 4; int Arr2[] = {6,5,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(2, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 2; int Arr2[] = {6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ColoringRectangle test;

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
