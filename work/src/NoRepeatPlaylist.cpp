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

class NoRepeatPlaylist {

 public:
  typedef long long ll;
  static const ll modulo = 1000000007;

  vector<ll> memo;
  
  int numPlaylists(int N, int M, int P)
  {
    memo.clear();

    memo = vector<ll>(N+1, -1);
    
    return go(N, M, P);
  }

  int go(int N, int M, int P)
  {
    if(memo[N] != -1) return memo[N];

    if(N < M) {
      memo[N] = 0;
      return 0;
    }
    
    ll r = 1;

    TIMES(p, P) {
      ll rr = p < M ? N - p : N - M;
      rr = max(rr, 0LL);
      r = (r * rr) % modulo;
    }

    if(r == 0) {
      memo[N] = 0;
      return 0;
    }
    
    UPTO(n, M, N-1) {
      r -= comb(N, n) * go(n, M, P);
      if(r < 0) {
        r = (((-r) / modulo + 1) * modulo + r) % modulo;
      }
    }

    memo[N] = r;
    return r;
  }
  
  int power(int b, int e)
  {
    int r = 1;
    TIMES(k, e) {
      r = (r * b) % modulo;
    }
    return r;
  }

  int gcd(int a, int b)
  {
    if(a > b) swap(a, b);
    if(a == 0 || a == b) return b;
    return gcd(b % a, a);
  }
  
  ll comb(int n, int k)
  {
    vector<int> num;
    vector<int> den;

    UPTO(m, 1, k) {
      num.push_back(n + 1 - m);
      den.push_back(m);
    }

    TIMES(i, den.size()) {
      while(den[i] != 1) {
        TIMES(j, num.size()) {
          int g = gcd(num[j], den[i]);
          num[j] /= g;
          den[i] /= g;
        }
      }
    }
    
    ll r = 1;
    TIMES(j, num.size()) {
      r = (r * num[j]) % modulo;
    }
    return r;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Michael loves listening to music from his cell phone while travelling by train. He currently has N songs in his cell phone. During one trip he has the time to listen to P songs. So his cell phone creates a playlist of P (not necessarily different) songs according to the following rules:

Each song has to be played at least once.
At least M songs have to be played between any two occurrences of the same song. (This ensures that the playlist is not playing the same song too often.)

Michael wonders how many different playlists his cell phone can create. You are given the ints N, M, and P. Let X be the number of valid playlists. Since X can be too large, your method must compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:NoRepeatPlaylist
Method:numPlaylists
Parameters:int, int, int
Returns:int
Method signature:int numPlaylists(int N, int M, int P)


NOTES
-Two playlists A and B are different if for some i between 1 and P, inclusive, the i-th song in A is different from the i-th song in B.


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 0 and N, inclusive.
-P will be between N and 100, inclusive.


EXAMPLES

0)
1
0
3

Returns: 1

You have only 1 song which can be played as often as you want. 
So the only valid playlist is: {song1, song1, song1}.

1)
1
1
3

Returns: 0

Now is the same scenario as in Example 0, but the song cannot be played 2 times in a row. 
Thus there is no valid playlist.

2)
2
0
3

Returns: 6

Now you have 2 songs and you can play them as often as you want. 
Just remember that playlists {song1, song1, song1} and {song2, song2, song2} are not valid, because each song must be played at least once.

3)
4
0
4

Returns: 24

You have time to play each song exactly once. So there are 4! possible playlists.

4)
2
1
4

Returns: 2

The only two possibilities are {song1, song2, song1, song2} and {song2, song1, song2, song1}.

5)
50
5
100

Returns: 222288991



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(0, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 4; int Arg3 = 24; verify_case(3, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(4, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 5; int Arg2 = 100; int Arg3 = 222288991; verify_case(5, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  NoRepeatPlaylist test;

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
