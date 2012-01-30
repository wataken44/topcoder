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

class CubePacking {
 public:
  int getMinimumVolume(int Ns, int Nb, int L) {
    // -- main code --

    int minvol = Ns + Nb * L * L * L;
    int ub = minvol + L * L;
    int My = 1 + (int)ceil(pow(ub, 1.0/3.0));
    
    //DUMP(lb);
    
    TIMES(i, L * L * L + 1) {
      int vol = minvol + i;

      UPTO(y, L, My) {
        if(vol % y != 0) continue;

        int Mx = 1 + (int)ceil(pow(vol/y, 0.5));
        UPTO(x, L, Mx) {
          
          if(vol % (x * y) != 0) {
            continue;
          }

          int z = vol / (x * y);

          int nnb = min(Nb, (x / L) * (y / L) * (z / L));
          int nns = vol - nnb * L * L * L;

          /*
          if(vol == 868402447) {
            DUMP(x); DUMP(y); DUMP(z);
            DUMP(nns); DUMP(nnb);
          } 
          */
          if(Ns <= nns and Nb <= nnb) {
            return vol;
          }
        }
      }
    }
    
    return -1;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel has Ns cubes with edge length 1 and Nb cubes with edge length L.  She wants to pack her cubes in a rectangular parallelepiped box.  Each cube must be packed in the box such that each of its edges is parallel to an edge of the box.

Ciel wants to know the smallest possible box she can use.  Return the minimum possible volume of a box which can store her cubes.


DEFINITION
Class:CubePacking
Method:getMinimumVolume
Parameters:int, int, int
Returns:int
Method signature:int getMinimumVolume(int Ns, int Nb, int L)


NOTES
-A rectangular parallelepiped is a closed box composed of three pairs of rectangular faces placed opposite each other and joined at right angles to each other.
-The answer will fit in 32-bit signed integer.


CONSTRAINTS
-Ns will be between 1 and 1,000,000,000, inclusive.
-Nb will be between 1 and 1,000,000, inclusive.
-L will be between 2 and 10, inclusive.


EXAMPLES

0)
2
2
2

Returns: 20

Ciel has two 1x1x1 cubes and two 2x2x2 cubes. She can pack them into 2x2x5 box. The volume of this box is 20.

1)
19
1
2

Returns: 27

Ciel's cubes can be packed into 3x3x3 box. Its volume is 27.

2)
51
7
5

Returns: 950



3)
12345
987
10

Returns: 999400



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 20; verify_case(0, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 19; int Arg1 = 1; int Arg2 = 2; int Arg3 = 27; verify_case(1, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 51; int Arg1 = 7; int Arg2 = 5; int Arg3 = 950; verify_case(2, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12345; int Arg1 = 987; int Arg2 = 10; int Arg3 = 999400; verify_case(3, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CubePacking test;

  test.getMinimumVolume(158846335, 973328, 9);
  
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
