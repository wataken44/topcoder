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

class OneDimensionalBalls {

 public:
  long long countValidGuesses(vector <int> firstPicture, vector <int> secondPicture)
  {
    long long result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
    cerr << "debug" << endl;
  }
/*
// PROBLEM STATEMENT
// There is an infinite axis with N balls on it. The balls are moving with equal positive velocity, some of them in the positive direction of the axis and some in the opposite. The balls are small enough to be treated as points on the axis. If two balls meet at a point, they do not collide, and instead, they each continue moving in the same direction and at the same speed as before.

Manao is shown a picture of the axis taken at some moment of time. All the balls are at different points in the picture. The balls are numbered from 0 to N-1 and the i-th ball is at point firstPicture[i].

Some time after the first picture is taken, several balls are added to the axis and another picture is taken. Yet again, no two balls share a point in this picture. The balls seem indistinguishable and their coordinates are given in vector <int> secondPicture in ascending order.

For each ball in the second picture, Manao has to guess whether it is present on the first one as well, and if so, say its number. Sometimes, this can't be determined unambiguously, so any valid guess is welcome. A guess is valid if the balls could move in the way described above and appear in the named locations in the second picture. Two guesses are different if there is a ball in the second picture which Manao identifies differently in these guesses. Return the number of valid guesses for the given pictures.


DEFINITION
Class:OneDimensionalBalls
Method:countValidGuesses
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long countValidGuesses(vector <int> firstPicture, vector <int> secondPicture)


CONSTRAINTS
-firstPicture will contain N elements, where N is between 1 and 50, inclusive.
-Each element of firstPicture will be between 0 and 100,000,000, inclusive.
-Elements in firstPicture will be distinct.
-secondPicture will contain between N and 50 elements, inclusive.
-Each element of secondPicture will be between 0 and 100,000,000, inclusive.
-Elements in secondPicture will be in strictly ascending order.


EXAMPLES

0)
{12,11}
{10,11,13}

Returns: 3

There are 2 balls in the first picture at points 12 and 11, respectively. One more ball is added in the second picture. The following three guesses are valid:
1) The ball at point 10 is ball 0, the ball at point 11 is the new one, the ball at point 13 is ball 1.
2) The ball at point 10 is ball 1, the ball at point 11 is ball 0, the ball at point 13 is the new one.
3) The ball at point 10 is ball 1, the ball at point 11 is the new one, the ball at point 13 is ball 0.

1)
{1,2,3}
{1,2,3}

Returns: 0

Each picture contains the same number of balls, so they must contain the same set of balls.  However, given that some time has passed between the shots, and the balls move with equal positive velocity, there is no way for them to have interchanged positions.


2)
{1,3}
{1,3}

Returns: 1

If the balls move in opposite directions, they will interchange their positions at some moment.

3)
{7234}
{6316,689156,689160,689161,800000,1000001}

Returns: 6

Ball 0 could be any of the balls in the second picture.

4)
{6,2,4}
{1,2,3,4,5,7,8}

Returns: 7



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,11,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(0, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(2, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7234}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6316,689156,689160,689161,800000,1000001}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 6LL; verify_case(3, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 7LL; verify_case(4, Arg2, countValidGuesses(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  OneDimensionalBalls test;

  if(argc == 1) {
    test.run_test(-1);
  }else {
    std::string arg(argv[1]);
    if(arg[0] != '-') {
      test.run_test(arg[0] - '0');
    }else {
      test.debug();
    }
  }
  
  return 0;
}

// END CUT HERE
