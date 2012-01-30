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
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define FORN(x,n) FOR(x, 0, n)

using namespace std;

class BridgeCrossing {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A well-known riddle goes like this: Four people are crossing an old bridge. The bridge cannot hold more than two people at once. It is dark, so they can't walk without a flashlight, and they only have one flashlight! Furthermore, the time needed to cross the bridge varies among the people in the group. For instance, let's say that the people take 1, 2, 5 and 10 minutes to cross the bridge. When people walk together, they always walk at the speed of the slowest person. It is impossible to toss the flashlight across the bridge, so one person always has to go back with the flashlight to the others. What is the minimum amount of time needed to get all the people across the bridge?

In this instance, the answer is 17. Person number 1 and 2 cross the bridge together, spending 2 minutes. Then person 1 goes back with the flashlight, spending an additional one minute. Then person 3 and 4 cross the bridge together, spending 10 minutes. Person 2 goes back with the flashlight (2 min), and person 1 and 2 cross the bridge together (2 min). This yields a total of 2+1+10+2+2 = 17 minutes spent.

You want to create a computer program to help you solve new instances of this problem. Given an vector <int> times, where the elements represent the time each person spends on a crossing, your program should return the minimum possible amount of time spent crossing the bridge.

DEFINITION
Class:BridgeCrossing
Method:minTime
Parameters:vector <int>
Returns:int
Method signature:int minTime(vector <int> times)


NOTES
-In an optimal solution, exactly two people will be sent across the bridge with the flashlight each time (if possible), and exactly one person will be sent back with the flashlight each time.  In other words, in an optimal solution, you will never send more than one person back from the far side at a time, and you will never send less than two people across to the far side each time (when possible).


CONSTRAINTS
-times will have between 1 and 6 elements, inclusive.
-Each element of times will be between 1 and 100, inclusive.


EXAMPLES

0)
{ 1, 2, 5, 10 }

Returns: 17

The example from the text.

1)
{ 1, 2, 3, 4, 5 }

Returns: 16

One solution is: 1 and 2 cross together (2min), 1 goes back (1min), 4 and 5 cross together (5min), 2 goes back (2min), 1 and 3 cross together (3min), 1 goes back (1min), 1 and 2 cross together (2min). This yields a total of 2 + 1 + 5 + 2 + 3 + 1 + 2 = 16 minutes spent.

2)
{ 100 }

Returns: 100

Only one person crosses the bridge once.

3)
{ 1, 2, 3, 50, 99, 100 }

Returns: 162

*/
// END CUT HERE

 public:
  int minTime(vector <int> times) {
    // -- main code --

    int case_count = 1 << times.size();

    const int inf = 1000000000;
    vector<int> spent_times(case_count, inf);
    spent_times[0] = 0;
    
    FORN(i, times.size()) {
      vector<int> bits(times.size(), 0);

      FORN(j, i + 1) {
        bits[times.size() - j - 1] = 1 ;
      }

      do {
        int id = 0;
        FORN(j, bits.size()) {
          id = id | (bits[j] << j);
        }
        FORN(j, case_count) {
          int move = id ^ j;

          int c = 0;
          FORN(k, times.size()) {
            if((1 & (move >> k)) == 1) { 
              ++c;
            }
          }
          if(! (c == 1 || c == 2) ) {
            continue;
          }

          int dt = 0;
          FORN(k, times.size()) {
            if((1 & (move >> k)) == 1) { 
              dt += times[k];
            }
          }
          cout << t << endl;
          spent_times[j] = min(spent_times[j], t);
        }
        
      }while(next_permutation(bits.begin(), bits.end()));
    }
    
    return spent_times[case_count];	
  }
    
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 5, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = { 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 50, 99, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  BridgeCrossing test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

