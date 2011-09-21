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

class WhichDay {

 public:
  string getDay(vector <string> notOnThisDay)
  {
    
    // -- main code --

    string days[7] = {
      "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    TIMES(i, 7) {
      string d = days[i];

      if(find(notOnThisDay.begin(), notOnThisDay.end(),d ) == notOnThisDay.end()) {
        return d;
      }
    }

    // never reach
    return "";	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// This week there will be an important meeting of your entire department. You clearly remember your boss telling you about it. The only thing you forgot is the day of the week when the meeting will take place.

You asked six of your colleagues about the meeting. None of them knew the day when it will take place, but each of them remembered one day when it will not take place. The days they remembered were distinct. For a clever programmer like you, this was enough to determine the day of the meeting.

You are given a vector <string> notOnThisDay containing six weekdays when the meeting will not take place. Return the weekday of the meeting.

DEFINITION
Class:WhichDay
Method:getDay
Parameters:vector <string>
Returns:string
Method signature:string getDay(vector <string> notOnThisDay)


NOTES
-There are seven weekdays. Their names are: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday".


CONSTRAINTS
-notOnThisDay will contain exactly 6 elements.
-Each element of notOnThisDay will be a name of a weekday (in the exact form specified in the Note above).
-No two elements of notOnThisDay will be equal.


EXAMPLES

0)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}

Returns: "Saturday"



1)
{"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"}

Returns: "Saturday"



2)
{"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"}

Returns: "Wednesday"



3)
{"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"}

Returns: "Thursday"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Saturday"; verify_case(0, Arg1, getDay(Arg0)); }
	void test_case_1() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Saturday"; verify_case(1, Arg1, getDay(Arg0)); }
	void test_case_2() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Wednesday"; verify_case(2, Arg1, getDay(Arg0)); }
	void test_case_3() { string Arr0[] = {"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Thursday"; verify_case(3, Arg1, getDay(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  WhichDay test;

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
