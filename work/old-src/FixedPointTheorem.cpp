#line 2 "FixedPointTheorem.cpp"

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

using namespace std;

class FixedPointTheorem {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The fixed-point theorem is one of those cornerstones of mathematics that reaches towards all disciplines, and oddly enough it is also closely related to the ability of any program to Quine itself (or to print out its own source code). Put simply, the fixed-point theorem states that with certain restrictions on a real-valued function F, there is always a point such that X=F(X). Taking the fixed-point theorem further, you can show that any function that meets certain restrictions will start to cycle through values if you keep on feeding it its own output (doing this with programs and their output is one way of producing programs that Quine themselves).
 One simple function that does this is the logistic function F(X)=R*X*(1-X) in the interval [0,1] for certain values of R. For example, if you start with the value X=.25 and feed it into F to get a new X, then feed that value into F to get yet another X, and so on, the values of X that are produced will converge to a small set of values that will eventually repeat forever, called a cycle. 

Your program will be given a double R between 0.1 and 3.569 inclusive. Starting with X=.25, generate the first 200,000 iterations of F using the given value of R, which will stabilize values of X. Then generate 1000 more values, and return the range of these values (highest value - lowest value).  In other words, you will be finding the range of the values produced between iterations 200,001 and 201,000 inclusive.

DEFINITION
Class:FixedPointTheorem
Method:cycleRange
Parameters:double
Returns:double
Method signature:double cycleRange(double R)


NOTES
-Don't worry about overflow. With the given values it'll never happen.


CONSTRAINTS
-R will be a value between 0.1 and 3.569 inclusive.
-R will always be a value such that the process stated above will produce a result accurate to 1e-9 (absolute or relative).


EXAMPLES

0)
0.1

Returns: 0.0

At low numbers, there exists only one point in the cycle, so the answer is 0.0.

1)
3.05

Returns: 0.14754098360655865

2)
3.4499

Returns: 0.4175631735867292

3)
3.55

Returns: 0.5325704489850351

4)
3.565

Returns: 0.5454276003030636

5)
3.5689

Returns: 0.5489996297493569

6)
3.00005

Returns: 0.004713996108955176

Make sure you're iterating 200,000 times.

*/
// END CUT HERE

 public:
  double cycleRange(double R) {
    double x = 0.25;
    // -- 

    double high = -1.0;
    double low = R * 2;
    
    for (int i = 0; i < 200000; ++i)
    {
      x = f(x, R);
    }

    for (int i = 0; i < 1000; ++i)
    {
      x = f(x, R);
      high = max(high, x);
      low = min(low, x);
    }
    
    return high - low;	
  }

  double f(double x, double R)
  {
    return R * x * (1-x); 
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arg0 = 0.1; double Arg1 = 0.0; verify_case(0, Arg1, cycleRange(Arg0)); }
	void test_case_1() { double Arg0 = 3.05; double Arg1 = 0.14754098360655865; verify_case(1, Arg1, cycleRange(Arg0)); }
	void test_case_2() { double Arg0 = 3.4499; double Arg1 = 0.4175631735867292; verify_case(2, Arg1, cycleRange(Arg0)); }
	void test_case_3() { double Arg0 = 3.55; double Arg1 = 0.5325704489850351; verify_case(3, Arg1, cycleRange(Arg0)); }
	void test_case_4() { double Arg0 = 3.565; double Arg1 = 0.5454276003030636; verify_case(4, Arg1, cycleRange(Arg0)); }
	void test_case_5() { double Arg0 = 3.5689; double Arg1 = 0.5489996297493569; verify_case(5, Arg1, cycleRange(Arg0)); }
	void test_case_6() { double Arg0 = 3.00005; double Arg1 = 0.004713996108955176; verify_case(6, Arg1, cycleRange(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
  FixedPointTheorem test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
