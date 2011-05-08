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
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

// -- utility --
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define TIMES(x,n) FOR(x, 0, n)
#define UPTO(x, a, b) for(int x = static_cast<int>(a); x <= static_cast<int>(b); ++x)
#define DOWNTO(x, a, b) for(int x = static_cast<int>(a); x >= static_cast<int>(b); --x)
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class RectangleArea {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Your friend has drawn a rectangle on the coordinate plane consisting of points (x, y) such that 0 <= x <= W, 0 <= y <= H, where W and H are positive numbers (not necessarily integer). Then she has divided it into a grid of NxM smaller rectangles. In order to do it, she has chosen numbers (X[0], X[1], ..., X[N]) and (Y[0], Y[1], ..., Y[M]) such that 0 = X[0] < X[1] < ... < X[N] = W and 0 = Y[0] < Y[1] < ... < Y[M] = H. The small rectangle in row i, column j of the grid consists of points (x, y) such that Y[i] <= y <= Y[i+1] and X[j] <= x <= X[j+1]. Note that rows are numbered from 0 to M-1 and columns are numbered from 0 to N-1.

Now, you and your friend play the following game. Initially, you only know the values of N and M, but do not know the values of W, H, X and Y. Your goal is to determine the area of the initial large rectangle, i.e., W * H, but since you don't know W and H, it's not so easy to do. In order to achieve the goal, you can ask questions to your friend. Each question is of the form: "What is the area of the small rectangle in row i, column j?" Your friend always gives true answers, i.e., she responds with the value of (Y[i+1] - Y[i]) * (X[j+1] - X[j]).

You have already asked some questions, the information about them is contained in a vector <string> known. It contains M elements, each element consists of N characters. The j-th character in i-th element is 'Y' if you already know the area of the small rectangle in row i, column j, and it is 'N' if you haven't yet asked the question about this small rectangle.

Return the minimum number of additional questions that you need to ask in order to determine the area of the initial large rectangle. If you can determine the area without asking additional questions, return 0.

DEFINITION
Class:RectangleArea
Method:minimumQueries
Parameters:vector <string>
Returns:int
Method signature:int minimumQueries(vector <string> known)


NOTES
-Your goal is always achievable. For example, if you know the areas of all small rectangles, you can find the area of the large rectangle as the sum of areas of all small rectangles.


CONSTRAINTS
-known will contain between 1 and 50 elements, inclusive.
-Each element of known will contain between 1 and 50 characters, inclusive.
-All elements of known will contain the same number of characters.
-Each character in known will be 'Y' or 'N'.


EXAMPLES

0)
{"NN",
 "NN"}

Returns: 3

Suppose that heights of rows 0 and 1 are R0 and R1 and widths of columns 0 and 1 are C0 and C1.
You can ask 3 questions about rectangle at row 0, column 0 (suppose the answer is A00), at row 0, column 1 (answer is A01) and at row 1, column 0 (answer is A10). We then have the following equations:

R0 * C0 = A00
R0 * C1 = A01
R1 * C0 = A10

After several transformations:

C0 = A00 / R0
C1 = A01 / R0
R1 = A10 / C0 = A10 / (A00 / R0) = (A10 / A00) * R0

The total area can then be calculated as follows:

W * H = (R0 + R1) * (C0 + C1) = 
= (R0 + (A10 / A00) * R0) * (A00 / R0 + A01 / R0) =
= R0 * (1 + A10 / A00) * (1 / R0) * (A00 + A01) =
= (1 + A10 / A00) * (A00 + A01)

So, 3 questions are enough to find the area of the large rectangle. It is impossible to achieve this goal with less than 3 questions.

1)
{"YNY",
 "NYN",
 "YNY"}

Returns: 1

Knowing the contents of any single additional small rectangle is enough to find the area of the large rectangle.

2)
{"YY",
 "YY",
 "YY",
 "YY"}

Returns: 0

You already know everything in this test case, so no additional questions are needed.

3)
{"NNNNNNNNNN"}

Returns: 10

Here you need to ask questions about all small rectangles.

4)
{"NNYYYNN",
 "NNNNNYN",
 "YYNNNNY",
 "NNNYNNN",
 "YYNNNNY"}

Returns: 2



*/
// END CUT HERE

 public:
  int minimumQueries(vector <string> known)
  {
    int result = 0;
    // -- main code --

    if(known[0].size() == 1) {
      int c = 0;
      TIMES(y, known.size()) {
        if(known[y][0] == 'N') ++c;
      }
      return c;
    }

    if(known.size() == 1) {
      int c = 0;
      TIMES(x, known[0].size()) {
        if(known[0][x] == 'N') ++c;
      }
      return c;
    }

    vector<int> xk(known[0].size(), 0);
    vector<int> yk(known.size(), 0);

    vector< vector<int> > kk(known.size(), vector<int>(known[0].size(), 0));
    
    TIMES(y, known.size()) {
      TIMES(x, known[0].size()) {
        TIMES(yy, known.size()) {
          TIMES(xx, known[0].size()) {
            if(yy == y or xx == x) {
              break;
            }

            int c = 0;

            if(known[y][x] == 'Y') ++c;
            if(known[yy][x] == 'Y') ++c;
            if(known[y][xx] == 'Y') ++c;
            if(known[yy][xx] == 'Y') ++c;

            if(c >= 3) {
              xk[x] = 1;
              yk[y] = 1;
              xk[xx] = 1;
              yk[yy] = 1;

              known[y][x] = 'Y';
              known[yy][x] = 'Y';
              known[y][xx] = 'Y';
              known[yy][xx] = 'Y';
              c = 4;
            }
            
            kk[y][x] = max(c, kk[y][x]);
            kk[yy][x] = max(c, kk[yy][x]);
            kk[y][xx] = max(c, kk[y][xx]);
            kk[yy][xx] = max(c, kk[yy][xx]);
          }
        }
      }
    }

    TIMES(y, known.size()) {
      
      TIMES(x, known[0].size()) {
        cerr << kk[y][x] ;
      }
      cerr << endl;
    }

    return result;	
  }
 
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minimumQueries(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNY",
 "NYN",
 "YNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimumQueries(Arg0)); }
	void test_case_2() { string Arr0[] = {"YY",
 "YY",
 "YY",
 "YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimumQueries(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minimumQueries(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNYYYNN",
 "NNNNNYN",
 "YYNNNNY",
 "NNNYNNN",
 "YYNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, minimumQueries(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  RectangleArea test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

