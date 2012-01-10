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

class Intersect {
 public:
  struct square {
    int x0;
    int y0;
    int x1;
    int y1;
  };
  
  int area(vector <int> x, vector <int> y)
  {
    // -- main code --

    vector<square> sq;

    TIMES(i, x.size() / 2) {
      square s;
      s.x0 = min(x[i*2], x[i*2+1]);
      s.y0 = min(y[i*2], y[i*2+1]);
      s.x1 = max(x[i*2], x[i*2+1]);
      s.y1 = max(y[i*2], y[i*2+1]);
      sq.push_back(s);
    }

    square r = sq[0];
    FOR(j, 1, sq.size()) {
      r = intersect(r, sq[j]);
    }

    DUMP(r.x0);
    DUMP(r.y0);
    DUMP(r.x1);
    DUMP(r.y1);
    
    return abs((r.x0 - r.x1) * (r.y0 - r.y1));
  }

  square intersect(square& sq0, square& sq1)
  {
    square r = {0, 0, 0, 0};
    
    if(sq0.x0 <= sq1.x0 and sq1.x0 <= sq0.x1 ) {
      // intersect left or inclded
      r.x0 = sq1.x0;
      r.x1 = min(sq0.x1, sq1.x1);
    }else if(sq0.x0 <= sq1.x1 and sq1.x1 <= sq1.x1) {
      // intersect right or inclded
      r.x0 = min(sq0.x0, sq1.x0);
      r.x1 = sq1.x1;
    }

    if(sq0.y0 <= sq1.y0 and sq1.y0 <= sq0.y1 ) {
      // intersect left or inclded
      r.y0 = sq1.y0;
      r.y1 = min(sq0.y1, sq1.y1);
    }else if(sq0.y0 <= sq1.y1 and sq1.y1 <= sq1.y1) {
      // intersect right or inclded
      r.y0 = min(sq0.y0, sq1.y0);
      r.y1 = sq1.y1;
    }
    
    return r;
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are searching for a new house. Location, location, location.  You have
identified a number of desirable attributes, and for each have sketched a
rectangular area that contains all the locations that have that attribute.

You want it all. You need to find the area that is contained in every one of 
your rectangles. Create a class Intersection that contains a method area that
takes as input the collection of rectangles and returns the area of 
their common intersection.

The collection of rectangles is given by a vector <int> x and a vector <int> y. The first 
two values of x and y specify opposing corners of one rectangle, the next two specify opposing corners of the next
rectangle, etc.  Thus, each rectangle is the region between its two x values and between
its two y values.



DEFINITION
Class:Intersect
Method:area
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int area(vector <int> x, vector <int> y)


NOTES
-the 2 values of x (and of y) for a given rectangle are not necessarily given in ascending order


CONSTRAINTS
-x contains an even number of elements between 2 and 50 inclusive
-y contains the same number of elements as x
-each element of x and y is between -10,000 and 10,000 inclusive


EXAMPLES

0)
{0,2,3,-4}
{17,1000,18,6}

Returns: 2

There are 2 rectangles, one having diagonally opposed corners (0,17) and (2,1000) and the other having diagonally opposed corners (3,18) and (-4,6).
The common intersection is the region bounded by x=0, x=2, y=17, y=18 which is
a rectangle 2 units wide and 1 unit tall.


1)
{10000,-10000}
{-10000,10000}

Returns: 400000000

There is just one rectangle, so the answer is the area of that rectangle.

2)
{3,8,6,12,10,15}
{7,17,7,17,7,17}

Returns: 0

The first two rectangles intersect each other, and the second and third rectangles intersect each other, but no area is contained in all three rectangles. 

3)
{0,0,0,0,0,0,0,0}
{5,5,5,5,5,5,5,5}

Returns: 0

Here we have 4 empty rectangles.

4)
{2,100,5,32,1000,-20,47,12}
{29,-1000,-800,-200,-900,300,-600,-650}

Returns: 1000

5)
{1,7,12,3,16,8,3,12}	
{-90,-60,-70,3,-60,-90,-80,-100}

Returns: 0

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,3,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17,1000,18,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, area(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10000,-10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 400000000; verify_case(1, Arg2, area(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,8,6,12,10,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,17,7,17,7,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, area(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5,5,5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, area(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,100,5,32,1000,-20,47,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {29,-1000,-800,-200,-900,300,-600,-650}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; verify_case(4, Arg2, area(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,7,12,3,16,8,3,12}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-90,-60,-70,3,-60,-90,-80,-100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, area(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Intersect test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
