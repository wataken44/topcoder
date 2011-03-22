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

class StreetParking {
 public:
  int freeParks(string street) {
    // -- main code --

    vector<int> parkable(street.size(), 1);

    TIMES(i, street.size()) {

      //1.	It is not directly in front of a private driveway.
      if(street[i] == 'D') {
        parkable[i] = 0;
      }
      //2.	It is not directly in front of a bus stop.
      //3.	It is not 5 meters before a bus stop.
      //4.	It is not 10 meters before a bus stop.
      UPTO(j, 0, 2) {
        int x = i + j;
        if(x < 0 || x >= (int)street.size()) {
          continue;
        }
        if(street[x] == 'B') {
          parkable[i] = 0;
        }
      }
      //5.	It is not directly in front of a side-street.
      //6.	It is not 5 meters before a side-street.
      //7.	It is not 5 meters after a side-street.
      UPTO(j, -1, 1) {
        int x = i + j;
        if(x < 0 || x >= (int)street.size()) {
          continue;
        }
        if(street[x] == 'S') {
          parkable[i] = 0;
        }
      }
    }

    int r = 0;
    TIMES(i, street.size()) {
      if(parkable[i] == 1) ++r;
    }
    
    return r;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are looking for a place to park your car on a suburban street. You can park at any position that meets the following requirements:

1.	It is not directly in front of a private driveway.
2.	It is not directly in front of a bus stop.
3.	It is not 5 meters before a bus stop.
4.	It is not 10 meters before a bus stop.
5.	It is not directly in front of a side-street.
6.	It is not 5 meters before a side-street.
7.	It is not 5 meters after a side-street.

The street will be represented as a string, where each character describes a section of the street 5 meters in length. So the first character describes the first 5 meters of the street, the second character describes the next 5 meters and so on. street will use 'D' for driveway, 'B' for bus stop, 'S' for side-street and '-' for all other sections of the street. A position is directly in front of an object if it has the same index as the object in street. A position is before an object if its index is lower than the index of the object in street. Finally, a position is after an object if its index is higher than the index of the object in street.

Given the street return the total number of possible parking spaces on that street.


DEFINITION
Class:StreetParking
Method:freeParks
Parameters:string
Returns:int
Method signature:int freeParks(string street)


CONSTRAINTS
-street will have between 1 and 50 characters inclusive.
-street will only contain characters 'D', 'B', 'S' and '-'.


EXAMPLES

0)
"---B--S-D--S--"

Returns: 4

The street looks like this:
---B--S-D--S--
^   ^    ^   ^
|   |    |   |
The arrows indicate where you are allowed to park on this street. Thus the method should return 4.

1)
"DDBDDBDDBDD"

Returns: 0

This street is full of private driveways and bus stops. You cannot park anywhere on this street. The method should return 0.

2)
"--S--S--S--S--"

Returns: 2

You can only park at the first and last positions on this street. The method should return 2.

3)
"SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D"

Returns: 14

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---B--S-D--S--"; int Arg1 = 4; verify_case(0, Arg1, freeParks(Arg0)); }
	void test_case_1() { string Arg0 = "DDBDDBDDBDD"; int Arg1 = 0; verify_case(1, Arg1, freeParks(Arg0)); }
	void test_case_2() { string Arg0 = "--S--S--S--S--"; int Arg1 = 2; verify_case(2, Arg1, freeParks(Arg0)); }
	void test_case_3() { string Arg0 = "SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D"; int Arg1 = 14; verify_case(3, Arg1, freeParks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  StreetParking test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
