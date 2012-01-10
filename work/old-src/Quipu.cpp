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

class Quipu {
 public:
  int readKnots(string knots) {
    // -- main code --

    int r = 0;
    
    FOR(k, 1, knots.size() - 1) {
      if(knots[k] == 'X') {
        r += 1;
      }else {
        r *= 10;
      }
    }
    
    return r;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The Incas used a sophisticated system of record keeping consisting of bundles of knotted cords.
Such a bundle of cords is called a quipu.  Each individual cord represents a single number.
Surprisingly, the Incas used a base-10 positional system, just like we do today.  Each digit of a number 
is represented by a cluster of adjacent knots, with spaces between neighboring clusters.  The digit is 
determined by the number of knots in the cluster.
For example, the number 243 would be represented by a cord with knots tied in the following pattern


     -XX-XXXX-XXX-

where each uppercase 'X' represents a knot and each '-' represents an unknotted segment of cord (all quotes for clarity only).


Unlike many ancient civilizations, the Incas were aware of the concept of zero, and used it in their quipus.
A zero is represented by a cluster containing no knots.
For example, the number 204003 would be represented by a cord with knots tied in the following pattern


     -XX--XXXX---XXX-
        ^^    ^^^
        ^^    ^^^
        ^^    two zeros between these three segments
        ^^
        one zero between these two segments

Notice how adjacent dashes signal the presence of a zero.


Your task is to translate a single quipu cord into an integer.  The cord will be given as a string knots
containing only the characters 'X' and '-'.  There will be a single '-' between each cluster 
of 'X's, as well as a leading '-' and a trailing '-'.  The first cluster will not be empty.


DEFINITION
Class:Quipu
Method:readKnots
Parameters:string
Returns:int
Method signature:int readKnots(string knots)


CONSTRAINTS
-knots contains between 3 and 50 characters, inclusive.
-knots contains only the characters 'X' and '-'.  Note that 'X' is uppercase.
-The first and last characters of knots are '-'s.  The second character is 'X'.
-knots does not contain 10 consecutive 'X's.
-knots will represent a number between 1 and 1000000, inclusive.


EXAMPLES

0)
"-XX-XXXX-XXX-"

Returns: 243

The first example above.

1)
"-XX--XXXX---XXX-"

Returns: 204003

The second example above.

2)
"-X-"

Returns: 1

3)
"-X-------"

Returns: 1000000

4)
"-XXXXXXXXX--XXXXXXXXX-XXXXXXXXX-XXXXXXX-XXXXXXXXX-"

Returns: 909979

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-XX-XXXX-XXX-"; int Arg1 = 243; verify_case(0, Arg1, readKnots(Arg0)); }
	void test_case_1() { string Arg0 = "-XX--XXXX---XXX-"; int Arg1 = 204003; verify_case(1, Arg1, readKnots(Arg0)); }
	void test_case_2() { string Arg0 = "-X-"; int Arg1 = 1; verify_case(2, Arg1, readKnots(Arg0)); }
	void test_case_3() { string Arg0 = "-X-------"; int Arg1 = 1000000; verify_case(3, Arg1, readKnots(Arg0)); }
	void test_case_4() { string Arg0 = "-XXXXXXXXX--XXXXXXXXX-XXXXXXXXX-XXXXXXX-XXXXXXXXX-"; int Arg1 = 909979; verify_case(4, Arg1, readKnots(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Quipu test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
