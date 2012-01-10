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
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class ColoredStrokes {
 public:
  int getLeast(vector <string> picture) {
    // -- main code --

    int ysz = picture.size();
    int xsz = picture[0].size();
    vector<string> drawn(ysz, string(xsz,'.'));

    int paint = 0;
    
    // greedy paing green
    TIMES(y, ysz) {
      TIMES(x, xsz) {
        if(picture[y][x] == 'G') {
          UPTO(yy, 1, ysz) {
            if(y+yy >= ysz) break;
            if(picture[y+yy][x] == 'B') {
              drawn[y+yy][x] = 'B';
            }else {
              break;
            }
          }
          UPTO(yy, 1, ysz) {
            if(0 > y-yy) break;
            if(picture[y-yy][x] == 'B') {
              drawn[y-yy][x] = 'B';
            }else {
              break;
            }
          }
          UPTO(xx, 1, xsz) {
            if(x + xx >= xsz) break;
            if(picture[y][x+xx] == 'R') {
              drawn[y][x+xx] = 'R';
            }else {
              break;
            }
          }
          UPTO(xx, 1, xsz) {
            if(0 > x - xx) break;
            if(picture[y][x-xx] == 'R') {
              drawn[y][x-xx] = 'R';
            }else {
              break;
            }
          }
          drawn[y][x] = 'G';
          paint += 2;
        }
      }
    }

    /*
    TIMES(y, ysz) {
      DUMP(drawn[y]);
    }
    */
    
    TIMES(y, ysz) {
      TIMES(x, xsz) {
        if(picture[y][x] == 'B' and drawn[y][x] == '.') {
          TIMES(yy, ysz) {
            if(y+yy >= ysz) {
              break;
            }
            if(picture[y+yy][x] == 'B') {
              drawn[y+yy][x] = 'B';
            }else {
              break;
            }
          }
          ++paint;
        }
        if(picture[y][x] == 'R' and drawn[y][x] == '.') {
          TIMES(xx, xsz) {
            if(x + xx >= xsz) break;
            if(picture[y][x+xx] == 'R') {
              drawn[y][x+xx] = 'R';
            }else {
              break;
            }
          }
          ++paint;
        }
      }
    }
    
    return paint;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Manao has a bitmap H pixels high and W pixels wide. Initially, each of the pixels is white. Manao draws several (possibly zero) horizontal and/or vertical strokes. A stroke is a line segment 1 pixel thick and 1 or more pixels long. Manao only draws horizontal strokes with red color and vertical strokes with blue. He can paint a one pixel long stroke with either red or blue color, and the stroke will be considered horizontal if red and vertical if blue. Manao never draws two horizontal or two vertical strokes that overlap. If a horizontal stroke and a vertical stroke cross, the pixel at their intersection becomes green.

You're given a vector <string> picture denoting the bitmap after Manao's drawing experiments. The x-th character of the y-th element of picture describes the color of the pixel at coordinates (x, y) of the bitmap, where (0, 0) is the pixel at the top left corner and (W-1, H-1) is the pixel at the bottom right corner.  'R' is red, 'G' is green, 'B' is blue and '.' is white. Return the least possible number of strokes needed to obtain the given picture.

DEFINITION
Class:ColoredStrokes
Method:getLeast
Parameters:vector <string>
Returns:int
Method signature:int getLeast(vector <string> picture)


CONSTRAINTS
-picture will contain between 1 and 50 elements, inclusive.
-Each element of picture will be between 1 and 50 characters long, inclusive.
-All elements of picture will have equal length.
-Each character in picture will be 'R', 'G', 'B' or '.'.


EXAMPLES

0)
{"...",
 "..."}

Returns: 0

The picture is blank, Manao made no strokes.

1)
{"..B.",
 "..B."}

Returns: 1

A single vertical stroke is enough.

2)
{".BB."}

Returns: 2

Since only vertical strokes are painted with blue color, this picture needs two strokes.

3)
{"...B..",
 ".BRGRR",
 ".B.B.."}

Returns: 3

One horizontal and two vertical strokes are necessary for this masterpiece.

4)
{"...B..",
 ".BRBRR",
 ".B.B.."}

Returns: 4

This is the same picture as in the previous case with pixel (3,1) colored blue instead of green. Therefore, a single horizontal stroke won't help.

5)
{"GR",
 "BG"}

Returns: 4



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getLeast(Arg0)); }
	void test_case_1() { string Arr0[] = {"..B.",
 "..B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLeast(Arg0)); }
	void test_case_2() { string Arr0[] = {".BB."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getLeast(Arg0)); }
	void test_case_3() { string Arr0[] = {"...B..",
 ".BRGRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLeast(Arg0)); }
	void test_case_4() { string Arr0[] = {"...B..",
 ".BRBRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, getLeast(Arg0)); }
	void test_case_5() { string Arr0[] = {"GR",
 "BG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getLeast(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ColoredStrokes test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
