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
#define TIMES(x,n) FOR(x, 0, n)
#define UPTO(x, a, b) for(int x = static_cast<int>(a); x <= static_cast<int>(b); ++x)
#define DOWNTO(x, a, b) for(int x = static_cast<int>(a); x >= static_cast<int>(b) ++x)
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class RevealTriangle {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
	Suppose there is a triangle of digits like the following:

74932
1325
457
92
1

	Each digit, with the exception of those in the top row, is equal to the last digit of the sum of 
	its upper and upper-right neighboring digits.


	You will be given a vector <string> questionMarkTriangle containing a triangle where 
	only one digit in each row is known and all others are represented by '?'s 
	(see example 0 for clarification).
	Each element of questionMarkTriangle represents a row of the triangle, and the rows are given 
	from top to bottom. Each element contains exactly one digit ('0'-'9') and 
	the remaining characters are all '?'s. Restore the triangle and return it as a 
	vector <string> without '?'s.



DEFINITION
Class:RevealTriangle
Method:calcTriangle
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> calcTriangle(vector <string> questionMarkTriangle)


CONSTRAINTS
-questionMarkTriangle will contain between 1 and 50 elements, inclusive.
-Element i (0 indexed) of questionMarkTriangle will contain exactly n-i characters, where n is the number of elements in questionMarkTriangle.
-Each element of questionMarkTriangle will contain exactly one digit ('0'-'9') and all others characters will be '?'s.


EXAMPLES

0)
{"4??", 
 "?2", 
 "1"}

Returns: {"457", "92", "1" }

Let's substitute '?'s with unknown variables:

4ab 
c2 
1


Having done that, we start solving for the variables from the bottom to the top. First, we know that the last digit of (c + 2) is 1. Therefore, c must be 9:


4ab 
92 
1

Now we know that the last digit of (4 + a) is 9, which means a is 5:

45b 
92 
1


And, finally, the last digit of (5 + b) is 2, so b is 7.

1)
{"1"}

Returns: {"1" }

2)
{"???2", "??2", "?2", "2"}

Returns: {"0002", "002", "02", "2" }

3)
{"??5?", "??9", "?4", "6"}

Returns: {"7054", "759", "24", "6" }

*/
// END CUT HERE

 public:
  vector <string> calcTriangle(vector <string> questionMarkTriangle)
  {
    vector <string> result = questionMarkTriangle;
    // -- main code --

    int c = 0;
    while(true) {
      bool changed = false;
      TIMES(y, result.size() - 1) {
        TIMES(x, result[y].size() - 1) {
          if(result[y][x] == '?' and result[y][x+1] != '?' and result[y+1][x] != '?') {
            changed = true;
            int i = (10 + to_i(result[y+1][x]) - to_i(result[y][x+1])) % 10;
            result[y][x] = to_c(i);
          }
          if(result[y][x] != '?' and result[y][x+1] == '?' and result[y+1][x] != '?') {
            changed = true;
            int i = (10 + to_i(result[y+1][x]) - to_i(result[y][x])) % 10;
            result[y][x+1] = to_c(i);
          }
          if(result[y][x] != '?' and result[y][x+1] != '?' and result[y+1][x] == '?') {
            changed = true;
            int i = (to_i(result[y][x]) + to_i(result[y][x+1])) % 10;
            result[y+1][x] = to_c(i);
          }
        }
      }
      ++c;
      if(not changed) {
        break;
      }

      // safty
      if(c > 50*50*20) {
        break;
      }
    }
    
    return result;	
  }
  
int to_i(char c) {
  return c - '0';
}

char to_c(int i) {
  return '0' + i;
}
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"4??", 
 "?2", 
 "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"457", "92", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calcTriangle(Arg0)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calcTriangle(Arg0)); }
	void test_case_2() { string Arr0[] = {"???2", "??2", "?2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0002", "002", "02", "2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calcTriangle(Arg0)); }
	void test_case_3() { string Arr0[] = {"??5?", "??9", "?4", "6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7054", "759", "24", "6" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calcTriangle(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  RevealTriangle test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

