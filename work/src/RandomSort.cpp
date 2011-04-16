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

class RandomSort {
 public:
  double getExpected(vector <int> permutation) {
    // -- main code --
    double r = 0.0;
    
    return r;	
  }

  long long go(vector<int> permutation) {
    TIMES(i, permutation.size()-1) {
      FOR(j, i+1, permutation.size()) {
        if(permutation[i] > permutation[j]) {
          swap(permutation[i], permutation[j]);
        }
      }
    }
  }

  bool isSorted(vector<int>& permutation) {
    TIMES(i, permutation.size()) {
      if(i != permutation[i]) {
        return false;
      }
    }
    return true;
  }

  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a vector <int> permutation containing a permutation of the first n positive integers (1 through n), and you want to sort them in ascending order.  To do this, you will perform a series of swaps.  For each swap, you consider all pairs (i, j) such that i < j and permutation[i] > permutation[j].  Among all those pairs, you choose one randomly and swap permutation[i] and permutation[j].  Each pair has the same probability of being chosen.  Return the expected number of swaps needed to sort permutation in ascending order.

DEFINITION
Class:RandomSort
Method:getExpected
Parameters:vector <int>
Returns:double
Method signature:double getExpected(vector <int> permutation)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-permutation will contain between 1 and 8 elements, inclusive.
-permutation will contain each integer between 1 and n, inclusive, exactly once, where n is the number of elements in permutation.


EXAMPLES

0)
{1,3,2}

Returns: 1.0

Exactly one swap is needed.

1)
{4,3,2,1}

Returns: 4.066666666666666

In the first step, any two elements can be swapped.

2)
{1}

Returns: 0.0

This permutation is already sorted, so there's no need to perform any swaps.

3)
{2,5,1,6,3,4}

Returns: 5.666666666666666



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.066666666666666; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,1,6,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.666666666666666; verify_case(3, Arg1, getExpected(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  RandomSort test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
