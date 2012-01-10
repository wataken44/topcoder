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

class BaseMystery {
 public:
  vector <int> getBase(string equation) {
    // -- main code --

    int pp = equation.find("+");
    string left = equation.substr(0, pp);

    int ep = equation.find("=");
    string right = equation.substr(pp + 1, ep - pp - 1);
    string sum = equation.substr(ep+1, equation.size() - ep - 1);
    
    vector<int> r;
    UPTO(b, 2, 20) {
      if(validEquation(left, right, sum, b)) {
        r.push_back(b);
      }
    }
    
    return r;	
  }

  bool validEquation(string& left, string& right, string& sum, int base)
  {
    int l = to_i(left,base);
    int r = to_i(right, base);
    int s = to_i(sum, base);

    if(l < 0 or r < 0 or s < 0) return false;

    return l + r == s;
  }

  int to_i(string& str, int base)
  {
    int val = 0;
    TIMES(i, str.size()) {
      int d = ('0' <= str[i] and str[i] <= '9') ?
          (str[i] - '0') : (10 + str[i] - 'A');
      if(d >= base) return -1;
      val = val * base + d;
    }
    return val;
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The base of a number system is the number of different values each digit can represent.  For example, in base-2 (binary), there are 2 values each digit can take: 0 and 1.  In base-10, a digit can take values 0 through 9, inclusive.  Sometimes, it is difficult to determine which base a numerical expression is in.  An equation is valid for a given base if all of the digits are less than the base, and the numerical meaning of the equation is correct.  For example, "1+1=10" for base-10 satisfies the rule that the digits are all less than 10, but 1+1 = 2 in base-10, so the equation is not correct for base-10.



If we assume that the characters '0'-'9' represent the values 0 - 9, and the characters 'A'-'J' represent the values 10 - 19, then we can represent numbers with a base up to 20.  The equation will be in the following form:


<num>+<num>=<num>


Where each <num> is a string consisting of characters '0'-'9' and 'A'-'J', which does not have any extra leading zeros, and is at most 5 digits long.



Given an equation as defined above, you should return which bases in the range of 2 to 20, inclusive, are valid for the equation.  Return the bases in a vector <int> in ascending order.


DEFINITION
Class:BaseMystery
Method:getBase
Parameters:string
Returns:vector <int>
Method signature:vector <int> getBase(string equation)


CONSTRAINTS
-equation will be of the form "<num>+<num>=<num>"
-Each <num> in equation will have between 1 and 5 characters, inclusive.
-Each <num> in equation will consist only of numeric digits '0' - '9' and capital letters 'A' - 'J', and will not have extra leading zeros.


EXAMPLES

0)
"1+1=2"

Returns: { 3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }


The only base which this does not work for is base-2.  In base 2, 2 is represented by "10"


1)
"1+1=10"

Returns: { 2 }


The same equation valid for base 2.


2)
"1+1=3"

Returns: { }


1+1 is never 3, no matter what base you are in.


3)
"ABCD+211=B000"

Returns: { 14 }


In base-14, the digits are 0-9, A-D.  Adding one to the ones column yields 10 base-14, which carries over to make the 10's column a 'D'.  Adding 1 to that column yields 10 again, which carries and makes the 100's column a 'C'.  Adding 2 to C yields 10 again, which adds 1 to the 1000's column, resulting in B000.


4)
"ABCD+322=B000"

Returns: { 15 }


For base-15, we have increased the number required to wrap to 0 by 1.


5)
"1+0=1"

Returns: { 2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }


This is valid for all bases.


6)
"GHIJ+1111=HJ00"

Returns: { 20 }

7)
"1234+8765=9999"

Returns: { 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "1+1=2"; int Arr1[] = { 3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getBase(Arg0)); }
	void test_case_1() { string Arg0 = "1+1=10"; int Arr1[] = { 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getBase(Arg0)); }
	void test_case_2() { string Arg0 = "1+1=3"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getBase(Arg0)); }
	void test_case_3() { string Arg0 = "ABCD+211=B000"; int Arr1[] = { 14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getBase(Arg0)); }
	void test_case_4() { string Arg0 = "ABCD+322=B000"; int Arr1[] = { 15 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getBase(Arg0)); }
	void test_case_5() { string Arg0 = "1+0=1"; int Arr1[] = { 2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getBase(Arg0)); }
	void test_case_6() { string Arg0 = "GHIJ+1111=HJ00"; int Arr1[] = { 20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getBase(Arg0)); }
	void test_case_7() { string Arg0 = "1234+8765=9999"; int Arr1[] = { 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(7, Arg1, getBase(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  BaseMystery test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
