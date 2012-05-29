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

class CirclesCountry {

 public:
  double dist(int x0, int y0, int x1, int y1)
  {
    return sqrt( 1.0 * pow(1.0 * x1 - x0, 2) + 1.0 * pow(1.0 * y1 - y0, 2) );
  }
  
  bool included(int x0, int y0, int r0, int x1, int y1, int r1)
  {
    return r0 + dist(x0, y0, x1, y1) <= r1;
  }
  
  int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
  {
    int sz = X.size();
    
    vector<int> parent(sz, -1);
    // -- main code --

    TIMES(k, sz + 3) {
      TIMES(a, sz) {
        TIMES(b, sz) {
          if(a == b) continue;
          if(included(X[a], Y[a], R[a], X[b], Y[b], R[b])) {
            if(parent[a] == -1) {
              parent[a] = b;
            }else {
              int c = parent[a];
              
            }
          }
        }
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
// Circles Country is a country that contains several circular-shaped districts.  Some districts may be situated inside other districts, but their borders do not intersect or touch.  Qatam is a resident of Circles Country.  When he travels between two locations, he always tries to cross the fewest number of district borders as possible because crossing borders is usually a laborious task.

Imagine Circles Country as an infinite plane.  You are given vector <int>s X, Y and R, where (X[i], Y[i]) are the coordinates of the i-th district's center and R[i] is its radius.  Qatam is currently at point (x1,y1) and he needs to get to point (x2,y2).  Neither of these points lies on a district border.  Return the minimal number of district borders he must cross to get to his destination.


DEFINITION
Class:CirclesCountry
Method:leastBorders
Parameters:vector <int>, vector <int>, vector <int>, int, int, int, int
Returns:int
Method signature:int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)


CONSTRAINTS
-X will contain between 1 and 50 elements, inclusive.
-X, Y and R will each contain the same number of elements.
-Each element of X and Y will be between -1000 and 1000, inclusive.
-Each element of R will be between 1 and 1000, inclusive.
-x1, y1, x2 and y2 will be between -1000 and 1000, inclusive.
-No two circumferences will have common points.
-The points (x1,y1) and (x2,y2) will not lie on any of the circumferences.


EXAMPLES

0)
{0}
{0}
{2}
-5
1
5
1

Returns: 0



1)
{0,-6,6}
{0,1,2}
{2,2,2}
-5
1
5
1

Returns: 2



2)
{1,-3,2,5,-4,12,12}
{1,-1,2,5,5,1,1}
{8,1,2,1,1,1,2}
-5
1
12
1

Returns: 3



3)
{-3,2,2,0,-4,12,12,12}
{-1,2,3,1,5,1,1,1}
{1,3,1,7,1,1,2,3}
2
3
13
2

Returns: 5



4)
{-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}
{175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}
{135,42,70,39,89,39,43,150,10,120,16,8}
102
16
19
-108

Returns: 3

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 0; verify_case(0, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = {0,-6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 2; verify_case(1, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {1,-3,2,5,-4,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,2,5,5,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8,1,2,1,1,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 12; int Arg6 = 1; int Arg7 = 3; verify_case(2, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {-3,2,2,0,-4,12,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,3,1,5,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,1,7,1,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 3; int Arg5 = 13; int Arg6 = 2; int Arg7 = 5; verify_case(3, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arr0[] = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {135,42,70,39,89,39,43,150,10,120,16,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 102; int Arg4 = 16; int Arg5 = 19; int Arg6 = -108; int Arg7 = 3; verify_case(4, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  CirclesCountry test;

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
