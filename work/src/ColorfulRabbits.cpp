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

class ColorfulRabbits {
 public:
  int getMinimum(vector <int> replies) {
    // -- main code --

    sort(replies.begin(), replies.end());

    int count = 0;

    // 1 1 2 2
    // 1 1 2 
    // a a b b b
    
    while(replies.size() > 0) {
      int cur = replies.back();
      replies.pop_back();
      
      int removed = 0;
      while(replies.size() > 0 and replies.back() == cur and removed < cur) {
        ++removed;
        replies.pop_back();
      }

      count += cur + 1;
    }
    
    return count;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Cat Pochi visited a town of rabbits and asked some of the rabbits the following question: 
"How many rabbits in this town other than yourself have the same color as you?". 
The rabbits all replied truthfully, and no rabbit was asked the question more than once. 
You are given the rabbits' replies in the vector <int> replies. 
Return the minimum possible number of rabbits in this town. 


DEFINITION
Class:ColorfulRabbits
Method:getMinimum
Parameters:vector <int>
Returns:int
Method signature:int getMinimum(vector <int> replies)


CONSTRAINTS
-replies will contain between 1 and 50 elements, inclusive. 
-Each element of replies will be between 0 and 1,000,000, inclusive. 


EXAMPLES

0)
{ 1, 1, 2, 2 }


Returns: 5

If there are 2 rabbits with a color and 3 rabbits with another color, 
Pochi can get this set of replies. 




1)
{ 0 }


Returns: 1

A poor lonely rabbit. 


2)
{ 2, 2, 44, 2, 2, 2, 444, 2, 2 }


Returns: 499



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 2, 44, 2, 2, 2, 444, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 499; verify_case(2, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ColorfulRabbits test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
