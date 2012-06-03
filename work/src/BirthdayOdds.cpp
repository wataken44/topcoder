#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
#define EACH(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(cont, it, cond, ret) \
  bool ret = true; EACH(cont, it) { if(!(cond)) {ret=false;break;} }
#define ANY(cont, it, cond, ret) \
  bool ret = false; EACH(cont, it) { if(cond) {ret=true;break;} }

using namespace std;
// debug
// BEGIN CUT HERE
#define DUMP(x) std::cerr << #x << " = " << to_s(x) << std::endl;
template<typename T> string to_s(const T& v);
template<> string to_s(const string& v);
template<> string to_s(const bool& v);
template<typename T> string to_s(const vector<T>& v);
template<typename T> string to_s(const list<T>& v);
template<typename T> string to_s(const set<T>& v);
template<typename F, typename S> string to_s(const pair<F,S>& v);
template<typename K, typename V> string to_s(const map<K,V>& v);
// END CUT HERE
#ifndef DUMP
#define DUMP(x) 
#endif

class BirthdayOdds {

 public:
  double prob(int n, int d)
  {
    double p = 1.0;
    TIMES(i, n) {
      p *= 1.0 * (1 - i) / d;
    }
    return 1 - p;
  }

  int minPeople(int minOdds, int daysInYear)
  {
    // -- main code --

    double p = 1.0;
    FOR(i, 1, daysInYear * 10) {
      p *= (daysInYear + 1.0 - i) / daysInYear;
      if((1 - p) * 100 >= minOdds) {
        return i;
      }

    }

    return 0;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Here is an interesting factoid:  "On the planet Earth, if there are at least 23 people in a room, the chance that two of them have the same birthday is greater than 50%."  You would like to come up with more factoids of this form.  Given two integers (minOdds and daysInYear), your method should return the fewest number of people (from a planet where there are daysInYear days in each year) needed such that you can be at least minOdds% sure that two of the people have the same birthday. See example 0 for further information.

DEFINITION
Class:BirthdayOdds
Method:minPeople
Parameters:int, int
Returns:int
Method signature:int minPeople(int minOdds, int daysInYear)


NOTES
-Two people can have the same birthday without being born in the same year.
-You may assume that the odds of being born on a particular day are (1 / daysInYear).
-You may assume that there are no leap years.


CONSTRAINTS
-minOdds will be between 1 and 99, inclusive.
-daysInYear will be between 1 and 10000, inclusive.
-For any number of people N, the odds that two people will have the same birthday (in a room with N people, on a planet with daysInYear days in each year) will not be within 1e-9 of minOdds. (In other words, you don't need to worry about floating-point precision for this problem.)


EXAMPLES

0)
75
5

Returns: 4

We must be 75% sure that at least two of the people in the room have the same birthday. This is equivalent to saying that the odds of everyone having different birthdays is 25% or less.

If there is only one person in the room, the odds are 5/5 or 100% that nobody shares a birthday.
If there are two people in the room, the odds are 5/5 * 4/5 = 80% that nobody shares a birthday. This is because the second person has 4 "safe" days on which his birthday could fall, out of 5 possible days in the year.
If there are three people in the room, the odds of no overlap are 5/5 * 4/5 * 3/5 = 48%.
If there are four people in the room, the odds are 5/5 * 4/5 * 3/5 * 2/5 = 19.2%. This means that you can be (100% - 19.2%) = 80.8% sure that two or more of them do, in fact, have the same birthday.

We only need to be 75% sure of this, which was untrue for three people but true for four.  Therefore, your method should return 4.

1)
50
365

Returns: 23

The factoid from the problem statement. If there are 22 people in a room, the odds of a shared birthday are roughly 47.57%. With 23 people, these odds jump to 50.73%, which is greater than or equal to the 50% needed.

2)
1
365

Returns: 4

Another example from planet Earth. The odds of a repeat birthday among only four people are roughly 1.64%.

3)
84
9227

Returns: 184

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 75; int Arg1 = 5; int Arg2 = 4; verify_case(0, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 50; int Arg1 = 365; int Arg2 = 23; verify_case(1, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 365; int Arg2 = 4; verify_case(2, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 84; int Arg1 = 9227; int Arg2 = 184; verify_case(3, Arg2, minPeople(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BirthdayOdds test;

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

template<typename T> string to_s(const T& v) { ostringstream oss; oss << v; return oss.str(); }
template<> string to_s(const string& v) { ostringstream oss; oss << '"' << v << '"'; return oss.str(); }
template<> string to_s(const bool& v) { ostringstream oss; oss << ( v ? "true" : "false") ; return oss.str(); } 
template<typename T> string to_s(const vector<T>& v) { ostringstream oss; oss << "["; EACH(v,i) oss << to_s(*i) << ","; oss << "]"; return oss.str(); }
template<typename T> string to_s(const list<T>& v) { ostringstream oss; oss << "("; EACH(v,i) oss << to_s(*i) << ","; oss << ")"; return oss.str(); }
template<typename T> string to_s(const set<T>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(*i) << ","; oss << "}"; return oss.str(); }
template<typename F, typename S> string to_s(const pair<F,S>& v) { ostringstream oss; oss << "<" << to_s(v.first) << " " << to_s(v.second) << ">"; return oss.str(); }
template<typename K, typename V> string to_s(const map<K,V>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(i->first) << " => " << to_s(i->second) << ","; oss << "}"; return oss.str(); }

// END CUT HERE
