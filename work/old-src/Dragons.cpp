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

class Dragons {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is a small cube planet somewhere. On each side of the cube there lives a four-armed dragon. It is time for dinner now. Each dragon sits in front of his bowl with food. 

During each round, the following happens: Each dragon is trying to steal food from his neighbors (living on four neighboring sides of the cube). He spreads his four arms there (each arm goes to 
each separate neighbor). As other dragons do the same, four hands meet in each bowl of food. Four hands fight for a while and each takes one quarter of the food in this bowl to its own bowl. Hence, each round the food distribution changes.

Given the initial amount of food in each bowl and the number of rounds, return the amount of food the dragons' boss Snaug will have after these rounds.

In more detail:

The initial amount of food will be given in the following order: front, back, up, down, left, right. The dragons' boss Snaug lives on the "up" side of the cube. If the answer is an integer, return this integer. If the answer is a fraction, return the answer in the format X/Y, where X and Y are integers without common factors. Extra leading zeroes shouldn't be present in your answer.

Example.

Suppose that the initial distribution of food is the following: 0, 0, 4, 0, 0, 0. That is Snaug has 4 and everybody else has 0 amount of food in their bowls. After the first round the distribution of food will be the following: 1, 1, 0, 0, 1, 1, that is every neighbor of Snaug steals from him one quarter of his food. After the second round the distribution of food will be the following: 1/2, 1/2, 1, 1, 1/2, 1/2.


DEFINITION
Class:Dragons
Method:snaug
Parameters:vector <int>, int
Returns:string
Method signature:string snaug(vector <int> initialFood, int rounds)


CONSTRAINTS
-initialFood has exactly 6 elements
-each element of initialFood is between 0 and 1,000 inclusive
-rounds is between 0 and 45 inclusive


EXAMPLES

0)
{0, 0, 4, 0, 0, 0}
2

Returns: "1"

See the explanation above

1)
{0, 0, 4, 0, 0, 0}
3

Returns: "1/2"

2)
{1000, 1000, 1000, 1000, 1000, 1000}
45

Returns: "1000"

When everybody has the same amount of food, they continue to have the same amount of food after each round

3)
{1, 2, 3, 4, 5, 6}
45

Returns: "7/2"

*/
// END CUT HERE

 public:
  string snaug(vector <int> initialFood, int rounds) {
    string result;
    // -- main code --

    // f b u d l r
    vector<unsigned long long> prev(6, 0);
    vector<unsigned long long> next(6, 0);

    int rest = rounds;

    FORN(i, 6) prev[i] = initialFood[i];
    
    FORN(i, rounds) {
      next[0] = prev[2] + prev[3] + prev[4] + prev[5];
      next[1] = next[0];
      next[2] = prev[0] + prev[1] + prev[4] + prev[5];
      next[3] = next[2];
      next[4] = prev[0] + prev[1] + prev[2] + prev[3];
      next[5] = next[4];

      FORN(j, 6) {
        prev[j] = next[j];
      }
      
      bool devide = true;
      FORN(j, 6) {
        if(prev[j] % 4 != 0) {
          devide = false;
        }
      }

      if(!devide) {
        continue;
      }

      FORN(j, 6) {
        prev[j] = prev[j] / 4;
      }
      --rest;
    }

    if(prev[2] == 0) {
      return i2s(prev[2]);
    }

    rest *= 2;
    while((prev[2] % 2 == 0) && (rest > 0)) {
      prev[2] = prev[2] >> 1;
      --rest;
    }

    if(rest != 0) {
      return i2s(prev[2]) + "/" + i2s(1 << rest);
    }else {
      return i2s(prev[2]);
    }
  }

  unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if(a < b) {
      return gcd(b, a);
    }else if(a == b || b == 0) {
      return a;
    }else {
      return gcd(b, a % b);
    }
  }

  string i2s(unsigned long long i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 4, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "1"; verify_case(0, Arg2, snaug(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 4, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "1/2"; verify_case(1, Arg2, snaug(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45; string Arg2 = "1000"; verify_case(2, Arg2, snaug(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45; string Arg2 = "7/2"; verify_case(3, Arg2, snaug(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Dragons test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

