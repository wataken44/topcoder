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

class SubgridsCounter {

 public:
  int howMany(vector <int> x, vector <int> y)
  {
    int result = 0;
    int sz = x.size();

    set< pair<int, int> > points;

    TIMES(k, sz) {
      points.insert(make_pair(x[k], y[k]));
    }

    sort(y.begin(), y.end());
    sort(x.begin(), x.end());

    int maxlen = min(x.back() - x.front(), y.back() - y.front()) / 2;

    UPTO(len, 1, maxlen) {
      EACH(points, it) {
        int bx = it->first;
        int by = it->second;

        bool ok = true;
        UPTO(xi, 0, 2) {
          UPTO(yi, 0, 2) {
            int xx = bx + len * xi;
            int yy = by + len * yi;

            if(find(points.begin(), points.end(), make_pair(xx, yy)) == points.end()) {
              ok = false;
              break;
            }
          }
          if(!ok) break;
        }
        if(ok) ++result;
      }
    }
    
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// This problem contains images best viewed from the applet.

You are given several points on the plane.  Nine points form a 3x3 subgrid if they are 
situated on the vertices of a 2x2 rectangle of equal size squares.  The sides of the rectangle 
must be parallel to the coordinate axes.




The orange points form a subgrid among all the points on the picture.


You are given vector <int>s x and y, where (x[i], y[i]) are the coordinates of the i-th point on the plane. The points are distinct. Return the number of distinct subgrids you can create with these points.  Two subgrids are distinct if one contains a point that is not contained in the other.



DEFINITION
Class:SubgridsCounter
Method:howMany
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int howMany(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between -1000 and 1000, inclusive.
-Each element of y will be between -1000 and 1000, inclusive.
-All points represented by (x[i], y[i]) will be distinct.


EXAMPLES

0)
{0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3}
{0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3}

Returns: 4

This is a 4x4 regular grid.


1)
{7,0,14,0,7,14,14,0,7}
{14,0,14,14,7,7,0,7,0}

Returns: 1

This is a 3x3 grid. It forms the only subgrid by itself.

2)
{6,6,3,0,0,3,0,3,6,1,2}
{6,3,0,0,6,3,3,6,0,1,2}


Returns: 1



3)
{6,0,4,0,20,0,0,4,12,6,6,12,12,6,0,12,4,6,4,4,20,20,20,6,6,4,20,4,20,12,12,0,12,0,20}
{4,10,10,9,10,25,0,16,25,0,18,0,4,10,4,16,4,16,25,18,9,4,18,9,25,0,0,9,25,9,18,16,10,18,16}

Returns: 1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7,0,14,0,7,14,14,0,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14,0,14,14,7,7,0,7,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,6,3,0,0,3,0,3,6,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,3,0,0,6,3,3,6,0,1,2}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6,0,4,0,20,0,0,4,12,6,6,12,12,6,0,12,4,6,4,4,20,20,20,6,6,4,20,4,20,12,12,0,12,0,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,10,10,9,10,25,0,16,25,0,18,0,4,10,4,16,4,16,25,18,9,4,18,9,25,0,0,9,25,9,18,16,10,18,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SubgridsCounter test;

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
