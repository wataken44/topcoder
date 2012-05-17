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

class ChangingSounds {

 public:
  bool ok(int l, int mL)
  {
    return 0 <= l && l <= mL;
  }

  int maxFinal(vector <int> cI, int bL, int mL)
  {
    int sz = cI.size();
    vector< set<int> > level(sz + 1);

    level[0].insert(bL);

    UPTO(i, 1, sz) {
      EACH(level[i-1], it) {
        int l = cI[i - 1];
        int n0 = *it + l;
        if(ok(n0, mL)) level[i].insert(n0);

        int n1 = *it - l;
        if(ok(n1, mL)) level[i].insert(n1);
      }
    }

    return level[sz].empty() ? -1 : *(--level[sz].end());	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are a guitar player and you are going to play a concert.  You don't like to play all the songs at the same volume, so you decide to change the volume level of your guitar before each new song.  Before the concert begins, you make a list of the number of intervals you will be changing your volume level by before each song.  For each volume change, you will decide whether to add that number of intervals to the volume, or substract it.

You are given a vector <int> changeIntervals, the i-th element of which is the number of intervals you will change your volume by before the i-th song. You are also given an int beginLevel, the initial volume of your guitar, and an int maxLevel, the highest volume setting of your guitar. You cannot change the volume of your guitar to a level above maxLevel or below 0 (but exactly 0 is no problem). Return the maximum volume you can use to play the last song. If there is no way to go through the list without exceeding maxLevel or going below 0, return -1.


DEFINITION
Class:ChangingSounds
Method:maxFinal
Parameters:vector <int>, int, int
Returns:int
Method signature:int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel)


CONSTRAINTS
-changeIntervals will contain between 1 and 50 elements, inclusive.
-Each element of changeIntervals will be between 1 and maxLevel, inclusive.
-maxLevel will be between 1 and 1000, inclusive.
-beginLevel will be between 0 and maxLevel, inclusive.


EXAMPLES

0)
{5, 3, 7}
5
10

Returns: 10

First we turn the volume down to 0 (-5), then we turn it up to 3 (+3), and then up to 10 (+7) for the last song.

1)
{15, 2, 9, 10}
8
20

Returns: -1

Adding 15 to 8 or substracting 15 from 8 both give an invalid sound level.

2)
{74,39,127,95,63,140,99,96,154,18,137,162,14,88}
40
243

Returns: 238



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 10; int Arg3 = 10; verify_case(0, Arg3, maxFinal(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {15, 2, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 20; int Arg3 = -1; verify_case(1, Arg3, maxFinal(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 243; int Arg3 = 238; verify_case(2, Arg3, maxFinal(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ChangingSounds test;

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
