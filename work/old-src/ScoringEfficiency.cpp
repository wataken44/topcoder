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

class ScoringEfficiency {

 public:
  double getPointsPerShot(vector <string> gameLog)
  {
    // -- main code --

    int total = 0;
    int field = 0;
    int free = 0;
    
    FOR(i, 0, gameLog.size()) {
      string& log = gameLog[i];

      if(log == "Made 2 point field goal") {
        total += 2;
        field += 1;
      } else if(log == "Missed 2 point field goal") {
        field += 1;
      } else if(log == "Made 3 point field goal") {
        total += 3;
        field += 1;
      } else if(log == "Missed 3 point field goal") {
        field += 1;
      } else if(log == "Made free throw") {
        total += 1;
        free += 1;
      } else if(log == "Missed free throw") {
        free += 1;
      } else {
        cout << "something wrong: " << log << endl;
      }
    }

    double result = 1.0 * total / (field + 0.5 * free );

    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In basketball, players can attempt either two point or three point field goals, and if they are fouled, they can also attempt one point free throws. Since missing a free throw or a field goal often results in losing possession of the ball, it is important to make the most of each shot attempt. Traditionally, this efficiency has been measured by shooting percentage, which is defined as:


                            Field goals made
   Shooting percentage = ---------------------
                         Field goals attempted


Unfortunately, this formula is problematic since it does not account for either free throws or the different types of field goals. Therefore, a new formula, called points per shot, is gaining prominence. This is given by:


                                         Total points
   Points per shot = -----------------------------------------------------
                     (Field goals attempted) + 0.5*(Free throws attempted)


Consider, for example, a player that makes 4 of 5 two point field goals, 3 of 7 three point field goals, and 7 of 9 free throws. The player has earned 4*2 + 3*3 + 7*1 = 24 points with 5+7=12 field goal attempts and 9 free throw attempts. Thus, the player has earned 24/16.5 = 1.45454545... points per shot.



Create a class ScoringEfficiency that contains a method getPointsPerShot, which is given a vector <string> gameLog. This will give the history of one player's shot attempts, with each element being equal to one of the following strings (quotes for clarity):

  - "Made 2 point field goal"
  - "Missed 2 point field goal"
  - "Made 3 point field goal"
  - "Missed 3 point field goal"
  - "Made free throw"
  - "Missed free throw"

Given this history, the method should return the player's points per shot, as computed above.


DEFINITION
Class:ScoringEfficiency
Method:getPointsPerShot
Parameters:vector <string>
Returns:double
Method signature:double getPointsPerShot(vector <string> gameLog)


NOTES
-Return values with either a relative or absolute error less than 1.0E-9 will be accepted.


CONSTRAINTS
-gameLog will contain between 1 and 50 elements inclusive.
-Each element of gameLog will be one of the six strings listed above.


EXAMPLES

0)
{"Made 3 point field goal",
 "Missed 2 point field goal"}

Returns: 1.5

This player has 3 total points, 2 field goals attempted, and 0 free throws attempted, so he has earned 3/2 = 1.5 points per shot.

1)
{"Made free throw",
 "Missed free throw",
 "Missed free throw",
 "Missed free throw",
 "Made free throw"}


Returns: 0.8

This player has 2 total points, 0 field goals attempted, and 5 free throws attempted, so he has earned 2/2.5 = 0.8 points per shot.

2)
{"Made 2 point field goal", "Made 2 point field goal", "Made 2 point field goal", 
 "Made 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Made 3 point field goal", "Made 3 point field goal",
 "Missed 3 point field goal", "Missed 3 point field goal", 
 "Missed 3 point field goal", "Missed 3 point field goal",
 "Made free throw", "Made free throw", "Made free throw", 
 "Made free throw", "Made free throw", "Made free throw", 
 "Made free throw", "Missed free throw", "Missed free throw"}

Returns: 1.4545454545454546

This is the example from the problem statement.

3)
{"Made 2 point field goal", "Missed free throw",
 "Made free throw", "Missed free throw", "Made free throw", 
 "Made 2 point field goal", "Made 2 point field goal",
 "Missed 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Missed 2 point field goal",
 "Made 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Missed 2 point field goal",
 "Missed 2 point field goal", "Missed 3 point field goal",
 "Made free throw", "Made free throw", 
 "Missed 3 point field goal", "Missed 2 point field goal",
 "Missed 2 point field goal", "Made 2 point field goal",
 "Missed 2 point field goal", "Made 2 point field goal",
 "Missed 3 point field goal"}
 

Returns: 0.9565217391304348

This log is from a game by NBA superstar Vince Carter. He had 22 points, 20 field goals attempted, and 6 free throws attempted, so he earned 22/23 = 0.956521739... points per shot.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Made 3 point field goal",
 "Missed 2 point field goal"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(0, Arg1, getPointsPerShot(Arg0)); }
	void test_case_1() { string Arr0[] = {"Made free throw",
 "Missed free throw",
 "Missed free throw",
 "Missed free throw",
 "Made free throw"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.8; verify_case(1, Arg1, getPointsPerShot(Arg0)); }
	void test_case_2() { string Arr0[] = {"Made 2 point field goal", "Made 2 point field goal", "Made 2 point field goal", 
 "Made 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Made 3 point field goal", "Made 3 point field goal",
 "Missed 3 point field goal", "Missed 3 point field goal", 
 "Missed 3 point field goal", "Missed 3 point field goal",
 "Made free throw", "Made free throw", "Made free throw", 
 "Made free throw", "Made free throw", "Made free throw", 
 "Made free throw", "Missed free throw", "Missed free throw"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.4545454545454546; verify_case(2, Arg1, getPointsPerShot(Arg0)); }
	void test_case_3() { string Arr0[] = {"Made 2 point field goal", "Missed free throw",
 "Made free throw", "Missed free throw", "Made free throw", 
 "Made 2 point field goal", "Made 2 point field goal",
 "Missed 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Missed 2 point field goal",
 "Made 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Missed 2 point field goal",
 "Missed 2 point field goal", "Missed 3 point field goal",
 "Made free throw", "Made free throw", 
 "Missed 3 point field goal", "Missed 2 point field goal",
 "Missed 2 point field goal", "Made 2 point field goal",
 "Missed 2 point field goal", "Made 2 point field goal",
 "Missed 3 point field goal"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.9565217391304348; verify_case(3, Arg1, getPointsPerShot(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ScoringEfficiency test;

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
