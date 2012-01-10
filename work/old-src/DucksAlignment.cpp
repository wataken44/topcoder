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

class DucksAlignment {

 public:
  int minimumTime(vector <string> grid)
  {
    int result = INT_MAX / 2 - 1;
    // -- main code --

    int dn = 0;
    vector<int> dx;
    vector<int> dy;

    int ysz = grid.size();
    int xsz = grid[0].size();
    
    FOR(y, 0, ysz) {
      FOR(x, 0, xsz) {
        if(grid[y][x] == 'o') {
          ++dn;
          dx.push_back(x);
          dy.push_back(y);
        }
      }
    }

    // horizontal

    FOR(y, 0, ysz) {
      FOR(x, 0, xsz - dn + 1) {
        int c = 0;
        FOR(xx, 0, dn) {
          int yyy = y;
          int xxx = x + xx;
          c += abs(dx[xx] - xxx) + abs(dy[xx] - yyy);
        }
        result = min(result, c);
      }
    }

    // vertical

    FOR(y, 0, ysz - dn + 1) {
      FOR(x, 0, xsz) {
        int c = 0;
        FOR(yy, 0, dn) {
          int yyy = y + yy;
          int xxx = x;
          c += abs(dx[yy] - xxx) + abs(dy[yy] - yyy);
        }
        result = min(result, c);
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
// Mr. Dengklek has a rectangular farm conveniently divided into a grid of unit squares. At this moment, each unit square contains at most one duck. Moreover, each row and column of the farm also contains at most one duck. You are given a vector <string> grid. The j-th character of the i-th element of grid will be 'o' if there is exactly one duck in square (i, j), i.e., row i column j, or '.' if there is no duck in that square. 

Today, Mr. Dengklek wants to align the ducks so that the ducks form a contiguous line. More precisely, assume that there are N ducks on the farm. After the alignment, the ducks must either occupy N contiguous squares in some row or N contiguous squares in some column. To accomplish that, he will move the ducks one at a time. To move a duck in square (a, b) to another empty square (c, d), he needs |a-c| + |b-d| seconds, where |x| denotes the absolute value of x. Mr. Dengklek can always move any duck to any empty square he desires - the other ducks are not obstacles.

Return the minimum time in seconds Mr. Dengklek needs to align the ducks. Note that restrictions imposed on the initial placement of ducks guarantee that a proper alignment is always possible.

DEFINITION
Class:DucksAlignment
Method:minimumTime
Parameters:vector <string>
Returns:int
Method signature:int minimumTime(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 characters, inclusive.
-All elements of grid will contain the same number of characters.
-Each character of grid will be either 'o' or '.'.
-Each row in grid will contain at most one character 'o'.
-Each column in grid will contain at most one character 'o'.
-grid will contain at least one character 'o'.


EXAMPLES

0)
{".o",
 "o."}

Returns: 1

Move either duck to an adjacent empty square.

1)
{".o...",
 "..o..",
 "....o"}

Returns: 3

One of the solutions is: move the the duck in the first row one square to the right, and then move the duck in the last row two squares to the left.

2)
{"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}

Returns: 16

Align all ducks in the second row.

3)
{".........",
 "....o....",
 "........."}

Returns: 0



4)
{"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}

Returns: 99



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
public:
void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
void test_case_0() { string Arr0[] = {".o",
                                      "o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumTime(Arg0)); }
void test_case_1() { string Arr0[] = {".o...",
                                      "..o..",
                                      "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minimumTime(Arg0)); }
void test_case_2() { string Arr0[] = {"o..........",
                                      "..o........",
                                      ".......o...",
                                      "...........",
                                      "...........",
                                      "...........",
                                      "........o..",
                                      "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, minimumTime(Arg0)); }
void test_case_3() { string Arr0[] = {".........",
                                      "....o....",
                                      "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minimumTime(Arg0)); }
void test_case_4() { string Arr0[] = {"...o..........................",
                                      "............................o.",
                                      ".o............................",
                                      "............o.................",
                                      ".................o............",
                                      "......................o.......",
                                      "......o.......................",
                                      "....o.........................",
                                      "...............o..............",
                                      ".......................o......",
                                      "...........................o..",
                                      ".......o......................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; verify_case(4, Arg1, minimumTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DucksAlignment test;

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
