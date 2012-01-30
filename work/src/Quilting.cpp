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

class Quilting {
 public:
  string lastPatch(int length, int width, vector <string> colorList) {
    // -- main code --

    vector< vector<string> > patch(length, vector<string>(width, "?"));

    int sy = length / 2 + 1;
    int sx = width / 2 + 1;

    int y = sy;
    int x = sx;
    
    while(true) {
      TIMES(d, 2) {
        patch[y][x] = "";
      }
    }
    
    return ;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A quilt is made by sewing square patches of different colors together in
a pattern.  We are using a pattern that says to start with one patch, and then add patches starting with the patch above it and continuing by spiraling outward counterclockwise until we
have the desired size. The picture below shows the order of the patches (a then b then c etc.)
in crafting a quilt whose length(i.e. height) is 4 and whose width is 3. 

          lkj    
          cbi     
          dah              
          efg                           

Define the neighbors of a newly added patch to be
all the previous patches that touch the new patch (including those that
just touch diagonally at a corner).  The rules for choosing the color of 
the newly added patch are 
    1) choose a color that minimizes the number of neighbors of the same color
    2) choose a color that has been used least often by previous patches
    3) choose the earliest(lowest index) color in the colorList

Rule 2 is applied only to decide among colors that are tied after rule 1 has been applied. Rule 3 
is applied only to decide among colors that are tied after the first two rules have been applied.

Create a class Quilting that contains a method lastPatch that returns the color
of the last patch added to the quilt.  Its inputs are an int length and an int 
width (the two dimensions of the finished quilt),  and 
a vector <string> colorList giving the
available colors.  length minus width will be 0 or 1,
so it will always be possible to produce a quilt of the given size.



DEFINITION
Class:Quilting
Method:lastPatch
Parameters:int, int, vector <string>
Returns:string
Method signature:string lastPatch(int length, int width, vector <string> colorList)


CONSTRAINTS
-width will be between 1 and 100 inclusive
-length will be between 1 and 100 inclusive
-length - width will be 0 or 1
-colorList will have between 1 and 10 elements inclusive
-each element of colorList will have between 1 and 15 characters inclusive
-each element of colorList will contain only uppercase letters 'A'-'Z'
-each element of colorList will be distinct


EXAMPLES

0)
3
2
{"RED","BLUE","TAN"}

Returns: "TAN"


  
       TAN  BLUE
       RED  RED 
       BLUE TAN

The layout above shows the finished quilt. It was created by starting at the position of the rightmost RED. (The color RED was chosen by rule 3). The BLUE above it was added next (RED was disqualified by rule 1, BLUE preferred over TAN by rule 3). Then TAN was chosen by rule 1, and then RED was chosen by rule 3. BLUE was chosen by rule 3 after RED was eliminated by rule 1. Finally the last patch was TAN by rule 1.



1)
4
3
{"E","D","C","B","A"}

Returns: "E"

  
       E B E
       C D A
       B E B
       A D C

The layout above shows the finished quilt. It was created by starting at the position of E near the middle.(The color E was chosen by rule 3). The D above it was added next (E was disqualified by rule 1, the
others were tied under rule 2, and D was preferred over the others by rule 3). The process continued until the final E in the upper left corner was chosen because B, C, and D were eliminated by rule 1, E and A were tied under rule 2 and E was preferred to A by rule 3.


2)
3
3
{"A","B","C","D"}

Returns: "C"



             C B C
             D A A
             B C D

This quilt was constructed by starting at the position of the middle A and
then adding the B patch above it.  The final patch was the C in the
upper right corner.


3)
1
1
{"RED","BLUE","YELLOW"}

Returns: "RED"

4)
10
10
{"X","Y","Z"}

Returns: "Z"


  Z Y Z Y X Y X Z X Y
  X X Z Y Z Y X Y X Z
  Z Y Z X Z Y Z Y Z Y
  X Z X Y X Y X Z X X
  Y Z Y Z Z Y Z Y Y Y
  Z X X X X X X Z X Z
  Y Y Y Z Y Z Y Y Z Y
  X X Z X Y X Z X X X
  Y Z Y X Z X Y Z Y Y
  Z X Y Z Y Z X Z X Z


*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; string Arr2[] = {"RED","BLUE","TAN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "TAN"; verify_case(0, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; string Arr2[] = {"E","D","C","B","A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "E"; verify_case(1, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"A","B","C","D"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "C"; verify_case(2, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"RED","BLUE","YELLOW"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "RED"; verify_case(3, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 10; string Arr2[] = {"X","Y","Z"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Z"; verify_case(4, Arg3, lastPatch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Quilting test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
