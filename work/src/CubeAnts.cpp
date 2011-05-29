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

class CubeAnts {
 public:
  int getMinimumSteps(vector <int> pos) {
    // -- main code --

    int t = 0;

    TIMES(i, pos.size()) {
      if(pos[i] == 1 or pos[i] == 3 or pos[i] == 4) t = max(t, 1);
      if(pos[i] == 2 or pos[i] == 7 or pos[i] == 5) t = max(t, 2);
      if(pos[i] == 6) t = max(t, 3);
    }
    
    return t;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Fox Ciel is observing the behavior of ants. She has a cube whose vertices are indexed from 0 to 7 as follows.

You are given a vector <int> pos containing the initial locations of the ants.  The i-th element of pos is the index of the vertex where the i-th ant is located.  In an attempt to observe their moves, Ciel puts honey on the 0-th vertex.  The ants notice it immediately and start moving toward the honey.  In a single turn, each ant will either move to an adjacent vertex along an edge of the cube or stay in its current vertex.  All moves in a turn happen simultaneously, and at all times, it is legal for multiple ants to be at the same location of the cube.

Ciel observes the ants until they all move to the 0-th vertex.  In order to determine how clever they were, she wants to know the minimal number of turns that were required for this to happen.  Return this minimal number.


DEFINITION
Class:CubeAnts
Method:getMinimumSteps
Parameters:vector <int>
Returns:int
Method signature:int getMinimumSteps(vector <int> pos)


CONSTRAINTS
-pos will contain between 1 and 50 elements, inclusive.
-Each element of pos will be between 0 and 7, inclusive.


EXAMPLES

0)
{0,1,1}

Returns: 1



1)
{5,4}

Returns: 2



2)
{0}

Returns: 0

There is only one ant, and it is already on the 0-th vertex, so the minimum number of turns required is 0.

3)
{6,1,6}

Returns: 3



4)
{7,7,3,3,7,7,3,3}

Returns: 2



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimumSteps(Arg0)); }
	void test_case_1() { int Arr0[] = {5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getMinimumSteps(Arg0)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMinimumSteps(Arg0)); }
	void test_case_3() { int Arr0[] = {6,1,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getMinimumSteps(Arg0)); }
	void test_case_4() { int Arr0[] = {7,7,3,3,7,7,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, getMinimumSteps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CubeAnts test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
