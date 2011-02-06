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
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

// -- utility --


using namespace std;

class GasStations {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// With today's high gas prices, drivers often go to great lengths to find the cheapest gas.  In this problem, you are to write a method for a system that helps a person plan where to stop for gas on a long trip.  You can assume that the person has already planned the route, and that it is fixed.  With the route information, the system (which might be built into a car, for example) can retrieve price information about the gas at all of the gas stations along the way.  With this information, your method must plan which gas stations to stop at, and how much gas to get at each station to minimize the cost of the trip.

More specifically, you will be given a vector <int> dist, a vector <int> prices, an int mpg, an int tankSize, and an int tripLength and are to return the lowest possible cost of the trip.  Each element of dist, and the corresponding element of prices, represents the distance to the gas station from the start of the trip (in miles) and the price of the gas at that station (in thousandths of a dollar per gallon).  mpg stands for miles per gallon, and represents the number of miles the car may travel on a single gallon of gas.  Note that gallons need not be used in whole amounts.  tankSize represents the maximum number of gallons that the tank of gas may hold.  The trip starts at mile 0 and ends at mile tripLength, and you start the trip with a full tank of gas.  You may purchase any quantity of gas (including fractional amounts of gallons) at any gas station.


DEFINITION
Class:GasStations
Method:tripCost
Parameters:vector <int>, vector <int>, int, int, int
Returns:double
Method signature:double tripCost(vector <int> dist, vector <int> price, int mpg, int tankSize, int tripLength)


NOTES
-Your solution need not be exactly correct to be evaluated as correct.  As long as the relative error between your result and the true result is less than 1e-9, your result will be evaluated as correct.


CONSTRAINTS
-distances and prices will contain the same number of elements.
-distances and prices will contain between 1 and 50 elements, inclusive.
-mpg will be between 1 and 1000, inclusive.
-tankSize will be between 1 and 1000, inclusive.
-tripLength will be between 2 and 10,000, inclusive.
-Each element of distances will be between 1 and tripLength-1, inclusive.
-Each element of prices will be between 50 and 20,000, inclusive.
-The trip will be possible.


EXAMPLES

0)
{100,100}
{1000,1500}
20
10
300

Returns: 5000.0

The 10 gallon tank allows the car to go 200 miles on a full tank.  So, in order to get from the station at 100 miles to the end of the trip at 300 miles, the tank has to be filled up at one of the gas stations after 100 miles.  Clearly, we should fill it up at the cheaper one, and since we have gone 100 miles so far, we need to buy 5 gallons of gas, for 5,000 thousandths of a dollar.

1)
{300,450,525}
{1659,1529,1439}
20
20
600

Returns: 15277.5

2)
{300,450,525}
{1659,1439,1529}
20
20
600

Returns: 14940.0

3)
{300,125,450,525}
{1659,1729,1439,1529}
20
20
600

Returns: 14940.0

4)
{200}
{1000}
20
20
400

Returns: 0.0

5)
{100,400}
{1549,1649}
25
16
600

Returns: 12792.0

*/
// END CUT HERE

 public:
  double tripCost(vector <int> dist, vector <int> price, int mpg, int tankSize, int tripLength) {
    double result;
    // -- main code --

    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 10; int Arg4 = 300; double Arg5 = 5000.0; verify_case(0, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {300,450,525}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1659,1529,1439}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 600; double Arg5 = 15277.5; verify_case(1, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {300,450,525}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1659,1439,1529}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 600; double Arg5 = 14940.0; verify_case(2, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {300,125,450,525}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1659,1729,1439,1529}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 600; double Arg5 = 14940.0; verify_case(3, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 400; double Arg5 = 0.0; verify_case(4, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arr0[] = {100,400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1549,1649}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; int Arg3 = 16; int Arg4 = 600; double Arg5 = 12792.0; verify_case(5, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  GasStations test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

