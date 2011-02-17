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

class LeaguePicks {
 public:
  vector <int> returnPicks(int position, int friends, int picks) {
    // -- main code --

    vector<int> ret;

    bool ascend = true;
    int picker = 1;
    
    UPTO(p, 1, picks) {
      if(picker == position) {
        ret.push_back(p);
      }
      if(ascend) {
        picker = picker + 1;
        if(picker > friends) {
          picker = friends;
          ascend = false;
        }
      }else {
        picker = picker - 1;
        if(picker == 0) {
          picker = 1;
          ascend = true;
        }
      }
    }
    
    return ret;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//  You and your friends are setting up a fantasy TopCoder league, where you choose coders to be on your team and score points in the league when any one of your coders wins their room or successfully challenges somebody, etc. To be fair, a system has been developed to choose the order in which picks are distributed. It works like this: first, lots are drawn to choose your position in the league. Then the player with the first position gets first pick, the second player gets second pick, all the way until the last player picks. Then the order reverses: the last player chooses again, then the next to last player, and so on, until you reach the first player again. Then the cycle repeats: the first position chooses again, then the second, and so on.
 For example: say you were in the third position on a 6 player league. You would get the 3rd pick, then you'd wait until the 10th pick (the order would be 1,2,you,4,5,6,6,5,4,you), and then the 15th pick, and so on until there were no more coders to choose. If there were 20 total picks, then you would get pick numbers 3,10,15.
Not wanting to miss your chance at a pick, your goal is to write a program that tells you what pick numbers you have in the order that you have them. You will receive three ints indicating your position in the league(1 being the first position), the number of friends that are in the league with you, and the number of picks that are being divvied up among the league. You will return an vector <int> that indicates the picks that you receive in ascending order.

DEFINITION
Class:LeaguePicks
Method:returnPicks
Parameters:int, int, int
Returns:vector <int>
Method signature:vector <int> returnPicks(int position, int friends, int picks)


NOTES
-Note that your position in the league and the pick numbers start at 1 and not 0. This should be clear from the examples.


CONSTRAINTS
-position will be between 1 and friends inclusive.
-friends will be between 1 and 40 inclusive.
-picks will be between 1 and 40 * friends inclusive.


EXAMPLES

0)
3
6
15

Returns: { 3,  10,  15 }

Example from above.

1)
1
1
10

Returns: { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }

You're the only player, so you get all the picks.

2)
1
2
39

Returns: { 1,  4,  5,  8,  9,  12,  13,  16,  17,  20,  21,  24,  25,  28,  29,  32,  33,  36,  37 }

You'll get the 1st and 4th picks in every set of 4.

3)
5
11
100

Returns: { 5,  18,  27,  40,  49,  62,  71,  84,  93 }

You'll get the 5th and (2*11-5+1) or 18th picks out of every 2*11 picks.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 6; int Arg2 = 15; int Arr3[] = { 3,  10,  15 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, returnPicks(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arr3[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, returnPicks(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 39; int Arr3[] = { 1,  4,  5,  8,  9,  12,  13,  16,  17,  20,  21,  24,  25,  28,  29,  32,  33,  36,  37 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, returnPicks(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 11; int Arg2 = 100; int Arr3[] = { 5,  18,  27,  40,  49,  62,  71,  84,  93 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, returnPicks(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  LeaguePicks test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
