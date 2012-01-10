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

class TireRotation {
 public:
  int getCycle(string initial, string current) {
    // -- main code --

    string turned = initial;
    TIMES(i, 4) {
      if(turned == current) {
        return i + 1;
      }
      string next = turned.substr(3,1) + turned.substr(2,1)+turned.substr(0,1)+turned.substr(1,1);
      turned = next;

      //cout << i << " " << turned << " " << current <<  endl;
      //cout.flush();
    }
    
    return -1;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Note to plugin users: there is an image in this problem statement.  Please view the statement in the applet to see the image



Tire rotation is a simple but effective part of vehicle preventive maintenance.  Without it, the tires of a car may wear out thousands of miles early.  The idea is to have each tire spend part of its life on each wheel of the car.  To accomplish this, the tire on each wheel is moved to another wheel according to a pattern.  First, we assume the wheel positions are numbered left to right, front to rear.  Then we establish a rotation pattern:







From the diagram, we see that for each phase of the rotation cycle, a tire is moved from one wheel position to another, according to the following chart:



starting      ending
 wheel        wheel
   1 ---------> 3
   2 ---------> 4
   3 ---------> 2
   4 ---------> 1



Therefore, if our four tires are represented by A, B, C, and D, there are four valid phases of the rotation cycle:



Phase:   1        2        3        4
Tires:  A B ---> D C ---> B A ---> C D
        C D      A B      D C      B A
         ^                          |
         |__________________________|



Write a method will take a string initial and a string current, which will both represent the tires on a car.  Each character will be a capital letter ('A'-'Z') and will represent a serial number that identifies a tire.  initial will be the starting locations of the tires, and current will be the current locations.  The position of a character represents the wheel that the tire is on.  The characters represent the wheels in the order: 1, 2, 3, 4 (from the diagram above).  Using the rotation pattern above, your method should return a 1, 2, 3, or 4 if the tires are in the 1st, 2nd, 3rd, or 4th phase of the rotation cycle.  If the tires have been rotated improperly (that is, they are not in any phase), your method should return -1.


DEFINITION
Class:TireRotation
Method:getCycle
Parameters:string, string
Returns:int
Method signature:int getCycle(string initial, string current)


CONSTRAINTS
-initial will only contain capital letters ('A' - 'Z', inclusive), and will be exactly 4 characters long.
-initial will not have any repeated characters.
-current will be exactly 4 characters long, and will contain the same characters that are in initial.
-current will not have any repeated characters.


EXAMPLES

0)
"ABCD"
"ABCD"

Returns: 1

These tires have not been rotated yet.

1)
"ABCD"
"DCAB"

Returns: 2

The initial locations of the tires are:


A B
C D
After one rotation, the locations of the tires are:
D C
A B

2)
"ABCD"
"CDBA"

Returns: 4

Continuing the rotation, we get the following for phase 3:

B A
D C
And finally, on phase 4:


C D
B A

3)
"ABCD"
"ABDC"

Returns: -1


Here, the rear two tires were moved incorrectly, and the front two were not moved at all.


4)
"ZAXN"
"XNAZ"

Returns: 4

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; string Arg1 = "ABCD"; int Arg2 = 1; verify_case(0, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCD"; string Arg1 = "DCAB"; int Arg2 = 2; verify_case(1, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABCD"; string Arg1 = "CDBA"; int Arg2 = 4; verify_case(2, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABCD"; string Arg1 = "ABDC"; int Arg2 = -1; verify_case(3, Arg2, getCycle(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ZAXN"; string Arg1 = "XNAZ"; int Arg2 = 4; verify_case(4, Arg2, getCycle(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  TireRotation test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
