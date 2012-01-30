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

class ComplementMachine2D {
 public:
  int largestSubmatrix(vector <string> matrix) {
    // -- main code --

    int ans = max(matrix.size(), matrix[0].size());

    vector< vector<int> > mm(
        matrix.size() - 1, vector<int>(matrix[0].size() - 1, 0));

    TIMES(y, mm.size()) {
      TIMES(x, mm[0].size()) {
        /*
          00 01 10 00 11 10 01 11
          01 00 00 10 10 11 11 01
         */

        mm[y][x] = matrix[y][x] + matrix[y][x+1] + matrix[y+1][x] + matrix[y+1][x+1];
        mm[y][x] = mm[y][x] % 2;
      }
    }


    TIMES(y, mm.size()) {
      TIMES(x, mm[0].size()) {
        cout << mm[y][x] ;
      }
      cout << endl;
    }

    TIMES(y, mm.size()) {
      TIMES(x, mm[0].size()) {
        FOR(yy, y, mm.size()) {
          FOR(xx, x, mm[0].size()) {
            int sq = (yy - y + 1 + 1) * (xx - x + 1 + 1);
            if(ans > sq) continue;
            bool ok = true;
            UPTO(yyy, y, yy) {
              UPTO(xxx, x, xx) {
                if(mm[yyy][xxx] == 1) {
                  ok = false;
                  break;
                }
              }
              if(!ok) break;
            }
            if(ok) ans = max(ans, sq);
          }
        }
      }
    }
    
    return ans;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A binary matrix is a matrix in which each cell contains either a 0 or a 1. A two dimensional complement machine is a machine that works over a binary matrix of N rows numbered from 0 through N-1 and M columns numbered from 0 to M-1.


The machine has 4 instructions: N, S, E and W. Instructions N and S take an integer parameter i (0 <= i <= N-1). N replaces each cell with a row index less than or equal to i with its complement, while S replaces each cell with a row index greater than or equal to i with its complement.  The complement of 0 is 1, and the complement of 1 is 0. Instructions W and E take an integer parameter j (0 <= j <= M-1). W replaces each cell with a column index less than or equal to j with its complement, while E replaces each cell with a column index greater than or equal to j with its complement.


We call a binary matrix erasable if it is possible to make all its cells contain a 0 after a finite number of instructions using a two dimensional complement machine. A contiguous submatrix is a matrix formed by selecting one or more consecutive rows and one or more consecutive columns from a bigger matrix. It is possible to select all rows and/or all columns. (See notes for an exact definition of "contiguous submatrix".)


You will be given a vector <string> matrix representing a binary matrix. Return the number of cells in the largest contiguous submatrix of the original matrix that is erasable.


DEFINITION
Class:ComplementMachine2D
Method:largestSubmatrix
Parameters:vector <string>
Returns:int
Method signature:int largestSubmatrix(vector <string> matrix)


NOTES
-Suppose that A is a binary matrix containing N rows and M columns. Both rows and columns are 0-indexed. Let's use A[i][j] to denote the cell in row i, column j. A contiguous submatrix B of matrix A can be uniquely represented by 4 integers I1, I2, J1 and J2, 0 <= I1 <= I2 < N, 0 <= J1 <= J2 < M. The matrix B contains I2-I1+1 rows and J2-J1+1 columns. The value of B[i][j] is the same as A[i+I1][j+J1], for any i, j such that 0 <= i <= I2-I1, 0 <= j <= J2-J1.


CONSTRAINTS
-matrix will contain between 1 and 40 elements, inclusive.
-Each element of matrix will contain between 1 and 40 characters, inclusive.
-All elements of matrix will contain the same number of characters.
-Each character of each element of matrix will be either '0' or '1'.


EXAMPLES

0)
{"0011",
 "0011",
 "1100",
 "0111"}

Returns: 12

The entire matrix is not erasable because it has an odd number of 0s and all allowed transformations complement an even number of cell values, and therefore maintain the parity of 0s. The contiguous submatrix that consists of the three topmost rows and all columns, however, is erasable. Here we depict a possible succession of steps that erases it:

0011         1100         0000
0011  -N1->  1100  -W1->  0000
1100         1100         0000

The first step complements the topmost 2 rows and the second step complements the leftmost 2 columns.

1)
{"0011",
 "1011",
 "0101",
 "1010"}

Returns: 9



2)
{"1011",
 "0011",
 "0101",
 "1010"}

Returns: 8



3)
{"0000110101010",
 "0111101010111",
 "1110110111011"}

Returns: 13



4)
{"11000000000110101101",
 "00111111011101101101",
 "00110011110111100010",
 "10011110111110000111",
 "00111010000000110111",
 "00001101011011010110",
 "11010010100100101100",
 "11101101011011000001",
 "11000010100100111001",
 "11011010100100101010",
 "10110010100100110110",
 "01100010100100111001",
 "10110010100100110011",
 "01110101011011001010",
 "01111101011011001011",
 "00001000010010101011",
 "11100101100100110001",
 "10100100111001010101",
 "11111000001010011110",
 "01110100001110011111"}


Returns: 100

The 10x10 contiguous submatrix that corresponds to rows 5-14 and columns 5-14 is erasable.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() {
          string Arr0[] = {"0111",
                           "1101",
                           "1001",
                           "0001",
                           "1101",
                           "1111",};
          vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, largestSubmatrix(Arg0)); }
	void test_case_1() { string Arr0[] = {"0011",
 "1011",
 "0101",
 "1010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, largestSubmatrix(Arg0)); }
	void test_case_2() { string Arr0[] = {"1011",
 "0011",
 "0101",
 "1010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, largestSubmatrix(Arg0)); }
	void test_case_3() { string Arr0[] = {"0000110101010",
 "0111101010111",
 "1110110111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, largestSubmatrix(Arg0)); }
	void test_case_4() { string Arr0[] = {"11000000000110101101",
 "00111111011101101101",
 "00110011110111100010",
 "10011110111110000111",
 "00111010000000110111",
 "00001101011011010110",
 "11010010100100101100",
 "11101101011011000001",
 "11000010100100111001",
 "11011010100100101010",
 "10110010100100110110",
 "01100010100100111001",
 "10110010100100110011",
 "01110101011011001010",
 "01111101011011001011",
 "00001000010010101011",
 "11100101100100110001",
 "10100100111001010101",
 "11111000001010011110",
 "01110100001110011111"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(4, Arg1, largestSubmatrix(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ComplementMachine2D test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
