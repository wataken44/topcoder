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
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define FORN(x,n) FOR(x, 0, n)

using namespace std;

class PeopleCircle {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There are numMales males and numFemales females arranged in a circle. Starting from a given point, you count clockwise and remove the K'th person from the circle (where K=1 is the person at the current point, K=2 is the next person in the clockwise direction, etc...).  After removing that person, the next person in the clockwise direction becomes the 
new starting point.  After repeating this procedure numFemales times, 
there are no females left in the circle.		

Given numMales, numFemales and K, your task is to return what the initial arrangement of people in the circle must have been, starting from the starting point and in clockwise order.

For example, if there are 5 males and 3 females and you remove every second person, your return String will be "MFMFMFMM".


DEFINITION
Class:PeopleCircle
Method:order
Parameters:int, int, int
Returns:string
Method signature:string order(int numMales, int numFemales, int K)


CONSTRAINTS
-numMales is between 0 and 25 inclusive
-numFemales is between 0 and 25 inclusive
-K is between 1 and 1000 inclusive


EXAMPLES

0)
5
3
2

Returns: "MFMFMFMM"

Return "MFMFMFMM". On the first round you remove the second person - "M_MFMFMM". Your new circle looks like "MFMFMMM" from your new starting point. Then you remove the second person again etc.

1)
7
3
1

Returns: "FFFMMMMMMM"

Starting from the starting point you remove the first person, then you continue and remove the next first person etc. Clearly, all the females are located at the beginning. Hence return "FFFMMMMMMM"

2)
25
25
1000

Returns: "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF"

3)
5
5
3

Returns: "MFFMMFFMFM"

Here we mark the removed people with '_', and the starting position with lower-case:

Number of      | People Remaining
Rounds         | (in initial order)
---------------+-----------------
 0             | mFFMMFFMFM
 1             | MF_mMFFMFM
 2             | MF_MM_fMFM
 3             | MF_MM_FM_m
 4             | M__mM_FM_M
 5             | M__MM__m_M



4)
1
0
245

Returns: "M"

*/
// END CUT HERE

 public:
  string order(int numMales, int numFemales, int K) {
    string result = "";
    // -- main code --

    int numPeople = numMales + numFemales;
    
    FORN(i, numPeople) {
      result += "M";
    }

    int pos = 0;
    FORN(i, numFemales) {
      
      int maleCount = 0;
      while(true) {
        if(result[pos] == 'M') {
          ++maleCount;
          if(maleCount == K) {
            break;
          }
        }
        pos = (pos + 1) % numPeople;
      }
      result[pos] = 'F';
    }
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; string Arg3 = "MFMFMFMM"; verify_case(0, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 1; string Arg3 = "FFFMMMMMMM"; verify_case(1, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 25; int Arg1 = 25; int Arg2 = 1000; string Arg3 = "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF"; verify_case(2, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; string Arg3 = "MFFMMFFMFM"; verify_case(3, Arg3, order(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 245; string Arg3 = "M"; verify_case(4, Arg3, order(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PeopleCircle test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

