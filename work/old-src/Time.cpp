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

class Time {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Computers tend to store dates and times as single numbers which represent the number of seconds or milliseconds since a particular date.  Your task in this problem is to write a method whatTime, which takes an int, seconds, representing the number of seconds since midnight on some day, and returns a string formatted as "<H>:<M>:<S>".  Here, <H> represents the number of complete hours since midnight, <M> represents the number of complete minutes since the last complete hour ended, and <S> represents the number of seconds since the last complete minute ended.  Each of <H>, <M>, and <S> should be an integer, with no extra leading 0's.  Thus, if seconds is 0, you should return "0:0:0", while if seconds is 3661, you should return "1:1:1".

DEFINITION
Class:Time
Method:whatTime
Parameters:int
Returns:string
Method signature:string whatTime(int seconds)


CONSTRAINTS
-seconds will be between 0 and 24*60*60 - 1 = 86399, inclusive.


EXAMPLES

0)
0

Returns: "0:0:0"

1)
3661

Returns: "1:1:1"

2)
5436

Returns: "1:30:36"

3)
86399

Returns: "23:59:59"

*/
// END CUT HERE

 public:
  string whatTime(int seconds) {
    // -- main code --
    ostringstream oss;

    int hour = seconds / 3600;
    seconds -= hour * 3600;

    int minutes = seconds / 60;
    seconds -= minutes * 60;

    oss << hour << ":" << minutes << ":" << seconds;
    
    return oss.str();	
  }

  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; string Arg1 = "0:0:0"; verify_case(0, Arg1, whatTime(Arg0)); }
	void test_case_1() { int Arg0 = 3661; string Arg1 = "1:1:1"; verify_case(1, Arg1, whatTime(Arg0)); }
	void test_case_2() { int Arg0 = 5436; string Arg1 = "1:30:36"; verify_case(2, Arg1, whatTime(Arg0)); }
	void test_case_3() { int Arg0 = 86399; string Arg1 = "23:59:59"; verify_case(3, Arg1, whatTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Time test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

