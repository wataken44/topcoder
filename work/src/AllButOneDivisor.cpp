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
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class AllButOneDivisor {
 public:
  int getMinimum(vector <int> divisors) {
    // -- main code --

    sort(divisors.begin(), divisors.end());

    vector<int> cand;
    
    TIMES(m, divisors.size()) {
      int lcm = 1;

      TIMES(n, divisors.size()) {
        if(m != n) {
          lcm = lcm * divisors[n] / gcd(lcm, divisors[n]); 
        }
      }
      //DUMP(lcm);
      //DUMP(divisors[m]);
      if(lcm % divisors[m] != 0) {
        cand.push_back(lcm);
      }
    }

    sort(cand.begin(), cand.end());
    
    return cand.size() == 0 ? -1 : cand[0];
  }

  int gcd(int a, int b) {
    if(a > b) swap(a, b);
    return a == 0 ? b : gcd(b % a, a);
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a vector <int> divisors containing K elements. Find a positive integer n such that exactly K-1 elements of divisors are exact divisors of n. If there are several such numbers n, return the smallest possible one. If no such number n exists, return -1 instead.

DEFINITION
Class:AllButOneDivisor
Method:getMinimum
Parameters:vector <int>
Returns:int
Method signature:int getMinimum(vector <int> divisors)


NOTES
-A number x is an exact divisor of y if y divided by x yields an integer result.
-If x is an exact divisor of y then we call y a multiple of x.


CONSTRAINTS
-divisors will contain between 2 and 6 elements, inclusive.
-Each element of divisors will be distinct.
-Each element of divisors will be between 1 and 15, inclusive.


EXAMPLES

0)
{2,3,5}

Returns: 6

There are many possible values for n in this case. For example: 6, 15, 75 and 12. 6 is the smallest of them.


1)
{2,4,3,9}

Returns: 12



2)
{3,2,6}

Returns: -1

Every multiple of 3 and 2 is also a multiple of 6.
Every multiple of 6 is also a multiple of 2 and 3.

Therefore, a number that is a multiple of exactly 2 out of the three elements in this array cannot exist.

3)
{6,7,8,9,10}

Returns: 360



4)
{10,6,15}

Returns: -1



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = {2,4,3,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = {6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 360; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { int Arr0[] = {10,6,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  AllButOneDivisor test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
