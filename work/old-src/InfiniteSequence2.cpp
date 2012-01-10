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

class InfiniteSequence2 {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
NOTE: This problem statement contains subscripts that may not display properly if viewed outside of the applet.


Let's consider an infinite sequence A defined as follows:

Ai = 1 for all i <= 0;
Ai = A[i/p]-x + A[i/q]-y for all i >= 1, where [x] denotes the floor function of x. (see Notes)


You will be given n, p, q, x and y. Return the n-th element of A (index is 0-based).

DEFINITION
Class:InfiniteSequence2
Method:calc
Parameters:long long, int, int, int, int
Returns:long long
Method signature:long long calc(long long n, int p, int q, int x, int y)


NOTES
-[x] denotes the floor function of x which returns the highest integer less than or equal to x. For example, [3.4] = 3, [0.6] = 0.


CONSTRAINTS
-n will be between 0 and 10^13, inclusive.
-p and q will both be between 2 and 10^9, inclusive.
-x and y will both be between 0 and 10^9, inclusive.


EXAMPLES

0)
10000000
2
3
10000000
10000000

Returns: 2

A[10000000] = A[-5000000] + A[-6666667] = 2.

1)
12
2
3
1
0

Returns: 8



2)
0
2
2
0
0

Returns: 1

A[0] = 1.

3)
123
45
67
8
9

Returns: 2



*/
// END CUT HERE

 public:
  long long calc(long long n, int p, int q, int x, int y) {
    long long result;
    // -- main code --

    if( n <= 0 ) {
      return 1;
    }else {

      if(memo.find(n) != memo.end()) {
        result = memo[n];
      }else {
        result = calc(n / p - x, p, q, x, y) + calc(n / q - y, p, q, x, y);
        if(n < 100000) {
          memo[n] = result;
        }
      }
    }
    
    return result;
  }

  map<long long, long long> memo;

  // BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10000000LL; int Arg1 = 2; int Arg2 = 3; int Arg3 = 10000000; int Arg4 = 10000000; long long Arg5 = 2LL; verify_case(0, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 12LL; int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; int Arg4 = 0; long long Arg5 = 8LL; verify_case(1, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 0LL; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 1LL; verify_case(2, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 123LL; int Arg1 = 45; int Arg2 = 67; int Arg3 = 8; int Arg4 = 9; long long Arg5 = 2LL; verify_case(3, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  InfiniteSequence2 test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

