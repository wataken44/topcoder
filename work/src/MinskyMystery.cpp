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

class MinskyMystery {

 public:
  typedef long long ll;
  static const ll MOD = 1000000009;

  int computeAnswer(long long N)
  {
    // -- main code --

    if(N == 0 || N == 1) return -1;
    
    ll x = 0;
    ll y = 0;
    ll z = 1;
    ll w = 0;

    ll k;
    for(k = 2; k <= N; ++k) {
      // DUMP(k);
      x = (x + 2 * N) % MOD;
      y = (y + 2 * N) % MOD;
      z = (z + 1) % MOD;
      w = (w + static_cast<ll>(ceil(1.0 * N / k))) % MOD;
      if(N % k == 0) break;
    }
    y -= N;
    if(y < 0) {
      y = (y + ((-y) / MOD + 1) * MOD) % MOD;
    }

    DUMP(x); DUMP(y); DUMP(z); DUMP(w);
    
    return (x + y + z + w) % MOD;	
  }

// BEGIN CUT HERE
  void debug()
  {
    computeAnswer(100000007);
  }
/*
// PROBLEM STATEMENT
// 
Marvin plays a simple game. The game is played with an infinite supply of marbles and five bags, labeled "bag 0" through "bag 4".



At the beginning, Marvin takes N marbles (where N is a nonnegative integer) and places them into bag 0. The remaining four bags are left empty.
Marvin then follows this simple algorithm:



    Add a marble into bag 1.
    Repeat forever:
        Add a marble into bag 1.
        Empty bag 4.
        While there are marbles in bag 0:
            While there are marbles both in bag 0 and in bag 1:
                Remove a marble from bag 0.
                Remove a marble from bag 1.
                Add a marble into bag 2.
                Add a marble into bag 3.
            End While
            Add a marble into bag 4.
            If bags 0 and 1 are both empty:
                Move all marbles from bag 3 to bag 4.
                TERMINATE THE GAME
            End If
            Move all marbles from bag 3 to bag 1.
        End While
        Move all marbles from bag 2 to bag 0.
    End Repeat



You are given a long long N. Count the number of times a marble enters a bag during Marvin's game. That is, compute X+Y, where X is the number of times a marble is added to some bag, and Y is the number of times a marble is moved from one bag to another. To avoid overflows, return just the value ((X+Y) modulo 1,000,000,009). If Marvin's game does not terminate for the given N, return -1 instead.


DEFINITION
Class:MinskyMystery
Method:computeAnswer
Parameters:long long
Returns:int
Method signature:int computeAnswer(long long N)


NOTES
-Suppose there are M marbles in bag A. The instruction "Move all marbles from bag A to bag B." then counts as M individual moves.
-Note that N is allowed to be zero.


CONSTRAINTS
-N will be between 0 and 10^12, inclusive.


EXAMPLES

0)
2

Returns: 9



1)
3

Returns: 27



2)
4

Returns: 16



3)
2401

Returns: 59058



4)
24

Returns: 86

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; int Arg1 = 9; verify_case(0, Arg1, computeAnswer(Arg0)); }
	void test_case_1() { long long Arg0 = 3LL; int Arg1 = 27; verify_case(1, Arg1, computeAnswer(Arg0)); }
	void test_case_2() { long long Arg0 = 4LL; int Arg1 = 16; verify_case(2, Arg1, computeAnswer(Arg0)); }
	void test_case_3() { long long Arg0 = 2401LL; int Arg1 = 59058; verify_case(3, Arg1, computeAnswer(Arg0)); }
	void test_case_4() { long long Arg0 = 24LL; int Arg1 = 86; verify_case(4, Arg1, computeAnswer(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MinskyMystery test;

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
