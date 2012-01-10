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

class QuipuReader {
 public:
  vector <int> readKnots(vector <string> knots) {
    // -- main code --
    bool digits = false;
    vector< pair<int, int> > ranges;

    TIMES(k, knots.size()) {
      knots[k] += '-';
    }

    
    int length = knots[0].size();

    pair<int, int> range;
    TIMES(i, length) {
      if(!digits) {
        TIMES(k, knots.size()) {
          if(knots[k][i] == 'X') {
            digits = true;
            range.first = i;
          }
        }
      }else {
        // all '-'
        bool allm = true;
        TIMES(k, knots.size()) {
          if(knots[k][i] == 'X') {
            allm = false;
          }
        }
        if(allm) {
          range.second = i;
          ranges.push_back(range);
          digits = false;
        }else {
          if(i <= length - 2) {
            // all '-' -> 'X' or 'X' -> '-'
            bool allt = true;
            TIMES(k, knots.size()) {
              if(knots[k][i] == knots[k][i+1]) {
                allt = false;
              }
            }
            if(allt) {
              range.second = i;
              ranges.push_back(range);
              digits = false;
            }
          }
        }
      }
    }

    vector<int> result;
    TIMES(k, knots.size()) {
      int r = 0;
      TIMES(p, ranges.size()) {
        int c = 0;
        UPTO(x, ranges[p].first, ranges[p].second) {
          if(knots[k][x] == 'X') {
            ++c;
          }
        }
        r *= 10;
        r += c;
      }
      result.push_back(r);
    }
    
    return result;	
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
For example, the number 243 could be represented by a cord with knots tied in the following pattern


     -XX-XXXX-XXX-

where each uppercase 'X' represents a knot and each '-' represents an unknotted segment of cord (all quotes for clarity only).



A sequence of numbers is represented by a sequence of cords.  For example, the numbers 725, 234, and 558 
could be represented by the cords


     -XXXXXXX--XX-----XXXXX---
     ---XX----XXX-----XXXX----
     -XXXXX---XXXXX--XXXXXXXX-

Notice how consecutive dashes are used to align clusters of knots on different cords.  
Clusters representing digits in the same position
are required to overlap completely.  Clusters representing digits in 
different positions never overlap.  All quipus obey these rules.  For example, the following configurations would all be illegal:

     -XXXXX---
     ----XXX--    [The 3 and 5 must overlap completely or not at all.]

     -XXXXXXXXX-
     --XX------- 
     -------XX--  [Both 2s overlap with the 9, but not each other.]

     -XXXXXXXX-
     --XX----X-   [The 2 and 1 cannot both overlap with the 8.]



Unlike many ancient civilizations, the Incas were aware of the concept of zero, and used it in their quipus.
A zero is represented by a cluster containing no knots.  For example, the numbers 105 and 340 could be 
represented by the cords


     --X--------XXXXX-
     -XXX--XXXX-------

Assume that the numbers being represented do not all contain zeros in the same position.  For example, any input that you could
conceivably interpret as representing the numbers 105 and 802, you should interpret as 15 and 82 instead.


Write a method to translate a sequence of quipu cords (of type vector <string>) into a sequence of integers (of type vector <int>), where the integer in position i
corresponds to the cord in position i.  


DEFINITION
Class:QuipuReader
Method:readKnots
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> readKnots(vector <string> knots)


CONSTRAINTS
-knots contains between 1 and 10 elements, inclusive.
-Each element of knots contains the same number of characters, between 1 and 50, inclusive.  
-Each element of knots contains only the characters 'X' and '-'.  Note that 'X' is uppercase.
-At least one element of knots contains at least one 'X'.
-No element of knots contains 10 consecutive 'X's.
-If two (non-empty) clusters of knots A and B overlap at all, then they must overlap completely.  More formally, let A0 be the position of the first 'X' in cluster A, and let A1 be the position of the last 'X' in cluster A.  Let B0 and B1 be defined similarly for cluster B.  Assume, without loss of generality, that A0 <= B0.  Then either B1 <= A1 (they overlap completely) or A1 < B0 (they do not overlap at all).
-All clusters of knots that overlap with some particular cluster also overlap with each other.  More formally, if two (non-empty) clusters of knots A and B both overlap with a third (non-empty) cluster C, then A and B also overlap with other.
-Each element of knots will represent a number between 0 and 1000000, inclusive.


EXAMPLES

0)
{ "-XXXXXXX--XX-----XXXXX---",
  "---XX----XXX-----XXXX----",
  "-XXXXX---XXXXX--XXXXXXXX-" }

Returns: { 725,  234,  558 }

One of the examples above.  Notice that adjacent digit positions are usually separated by
one or more columns of dashes.  In this example, the first and second positions are separated 
by one column of dashes, and the second and third positions are separated by two columns
of dashes.

1)
{ "XX---XXXX",
  "XXX-----X" }

Returns: { 24,  31 }

Notice that leading and trailing dashes are not required.

2)
{ "-XXX---XX----X",
  "--X----X-XXXXX",
  "-XX--XXXX---XX" }

Returns: { 321,  115,  242 }

Notice that adjacent digit positions are not always separated by columns of dashes.
In this example, the first and second positions are separated by a column of dashes,
but the second and third positions are not.

3)
{ "-------X--------",
  "--XXX----XXXX---",
  "--------------XX" }

Returns: { 100,  3040,  2 }

Notice that leading zeros are permitted.  For example, 100 is really 0100 and 2 is really 0002.

4)
{ "--XXX-XXXXXXXX----------XXXXXXXXX--XXXXXXXX-",
  "--XX----XXXX-----XXXXXX---XXX------XXXXXXXX-",
  "--------------------X----XXXXXXXX--XXXXXXXX-",
  "--XX-------X------XXXX----XXX-------XXXXXX--",
  "--XXX---XXXXX-------X------XX--------X------",
  "-XXXX--XXXXXXX-----------XXXXXXX----XXXXX---",
  "-----------X---XXXXXXXX----XX--------XXX----",
  "-----------X---XXXXXXXX----X----------------",
  "---X--XXXXXXXX--XXXXXXX---XXX---------------",
  "--XX---XXXXXXX--XXXXXXX----XX-------XXXXX---" }

Returns: { 38098,  24638,  188,  21436,  35121,  47075,  1823,  1810,  18730,  27725 }

5)
{"X","-"}

Returns: { 1,  0 }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "-XXXXXXX--XX-----XXXXX---",
  "---XX----XXX-----XXXX----",
  "-XXXXX---XXXXX--XXXXXXXX-" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 725,  234,  558 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, readKnots(Arg0)); }
	void test_case_1() { string Arr0[] = { "XX---XXXX",
  "XXX-----X" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 24,  31 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, readKnots(Arg0)); }
	void test_case_2() { string Arr0[] = { "-XXX---XX----X",
  "--X----X-XXXXX",
  "-XX--XXXX---XX" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 321,  115,  242 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, readKnots(Arg0)); }
	void test_case_3() { string Arr0[] = { "-------X--------",
  "--XXX----XXXX---",
  "--------------XX" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 100,  3040,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, readKnots(Arg0)); }
	void test_case_4() { string Arr0[] = { "--XXX-XXXXXXXX----------XXXXXXXXX--XXXXXXXX-",
  "--XX----XXXX-----XXXXXX---XXX------XXXXXXXX-",
  "--------------------X----XXXXXXXX--XXXXXXXX-",
  "--XX-------X------XXXX----XXX-------XXXXXX--",
  "--XXX---XXXXX-------X------XX--------X------",
  "-XXXX--XXXXXXX-----------XXXXXXX----XXXXX---",
  "-----------X---XXXXXXXX----XX--------XXX----",
  "-----------X---XXXXXXXX----X----------------",
  "---X--XXXXXXXX--XXXXXXX---XXX---------------",
  "--XX---XXXXXXX--XXXXXXX----XX-------XXXXX---" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 38098,  24638,  188,  21436,  35121,  47075,  1823,  1810,  18730,  27725 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, readKnots(Arg0)); }
	void test_case_5() { string Arr0[] = {"X","-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, readKnots(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  QuipuReader test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
