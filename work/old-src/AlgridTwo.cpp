#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
// debug
#define DUMP(x) std::cout << #x << " = " << x << std::endl;

using namespace std;

class AlgridTwo {
 public:

  typedef unsigned long long ull;
  const ull modulo = 1000000007;  

  int makeProgram(vector <string> output) {
    // -- main code --


    int hsz = output.size();
    int wsz = output[0].size();

    return go(output, output, wsz - 2 , 0);
  }

  ull go(vector<string>& dest, vector<string> output, int x, int y) {
    if(dest[y][x] != output[y][x] or dest[y][x-1] != output[y][x-1]) {
      return 0;
    }

    ull c = 0;

    int col = color(output[y][x])*2 + color(output[y][x-1]);
    if(col == 0) {
      c += go(dest, output, x - 1, y);
    }else if(col == 1) {

    }else if(col == 2) {

    }else if(col == 3) {

    }
    
    return c;
  }
  
  int color(char c) {
    return c == 'W' ? 0 : 1; 
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Algrid2 is a program that uses a single grid with cells colored white or black as input and returns a new one as output. The grid has H rows and W columns. The topmost row is row 0, the bottommost row is row H-1, the leftmost column is column 0 and the rightmost column is column W-1. The cell at row i, column j can be denoted as (i,j). The program works by evaluating pairs of contiguous cells and making decisions depending on their contents. The following pseudo-code describes how the program works:


For i = 0 to H-2:
    For j = 0 to W-2:
        //Get the current colors of cells (i,j) and (i,j+1)

        A = Color(i,j) , B = Color(i,j+1)

        If (A,B) == (White, White) Then:
             Do nothing.
        EndIf
        If (A,B) == (Black, White) Then: 
             Repaint cells (i+1,j) and (i+1,j+1) Black.
        EndIf
        If (A,B) == (White, Black) Then:
             Repaint cells (i+1,j) and (i+1,j+1) White.
        EndIf
        if (A,B) == (Black, Black) Then:
             Swap the colors in cells (i+1,j) and (i+1,j+1).
        EndIf
    EndFor
EndFor


You will be given a possible output for the program as a vector <string> output. The j-th character in the i-th element of output represents the color of cell (i,j) where 'W' represents white and 'B' represents black. Count the total number of input grids that can generate this output. Two input grids are different if there is at least one cell in which the colors are different. Since the result may be very large, return it modulo 1000000007.

DEFINITION
Class:AlgridTwo
Method:makeProgram
Parameters:vector <string>
Returns:int
Method signature:int makeProgram(vector <string> output)


CONSTRAINTS
-output will contain between 2 and 50 elements, inclusive.
-Each element of output will contain between 2 and 50 characters, inclusive.
-All elements of output will have the same length.
-Each element of output will only contain 'W' or 'B' characters.


EXAMPLES

0)
{"BB",
 "WB"}

Returns: 1

The only way to generate that output following the rules described is:

BB
BW


1)
{"BBWBBB",
 "WBWBBW"}

Returns: 8

There are 8 ways in total:

BBWBBB BBWBBB BBWBBB BBWBBB
BWWWBB WWWBBB BWBBBB WWWWBB

BBWBBB BBWBBB BBWBBB BBWBBB
WWBBBB BWBWBB WWBWBB BWWBBB



2)
{"BWBWBW",
 "WWWWWW",
 "WBBWBW"}

Returns: 0



3)
{"WWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBB",
 "BWBWBWBWBWBWBWBW"}

Returns: 73741817



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BB",
 "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, makeProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBWBBB",
 "WBWBBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, makeProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"BWBWBW",
 "WWWWWW",
 "WBBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, makeProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBB",
 "BWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(3, Arg1, makeProgram(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  AlgridTwo test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
