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

class SimpleGuess {
 public:
  int getMaximum(vector <int> hints) {
    // -- main code --

    int m = 0;

    TIMES(si, hints.size()) {
      TIMES(di, hints.size()) {
        if(si == di) continue;

        int s = hints[si];
        int d = hints[di];

        //DUMP(s);DUMP(d);
        
        if((s + d) % 2 != 0) continue;

        int x = (s + d) / 2;
        int y = (s - d) / 2;

        //DUMP(x);DUMP(y);
        
        m = max(m, x * y);
      }
    }
    
    return m;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A cat and a rabbit are playing a simple number guessing game. 
The cat chose two different positive integers X and Y. 
He then told the rabbit several numbers. 
One of those numbers was X + Y and another was X - Y. 
The others were simply made up.


The rabbit thinks the cat prefers large numbers. 
Given a vector <int> hints containing the numbers the cat told the rabbit, 
return the largest possible value of X * Y. 


DEFINITION
Class:SimpleGuess
Method:getMaximum
Parameters:vector <int>
Returns:int
Method signature:int getMaximum(vector <int> hints)


CONSTRAINTS
-hints will contain between 2 and 50 elements, inclusive.  
-Each element of hints will be between 1 and 100, inclusive. 
-All elements of hints will be distinct. 
-There will exist at least one pair of positive integers (X, Y) such that both X + Y and X - Y are elements of hints.


EXAMPLES

0)
{ 1, 4, 5 }

Returns: 6

The?rabbit?can?determine?that?(X,?Y)?=?(3,?2).

1)
{ 1, 4, 5, 8 }

Returns: 12

Possible pairs (X, Y) are (3, 2) and (6, 2). 
The values of X * Y are 6 and 12, respectively, and the largest is 12. 


2)
{ 9, 8, 7, 6, 5, 4, 3, 2, 1 }

Returns: 20

3)
{ 2, 100 }

Returns: 2499

4)
{ 50, 58, 47, 57, 40 }

Returns: 441

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getMaximum(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 4, 5, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, getMaximum(Arg0)); }
	void test_case_2() { int Arr0[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, getMaximum(Arg0)); }
	void test_case_3() { int Arr0[] = { 2, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2499; verify_case(3, Arg1, getMaximum(Arg0)); }
	void test_case_4() { int Arr0[] = { 50, 58, 47, 57, 40 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 441; verify_case(4, Arg1, getMaximum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  SimpleGuess test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
