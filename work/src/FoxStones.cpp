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

class UnionFindTree {
 public:
  UnionFindTree(int size) : m_parent(size, -1) {}
  virtual ~UnionFindTree() {}

  void Unite(const int& a, const int& b)
  {
    int ra = Root(a);
    int rb = Root(b);
    if(ra == rb) return;

    int ca = Count(ra);
    int cb = Count(rb);

    if(ca > cb || (ca == cb && a < b) ) {
      m_parent[ra] += m_parent[rb];
      m_parent[rb] = ra;
    }else {
      m_parent[rb] += m_parent[ra];
      m_parent[ra] = rb;
    }
  }

  int Root(int a)
  {
    while(!IsRoot(a)) {
      int p = Parent(a);
      if(!IsRoot(p)) {
        m_parent[a] = m_parent[p];
      }
      a = p;
    }
    return a;
  }

  bool IsRoot(const int& a) const
  {
    return m_parent[a] < 0;
  }

  int Parent(const int& a) const
  {
    return m_parent[a];
  }

  int Count(const int& a)
  {
    return -m_parent[Root(a)];
  }

  void Dump()
  {
    for(int i = 0; i < static_cast<int>(m_parent.size()); ++i) {
      cout << m_parent[i] << " ";
    }
    cout << endl;
  }
  
 private:
  vector<int> m_parent;
};


class FoxStones {

 public:

  typedef long long llong;
  int getCount(int N, int M, vector <int> sx, vector <int> sy)
  {
    // -- main code --

    const llong modulo = 1000000009;

    int tsz = N * M;
    UnionFindTree uft(tsz);

    int msz = sx.size();

    int sx0 = sx[0] - 1;
    int sy0 = sy[0] - 1;
    
    TIMES(i0, tsz) {
      int x0 = i0 % N;
      int y0 = i0 / N;

      int dx0 = x0 - sx0;
      int dy0 = y0 - sy0;

      int cx = sx0 - dx0;
      int cy = sy0 - dy0;

      bool all;
      all = true;
      TIMES(k, msz) {
        if(dist(x0, y0, sx, sy) != dist(cx, y0, sx, sy)) {
          all = false;
          break;
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
// Fox Ciel has a rectangular board separated into 1x1 cells.  The board is N cells wide and M cells high.  Columns are numbered 1 to N from left to right, and rows are numbered 1 to M from top to bottom.  A cell in column x, row y is said to have coordinates (x, y).  Each cell contains a stone, and all stones are different.  Also, some cells are marked.  These marked cells are given in the vector <int>s sx and sy, where (sx[i], sy[i]) are the coordinates of the i-th marked cell.

Ciel is interested to know how many layouts of the same stones on this board are similar to the current layout.  Two layouts are considered to be similar if, for each possible pairing of a stone and a marked cell, the distance between the stone and the marked cell is the same in both layouts.  The distance between cells with coordinates (xA, yA) and (xB, yB) is defined as max{|xA-xB|, |yA-yB|}, where |z| is the absolute value of z.

Return the number of layouts that are similar to the current layout, modulo 1,000,000,009. Note that according to the definition above, the current layout is similar to itself, so it should also be counted.


DEFINITION
Class:FoxStones
Method:getCount
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int getCount(int N, int M, vector <int> sx, vector <int> sy)


CONSTRAINTS
-N and M will each be between 1 and 200, inclusive.
-sx and sy will each contain between 1 and 50 elements, inclusive.
-sx and sy will contain the same number of elements.
-Each element of sx will be between 1 and N, inclusive.
-Each element of sy will be between 1 and M, inclusive.
-No two cells represented by sx and sy will have the same coordinates.


EXAMPLES

0)
6
1
{3}
{1}

Returns: 4

There are 4 similar layouts:



1)
2
2
{2}
{1}

Returns: 6



2)
3
3
{1,2,3}
{1,2,3}

Returns: 8



3)
12
34
{5,6,7,8,9,10}
{11,12,13,14,15,16}

Returns: 410850247



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(1, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 8; verify_case(2, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 34; int Arr2[] = {5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11,12,13,14,15,16}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 410850247; verify_case(3, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxStones test;

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
