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

class PaternityTest {
 public:
  vector <int> possibleFathers(string child, string mother, vector <string> men) {
    // -- main code --
    vector<int> mm(child.size(), 0);

    TIMES(i, child.size()) {
      if(child[i] == mother[i]) {
        mm[i] = 1;
      }
    }

    vector<int> r;

    TIMES(m, men.size()) {
      string man = men[m];
      bool matched = true;
      int c = 0;
      TIMES(i, child.size()) {
        if(child[i] == man[i]) {
          ++c;
        }else {
          if(mm[i] == 0) {
            matched = false;
          }
        }
      }
      if( (c >= (double)man.size() / 2.0) and matched) {
        r.push_back(m);
      }
    }
    
    return r;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
DNA testing is one of the most popular methods of establishing paternity.  In such a test, you compare samples of DNA from the
man, the child, and the child's mother.  For the purposes of this problem, assume that each sample is represented as a string of uppercase letters ('A'-'Z').  
If half of the characters in the child's sample match the characters in the 
corresponding positions in the man's sample, and the remaining characters in the child's sample match the characters in
the corresponding positions in the mother's sample, then the man is most likely the father.  On the other hand, if it is
impossible to partition the child's sample such that half of the characters match the man's and the other half match the
mother's, then the man is definitely ruled out as the father.



For example, suppose the child's sample is "ABCD" and the mother's sample is "AXCY" (all quotes for clarity only).
The 'A' and 'C' in the child's sample must have come from the mother, so the 'B' and 'D' must have come from the father.
If the man's sample is "SBTD", then he is most likely the father, but if the man's sample is "QRCD", then he is definitely
not the father.  Note in the latter case that the man was definitely ruled out even though half of his sample (the 'C' and
'D') did in fact match the child's. 



Your method will take samples from the child and the mother, as well as samples from several men, and return the indices of the
men who cannot be ruled out as the father, in increasing order.




DEFINITION
Class:PaternityTest
Method:possibleFathers
Parameters:string, string, vector <string>
Returns:vector <int>
Method signature:vector <int> possibleFathers(string child, string mother, vector <string> men)


NOTES
-You may assume that the identity of the mother is not in question.


CONSTRAINTS
-men contains between 1 and 5 elements, inclusive.
-child, mother, and all elements of men contain the same number of characters, which is even and between 2 and 20, inclusive.
-child, mother, and all elements of men contain only uppercase letters ('A'-'Z').
-At least half of the characters in mother match the characters in the corresponding positions in child.


EXAMPLES

0)
"ABCD"
"AXCY"
{ "SBTD", "QRCD" }

Returns: { 0 }

The example above.

1)
"ABCD"
"ABCX"
{ "ABCY", "ASTD", "QBCD" } 

Returns: { 1,  2 }

"ABCY" could not be the father.  "ASTD" could be the father, with the 'A' and 'D' coming from
the father and the 'B' and 'C' coming from the mother.  "QBCD" could also be the father, with
either the 'B' and 'D' or the 'C' and 'D' coming from the father.

2)
"ABABAB"
"ABABAB"
{ "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" }

Returns: { 0,  1 }

3)
"YZGLSYQT"
"YUQRWYQT"
{"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"}

Returns: { }

4)
"WXETPYCHUWSQEMKKYNVP"
"AXQTUQVAUOSQEEKCYNVP"
{ "WNELPYCHXWXPCMNKDDXD",
  "WFEEPYCHFWDNPMKKALIW",
  "WSEFPYCHEWEFGMPKIQCK",
  "WAEXPYCHAWEQXMSKYARN",
  "WKEXPYCHYWLLFMGKKFBB" }

Returns: { 1,  3 }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; string Arg1 = "AXCY"; string Arr2[] = { "SBTD", "QRCD" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "ABCD"; string Arg1 = "ABCX"; string Arr2[] = { "ABCY", "ASTD", "QBCD" } ; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ABABAB"; string Arg1 = "ABABAB"; string Arr2[] = { "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "YZGLSYQT"; string Arg1 = "YUQRWYQT"; string Arr2[] = {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "WXETPYCHUWSQEMKKYNVP"; string Arg1 = "AXQTUQVAUOSQEEKCYNVP"; string Arr2[] = { "WNELPYCHXWXPCMNKDDXD",
  "WFEEPYCHFWDNPMKKALIW",
  "WSEFPYCHEWEFGMPKIQCK",
  "WAEXPYCHAWEQXMSKYARN",
  "WKEXPYCHYWLLFMGKKFBB" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PaternityTest test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
