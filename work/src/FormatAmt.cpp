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

class FormatAmt {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In documents, it is frequently necessary to write monetary amounts in a 
standard format.  We have decided to format amounts as follows:
    the amount must start with '$'
    the amount should have a leading '0' if and only if it is less then 1 dollar.
    the amount must end with a decimal point and exactly 2 following digits.
    the digits to the left of the decimal point must be separated into groups of three by commas (a group of one or two digits may appear on the left).


Create a class FormatAmt that contains a method amount that takes two int's, dollars and cents, as inputs and returns the properly formatted string.



DEFINITION
Class:FormatAmt
Method:amount
Parameters:int, int
Returns:string
Method signature:string amount(int dollars, int cents)


NOTES
-One dollar is equal to 100 cents.


CONSTRAINTS
-dollars will be between 0 and 2,000,000,000 inclusive
-cents will be between 0 and 99 inclusive


EXAMPLES

0)
123456
0

Returns: "$123,456.00"

Note that there is no space between the $ and the first digit.

1)
49734321
9

Returns: "$49,734,321.09"

2)
0
99

Returns: "$0.99"

Note the leading 0.

3)
249
30

Returns: "$249.30"

4)
1000
1

Returns: "$1,000.01"

*/
// END CUT HERE

 public:
  string amount(int dollars, int cents) {
    string result;
    // -- main code --

    vector<int> parts;
    while(dollars > 0) {
      parts.push_back(dollars % 1000);
      dollars = dollars / 1000;
    }

    DOWNTO(i, parts.size() - 1, 0) {
      ostringstream oss;
      if(i != parts.size() - 1) {
        oss.width(3);
        oss.fill('0');
      }
      oss << parts[i];
      result += oss.str();
      if(i > 0) {
        result += ",";
      }
    }

    if(result == "") {
      result = "0";
    }
    
    ostringstream oss2;
    oss2 << (cents < 10 ? "0" : "") << cents;
    
    result = "$" + result + "." + oss2.str();
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 123456; int Arg1 = 0; string Arg2 = "$123,456.00"; verify_case(0, Arg2, amount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 49734321; int Arg1 = 9; string Arg2 = "$49,734,321.09"; verify_case(1, Arg2, amount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 99; string Arg2 = "$0.99"; verify_case(2, Arg2, amount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 249; int Arg1 = 30; string Arg2 = "$249.30"; verify_case(3, Arg2, amount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 1; string Arg2 = "$1,000.01"; verify_case(4, Arg2, amount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  FormatAmt test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
