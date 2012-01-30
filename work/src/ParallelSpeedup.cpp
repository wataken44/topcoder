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

class ParallelSpeedup {
 public:
  int numProcessors(int k, int overhead) {
    // -- main code --

    long long m = k; // single processor;
    int mi = 1;
    UPTO(i, 2, k) {
      long long t = ceil((double)k / (double)i) + (long long)overhead * i * (i - 1) / 2;
      
      if(m > t) {
        m = t;
        mi = i;
      }
    }
    
    return mi;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Your boss thinks you can speed up an application you are writing by running it on multiple processors in parallel.
Your application performs k independent tasks that each take 1 millisecond to run on a single processor.  
Distributing a task across several processors does not make it run faster, but running different tasks on 
different processors may indeed make your application faster.



Unfortunately, when your application runs on more than one processor, communication overheads between processors become a significant
factor.  In particular, every pair of processors spends overhead milliseconds communicating with each other before work on the tasks can begin.  Worse, because the processors share a single bus for communications, different pairs of processors cannot communicate in parallel.  For example, if overhead is 2 milliseconds and you run your application on 3 processors, there will 
be a 6 millisecond delay before the actual computations begin: 2 milliseconds for processors 1 and 2 to communicate, 2 milliseconds for processors 1 and 3 to communicate, and 2 milliseconds for processors 2 and 3 to communicate.  Note that, once the initial communications
phase has completed, no further communications are required, even if each processor is executing multiple tasks.



Your task is to determine the number of processors that will run the k tasks in the minimum amount of time, assuming overhead
milliseconds of communication overhead per pair of processors.
If several configurations of processors will achieve the minimum amount of time, prefer the configuration with the smallest number of
processors.




DEFINITION
Class:ParallelSpeedup
Method:numProcessors
Parameters:int, int
Returns:int
Method signature:int numProcessors(int k, int overhead)


CONSTRAINTS
-k is between 1 and 1000000, inclusive.
-overhead is between 1 and 10, inclusive.


EXAMPLES

0)
12
1

Returns: 2

The application runs in 7 milliseconds on 2 processors (1 millisecond of communication and
6 milliseconds for the actual tasks).  It also runs in 7 milliseconds on 3 processors (3 milliseconds of communication and 4 milliseconds for the actual tasks).  However, we prefer
the smaller number of processors.

1)
50
3

Returns: 3

The application runs in 26 milliseconds on 3 processors (9 milliseconds of communication
and 17 milliseconds for the tasks).  One of the processors actually finishes one millisecond early, after a total of
25 milliseconds, but the application is not considered complete until the last task is finished.

2)
9
10

Returns: 1

3)
3333
2

Returns: 12

4)
1000000
4

Returns: 63

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 50; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 10; int Arg2 = 1; verify_case(2, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3333; int Arg1 = 2; int Arg2 = 12; verify_case(3, Arg2, numProcessors(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 4; int Arg2 = 63; verify_case(4, Arg2, numProcessors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ParallelSpeedup test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
