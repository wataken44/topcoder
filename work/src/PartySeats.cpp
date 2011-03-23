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

class PartySeats {
 public:
  vector <string> seating(vector <string> attendees) {
    // -- main code --

    vector<string> boy;
    vector<string> girl;

    TIMES(i, attendees.size()) {
      istringstream iss(attendees[i]);
      string name;
      string gender;

      iss >> name;
      iss >> gender;

      if(gender == "boy") {
        boy.push_back(name);
      }else if(gender == "girl") {
        girl.push_back(name);
      }
    }

    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());

    vector<string> r;

    if(boy.size() != girl.size() or boy.size() % 2 == 1) {
      return r;
    }

    r.push_back("HOST");

    TIMES(i, boy.size() / 2) {
      r.push_back(girl[i]);
      r.push_back(boy[i]);
    }
    
    r.push_back("HOSTESS");

    FOR(i, boy.size() / 2, boy.size()) {
      r.push_back(boy[i]);
      r.push_back(girl[i]);
    }
    
    return r;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// It is time to arrange the seating around a circular table for a party.  We
want to alternate boys and girls around the table.  We have a list of all
the attendees and their genders. Each attendee is specified by a string that
consists of the name, followed by one space, followed by either "boy" or "girl".

In addition to the attendees, we need to seat 
the HOST (a boy) and the HOSTESS (a girl) with the HOSTESS directly across from
the HOST. That means that half the attendees should be on the HOST's left, and half on his right.  

Create a class PartySeats that contains a method seating that is given a 
vector <string> attendees that lists all the attendees and their genders. The method
returns a vector <string> that gives the seating plan, starting with "HOST" and proceeding
clockwise around the table, including all the attendees and the HOSTESS. 

If there is more than one possible seating plan,
return the one that comes first lexicographically. "First lexicographically" means that each successive element in the return should be chosen to be the earliest alphabetically that is consistent with a legal seating plan. If there is no legal seating
plan, the return should contain 0 elements.



DEFINITION
Class:PartySeats
Method:seating
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> seating(vector <string> attendees)


CONSTRAINTS
-attendees will contain between 1 and 50 elements inclusive
-each element of attendees will consists of a name followed by a single space followed by either "boy" or "girl". There will be no leading or trailing spaces.
-each name will contain between 1 and 20 characters inclusive
-each name will contain only uppercase letters 'A'-'Z'
-no name will be "HOST" or "HOSTESS"


EXAMPLES

0)
{"BOB boy","SAM girl","DAVE boy","JO girl"}

Returns: { "HOST",  "JO",  "BOB",  "HOSTESS",  "DAVE",  "SAM" }

   A girl must follow the HOST, and JO comes earliest lexicographically. Then comes
   a boy, and BOB is the earliest lexicographically. HOSTESS must come next so 
   she can be opposite the HOST and then DAVE and SAM must follow in that order
   to honor the alternating gender requirement.



1)
{"JOHN boy"}

Returns: { }


   There are more boys than girls so we cannot alternate.
 

2)
{"JOHN boy","CARLA girl"}

Returns: { }


   There is no way to alternate gender and also have the HOST sit directly
   across from the HOSTESS

3)
{"BOB boy","SUZIE girl","DAVE boy","JO girl",
"AL boy","BOB boy","CARLA girl","DEBBIE girl"}

Returns: { "HOST",  "CARLA",  "AL",  "DEBBIE",  "BOB",  "HOSTESS",  "BOB",  "JO",  "DAVE",  "SUZIE" }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"BOB boy","SAM girl","DAVE boy","JO girl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "HOST",  "JO",  "BOB",  "HOSTESS",  "DAVE",  "SAM" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, seating(Arg0)); }
	void test_case_1() { string Arr0[] = {"JOHN boy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, seating(Arg0)); }
	void test_case_2() { string Arr0[] = {"JOHN boy","CARLA girl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, seating(Arg0)); }
	void test_case_3() { string Arr0[] = {"BOB boy","SUZIE girl","DAVE boy","JO girl",
"AL boy","BOB boy","CARLA girl","DEBBIE girl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "HOST",  "CARLA",  "AL",  "DEBBIE",  "BOB",  "HOSTESS",  "BOB",  "JO",  "DAVE",  "SUZIE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, seating(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PartySeats test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
