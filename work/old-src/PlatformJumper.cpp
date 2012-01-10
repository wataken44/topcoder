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

class PlatformJumper {
 public:
  int maxCoins(vector <string> platforms, int v, int g) {
    // -- main code --

    int sz = platforms.size();
    vector< int > x(sz, 0);
    vector< int > y(sz, 0);
    vector< int > c(sz, 0);

    TIMES(i, sz) {
      istringstream iss(platforms[i]);
      int xx = 0;
      int yy = 0;
      int cc = 0;

      iss >> xx;
      iss >> yy;
      iss >> cc;

      x[i] = xx;
      y[i] = yy;
      c[i] = cc;
    }

    TIMES(i, sz) {
      FOR(j, i+1, sz) {
        if(y[j] < y[i]) {
          swap(x[i], x[j]);
          swap(y[i], y[j]);
          swap(c[i], c[j]);
        }
      }
    }

    vector<int> result(sz, 0);

    TIMES(i, sz) {
      result[i] = c[i];
    }
    
    DOWNTO(i, sz-1, 0) {
      FOR(j, i + 1, sz) {
        int rr = 0;
        if(canMove(abs(x[i] - x[j]), abs(y[i] - y[j]), v, g)) {
          rr = max(rr, result[j] + c[i]);
        }
        result[i] = rr;
      }
    }

    int r = -1;
    TIMES(i, sz) {
      r = max(r, result[i]);
    }
    
    // x = vt; y = 0.5 * g * t ^ 2 = 0.5 * g * x ^ 2 / v ^ 2
    
    return r;
  }

  bool canMove(int dx, int dy, int v, int g) {
    return (double)dy >= 0.5 * g * (dx * dx) / (double)(v * v); 
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In an old school arcade video game, you have reached the following bonus level. There are a number of platforms containing coins, and you must jump from platform to platform collecting the coins. You may only jump to lower platforms, so your entire journey will be downward. You can select any platform as your starting platform.

Your jumping behavior is defined as follows. On each jump, your horizontal speed is constant and does not exceed v. Your fall down follows the standard laws of physics: your free fall acceleration is g and initially your speed is 0.

For simplicity, we will represent each platform as a single point. Each element of platforms represents a single platform and is formatted "X Y C" (quotes for clarity), where X and Y are the x and y coordinates of the platform and C is the number of coins on the platform. Greater values of y represent higher locations. Return the greatest number of coins you can collect.



DEFINITION
Class:PlatformJumper
Method:maxCoins
Parameters:vector <string>, int, int
Returns:int
Method signature:int maxCoins(vector <string> platforms, int v, int g)


NOTES
-A dropped object without starting velocity will fall down g*t2/2 units in time t.
-Note, that you always can drop to the platform right below you.


CONSTRAINTS
-platforms will contain between 1 and 50 elements, inclusive.
-Each element of platforms will be formatted as "X Y C", where X, Y and C are integers with no extra leading zeroes.
-In each element of platforms, X and Y will be between 0 and 5000, inclusive.
-In each element of platforms, C will be between 0 and 10000, inclusive.
-All platforms will have distinct locations.
-v and g will each be between 1 and 100, inclusive.


EXAMPLES

0)
{"3 10 7", "5 15 7", "8 9 12" }
2
10

Returns: 14

It is possible to jump from platform 1 to platform 0, thus we can earn 7+7=14 coins. It is impossible to jump from platform 1 to platform 2.

1)
{"0 0 1", "2 4 1", "4 0 1"}
1
2

Returns: 2



2)
{"0 0 1", "5000 5000 10"}
100
87

Returns: 10



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 10 7", "5 15 7", "8 9 12" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 10; int Arg3 = 14; verify_case(0, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 0 1", "2 4 1", "4 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 0 1", "5000 5000 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 87; int Arg3 = 10; verify_case(2, Arg3, maxCoins(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PlatformJumper test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
