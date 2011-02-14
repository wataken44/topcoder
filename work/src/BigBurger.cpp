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

class BigBurger {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// BigBurger Inc. wants to see if having a single person at the counter both to
take orders and to serve them is feasible.  At each BigBurger, customers will 
arrive and get in line. When they get to the head of the line they will place
their order, which will be assembled and served to them.  Then they will leave
the BigBurger and the next person in line will be able to order.

We need to know how long a customer may be forced to wait before he or she can
place an order.  Given a script that lists each customer for a typical day,
we want to calculate the maximum customer waiting time.  Each customer in the
script is characterized by an arrival time (measured in minutes after the store
opened) and a service duration (the number of minutes between ordering and
getting the food). 

Create a class BigBurger that contains method maxWait that is given a vector <int>
arrival and a vector <int> service describing all the customers and returns the
maximum time spent by a customer between arriving and placing the order. Corresponding
elements of arrival and service refer to the same customer, and they are
given in the order in which they arrive at the store (arrival is in non-descending
order).

If multiple customers arrive at the same time they will all join the line at the
same time, with the ones listed earlier ahead of ones appearing later in the list.



DEFINITION
Class:BigBurger
Method:maxWait
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxWait(vector <int> arrival, vector <int> service)


CONSTRAINTS
-arrival will contain between 1 and 50 elements inclusive
-service will contain the same number of elements as arrival
-the elements of arrival will be in non-decreasing order
-each element of arrival will be between 1 and 720 inclusive
-each element of service will be between 1 and 15 inclusive


EXAMPLES

0)
{3,3,9}
{2,15,14}

Returns: 11


   Two customers arrive at time 3. The first one waits 0 time, orders, 
and is  served after 2 minutes, leaving at time 5. The second one then
orders and is served at time 20.  Meanwhile a customer arrives at
time 9 and waits until the second customer leaves.  This last customer 
then orders at time 20, and is served and leaves at time 20+14 = 34.  
The first customer waited 0 minutes, the second waited 2 minutes (from 
time 3 to time 5), and the last customer waited 11 minutes (from 
time 9 to time 20).

1)
{182}
{11}

Returns: 0

The first customer never needs to wait.

2)
{2,10,11}
{3,4,3}

Returns: 3

The third customer needs to wait from time 11 to time 14. Neither of the other customers needs to wait at all.

3)
{2,10,12}
{15,1,15}

Returns: 7

The second customer waits the longest.

*/
// END CUT HERE

 public:
  int maxWait(vector <int> arrival, vector <int> service) {
    // -- main code --

    TIMES(i, arrival.size()) {
      FOR(j, i + 1, arrival.size()) {
        if(arrival[i] > arrival[j] or
           (arrival[i] == arrival[j] and service[i] > service[j])) {
          swap(arrival[i], arrival[j]);
          swap(service[i], service[j]);
        }
      }
    }

    
    int maxWait = 0;
    int prevServiceFinish = 0;
    TIMES(i, arrival.size()) {
      if(prevServiceFinish <= arrival[i]) {
        // no wait
        prevServiceFinish = arrival[i] + service[i];
      }else {
        maxWait = max(maxWait, prevServiceFinish - arrival[i]);
        prevServiceFinish = prevServiceFinish + service[i];
      }
    }
    
    return maxWait;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,15,14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(0, Arg2, maxWait(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {182}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, maxWait(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,10,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, maxWait(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,10,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,1,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, maxWait(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  BigBurger test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
