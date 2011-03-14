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

using namespace std;

class Table {
 public:
  vector <string> layout(vector <string> tbl) {
    // -- main code --

    vector< vector<char> > cur;

    int xsz = 0;
    int ysz = 0;

    TIMES(i, tbl.size()) {
      string s = tbl[i];

      TIMES(j, s.size() / 7) {
        int col = s[j*7+1] - '0';
        int row = s[j*7+3] - '0';
        char c = s[j*7+5];

        if(ysz + row > cur.size()) {
          TIMES(k, ysz + row - cur.size()) {
            cur.push_back(vector<char>(xsz));
          }
          ysz += row;
        }

        if(xsz + col > cur[ysz-1].size()) {
          TIMES(k, cur.size()) {
            cur[k].resize(xsz+col);
          }
          xsz += col;
        }
      }
    }

    TIMES(y, cur.size()) {
      TIMES(x, cur[y].size()) {
        cur[y][x] = '?';
      }
    }

    int x = 0;
    int y = 0;
    TIMES(i, tbl.size()) {
      
      string s = tbl[i];

      TIMES(j, s.size() / 7) {
        int col = s[j*7+1] - '0';
        int row = s[j*7+3] - '0';
        char c = s[j*7+5];

        TIMES(yy, row) {
          TIMES(xx, col) {
            
          }
        }
      }

      x = 0;
      ++y;
    }

    
    return cur;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A table is a common structure used in HTML when doing the layout of a home page. A table without any merged cells simply contains rows*columns basic cells (see figure 1 below). It's often desirable to merge several basic cells, either horizontally, vertically, or both, in which case the table may look like the one in figure 2. A merged cell will always be of rectangular shape, so the table in figure 3 is not a valid table.



Each cell in the table is described with a 3-tuple in the format (colspan,rowspan,content) where colspan and rowspan are integers between 1 and 9, inclusive, representing the width and height of the cell (in basic cell units) and content is an upper case letter ('A'-'Z').

The table will be described as a vector <string> where each element corresponds to a row of basic cells in the table, and the cells in each row are described from left to right. The merged cells are defined in the input by their upper left corner, the other parts of a merged cell are not explicitly defined in the input. Thus, element i will represent all cells whose upper left corner are in the ith row. Consider figure 4 below: the shaded "cells" are part of a merged cell and will not be mentioned in the description.



Thus this table will be described like this:


{"(1,1,A)(2,1,B)(1,1,C)(1,1,D)",
 "(1,1,E)(1,1,F)(1,1,G)(1,1,H)(1,1,I)",
 "(1,3,J)(1,1,K)(3,2,L)",
 "(1,1,M)",
 "(1,1,N)(1,1,O)(1,1,P)(1,1,Q)",
 "(1,1,R)(1,1,S)(1,1,T)(1,1,U)(1,1,V)"}


The desired output is the same table but in matrix form. That is, each basic cell should occupy one character in a vector <string>. You may assume that the input table is valid, that all rows will contain the same number of basic cells, that no cell will be missing or overlapped.

Create a class Table containing the method layout which takes a vector <string> tbl which describes a table in the format above and returns a vector <string> containing the table in the matrix form described above.

DEFINITION
Class:Table
Method:layout
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> layout(vector <string> tbl)


NOTES
-It's possible that a row might be empty, see example 1.
-If you are using a plugin and you don't see the pictures, you may want to read the problem statement in the applet.


CONSTRAINTS
-tbl will contain between 1 and 50 elements, inclusive.
-Each element in tbl will contain between 0 and 50 characters, inclusive.
-Each element in tbl will contain zero or more tuples in the format above, with no extra characters.
-tbl will describe a valid table with no cells missing or overlapping.
-The return value will contain between 1 and 50 elements, inclusive, and each element will contain between 1 and 50 characters, inclusive.


EXAMPLES

0)
{"(1,1,A)(2,1,B)(1,1,C)(1,1,D)",
 "(1,1,E)(1,1,F)(1,1,G)(1,1,H)(1,1,I)",
 "(1,3,J)(1,1,K)(3,2,L)",
 "(1,1,M)",
 "(1,1,N)(1,1,O)(1,1,P)(1,1,Q)",
 "(1,1,R)(1,1,S)(1,1,T)(1,1,U)(1,1,V)"}

Returns: { "ABBCD",  "EFGHI",  "JKLLL",  "JMLLL",  "JNOPQ",  "RSTUV" }

This is the example in the problem text:


ABBCD
EFGHI
JKLLL
JMLLL
JNOPQ
RSTUV


1)
{"(1,3,N)(3,2,E)(3,1,M)(1,1,Q)",
 "(1,1,T)(3,1,U)",
 "(1,1,Y)(4,5,A)(1,2,V)(1,2,W)",
 "(1,3,G)(1,3,Z)",
 "(1,2,S)(1,3,D)",
 "",
 "(1,2,P)(1,2,F)(1,3,J)",
 "(1,1,L)(3,3,K)(1,1,R)",
 "(3,2,B)(1,1,D)",
 "(2,1,A)",
 "(2,3,O)(4,1,X)(1,1,I)(1,1,B)",
 "(3,2,H)(3,2,C)",
 ""}

Returns: { "NEEEMMMQ",  "NEEETUUU",  "NYAAAAVW",  "GZAAAAVW",  "GZAAAASD",  "GZAAAASD",  "PFAAAAJD",  "PFLKKKJR",  "BBBKKKJD",  "BBBKKKAA",  "OOXXXXIB",  "OOHHHCCC",  "OOHHHCCC" }

Note the two empty rows!


2)
{"(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,9,G)(9,9,H)(9,9,I)(9,9,J)(9,9,K)(5,9,L)",
 "","","","","","","","",
 "(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,9,G)(9,9,H)(9,9,I)(9,9,J)(9,9,K)(5,9,L)",
 "","","","","","","","",
 "(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,5,G)(9,5,H)(9,5,I)(9,5,J)(9,5,K)(5,5,L)",
 "","","",""}

Returns: { "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL" }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"(1,1,A)(2,1,B)(1,1,C)(1,1,D)",
 "(1,1,E)(1,1,F)(1,1,G)(1,1,H)(1,1,I)",
 "(1,3,J)(1,1,K)(3,2,L)",
 "(1,1,M)",
 "(1,1,N)(1,1,O)(1,1,P)(1,1,Q)",
 "(1,1,R)(1,1,S)(1,1,T)(1,1,U)(1,1,V)"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ABBCD",  "EFGHI",  "JKLLL",  "JMLLL",  "JNOPQ",  "RSTUV" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, layout(Arg0)); }
	void test_case_1() { string Arr0[] = {"(1,3,N)(3,2,E)(3,1,M)(1,1,Q)",
 "(1,1,T)(3,1,U)",
 "(1,1,Y)(4,5,A)(1,2,V)(1,2,W)",
 "(1,3,G)(1,3,Z)",
 "(1,2,S)(1,3,D)",
 "",
 "(1,2,P)(1,2,F)(1,3,J)",
 "(1,1,L)(3,3,K)(1,1,R)",
 "(3,2,B)(1,1,D)",
 "(2,1,A)",
 "(2,3,O)(4,1,X)(1,1,I)(1,1,B)",
 "(3,2,H)(3,2,C)",
 ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "NEEEMMMQ",  "NEEETUUU",  "NYAAAAVW",  "GZAAAAVW",  "GZAAAASD",  "GZAAAASD",  "PFAAAAJD",  "PFLKKKJR",  "BBBKKKJD",  "BBBKKKAA",  "OOXXXXIB",  "OOHHHCCC",  "OOHHHCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, layout(Arg0)); }
	void test_case_2() { string Arr0[] = {"(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,9,G)(9,9,H)(9,9,I)(9,9,J)(9,9,K)(5,9,L)",
 "","","","","","","","",
 "(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,9,G)(9,9,H)(9,9,I)(9,9,J)(9,9,K)(5,9,L)",
 "","","","","","","","",
 "(9,9,A)(9,9,B)(9,9,C)(9,9,D)(9,9,E)(5,9,F)",
 "","","","","","","","",
 "(9,5,G)(9,5,H)(9,5,I)(9,5,J)(9,5,K)(5,5,L)",
 "","","",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "AAAAAAAAABBBBBBBBBCCCCCCCCCDDDDDDDDDEEEEEEEEEFFFFF",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL",  "GGGGGGGGGHHHHHHHHHIIIIIIIIIJJJJJJJJJKKKKKKKKKLLLLL" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, layout(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Table test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
