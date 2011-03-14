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

class SmartElevator {
 public:
  int timeWaiting(vector <int> arrivalTime, vector <int> startingFloor, vector <int> destinationFloor) {
    // -- main code --
    int sz = arrivalTime.size();
    TIMES(y, sz-1) {
      FOR(x, y+1, sz) {
        if(arrivalTime[y] < arrivalTime[x]) {
          swap(arrivalTime[y], arrivalTime[x]);
          swap(startingFloor[y], startingFloor[x]);
          swap(destinationFloor[y], destinationFloor[x]);
        }
      }
    }

    vector<int> floors;
    
    TIMES(y, sz) {
      int f = startingFloor[y];
      vector<int>::iterator it = find(floors.begin(), floors.end(), f);
      if(it == floors.end()) floors.push_back(f);

      f = destinationFloor[y];
      it = find(floors.begin(), floors.end(), f);
      if(it == floors.end()) floors.push_back(f);
      
    }
    sort(floors.begin(), floors.end());
    
    vector< map<int, int> > dp(sz);

    TIMES(y, sz) {
      TIMES(x, floors.size()) {
        int f = floors[x];
        dp[y][f] = max(arrivalTime[y], startingFloor[y]-1) + abs(startingFloor[y] - f);
      }

    }

    FOR(y, 1, sz) {
      int prevDestArriveTime = dp[y-1][destinationFloor[y-1]];
      int prevDestToCurDestTime = abs(destinationFloor[y] - destinationFloor[y-1]);
      if(prevDestArriveTime + prevDestToCurDestTime > arrivalTime[y]) {
        TIMES(x, floors.size()) {
          int f = floors[x];
          dp[y][f] += prevDestToCurDestTime;
          dp[y][f] += abs(f - destinationFloor[y]);
        }
      }
    }
    
    return dp[sz-1][destinationFloor[sz-1]];
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have been put in charge of writing the sofware that powers an elevator in a very tall office building.  Because there is only one elevator in the building, and many floors, the designers of the elevator gave it the capacity to remember past usage history.  By assuming that the employees will probably use the elevator in the same ways and at the same times each day (arriving at work, going to the cafeteria, leaving for the day), the software can be a much better judge of where to travel and when.  For example, if it's currently on the fifth floor, and it knows that the next employee to use the elevator will be on the third floor, it can travel there early so that the employee will not have to spend any time waiting.

Given the arrival times, starting floors, and destination floors of each employee for the day, determine the fastest time in which the elevator can get each employee to his or her destination.  The elevator starts on floor 1 at time 0.  Travelling from floor p to floor q takes (abs(p - q)) units of time.  Also, the elevator may stand still for any length of time, if that is optimal.  Assume that it takes no time for employees to enter or exit the elevator.  Your method should return the minimal value of T such that, at time T, all employees have arrived at their destinations.  Employee i corresponds to the ith element of each input parameter.

DEFINITION
Class:SmartElevator
Method:timeWaiting
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int timeWaiting(vector <int> arrivalTime, vector <int> startingFloor, vector <int> destinationFloor)


CONSTRAINTS
-arrivalTime will contain between 1 and 5 elements, inclusive.
-arrivalTime, startingFloor, and destinationFloor will all contain the same number of elements.
-Each element in arrivalTime will be between 1 and 1000000, inclusive.
-Each element in startingFloor will be between 1 and 1000000, inclusive.
-Each element in destinationFloor will be between 1 and 1000000, inclusive.
-For all valid i, startingFloor[i] will never be equal to destinationFloor[i].


EXAMPLES

0)
{5}
{30}
{50}

Returns: 49

In this example, there is only one passenger.  He will arrive on floor 30 at time 5, but the elevator will not be able to get to floor 30 until time 29.  It will then pick up the employee and drop him off at floor 50 at time 49.

1)
{100}
{30}
{50}

Returns: 120

This is the same as example 0, but now the elevator can be ready at floor 30 when the employee arrives at time 100.  It will still take 20 units of time to reach floor 50, dropping off the passenger at time 120.

2)
{10,120}
{1,100}
{210,200}

Returns: 230

The first employee will be picked up at time 10 on floor 1.  At time 109, the elevator will arrive at floor 100.  Here, it will wait 11 units of time until the second employee arrives and gets on (at time 120).  It will then take another 100 units of time to reach floor 200 to drop off the second employee, and at time 230 it will finally arrive at floor 210 to drop off the first employee.

3)
{10,500}
{1,100}
{210,200}

Returns: 600

This is the same as example 2, but now the second employee doesn't arrive until time 500.  In this case, it makes more sense for the elevator to drop the first employee off immedately, and then return to floor 100 to wait for the second employee.

4)
{1000,1200,1600,2000,2400}
{500,500,500,500,500}
{700,300,700,300,700}

Returns: 2600

The elevator should wait at floor 500 until time 2000, picking up the first four passengers as they arrive.  It should drop off the second and fourth employees on floor 300, then return to floor 500 to pick up the fifth employee, and finally drop off the first, third, and fifth employees on floor 700.

5)
{775397,261225,870141,287698,884334}
{82225,958610,998971,413596,21922}
{769962,78706,477861,237168,258488}

Returns: 2724059

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 49; verify_case(0, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 120; verify_case(1, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10,120}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {210,200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 230; verify_case(2, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {210,200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 600; verify_case(3, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1000,1200,1600,2000,2400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500,500,500,500,500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {700,300,700,300,700}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2600; verify_case(4, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {775397,261225,870141,287698,884334}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {82225,958610,998971,413596,21922}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {769962,78706,477861,237168,258488}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2724059; verify_case(5, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  SmartElevator test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
