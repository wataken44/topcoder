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

class ImprovingStatistics {

 public:
  int howManyGames(int played, int won)
  {
    int c = static_cast<int>(floor(won * 100.0 / played));

    if(won == played) return -1;
    if(c == 99) return -1;

    int l = 0;
    int r = 2000000000;

    TIMES(k, 1000000000) {
      int m = l + (r - l) / 2;
      int dm = static_cast<int>(floor((won + m) * 100.0 / (played + m)));

      if(l == r) return l;
      if(l + 1 == r) return r;
      
      if(dm > c + 1) {
        r = m;
      }else if(dm == c + 1) {
        r = m;
      }else {
        l = m;
      }
    }
    return -1;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
Several years ago I was playing Spider Solitaire on my computer all the time. Sometimes I won, sometimes I lost. Then I stopped playing Spider Solitaire 
and started participating in programming competitions. After a few years I happened to start my old solitaire program again. I was pleased to discover
that with the skill I gained during the years I am now able to win each and every game of Spider Solitaire.
However, the program still remembers some of my previous games and thus the statistics don't necessarily reflect my current perfect skills.



The program displays the statistics in the following way:
Games played: X
Games won: Y (Z %)



The number Z is the percentage of games I won, rounded down to the nearest integer. For example, if X=53 and Y=47, then Z=88. 
(The value Y/X is roughly equal to 0.8868, which means that I won roughly 88.68% of the games I played. 88.68% rounded down to an integer is 88%.)



You will be given two ints played and won - the number of games I played so far, and the number
of games I won so far. Return the smallest positive integer G such that if I now win G games in a row the displayed value of Z will increase.
If this is impossible, return -1 instead.


DEFINITION
Class:ImprovingStatistics
Method:howManyGames
Parameters:int, int
Returns:int
Method signature:int howManyGames(int played, int won)


NOTES
-You may assume that the return value will always be less than 2,000,000,000.


CONSTRAINTS
-played will be between 1 and 1,000,000,000, inclusive.
-won will be between 0 and played, inclusive.


EXAMPLES

0)
10
8

Returns: 1

So far I won 8 games out of 10, and thus the displayed success percentage is 80%.
After I win the next game the percentage will increase to 81%.

1)
100
80

Returns: 6

Again, the currently displayed value is 80%. However, now I need to win at least 6 more games to bring it to 81%.

2)
47
47

Returns: -1

Nothing left to improve.

3)
99000
0

Returns: 1000



4)
1000000000
470000000

Returns: 19230770



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 1; verify_case(0, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 80; int Arg2 = 6; verify_case(1, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 47; int Arg2 = -1; verify_case(2, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 99000; int Arg1 = 0; int Arg2 = 1000; verify_case(3, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 470000000; int Arg2 = 19230770; verify_case(4, Arg2, howManyGames(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ImprovingStatistics test;

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
