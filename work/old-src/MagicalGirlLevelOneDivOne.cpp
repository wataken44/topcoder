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

class MagicalGirlLevelOneDivOne {

 public:
  string isReachable(vector <int> jumpTypes, int x, int y)
  {
    // -- main code --

    x = abs(x);
    y = abs(y);
    if(y > x) swap(x, y);

    TIMES(i, jumpTypes.size()) {
      if(jumpTypes[i] % 2 == 0) return "YES";
    }

    return ((x + y) % 2 == 0) ? "YES" : "NO";
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Magical Girls are girls who have magical powers. They fight against evil witches to protect the Earth.

You, one of the Magical Girls, are at point (0, 0) of the plane. You find another Magical Girl at (x, y) and she seems to be injured. So you decide to go to point (x, y) to help her.

You can move only by n-knight jump. For a positive integer n, the n-knight jump is 8 types of moves. You can go from (0, 0) to (n, 1), (n, -1), (-n, 1), (-n, -1), (1, n), (-1, n), (1, -n) or (-1, -n) by using n-knight jump once.

You are given a vector <int> jumpTypes containing the valid n-knight jumps you can perform. You can only use an n-knight jump if jumpTypes contains n. Return "YES" if you can reach (x, y) with the n-knight jumps of given numbers. Otherwise return "NO" (all quotes for clarity). You can use each n-knight jump as many times as you want.


DEFINITION
Class:MagicalGirlLevelOneDivOne
Method:isReachable
Parameters:vector <int>, int, int
Returns:string
Method signature:string isReachable(vector <int> jumpTypes, int x, int y)


CONSTRAINTS
-jumpTypes will contain between 1 and 50 elements, inclusive.
-Each element of jumpTypes will be between 1 and 1,000,000,000, inclusive.
-All elements of jumpTypes will be distinct.
-x and y will each be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2}
5
4

Returns: "YES"

(0,?0)?->?(2,?1)?->?(4,?2)?->?(5,?4)

1)
{3}
5
4

Returns: "NO"



2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
1000000000
-999999999

Returns: "YES"



3)
{999999999}
999999999
0

Returns: "NO"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; string Arg3 = "YES"; verify_case(0, Arg3, isReachable(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; string Arg3 = "NO"; verify_case(1, Arg3, isReachable(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -999999999; string Arg3 = "YES"; verify_case(2, Arg3, isReachable(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {999999999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999999; int Arg2 = 0; string Arg3 = "NO"; verify_case(3, Arg3, isReachable(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MagicalGirlLevelOneDivOne test;

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
