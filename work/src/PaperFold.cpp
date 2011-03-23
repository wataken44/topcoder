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

class PaperFold {
 public:
  int numFolds(vector <int> paper, vector <int> box) {
    // -- main code --

    int width = paper[0];
    int height = paper[1];

    TIMES(x, 8) {
      TIMES(i, 256) {
        int ndx = 0;
        int ndy = 0;
        TIMES(y, x) {
          if(((i >> y) & 1) == 1) {
            ++ndx;
          }else {
            ++ndy;
          }
        }
        
        if((width <= box[0] * (1<<ndx) and height <= box[1] * (1<<ndy)) or
           (width <= box[1] * (1<<ndx) and height <= box[0] * (1<<ndy))) {
          return x;
        }
      }
    }
    
    return -1;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have a piece of paper that you need to fold to fit into a box with a given width and length.  Each time you fold the paper, you can fold it in half across either its width or length, but you can only fold the paper 8 times (after 8 times, the paper is too dense to fold again).



You will be given a vector <int> paper, which contains the width and length of the paper in inches, and a vector <int> box, which contains the width and length of the box in inches.  In both cases, the first element is the width and the second element is the length.  Your method should return the fewest number of folds which would allow you to fit the paper into the box.  You can rotate the paper 90 degrees if it will fit with fewer folds, but the paper must lie completely flat inside the box.  If the paper cannot be fit into the box with 8 folds or fewer, return -1.


DEFINITION
Class:PaperFold
Method:numFolds
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int numFolds(vector <int> paper, vector <int> box)


NOTES
-After the paper is folded, it is possible that it has fractional dimensions.
-The paper will fit into the box even if one or both of the dimensions are exactly the same as the corresponding box dimensions.


CONSTRAINTS
-paper will contain exactly two elements.
-box will contain exactly two elements.
-Each element of paper and box will be between 1 and 10000, inclusive.


EXAMPLES

0)
{8, 11}
{6, 10}

Returns: 1

By folding the paper so that the length is reduced from 11 to 5.5 inches, it will fit inside the box if you rotate it 90 degrees.

1)
{11, 17}
{6, 4}

Returns: 4


There are two ways to fold the paper so that it fits within the box.



First, you could fold the width in half to get 5.5 inches, and then fold the length in half three times to get 2.125 inches.



Second, you could fold the width in half twice to get 2.25 inches, and then fold the length in half twice to get 4.25 inches.  In this case, you must also rotate 90 degrees to fit the paper in.


2)
{11, 17}
{5, 4}

Returns: 4

Now, you must use the second method to get it to fit:  Fold the width and length each twice, and rotate 90 degrees.  If you try fitting without rotating, it would take 5 folds.

3)
{1000,1000}
{62,63}

Returns: -1

Folding in each direction 4 times, you can get the paper down to 62.5 x 62.5.  However, this will not fit into the box because neither dimension fits in 62.

4)
{100,30}
{60,110}

Returns: 0

5)
{1895, 6416}
{401, 1000}

Returns: 5

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {11, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {11, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {62,63}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,110}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1895, 6416}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {401, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, numFolds(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PaperFold test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
