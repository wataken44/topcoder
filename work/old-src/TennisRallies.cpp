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

class TennisRallies {
 public:
  int howMany(int numLength, vector <string> forbidden, int allowed) {
    // -- main code --

    int c = 0;

    TIMES(i, 1 << numLength) {
      string sequence = "";
      TIMES(j, numLength) {
        if(((i >> j) & 1) == 1) {
          sequence += 'c';
        }else {
          sequence += 'd';
        }
      }

      //DUMP(sequence);

      int a = 0;
      TIMES(k, forbidden.size()) {
        int pos = 0;
        while(true) {
          int fpos = sequence.find(forbidden[k], pos);
          if(fpos != (int)string::npos) {
            ++a;
            if(a == allowed) {
              break;
            }
            pos = fpos + 1;
          }else {
            break;
          }
        }
      }
      if(a < allowed) {
        //DUMP(sequence);
        ++c;
      }
    }
    return c;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are practicing your tennis game with a hitting partner.  Each time the ball comes over the net a player can either hit it 
cross-court, or down-the-line.  In this problem, a sequence of shots will be denoted by a string 
composed of (quotes for clarity) the letters 'c' and 'd', representing cross-court and down-the-line shots respectively.  For 
example, "cccddc" would be such a sequence consisting of 3 cross-courts, 2 down-the-lines, and a final cross-court.

Since you are going to practice a particular play strategy there are certain shot sequences you will avoid.  You are given a 
vector <string> forbidden containing precisely which sequences must be avoided.  For example, if (quotes for 
clarity) "ccd" is an element of forbidden then you should never allow 2 cross-court shots followed by a down-the-line 
shot to occur consecutively at any point in the rally.  If you were a professional, a single forbidden sequence might cause you 
to stop hitting.  Since you are an amateur, you are willing to let allowed distinct forbidden sequences to occur 
before you stop.  For example, if allowed was 2, the second forbidden sequence would terminate the hitting sequence.

You will return the number of distinct hitting sequences of length numLength which contain fewer than 
allowed forbidden sequences.  Two hitting sequences are distinct if they differ at some stroke in the sequence.  Two 
forbidden sequences are distinct if they differ in length, or position in the hitting sequence they begin at.  For 
example, if forbidden = {"cc","cd","ccd"} then the sequence "ccccdd" has 5 distinct forbidden sequences (3 distinct 
"cc" sequences, a "cd" sequence, and a "ccd" sequence).

DEFINITION
Class:TennisRallies
Method:howMany
Parameters:int, vector <string>, int
Returns:int
Method signature:int howMany(int numLength, vector <string> forbidden, int allowed)


CONSTRAINTS
-numLength will be between 1 and 18 inclusive
-forbidden will contain between 0 and 10 elements inclusive
-allowed will be between 1 and 100 inclusive
-forbidden will contain no repeated elements
-Each element of forbidden will contain between 1 and 18 'c's and 'd's inclusive (quotes for clarity; both are lowercase)


EXAMPLES

0)
3
{"cc","dd"}
1

Returns: 2

Since allowed is 1, neither "cc" nor "dd" can occur anywhere in a valid sequence.  The only possible sequences are thus "cdc" and "dcd".

1)
10
{"c"}
1

Returns: 1

There is exactly 1 sequence with 10 shots that contains no cross-court shots.

2)
10
{"c"}
2

Returns: 11

There are 11 sequences that contain at most 1 cross-court shot.

3)
18
{"c","d"}
1

Returns: 0

4)
18
{}
1

Returns: 262144

5)
18
{"c","cc","ccc","cccc","ccccc","cccccc","ccccccc",
 "cccccccc","ccccccccc","cccccccccc"}
100

Returns: 262122

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"cc","dd"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; string Arr1[] = {"c"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"c"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 11; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 18; string Arr1[] = {"c","d"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 18; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 262144; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 18; string Arr1[] = {"c","cc","ccc","cccc","ccccc","cccccc","ccccccc",
 "cccccccc","ccccccccc","cccccccccc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 262122; verify_case(5, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  TennisRallies test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
