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

class Inchworm {
 public:
  int lunchtime(int branch, int rest, int leaf) {
    // -- main code --
    //DUMP((rest * leaf / gcd(branch, leaf)));
    //DUMP(gcd(branch,leaf));
    return 1 + branch / (rest * leaf / gcd(rest, leaf));
  }

  int gcd(int a, int b)
  {
    if(a == 0) {
      return b;
    }else if(b == 0 or a == b) {
      return a;
    }else if(a < b) {
      return gcd(b % a, a);
    }else if(a > b) {
      return gcd(a % b, b);
    }
    return - 1;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The inchworm is a creature of regular habits. She inches forward some distance along the branch of a tree, then stops to rest. If she has stopped at a leaf, she makes a meal of it. Then she inches forward the same distance as before, and repeats this routine until she has reached or passed the end of the branch.


Consider an inchworm traveling the length of a branch whose leaves are spaced at uniform intervals. Depending on the distance between her resting points, the inchworm may or may not be able to eat all of the leaves. There is always a leaf at the beginning of the branch, which is where the inchworm rests before setting out on her journey.


You are given three int values that specify, in inches: the length of the branch; the distance traveled by the inchworm between rests; and the distance between each consecutive pair of leaves. Given that the inchworm only eats at rest, calculate the number of leaves she will consume.


DEFINITION
Class:Inchworm
Method:lunchtime
Parameters:int, int, int
Returns:int
Method signature:int lunchtime(int branch, int rest, int leaf)


NOTES
-The inchworm starts by gobbling up the leaf at the beginning of the branch.
-If there is a leaf at the end of the branch, the inchworm eats it only if it falls at a resting point.


CONSTRAINTS
-branch is between 1 and 1000000 (one million), inclusive
-rest is between 1 and 1000, inclusive
-leaf is between 1 and 1000, inclusive


EXAMPLES

0)
11
2
4

Returns: 3

Leaves grow 0, 4, and 8 inches from the beginning of the branch. The inchworm eats them all.

1)
12
6
4

Returns: 2

The inchworm misses the leaves growing at distances 4 and 8, but eats those at 0 and 12.

2)
20
3
7

Returns: 1

The inchworm eats only the leaf at the outset.

3)
21
7
3

Returns: 2

The inchworm eats the leaves at the beginning and end of the branch.

4)
15
16
5

Returns: 1

The inchworm eats only the leaf at the outset.

5)
1000
3
7

Returns: 48

6)
1000
7
3

Returns: 48

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 2; int Arg2 = 4; int Arg3 = 3; verify_case(0, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 6; int Arg2 = 4; int Arg3 = 2; verify_case(1, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 3; int Arg2 = 7; int Arg3 = 1; verify_case(2, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 21; int Arg1 = 7; int Arg2 = 3; int Arg3 = 2; verify_case(3, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 16; int Arg2 = 5; int Arg3 = 1; verify_case(4, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 3; int Arg2 = 7; int Arg3 = 48; verify_case(5, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 1000; int Arg1 = 7; int Arg2 = 3; int Arg3 = 48; verify_case(6, Arg3, lunchtime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Inchworm test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
