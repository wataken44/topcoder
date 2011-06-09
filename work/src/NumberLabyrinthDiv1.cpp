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

class NumberLabyrinthDiv1 {

 public:
  int getNumberOfPaths(vector <int> X, vector <int> Y, vector <int> val, int xFinish, int yFinish, int K)
  {
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Little Arthur loves numbers. This time he is playing a game called Number Labyrinth.

The game is played on an infinitely large grid; columns are numbered 0, 1, 2, .. from left to right and rows are numbered 0, 1, 2, .. from bottom to top. The cell in column x and row y is said to have coordinates (x, y). Each cell of the board either contains a positive integer or is empty. There are exactly N cells that contain numbers and their descriptions are given as vector <int>s X, Y, and val. For each i between 0 and N-1, inclusive, the i-th such cell has coordinates (X[i], Y[i]) and contains number val[i].

The goal of the game is to get from cell (0, 0) to cell (xFinish, yFinish) by performing valid moves. A valid move is a jump of length d in a horizontal or vertical direction from a cell with a number d; more formally, if Arthur's position is (x, y) and the cell contains a number d, he can move to cell (x - d, y), (x + d, y), (x, y - d), or (x, y + d). Note that an empty cell is a dead-end. Arthur is also not allowed to leave the board at any time, i.e., enter a cell (x, y) where x or y (or both) are negative.

Furthermore, before performing moves Arthur is allowed to write any positive integers in at most K empty cells.

Arthur of course wants to reach the goal of the game with the shortest possible path, i.e., the smallest sum of the lengths of jumps that lead from (0, 0) to (xFinish, yFinish).

However, finding a single shortest path in not a difficult task for Arthur. Thus, he is going to find all possible shortest paths. Given X, Y, val, xFinish, yFinish, and K, return the number of different shortest paths Arthur can obtain. Two paths are cosidered different if their respective sequences of jumps are different. Two jumps are different if they have different length or different direction. This number may be very big, so return it modulo 1,000,000,009. If no path exists return 0.


DEFINITION
Class:NumberLabyrinthDiv1
Method:getNumberOfPaths
Parameters:vector <int>, vector <int>, vector <int>, int, int, int
Returns:int
Method signature:int getNumberOfPaths(vector <int> X, vector <int> Y, vector <int> val, int xFinish, int yFinish, int K)


CONSTRAINTS
-N will be between 0 and 40, inclusive.
-X, Y, and val will each contain exactly N elements.
-Each element of X, Y, and val will be between 1 and 1000000 (10^6), inclusive.
-xFinish and yFinish will each be between 1 and 1000000 (10^6), inclusive.
-K will be between 0 and 10, inclusive.
-All coordinates (X[i], Y[i]) will be distinct and different from (xFinish, yFinish).


EXAMPLES

0)
{}
{}
{}
3
3
2

Returns: 2

There is no way to reach the finish cell writing numbers in less than two cells. However, the finish can be reached by writing numbers in exactly two cells. The shortest possible path in this case is 6 and that can be obtained in two ways:

- writing 3 in cell (0, 0) and 3 in cell (0, 3), allowing him to perform jumps (0, 0) -> (0, 3) -> (3, 3);

- writing 3 in cell (0, 0) and 3 in cell (3, 0), allowing him to perform jumps (0, 0) -> (3, 0) -> (3, 3).

1)
{}
{}
{}
3
3
3

Returns: 14

The same situation as in the previous example, but this time there are 12 more paths possible if numbers are written in three cells. For example, Arthur can write 2 in cell (0, 0), 3 in cell (0, 2), and 1 in cell (3, 2) to enable path (0, 0) -> (0, 2) -> (3, 2) -> (3, 3).

2)
{2}
{2}
{1}
3
3
3

Returns: 18

This time one cell already contains a number enabling 4 new shortest paths.

3)
{1, 3, 6}
{1, 3, 6}
{2, 2, 2}
5
5
4

Returns: 210



4)
{1, 19, 20, 21, 21, 21, 20, 19, 19}
{1, 11, 11, 11, 10, 9, 9, 9, 10}
{1, 2, 2, 2, 2, 2, 2, 2, 2}
20
10
4

Returns: 1778



5)
{13, 224, 77, 509, 1451, 43, 379, 142, 477}
{1974, 375, 38, 783, 3, 1974, 1790, 1008, 2710}
{30, 1845, 360, 11, 837, 84, 210, 4, 6704}
509
2011
10

Returns: 196052726



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 3; int Arg5 = 2; int Arg6 = 2; verify_case(0, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 3; int Arg5 = 3; int Arg6 = 14; verify_case(1, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 3; int Arg5 = 3; int Arg6 = 18; verify_case(2, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arr0[] = {1, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 5; int Arg5 = 4; int Arg6 = 210; verify_case(3, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arr0[] = {1, 19, 20, 21, 21, 21, 20, 19, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 11, 11, 11, 10, 9, 9, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; int Arg4 = 10; int Arg5 = 4; int Arg6 = 1778; verify_case(4, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arr0[] = {13, 224, 77, 509, 1451, 43, 379, 142, 477}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1974, 375, 38, 783, 3, 1974, 1790, 1008, 2710}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {30, 1845, 360, 11, 837, 84, 210, 4, 6704}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 509; int Arg4 = 2011; int Arg5 = 10; int Arg6 = 196052726; verify_case(5, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  NumberLabyrinthDiv1 test;

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
