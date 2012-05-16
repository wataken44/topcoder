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


#include <iomanip>
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

class MirroredClock {

 public:
  string whatTimeIsIt(string time)
  {
    time[2] = ' ';
    istringstream iss(time);

    int h, m;
    iss >> h >> m;

    int rm = 720 - h * 60 - m;
    int rh = (rm / 60) % 12;
    rm %= 60;

    ostringstream oss;
    oss << setw(2) << setfill('0') << rh << ":" << setw(2) << setfill('0') << rm;
    
    string result(oss.str());
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are sitting in front of a mirror and looking at the image of a clock located behind you. You want to know what time it is. The clock is a traditional clock with a 12-hour board (without numbers written on it), a minute and an hour hand (the hour hand is shorter, so that you can distuniguish them). You are given a string time denoting the time as it is seen in the mirror. The time will be formatted as "HH:MM" (quotes for clarity), where HH is the two digit hour and MM is the two digit minute. The hour will be between 00 and 11, inclusive, where 00 represents 12 o' clock. Return a string in the same format denoting the actual time. See examples for further clarification.

DEFINITION
Class:MirroredClock
Method:whatTimeIsIt
Parameters:string
Returns:string
Method signature:string whatTimeIsIt(string time)


CONSTRAINTS
-time will be formatted as "HH:MM" (quotes for clarity), where HH is a two digit integer between 00 and 11, inclusive, and MM is a two digit integer between 00 and 59, inclusive.


EXAMPLES

0)
"10:00"

Returns: "02:00"



1)
"01:15"

Returns: "10:45"



2)
"03:40"

Returns: "08:20"



3)
"00:00"

Returns: "00:00"

Although it doesn't happen often, sometimes we can see the actual time right in the mirror.

4)
"11:53"

Returns: "00:07"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "10:00"; string Arg1 = "02:00"; verify_case(0, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_1() { string Arg0 = "01:15"; string Arg1 = "10:45"; verify_case(1, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_2() { string Arg0 = "03:40"; string Arg1 = "08:20"; verify_case(2, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_3() { string Arg0 = "00:00"; string Arg1 = "00:00"; verify_case(3, Arg1, whatTimeIsIt(Arg0)); }
	void test_case_4() { string Arg0 = "11:53"; string Arg1 = "00:07"; verify_case(4, Arg1, whatTimeIsIt(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MirroredClock test;

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
