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

class StringTrain {
 public:
  string buildTrain(vector <string> cars) {
    // -- main code --

    string train = cars[0];

    FOR(i, 1, cars.size()) {
      int s = min(train.size() - 1, cars[i].size() - 1);
      
      DOWNTO(j, s, 1) {
        if(train.substr(train.size() - j, j) == cars[i].substr(0, j)) {
          train += cars[i].substr(j, cars[i].size() - j);
          break;
        }
      }
    }

    string t = "";
    
    DOWNTO(k, train.size() - 1, 0) {
      bool found = false;
      TIMES(l, t.size()) {
        if(t[l] == train[k]) {
          found = true;
        }
      }

      if(!found) {
        t = train.substr(k, 1) + t;
      }
    }

    ostringstream oss;
    oss << train.size() << " " << t;
    
    return oss.str();
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You will be given a vector <string> cars containing a list of strings that will participate in the Train. 
The Train is a string that will be built using the given strings.  The building process works as follows:

	Train is initialized to the value of the 0th element of cars
	For each element of cars in order, beginning with element 1, check if some proper prefix of the current 	
        element matches some proper suffix of the Train.  If so, append the element of cars to the Train, not repeating the matched 	prefix.  If more than one proper prefix matches, take the longest.  If no proper prefix matches, the current element of cars 
        is not appended.

A prefix of a string is a substring that starts at the beginning of the string.  A proper prefix is a prefix that has 
positive length, and is not the entire string.  A suffix of a string is a substring that terminates at the end of the string. 
A proper suffix is a suffix that has positive length, and is not the entire string.

Once you have built the Train, remove all but the last occurrence of each character in the Train.  For example, if the Train 
was (quotes for clarity) "abbbcabdb" you would be left with "cadb".  You will return a string of the form "n x" where, n is the length of the Train before removing all but the last occurrence of each character, and x is the string after the removal. n and x are separated by exactly one space, the return should not have any leading or trailing whitespace, and n should have no leading zeros.

DEFINITION
Class:StringTrain
Method:buildTrain
Parameters:vector <string>
Returns:string
Method signature:string buildTrain(vector <string> cars)


CONSTRAINTS
-cars will contain between 2 and 50 elements inclusive
-Each element of cars will contain between 1 and 50 uppercase letters inclusive


EXAMPLES

0)
{"ABCDE","CDFFF","CDE","CDEGG","GABC"}

Returns: "10 DEGABC"

The Train begins as (quotes for clarity) "ABCDE".  Element 1 of cars cannot be added since it doesn't match any suffix of the Train.  Element 2 of cars cannot be added since the only matching prefix is the entire string.  Element 3 can be added, and the resulting Train is "ABCDEGG".  Element 4 can also be added, and the resulting Train is "ABCDEGGABC".  After removing all but the last occurrence of each character we are left with "DEGABC".

1)
{"AAAAA","AAAAA","AAAAA"}

Returns: "7 A"

The Train begins as "AAAAA".  The longest matching proper prefix of element 1 of cars is "AAAA" so the resulting Train is "AAAAAA".  The longest matching proper prefix of element 1 of cars is "AAAA" so the resulting Train is "AAAAAAA".  After removing all but the last occurrence of each character, the result is "A".

2)
{"CABABDABAB","CABAB","ABABDABAB","DABAB"}

Returns: "15 CDAB"

3)
{"ABABAB","ABABAB","ABABABAB","BZZZZZ"}

Returns: "15 ABZ"

4)
{"A","A","A","AA"}

Returns: "1 A"

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDE","CDFFF","CDE","CDEGG","GABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "10 DEGABC"; verify_case(0, Arg1, buildTrain(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAAAA","AAAAA","AAAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "7 A"; verify_case(1, Arg1, buildTrain(Arg0)); }
	void test_case_2() { string Arr0[] = {"CABABDABAB","CABAB","ABABDABAB","DABAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "15 CDAB"; verify_case(2, Arg1, buildTrain(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABABAB","ABABAB","ABABABAB","BZZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "15 ABZ"; verify_case(3, Arg1, buildTrain(Arg0)); }
	void test_case_4() { string Arr0[] = {"A","A","A","AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1 A"; verify_case(4, Arg1, buildTrain(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  StringTrain test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
