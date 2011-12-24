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

class MagicCandy {

 public:
  int root(int n)
  {
    int r = (int)floor(sqrt(n*1.0));
    return r;
  }
  
  int whichOne(int n)
  {
    return n - go(n);
  }

  int go(int n)
  {
    if(n == 1) {
      return 0;
    }

    int r = root(n);
    if(r * r == n) {
      return go(n - 1) + 1;
    }

    return go(n - r);
  }

// BEGIN CUT HERE
  void debug()
  {
    cout << whichOne(4) << endl;
  }
/*
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world celebrate this 
holiday. The following story takes place in the land of reindeer, where Santa Claus resides.



The reindeer love candies. They have n pieces of candy. The pieces of candy are numbered 1 through n. Dasher is one of the reindeer. He wants to eat one of the candies. To pick the one he will eat, Dasher uses the following method:

While there is more than one piece of candy:
Discard all candies that are numbered by perfect squares (i.e., candies 1, 4, 9, 16, 25, etc.).
Relabel the remaining k candies 1 through k, keeping the numbers in the same order.
Once only one piece of candy remains, Dasher will eat it.




You are given an int n. Your method must compute and return the number initially assigned to the piece of candy eaten by Dasher.

DEFINITION
Class:MagicCandy
Method:whichOne
Parameters:int
Returns:int
Method signature:int whichOne(int n)


NOTES
-It can be proved that Dasher's method will always lead to a situation in which only one piece of candy remains.


CONSTRAINTS
-n will be between 1 and 1,000,000,000 inclusive.


EXAMPLES

0)
5

Returns: 5

We start with 5 candies. Let's call them A, B, C, D, and E. Initially, they are numbered 1 through 5, in this order.

In the first round, we discard candies with numbers 1 (which is A) and 4 (which is D).
This leaves us with candies B, C, and E.
These candies now get new numbers: B becomes 1, C becomes 2, and E becomes 3.
In the second round, we discard candy number 1 (which is now B).
This leaves us with candies C and E.
Again, the candies now get new numbers: C becomes 1 and E becomes 2.
In the third round, we discard candy number 1 (which is now C).

The only remaining candy is E. Its number in the beginning was 5, therefore our method should return 5.

1)
9

Returns: 7

This time we start with 9 pieces of candy. If we label them A through I, the process will look as follows:

start: ABCDEFGHI
throw away candies 1, 4, 9 (A, D, I)
after the first round: BCEFGH
throw away candies 1, 4 (B, F)
after the second round: CEGH
throw away candies 1, 4 (C, H)
after the third round: EG
throw away candy 1 (E)
at the end: G


2)
20

Returns: 17



3)
5265

Returns: 5257



4)
20111223

Returns: 20110741



5)
1

Returns: 1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; verify_case(0, Arg1, whichOne(Arg0)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 7; verify_case(1, Arg1, whichOne(Arg0)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 17; verify_case(2, Arg1, whichOne(Arg0)); }
	void test_case_3() { int Arg0 = 5265; int Arg1 = 5257; verify_case(3, Arg1, whichOne(Arg0)); }
	void test_case_4() { int Arg0 = 20111223; int Arg1 = 20110741; verify_case(4, Arg1, whichOne(Arg0)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; verify_case(5, Arg1, whichOne(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MagicCandy test;

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
