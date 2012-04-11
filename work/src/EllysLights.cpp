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

class EllysLights {

 public:
  int getMinimum(string initial, vector <string> switches)
  {
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Elly's house has a number of light bulbs. Some of them are turned on, some of them are not. She wants to switch all of them off for the upcoming Earth Hour.

Unfortunately, her house has a strange system of light switches. Each switch changes the state of some of the bulbs (possibly none or all of them). This means that if she uses the switch, all bulbs that are connected to it go off if they were on, and go on if they were off. She also knows that each bulb is connected to at most two switches. Help Elly determine what is the minimal number of switches she must use in order to turn off all the lights.

You are given a string initial and a vector <string> switches. Each character in initial represents one light bulb: if the i-th light bulb (0-based index) is initially on, the i-th character of initial is 'Y', otherwise it is 'N'. Each element of switches represents one switch: if the i-th switch toggles the j-th light bulb, switches[i][j] is 'Y', otherwise it is 'N'.

Find and return the smallest nonnegative integer X such that there is a sequence of X switches such that if Elly toggles those switches in the given order, all light bulbs will be turned off at the end. If no such X exists, return -1.

DEFINITION
Class:EllysLights
Method:getMinimum
Parameters:string, vector <string>
Returns:int
Method signature:int getMinimum(string initial, vector <string> switches)


NOTES
-It is possible that none or all of the bulbs are turned on initially.
-Elly is allowed to toggle the same switch more than once.


CONSTRAINTS
-initial will contain between 1 and 50 characters, inclusive.
-Each character of initial will be either 'Y' or 'N'.
-switches will contain between 1 and 50 elements, inclusive.
-Each element of switches will contain the same number of characters as initial.
-Each character of each element of switches will be either 'Y' or 'N'.
-For each index of initial there will be at most two elements of switches that will have 'Y' at that index.


EXAMPLES

0)
"YNYNNN"
{"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"}

Returns: 2

There are multiple ways how to turn off all the lights.
For example, she can first use switch 0, then switch 4, and finally switch 1.
The shortest solutions only use two switches.
For example, it is enough to flip the switch 2 followed by the switch 3.

1)
"YNYNYN"
{"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"}

Returns: 4

Some of the switches might change the state of none or all of the bulbs. Some of the bulbs might be influenced by less than 2 switches.


2)
"YYN"
{"YNY", "NYN"}

Returns: -1

Sometimes there might be no way to switch off all the bulbs. In this case return -1.


3)
"NNYNYNYYYNNYYYYN"
{"NYNYNYNYNYNYNYNY",
 "YNYNYNYNYNYNYNYN",
 "NNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNN",
 "NNNNYNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNN",
 "NNNNNNYNNNNNNNNN",
 "NNNNNNNYNNNNNNNN",
 "NNNNNNNNYNNNNNNN",
 "NNNNNNNNNYNNNNNN",
 "NNNNNNNNNNYNNNNN",
 "NNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNYN",
 "NNNNNNNNNNNNNNNY"}

Returns: 6

There are 9 lit bulbs initially. We can turn them off one by one, but it will be faster to use one of the complex switches and then to toggle the ones that are still lit.

4)
"NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY"
{"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
 "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
 "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
 "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"}

Returns: 7



5)
"NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN"
{"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
 "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
 "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
 "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
 "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"}

Returns: -1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYNNN"; string Arr1[] = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "YNYNYN"; string Arr1[] = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "YYN"; string Arr1[] = {"YNY", "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "NNYNYNYYYNNYYYYN"; string Arr1[] = {"NYNYNYNYNYNYNYNY",
 "YNYNYNYNYNYNYNYN",
 "NNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNN",
 "NNNNYNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNN",
 "NNNNNNYNNNNNNNNN",
 "NNNNNNNYNNNNNNNN",
 "NNNNNNNNYNNNNNNN",
 "NNNNNNNNNYNNNNNN",
 "NNNNNNNNNNYNNNNN",
 "NNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNYN",
 "NNNNNNNNNNNNNNNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY"; string Arr1[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
 "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
 "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
 "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN"; string Arr1[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
 "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
 "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
 "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
 "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  EllysLights test;

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
