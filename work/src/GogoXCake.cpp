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

class GogoXCake {

 public:
  bool ok(vector<string>& cake, vector<string>& cutter)
  {
    int xasz = cake[0].size();
    int yasz = cake.size();

    int xusz = cutter[0].size();
    int yusz = cutter.size();

    int xus = 0;
    FOR(x, 0, xusz) {
      if(cutter[0][x] == '.') {
        xus = x;
        break;
      }
    }

    int yus = 0;
    FOR(y, 0, yusz) {
      if(cutter[y][0] == '.') {
        yus = y;
        break;
      }
    }
    
    for(int y = 0; y + yusz - 1 < yasz; ++y) {
      for(int x = 0; x + xusz - 1 < xasz; ++x) {
        if(cake[y+yus][x] == '.' || cake[y][x+xus] == '.') {
        }else {
          continue;
        }

        bool go = true;
        for(int yy = 0; yy < yusz; ++yy) {
          for(int xx = 0; xx < xusz; ++xx) {
            if(cutter[yy][xx] == '.' && cake[y+yy][x+xx] == 'X') {
              go = false;
            }
          }
        }

        if(go) {
          for(int yy = 0; yy < yusz; ++yy) {
            for(int xx = 0; xx < xusz; ++xx) {
              if(cutter[yy][xx] == '.') {
                cake[y+yy][x+xx] = 'X';
              }
            }
          }
        }
      }
    }

    
    FOR(y, 0, yasz) {
      FOR(x, 0, xasz) {
        if(cake[y][x] == '.') return false;
      }
    }
    return true;
  }

  string solve(vector <string> cake, vector <string> cutter)
  {
    
    vector<string> cake2 = cake;
    
    bool ret = ok(cake2, cutter);
    if(ret) return "YES";
        
    return "NO";	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to cut and eat cake. He used a rectangular baking dish to make a cake. The dish is divided into a grid of unit square cells. Initially, all the cells contained the cake.

Gogo's friend John wanted to eat the cake. Gogo gave John a rectangular cake cutter with the following properties:

The cake cutter is divided into a grid of cells. The cells are of the same size as the cells of the dish.
The cake cutter contains cells of two types: used cells and ignored cells.
Each of the first row, the last row, the first column, and the last column of the cutter contains at least one used cell.

When used, the cake cutter must be placed on the dish according to the following rules:

Each cell of the cutter must contain a single cell of the dish.
It is not allowed to flip or rotate the cutter. Rows and columns of the cutter must correspond to some consecutive rows and some consecutive columns of the dish in the given orientation. (See the last two examples.)
Each used cell of the cutter must be placed onto a cell that still contains cake. The ignored cells may be placed onto any cells.


When the cake cutter is used in the way described above, it removes the cake from all the used cells. John may have used the cake cutter multiple times, one after another.

After John went home, Gogo examined the cake that remained in the dish. He now wants to check whether John really cut the cake according to the above rules. You are given vector <string>s cake and cutter. The remaining cake is described by cake. More precisely, cake[i][j] is 'X' if the cell in the i-th row and j-th column of the dish still contains cake; otherwise cake[i][j] is '.' (a period). The cake cutter is described by cutter. More precisely, cutter[i][j] is '.' (a period) if the cell in the i-th row and j-th column of the cutter is used, and 'X' if the cell is ignored.

Return "YES" (quotes for clarity) if it is possible that John only ate the cake by using the cutter in the way described above. Return "NO" otherwise.

DEFINITION
Class:GogoXCake
Method:solve
Parameters:vector <string>, vector <string>
Returns:string
Method signature:string solve(vector <string> cake, vector <string> cutter)


NOTES
-The used cells in the cutter do not have to be contiguous.


CONSTRAINTS
-cake will contain between 1 and 50 elements, inclusive.
-Each element of cake will contain between 1 and 50 characters, inclusive.
-All elements of cake will contain the same number of characters.
-Each character in each element of cake will be either '.' or 'X'.
-There will be at least one '.' in cake
-cutter will contain between 1 and R elements, inclusive, where R is the number of elements in cake.
-Each element of cutter will contain between 1 and C characters, inclusive, where C is the number of characters in each element of cake.
-All elements of cutter will contain the same number of characters.
-Each character in each element of cutter will be either '.' or 'X'.
-Each of the first row, the first column, the last row, and the last column of the cutter will contain at least one '.'.


EXAMPLES

0)
{"X.X"
,"..."
,"..."
,"X.X"}
{".X"
,".."
,"X."}

Returns: "YES"



1)
{"..XX"
,"...X"
,"X..."
,"XX.."}
{".."
,".."}

Returns: "NO"



2)
{"...X..."}
{"..."}

Returns: "YES"



3)
{".X."
,"X.X"
,".X."}
{"."}

Returns: "YES"



4)
{"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}
{".X."
,"XXX"
,".X."}

Returns: "NO"



5)
{".."
,"X."
,".X"}
{".."
,".X"
,"X."}

Returns: "NO"

You may not flip the cutter.

6)
{"X.."
,".XX"
,".XX"}
{".XX"
,".XX"
,"X.."}

Returns: "NO"

You may not rotate the cutter.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X"
,"..."
,"..."
,"X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X"
,".."
,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..XX"
,"...X"
,"X..."
,"XX.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".X."
,"X.X"
,".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X."
,"XXX"
,".X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".."
,"X."
,".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".X"
,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(5, Arg2, solve(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"X.."
,".XX"
,".XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".XX"
,".XX"
,"X.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(6, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  GogoXCake test;

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
