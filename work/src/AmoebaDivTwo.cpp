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

class AmoebaDivTwo {

 public:
  int count(vector <string> table, int K)
  {
    int result = 0;
    // -- main code --

    int xsz = table[0].size();
    int ysz = table.size();

    DUMP(table);
    
    for(int y = 0; y + K <= ysz; ++y) {
      for(int x = 0; x < xsz; ++x) {
        bool all = true;
        for(int yy = 0; yy < K; ++yy) {
          if(table[y+yy][x] != 'A') {
            //DUMP(y + yy); DUMP(x); DUMP(table[y+yy]);
            all = false;
            break;
          }
        }
        if(all) {
          ++result;
          //DUMP(y); DUMP(x);
        }
      }
    }

    if(K != 1) {
      for(int y = 0; y < ysz ; ++y) {
        for(int x = 0; x + K <= xsz; ++x) {
          bool all = true;
          for(int xx = 0; xx < K; ++xx) {
            if(table[y][x+xx] != 'A') {
              all = false;
              break;
            }
          }
          if(all) ++result;
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
// Little Romeo likes cosmic amoebas a lot.  Recently he received one as a gift from his mother.  He decided to place his amoeba on a rectangular table.  The table is a grid of square 1x1 cells, and each cell is occupied by either matter or antimatter.  The amoeba is a rectangle of size 1xK.  Romeo can place it on the table in any orientation as long as every cell of the table is either completely covered by part of the amoeba or completely uncovered, and no part of the amoeba lies outside of the table.  It is a well-known fact that cosmic amoebas cannot lie on top of matter, so every cell of the table covered by the amoeba must only contain antimatter. 

You are given a vector <string> table, where the j-th character of the i-th element is 'A' if the cell in row i, column j of the table contains antimatter or 'M' if it contains matter.  Return the number of different ways that Romeo can place the cosmic amoeba on the table.  Two ways are considered different if and only if there is a table cell that is covered in one but not the other.

DEFINITION
Class:AmoebaDivTwo
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> table, int K)


CONSTRAINTS
-table will contain between 1 and 50 elements, inclusive.
-Each element of table will contain between 1 and 50 characters, inclusive.
-All elements of table will have the same length.
-Each character of each element of table will be either 'A' or 'M'.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
{"MA"}
2

Returns: 0

The amoeba requires a 1x2 or 2x1 rectangle containing only antimatter, but there is no such space available on the table.

1)
{"AAA",
 "AMA",
 "AAA"}
3

Returns: 4



2)
{"AA",
 "AA",
 "AA"}
2

Returns: 7

Here are all 7 configurations, where X represents the amoeba:

XX .. .. X. .X .. ..
.. XX .. X. .X X. .X
.. .. XX .. .. X. .X


3)
{"MMM",
 "MMM",
 "MMM"}
1

Returns: 0

There are no cells with antimatter at all.

4)
{"AAM",
 "MAM",
 "AAA"}
1

Returns: 6



5)
{"AAA",
 "AAM",
 "AAA"}
2

Returns: 9



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"MA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AAA",
 "AMA",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AA",
 "AA",
 "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 7; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"MMM",
 "MMM",
 "MMM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"AAM",
 "MAM",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"AAA",
 "AAM",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 9; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  AmoebaDivTwo test;

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
