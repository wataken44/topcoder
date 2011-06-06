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

class StonesGame {

 public:
  string winner(int N, int M, int K, int L)
  {
    string result = "--";
    // -- main code --

    if(M != L && K == 1) {
      return "Draw";
    }else if(M == L && K == 1) {
      return "Romeo";
    }

    if((K % 2 == 1) && (abs(M - L) % 2 == 1)) {
      return "Draw";
    }
    
    // Romeo, Strangelet, Draw

    int rl = left(N, M, K);
    int rr = right(N, M, K);

    if(rl <= L && L <= rr) {
      return "Romeo";
    }

    int sl = left(N, rr, K);
    int sr = right(N, rl, K);

    if(sl <= L && L <= sr) {
      return "Strangelet";
    }
    
    return "Draw";
  }

  int left(int N, int M, int K) {
    if(M - (K - 1) >= 1) {
      return M - (K - 1);
    }else {
      int a =  (- M + (K - 1)) / 2;
      return M - (K - 1) + (a + 1) * 2;
    }
  }

  int right(int N, int M, int K) {
    if(M + (K - 1) <= N) {
      return M + (K - 1);
    }else {
      return (M + (K - 1)) - ((M + (K - 1)) - N) / 2 * 2 - 2; 
    }
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Romeo and his friend Strangelet are playing a game. There are N stones in a row, all of which are black except for the M-th one, which is white (all positions in this problem are 1-based). The players alternate turns, and Romeo plays first. On each turn, a player must choose exactly K consecutive stones, one of which must be white, and reverse their order. The winner is the first player who puts the white stone in the L-th position.

Return "Romeo" if Romeo can win regardless of how Strangelet plays, and return "Strangelet" if Strangelet can win regardless of Romeo's strategy.  Otherwise, return "Draw" since neither player can win if both players play optimally.  All quotes are for clarity only.

DEFINITION
Class:StonesGame
Method:winner
Parameters:int, int, int, int
Returns:string
Method signature:string winner(int N, int M, int K, int L)


CONSTRAINTS
-N will be between 2 and 1,000,000,  inclusive.
-M, K and L will each be between 1 and N, inclusive.
-M and L will be different.


EXAMPLES

0)
3
1
1
2

Returns: "Draw"

There are three stones and the stone in position 1 is white.  To win the game, a player must put the white stone in position 2.  However, since K is 1, each player can only choose a single stone to reverse, so it is impossible to move the white stone from its original position.  Therefore, neither player can win.

1)
5
1
2
2

Returns: "Romeo"

Romeo can win on his first move by reversing the order of the first two stones.

2)
5
5
2
3

Returns: "Strangelet"

Romeo's only possible move is to reverse the last two stones.  This puts the white stone in position 4.  Strangelet can then reverse the third and fourth stones, putting the white stone in position 3 and winning the game.

3)
5
5
2
2

Returns: "Draw"

This is similar to the previous example, but here, the white stone must be moved to position 2.  As in the previous example, Romeo's first move will put the white stone in position 4.  This time, Strangelet will then move it back to position 5 because otherwise, Romeo would move it to position 2 and win.  This sequence of moves will repeat infinitely and neither player will win.

4)
1000000
804588
705444
292263

Returns: "Romeo"

5)
1000000
100000
500000
600000

Returns: "Strangelet"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; string Arg4 = "Draw"; verify_case(0, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Romeo"; verify_case(1, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; string Arg4 = "Strangelet"; verify_case(2, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Draw"; verify_case(3, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 804588; int Arg2 = 705444; int Arg3 = 292263; string Arg4 = "Romeo"; verify_case(4, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 100000; int Arg2 = 500000; int Arg3 = 600000; string Arg4 = "Strangelet"; verify_case(5, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  StonesGame test;

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
