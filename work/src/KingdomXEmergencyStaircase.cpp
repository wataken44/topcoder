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

class KingdomXEmergencyStaircase {
 public:
  long long determineCost(string leftBuilding, string rightBuilding, vector <int> cost) {
    // -- main code --
    
    return ;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


A city has imposed new safety measures for its buildings. An emergency staircase is going to be built between the only two tall buildings in Linear Kingdom. These buildings are side-by-side and are infinitely tall. The lowest floor is floor 0 on the ground. The distance between two adjacent floors is two meters. The sides of the buildings are parallel and the distance between the buildings is Width meters, where Width is an even integer. The illustration below shows the bottom of the buildings when the buildings are separated by 4 meters (note that for simplicity only the first six floors are labeled):



Normally a staircase is a structure composed of "flights" (or "flights of stairs") and "landings." A flight is a continious sequence of stairs (steps), usually the same size and in the same direction, which begins and ends on flat areas called landings. For this problem we will use an idealized staircase where landings are a single points and flights are straight line segments.

Each flight that is going to be built is a straight line segment whose slope is either 1 or -1. The picture below illustrates two examples of flights.



Some floors of the buildings have emergency exits. These exits are going to be connected to the ground through the staircase. You are given strings leftBuilding and rightBuilding. The i-th character (1-based indexing) of leftBuilding (rightBuilding) will be 'Y' if there is an emergency exit on floor i of the left building (right building). Note that this implies that no emergency exit will be on floor 0.  

Initially, all floors except floor 0 are not connected to the ground. The procedure for building the staircase will be as follows:

You pick a point that is connected to the ground (this point must be located on the staircase or on floor 0).
Then, you pick one of the two possible slopes for the flight and extend a line segment from your chosen point until the first time you hit the edge of a building or another flight. This segment must not end in the middle of the ground (though segments that end at floor 0 are allowed). This line segment is the new flight that you are going to build.
Flights must be built only in the space between the buildings.
All points on the new flight become connected to the ground and if this flight ends at the edge of a building, that floor of that building becomes connected to the ground.
For simplicity, you are only allowed to create flights whose length is a multiple of the square root of 2. That is, a flight connects a vertex of the grid in the first image to another vertex there. Below is an example of a final staircase configuration of valid  flights:



The cost of a flight is determined by its length. You are given vector <int> cost containing Width elements. The i-th element in cost (0-based indexing) is the actual cost to build a flight whose length is (i+1) * SQRT(2). Note that the cost of the flight is the cost of the original length at the time it is built. Starting a new flight at some non-endpoint of an existing flight (for the purposes of this problem) does not divide the existing flight into two and does not affect the cost of the existing flight.

Return the minimum cost required to connect all the emergency exits to the ground.


DEFINITION
Class:KingdomXEmergencyStaircase
Method:determineCost
Parameters:string, string, vector <int>
Returns:long long
Method signature:long long determineCost(string leftBuilding, string rightBuilding, vector <int> cost)


CONSTRAINTS
-leftBuilding will contain between 1 and 50 characters, inclusive.
-rightBuilding will contain between 1 and 50 characters, inclusive.
-Each character in leftBuilding and rightBuilding will be 'Y' or 'N'.
-There will be at least one 'Y' in leftBuilding, or, there will be at least one 'Y' in rightBuilding.
-cost will contain between 2 and 10 elements, inclusive.
-cost will contain an even number of elements.
-Each element of cost will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
"YNYY"
"NNNY"
{10, 40, 18, 25}

Returns: 98

The optimal solution corresponds to the last image in the statement. Note that the black squares on some of the floors represent the ones with exits.

1)
"N"
"Y"
{1, 1000}

Returns: 1000



2)
"NNNNNNNY"
"NNNNNNNY"
{1, 2}

Returns: 17



3)
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN"
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY"
{800000000,800000000,800000000,800000000,800000000,800000000,800000000,800000000}

Returns: 6400000000

The answer may not fit into a 32-bit integer.

4)
"NNY"
"NNYYY"
{10000, 10, 40, 10000, 80, 80}

Returns: 220



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYY"; string Arg1 = "NNNY"; int Arr2[] = {10, 40, 18, 25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 98LL; verify_case(0, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "N"; string Arg1 = "Y"; int Arr2[] = {1, 1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1000LL; verify_case(1, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "NNNNNNNY"; string Arg1 = "NNNNNNNY"; int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 17LL; verify_case(2, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN"; string Arg1 = "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY"; int Arr2[] = {800000000,800000000,800000000,800000000,800000000,800000000,800000000,800000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6400000000LL; verify_case(3, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "NNY"; string Arg1 = "NNYYY"; int Arr2[] = {10000, 10, 40, 10000, 80, 80}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 220LL; verify_case(4, Arg3, determineCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  KingdomXEmergencyStaircase test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
