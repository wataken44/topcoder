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

class Justifier {
 public:
  vector <string> justify(vector <string> textIn) {
    // -- main code --

    int length = textIn[0].size();
    FOR(i, 1, textIn.size()) {
      length = max((int)textIn[i].size(), length);
    }

    vector<string> r;

    FOR(i, 0, textIn.size()) {
      string space(length - textIn[i].size(), ' ');
      r.push_back(space + textIn[i]);
    }
    
    return r;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// We have a collection of strings, and we want to right justify them.
Create a class Justifier that contains a method justify that is 
given a vector <string> textIn and returns
a vector <string> containing the same strings, right justified, in the same order as they
appear in textIn.

The returned strings should be padded on the left with space characters 
so that they are all the same length as the longest string in textIn.




DEFINITION
Class:Justifier
Method:justify
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> justify(vector <string> textIn)


CONSTRAINTS
-textIn will contain between 1 and 50 elements inclusive
-each element of textIn will contain only uppercase letters 'A'-'Z'
-each element of textIn will contain between 1 and 50 characters inclusive


EXAMPLES

0)
{"BOB","TOMMY","JIM"}

Returns: { "  BOB",  "TOMMY",  "  JIM" }

The longest string is "TOMMY" which has 5 characters. So the returned strings all contain exactly 5 characters. 

1)
{"JOHN","JAKE","ALAN","BLUE"}

Returns: { "JOHN",  "JAKE",  "ALAN",  "BLUE" }

No padding is necessary since they all contain the same number of characters.

2)
{"LONGEST","A","LONGER","SHORT"}

Returns: { "LONGEST",  "      A",  " LONGER",  "  SHORT" }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"BOB","TOMMY","JIM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "  BOB",  "TOMMY",  "  JIM" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, justify(Arg0)); }
	void test_case_1() { string Arr0[] = {"JOHN","JAKE","ALAN","BLUE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "JOHN",  "JAKE",  "ALAN",  "BLUE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, justify(Arg0)); }
	void test_case_2() { string Arr0[] = {"LONGEST","A","LONGER","SHORT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "LONGEST",  "      A",  " LONGER",  "  SHORT" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, justify(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Justifier test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
