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

class TheProgrammingContestDivOne {
 public:
  int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime) {
    // -- main code --
    
    return ;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Farmer John and Fox Brus are participating in a programming contest as a team.


The duration of the contest is T minutes and they are given N tasks. Solutions can be submitted at any time during the contest, including exactly T minutes after the start of the contest. If they solve the i-th task immediately after the start of the contest, they get maxPoints[i] points and it decreases by pointsPerMinute[i] points per minute. In other words, if they solve the i-th task t minutes after the start of the contest, they will get maxPoints[i] - t * pointsPerMinute[i] points. It takes them requiredTime[i] minutes to solve the i-th task.


Return the maximal points they can get.

DEFINITION
Class:TheProgrammingContestDivOne
Method:find
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime)


CONSTRAINTS
-T will be between 1 and 100,000, inclusive.
-maxPoints will contain between 1 and 50 elements, inclusive.
-maxPoints, pointsPerMinute and requiredTime will contain the same number of elements.
-Each element of maxPoints will be between 1 and 100,000, inclusive.
-Each element of pointsPerMinute will be between 1 and 100,000, inclusive.
-Each element of requiredTime will be between 1 and 100,000, inclusive.


EXAMPLES

0)
74
{502}
{2}
{47}

Returns: 408

They can solve the task 47 minutes after the start of the contest. They will get 502 - 2 * 47 = 408 points.

1)
40000
{100000, 100000}
{1, 100000}
{50000, 30000}

Returns: 0

They don't have time to solve the first task. If they solve the second task, they will get negative points (100000 - 100000 * 30000 = -2999900000 points), so they shouldn't solve it.

2)
75
{250, 500, 1000}
{2, 4, 8}
{25, 25, 25}

Returns: 1200


First, they can solve the third task 25 minutes after the start of the contest. They get 1000 - 8 * 25 = 800 points.
Second, they can solve the second task 50 minutes after the start of the contest. They get 500 - 4 * 50 = 300 points.
Third, they can solve the first task 75 minutes after the start of the contest. They get 250 - 2 * 75 = 100 points.

In total, they can get 800 + 300 + 100 = 1200 points.

3)
30
{100, 100, 100000}
{1, 1, 100}
{15, 15, 30}

Returns: 97000

The best strategy is solving only the third task.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 74; int Arr1[] = {502}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {47}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 408; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 40000; int Arr1[] = {100000, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 100000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50000, 30000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 75; int Arr1[] = {250, 500, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {25, 25, 25}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1200; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 30; int Arr1[] = {100, 100, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {15, 15, 30}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 97000; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  TheProgrammingContestDivOne test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
