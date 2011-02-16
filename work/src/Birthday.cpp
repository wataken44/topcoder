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

class Birthday {
 public:
  string getNext(string date, vector <string> birthdays) {
    // -- main code --

    sort(birthdays.begin(), birthdays.end());

    int i = 0;
    while(i < (int)birthdays.size() and date < birthdays[i]) ++i;

    i = i % birthdays.size();
    if(birthdays[i].substr(0,5) != date) {
      i = (i + 1) % birthdays.size();
    }
    
    return birthdays[i].substr(0, 5);
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Forgetting a close friend's birthday is quite embarrassing, but forgetting it two years in a row is a catastrophe.
So what can a coder do to prevent this from happening again? Well, the thing he possibly can do best: code...

Given a string date (the current date) and a vector <string> birthdays, a list of
people's birthdays and names, return a string, the date of the next occurring birthday, starting from the current date.

date is in the format "MM/DD" (quotes for clarity), where MM represents the two-digit month and DD represents the two-digit day (leading zero if necessary).
Each element of birthdays is in the format "MM/DD <Name>" (quotes for clarity), where MM/DD is the date of <Name>'s birthday. <Name> is a sequence of characters from 'A'-'Z' and 'a'-'z'. There is exactly one space character between the date and <Name>. The date returned also has to be in the format "MM/DD" (quotes for clarity).


DEFINITION
Class:Birthday
Method:getNext
Parameters:string, vector <string>
Returns:string
Method signature:string getNext(string date, vector <string> birthdays)


CONSTRAINTS
-birthdays contains between 1 and 50 elements, inclusive.
-Each element of birthdays contains between 7 and 50 characters, inclusive.
-date and each element of birthdays follow the format described in the problem statement.
-All dates are legal dates and neither date nor any date in birthdays is the 29th of February.


EXAMPLES

0)
"06/17"
{"02/17 Wernie", "10/12 Stefan"}

Returns: "10/12"

1)
"06/17"
{"10/12 Stefan"}

Returns: "10/12"

2)
"02/17"
{"02/17 Wernie", "10/12 Stefan"}

Returns: "02/17"

3)
"12/24"
{"10/12 Stefan"}

Returns: "10/12"

4)
"01/02"
{"02/17 Wernie",
 "10/12 Stefan",
 "02/17 MichaelJordan",
 "10/12 LucianoPavarotti",
 "05/18 WilhelmSteinitz"}

Returns: "02/17"

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "06/17"; string Arr1[] = {"02/17 Wernie", "10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(0, Arg2, getNext(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "06/17"; string Arr1[] = {"10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(1, Arg2, getNext(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "02/17"; string Arr1[] = {"02/17 Wernie", "10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "02/17"; verify_case(2, Arg2, getNext(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "12/24"; string Arr1[] = {"10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(3, Arg2, getNext(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "01/02"; string Arr1[] = {"02/17 Wernie",
 "10/12 Stefan",
 "02/17 MichaelJordan",
 "10/12 LucianoPavarotti",
 "05/18 WilhelmSteinitz"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "02/17"; verify_case(4, Arg2, getNext(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Birthday test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
