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

class Pathfinding {

 public:
  int getDirections(int x, int y)
  {
    // -- main code --
    int result = 0;

    int xx = 0;
    int yy = 0;

    while(!(xx == x && yy == y)) {
      // DUMP(xx);DUMP(yy);
      int dx = (yy % 2 == 0) ? 1 : -1;
      int dy = (xx % 2 == 0) ? 1 : -1;

      double d0 = dist(xx + dx, yy, x, y);
      double d1 = dist(xx, yy + dy, x, y);

      if(d0 < d1) {
        xx = xx + dx;
      }else {
        yy = yy + dy;
      }
      ++result;
    }
    
    return result;	
  }

  double dist(int x0, int y0, int x1, int y1)
  {
    double x = x1 - x0;
    double y = y1 - y0;
    return sqrt(x * x + y * y);
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Recently you have been working on the pathfinding module for your AI system.  Your objective is to find the shortest path for an agent that wants to travel between two points on a plane.  The agent will start at the point (0,0), and travel to the point (x,y).  You decided that the agent will move either on horizontal of vertical lines such that, at every moment, at least one coordinate of the agent is an integer.

  There is yet another restriction however.  Each line will only allow movement in one direction.  All horizontal lines with odd y-coordinates will be directed toward decreasing values of x, and all other horizontal lines toward increasing values of x.  Similarly, all vertical lines with odd x-coordinates will be directed toward decreasing values of y, and all other vertical lines toward increasing values of y.


Given x and y, return the distance that the agent must travel.

DEFINITION
Class:Pathfinding
Method:getDirections
Parameters:int, int
Returns:int
Method signature:int getDirections(int x, int y)


CONSTRAINTS
-x and y will both be between -10^6 and 10^6, inclusive.


EXAMPLES

0)
0
-4

Returns: 8

A possible path from (0,0) to (0,-4) is through the points (1,0), (1,-3), (-1,-3) and (-1,-4). 

1)
5
-4

Returns: 9



2)
5
4

Returns: 9



3)
-1
-4

Returns: 7



4)
0
0

Returns: 0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = -4; int Arg2 = 8; verify_case(0, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = -4; int Arg2 = 9; verify_case(1, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 9; verify_case(2, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -1; int Arg1 = -4; int Arg2 = 7; verify_case(3, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(4, Arg2, getDirections(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Pathfinding test;

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
