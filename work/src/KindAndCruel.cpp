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

class KindAndCruel {

 public:
  vector< vector<bool> > pass;
  vector< int > mint;
  int xsz;
  int ysz;
  
  int crossTheField(string field, int K, int C)
  {
    xsz = field.size();
    ysz = max(K+1, C+1) * xsz;
    pass = vector< vector<bool> >(ysz, vector<bool>(xsz, false));
    mint = vector<int>(xsz, 0);
    
    TIMES(x, xsz) {
      if(field[x] == '.') continue;
      TIMES(y, ysz) {
        if(field[x] == 'K') {
          pass[y][x] = (y % K == 0 ? false : true);
        }else if(field[x] == 'C') {
          pass[y][x] = (y % C == 0 ? true : false);
        }
      }
    }

    TIMES(x, xsz) {
      TIMES(y, x - 1) {
        pass[y][x] = false;
      }
    }

    int ret = dfs(0, 0);
    return ret == -2 ? -1 : ret;	
  }

  int dfs(int pos, int time)
  {
    // reach rightmost
    if(pos == xsz - 1) {
      return time;
    }

    if(time >= ysz) {
      return -2;
    }

    if(
    
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are placed at one end of a field represented by a row of cells. Each cell of the field can be one of the following:

empty: is always passable (represented by a '.');

contains a kind creature (represented by a 'K'): is passable, unless the creature is in a bad mood. This happens if the number of the second at which you enter it is divisible by K;

contains a cruel creature (represented by a 'C'): is impassable, unless the creature in in a good mood. This happens if the number of the second at which you enter it is divisible by C.

You start at the leftmost cell of the field. You have to get to the rightmost cell of the field using a minimal number of seconds. Both leftmost and rightmost cells are empty. In one second you can move to a cell which is immediately to the left or to the right of the current cell, or stay where you are. You can not stay in a cell containing kind creature if the number of second is divisible by K, or in a cell containing cruel creature if the number of second is not divisible by C. The seconds are numbered with consecutive integers, starting with 1.

You are given a string field, where each character represents a cell in the field, from left to right. You are also given ints K and C. Return the minimal number of seconds which will bring you to the rightmost cell of the field. If you can't get there, return -1.

DEFINITION
Class:KindAndCruel
Method:crossTheField
Parameters:string, int, int
Returns:int
Method signature:int crossTheField(string field, int K, int C)


CONSTRAINTS
-field will contain between 2 and 50 characters, inclusive.
-Each character in field will be '.', 'K' or 'C'.
-The first and the last characters of field will be '.'.
-K and C will be between 1 and 50, inclusive.


EXAMPLES

0)
"..."
2
5

Returns: 2

There are no creatures on the field, so you just go two cells to the right in two seconds.

1)
".K.C."
3
4

Returns: 5

At second 1, you move to the cell with the kind creature. At second 2, you move right to the empty cell. At second 3, you wait in the empty cell, because you can't enter the cell with the cruel creature yet. At second 4, the cruel creature is in a good mood and you can enter its cell. Finally, at second 5 you enter the rightmost cell.

2)
".CCCC."
3
5

Returns: -1

You can not pass.

3)
".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK."
5
5

Returns: 60



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "..."; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; verify_case(0, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = ".K.C."; int Arg1 = 3; int Arg2 = 4; int Arg3 = 5; verify_case(1, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = ".CCCC."; int Arg1 = 3; int Arg2 = 5; int Arg3 = -1; verify_case(2, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = ".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK."; int Arg1 = 5; int Arg2 = 5; int Arg3 = 60; verify_case(3, Arg3, crossTheField(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  KindAndCruel test;

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
