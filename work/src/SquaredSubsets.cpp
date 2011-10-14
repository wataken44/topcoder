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

class SquaredSubsets {

 public:
  long long countSubsets(int n, vector <int> x, vector <int> y)
  {
    long long result = 0;
    // -- main code --

    int sz = x.size();
    
    TIMES(k, sz) {
      FOR(j, k+1, sz) {
        if(x[k] > x[j]) {
          swap(x[k], x[j]);
          swap(y[k], y[j]);
        }else if(x[k] == x[j] && y[k] > y[j]) {
          swap(x[k], x[j]);
          swap(y[k], y[j]);
        }
      }
    }

    vector< vector<int> > dx(sz, vector<int>(sz, 0));
    vector< vector<int> > dy(sz, vector<int>(sz, 0));

    TIMES(k, sz) {
      TIMES(j, sz) {
        dx[k][j] = abs(x[k] - x[j]);
        dy[k][j] = abs(y[k] - y[j]);
      }
    }

    TIMES(k, sz) {
      int kx = x[k];
      int ky = y[k];

      int li = 0;
      for(li = 0; li < sz; ++li) {
        if(x[li] >= kx - n) break;
      }

      int ri = 0;
      for(ri = 0; ri < sz; ++ri) {
        if(x[ri] > kx + n) break;
      }

      vector<int> cy;
      for(int j = k + 1; j < ri; ++j) {
        cy.push_back(y[j]);
      }

      sort(cy.begin(), cy.end());

      int cc = 0;
      EACH(cy, cit) {
        if(abs(*cit - ky) <= n) {
          ++result;
          ++cc;
        }
      }

      if(cc != 0) {
        vector<int> ey;
        for(int j = li; j < k; ++j) {
          ey.push_back(y[j]);
        }
        sort(ey.begin(), ey.end());
        bool all = true;
        EACH(ey, eit) {
          if(abs(*eit - ky) <= n) {
            all = false;
            break;
          }
        }
        if(all) {
          ++result;
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
// 
Given a set of points in the XY plane and an integer n, a subset P of those points is called n-squared if it is not empty and there exists a square of side n in the XY plane with its sides parallel to the axes such that a point from the given set of points is in P if and only if it is contained within the square. A point lying on a side or a vertex of the square is considered to be contained in it.

You will be given n as explained in the input. You will also be given two vector <int>s x and y such that the coordinates of point i are (x[i],y[i]). Return the number of n-squared subsets in the input set described by x and y.


DEFINITION
Class:SquaredSubsets
Method:countSubsets
Parameters:int, vector <int>, vector <int>
Returns:long long
Method signature:long long countSubsets(int n, vector <int> x, vector <int> y)


CONSTRAINTS
-n will be between 1 and 100000000 (10^8), inclusive.
-x and y will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x and y will be between -100000000 (-10^8) and 100000000 (10^8), inclusive.
-All described points will be different.


EXAMPLES

0)
5
{-5,0,5}
{0,0,0}

Returns: 5

The following subsets are squared: {(-5,0)}, {(0,0)}, {(5,0)}, {(-5,0),(0,0)}, {(0,0),(5,0)}.

1)
10
{-5,0,5}
{0,0,0}

Returns: 5

The following subsets are squared: {(-5,0)}, {(5,0)}, {(0,0),(5,0)}, {(-5,0),(0,0)}, {(-5,0),(0,0),(5,0)}.

2)
100000000
{-1,-1,-1,0,1,1,1}
{-1,0,1,1,-1,0,1}

Returns: 21



3)
5
{5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}
{0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}

Returns: 66



4)
1
{-1,0}
{0,0}

Returns: 3



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(0, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100000000; int Arr1[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,0,1,1,-1,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 21LL; verify_case(2, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 66LL; verify_case(3, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(4, Arg3, countSubsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SquaredSubsets test;

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
