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

class MNS {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
9 numbers need to be arranged in a magic number square.  A magic number square is a square of numbers that is arranged such that every row and column has the same sum.  For example:


1 2 3
3 2 1
2 2 2


Create a class MNS containing a method combos which takes as an argument a vector <int> numbers and returns the number of distinct ways those numbers can be arranged in a magic number square.  Two magic number squares are distinct if they differ in value at one or more positions.  For example, there is only one magic number square that can be made of 9 instances of the same number.


DEFINITION
Class:MNS
Method:combos
Parameters:vector <int>
Returns:int
Method signature:int combos(vector <int> numbers)


NOTES
-Unlike some versions of the magic number square, the numbers do not have to be unique.


CONSTRAINTS
-numbers will contain exactly 9 elements.
-each element of numbers will be between 0 and 9, inclusive.


EXAMPLES

0)
{1,2,3,3,2,1,2,2,2}

Returns: 18

1)
{4,4,4,4,4,4,4,4,4}

Returns: 1

2)
{1,5,1,2,5,6,2,3,2}

Returns: 36

3)
{1,2,6,6,6,4,2,6,4}

Returns: 0

*/
// END CUT HERE

 public:
  int combos(vector <int> numbers) {
    int result = 0;
    // -- main code --

    sort(numbers.begin(), numbers.end());
    int sum = 0;
    TIMES(i, numbers.size()) sum += numbers[i];

    if(sum % 3 != 0) return 0;

    int edge_sum = sum / 3;

    do {
      if(numbers[0] + numbers[1] + numbers[2] != edge_sum) continue;
      if(numbers[3] + numbers[4] + numbers[5] != edge_sum) continue;
      if(numbers[6] + numbers[7] + numbers[8] != edge_sum) continue;

      if(numbers[0] + numbers[3] + numbers[6] != edge_sum) continue;
      if(numbers[1] + numbers[4] + numbers[7] != edge_sum) continue;
      if(numbers[2] + numbers[5] + numbers[8] != edge_sum) continue;
      
      ++result;
      
    }while(next_permutation(numbers.begin(), numbers.end()));

    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,3,2,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, combos(Arg0)); }
	void test_case_1() { int Arr0[] = {4,4,4,4,4,4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, combos(Arg0)); }
	void test_case_2() { int Arr0[] = {1,5,1,2,5,6,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(2, Arg1, combos(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,6,6,6,4,2,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, combos(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  MNS test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
