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

class Pool {
 public:
  int rackMoves(vector <int> triangle) {
    // -- main code --

    int csld0 = 0;
    int c80 = 0;
    int cstr0 = 0;
    
    TIMES(i, triangle.size()) {
      if(i == 1 or i == 2 or i == 6 or i == 8 or i == 11 or i == 13 or i == 14) {
        if(triangle[i] <= 8) {
          ++csld0;
        }
      }else if(i == 4) {
        if(triangle[i] != 8) {
          ++c80;
        }
      }else {
        if(triangle[i] >= 8) {
          ++cstr0;
        }
      }
    }

    int csld1 = 0;
    int c81 = 0;
    int cstr1 = 0;
    
    TIMES(i, triangle.size()) {
      if(i == 1 or i == 2 or i == 6 or i == 8 or i == 11 or i == 13 or i == 14) {
        if(triangle[i] >= 8) {
          ++cstr1;
        }
      }else if(i == 4) {
        if(triangle[i] != 8) {
          ++c81;
        }
      }else {
        if(triangle[i] <= 8) {
          ++csld1;
        }
      }
    }
    /*
    DUMP(csld0);
    DUMP(cstr0);
    DUMP(csld1);
    DUMP(cstr1);
    cout.flush();
    */
    return min(min(csld0 + c80, cstr0 + c80),min(csld1 + c81, cstr1 + c81));
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
"Rack 'em up!" says Jane. She's beaten you at pool again, so you're stuck with the chore of racking the balls for the next game. There are fifteen balls at your disposal, numbered 1 through 15. Those numbered 1 through 7 are called "solids", while 9 through 15 are "stripes". Number 8, the "eight-ball", is neither stripe nor solid.


You are to arrange the balls into five rows such that the first row contains one ball; the second, two balls; and so on. The overall effect is that of an equilateral triangle pointing upward. For the purpose of this problem, we number the positions in the triangle from 0 to 14, starting in the first row and proceeding from left to right, top to bottom. The following piece of ASCII art shows the position numbers.



                                          0
                                        1   2
                                      3   4   5
                                    6   7   8   9
                                  10 11  12  13  14


In a correct rack, the eight-ball occupies position 4, while positions 10 and 14 may not be occupied by two stripes or two solids. Furthermore, you are at a pool hall whose rules dictate that stripes and solids alternate along the upper left side of the triangle (positions 10, 6, 3, 1, 0); along the fourth row (positions 6, 7, 8, 9); and along the first four positions in the bottom row (positions 10, 11, 12, 13). Finally, positions 5 and 9 must be occupied by two stripes or two solids. In effect, only two patterns of stripes and solids are possible. These patterns are shown below, using X to represent stripes, O for solids, and the numeral 8 for the eight-ball.



                         X                                O
                       O   O                            X   X
                     X   8   X                        O   8   O
                   O   X   O   X                    X   O   X   O
                 X   O   X   O   O                O   X   O   X   X


The balls are, at first, arranged randomly in the triangle. Etiquette demands that you change the configuration only by swapping the positions of two balls at a time. Any two balls, not merely an adjacent pair, may be swapped. Given a vector <int> describing the initial configuration of the triangle, so that the element at index 0 is the number of the ball at position 0 and so forth, what is the smallest number of swaps required to achieve a correct rack?


DEFINITION
Class:Pool
Method:rackMoves
Parameters:vector <int>
Returns:int
Method signature:int rackMoves(vector <int> triangle)


CONSTRAINTS
-triangle contains exactly 15 elements
-each element in triangle is between 1 and 15, inclusive
-triangle contains no duplicates


EXAMPLES

0)
{6, 12, 14, 1, 8, 2, 11, 3, 9, 4, 7, 13, 5, 15, 10}

Returns: 0

This is already a correct rack.

1)
{2, 10, 7, 1, 8, 12, 6, 11, 4, 9, 13, 3, 14, 15, 5}

Returns: 2

The eight-ball is in the right place. We can finish the rack by swapping balls 2 and 10, then 1 and 15.

2)
{8, 15, 9, 4, 10, 6, 11, 3, 14, 7, 2, 1, 13, 12, 5}

Returns: 3

One minimal solution is to swap balls 1 and 13, then 10 and 5, and finally 5 and 8.

3)
{15, 5, 8, 13, 2, 14, 10, 3, 4, 6, 7, 9, 1, 12, 11}

Returns: 4

4)
{1, 5, 15, 6, 10, 9, 11, 13, 7, 4, 3, 8, 2, 12, 14}

Returns: 3

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6, 12, 14, 1, 8, 2, 11, 3, 9, 4, 7, 13, 5, 15, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, rackMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 10, 7, 1, 8, 12, 6, 11, 4, 9, 13, 3, 14, 15, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, rackMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {8, 15, 9, 4, 10, 6, 11, 3, 14, 7, 2, 1, 13, 12, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, rackMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {15, 5, 8, 13, 2, 14, 10, 3, 4, 6, 7, 9, 1, 12, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, rackMoves(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 5, 15, 6, 10, 9, 11, 13, 7, 4, 3, 8, 2, 12, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, rackMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Pool test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
