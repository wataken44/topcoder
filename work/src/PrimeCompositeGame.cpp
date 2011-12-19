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

class PrimeCompositeGame {

  vector<bool> m_sieve;

  void init(int n)
  {
    m_sieve.clear();
    m_sieve = vector<bool>(n + 1, true);

    m_sieve[0] = false;
    m_sieve[1] = false;
    
    for(int i = 2; i * i <= n; ++i) {
      if(!m_sieve[i]) continue;
      for(int j = 2; j * i <= n; ++j) {
        m_sieve[i * j] = false;
      }
    }
  }

  bool isPrime(int n) const
  {
    if(n <= 1) return false;
    return m_sieve[n];
  }

  bool isComposite(int n) const
  {
    if(n <= 1) return false;
    return !m_sieve[n];
  }
  
 public:
  int theOutcome(int N, int K)
  {
    init(N);

    int n = N;
    int t = 0;

    map<int, int> comp;
    comp[2] = 0;
    comp[3] = 0;

    bool iwin = true;
    
    int p = 3;
    UPTO(i, 4, N) {
      if(isPrime(i)) {
        comp[i] = i - p - 1;
        p = i;

        if(comp[i] >= K) {
          iwin = false;
        }
      }
    }

    //DUMP(comp);
    
    while(n > 0) {
      if(iwin) {
        bool lose_i = true;
        DOWNTO(k, min(n-1, K), 1) {
          if(isPrime(n - k)) {
            lose_i = false;
            n -= k;
            ++t;
            break;
          }
        }
        if(lose_i) {
          return -t;
        }
        if(n == 2 || n == 3) {
          return t;
        }
      } else {
        bool lose_i = true;
        UPTO(k, 1, min(n-1, K) ) {
          if(isPrime(n - k)) {
            lose_i = false;
            n -= k;
            ++t;
            break; 
          }
        }
        if(lose_i) {
          return -t;
        }
      }
      if(!iwin) {
        bool win_next = false;

        //DUMP(n);
        EACH(comp, it) {
          int p = it->first;
          int c = it->second;

          //DUMP(p); DUMP(c); DUMP(K); DUMP(n-K); DUMP(p-1);
          if(c > K && n - K <= p - 1 && p - 1 < n) {
            win_next = true;
            break;
          }
        }

        if(win_next) {
          ++t;
          return -t;
        } else {
          DOWNTO(k, min(n - 1, K), 1) {
            if(isComposite(n - k)) {
              n -= k;
              ++t;
              break;
            }
          }
        }
      } else {
        bool lose_d = true;
        UPTO(k, 1, min(n-1, K)) {
          if(isComposite(n - k)) {
            n -= k;
            ++t;
            lose_d = false;
            break;
          }
        }
        if(lose_d) {
          return t;
        }
      }
    }
    
    cout << "never reach" << endl;
    return INT_MAX;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You and Mr. Dengklek are playing a game called Prime-Composite Game.

Initially, there is a pile consisting of N stones. You and Mr. Dengklek take alternating turns, starting from you. In your turn, you must remove at least 1 and at most K stones from the pile. Additionally, after your move the number of stones in the pile must be a prime number. In Mr. Dengklek's turn, he must remove at least 1 and at most K stones from the pile. Additionally, after his move the number of stones in the pile must be a composite number. The first player who cannot make a valid move loses the game.

You and Mr. Dengklek both play the game optimally. Optimal play is defined as follows: Clearly, one of the players has a strategy that will guarantee him winning the game. If at any turn this player has multiple moves to choose from, he always chooses the one that minimizes the number of turns the game will take. The other player always chooses the move that will maximize the number of turns the game will take. Each player is following these rules and each player knows that the other player is also following these rules.

You are given the ints N and K. Determine the outcome of the game. Let X be the number of turns in the game. If you win, return X, otherwise return -X.

DEFINITION
Class:PrimeCompositeGame
Method:theOutcome
Parameters:int, int
Returns:int
Method signature:int theOutcome(int N, int K)


NOTES
-A prime number is a positive number that has exactly two distinct divisors. A composite number is a positive number that has more than two distinct divisors. By definition, 1 is neither prime nor composite.


CONSTRAINTS
-N will be between 1 and 474,747, inclusive.
-K will be between 1 and N, inclusive.


EXAMPLES

0)
3
2

Returns: 1

Take a single stone in your first turn, leaving two stones. This ends the game, as Mr. Dengklek now has no valid move.

1)
58
1

Returns: 0

The game is already over and you lost, as you have no valid move to make. (The only option is to take a single stone, but 57 is not a prime number.)

2)
30
3

Returns: -2

The game will proceed as follows:

You will take 1 stone, leaving 29 stones.
Mr. Dengklek will take 1 or 2 stones, leaving 28 or 27 stones. In either case, you cannot leave a prime number of stones in your next turn, therefore, you will surely lose.


3)
6
3

Returns: 1

Taking 1 stone in your first turn would guarantee you to win after your next turn. However, it is better to take 3 stones and win right now.

4)
526
58

Returns: 19



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 58; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 3; int Arg2 = -2; verify_case(2, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1; verify_case(3, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 526; int Arg1 = 58; int Arg2 = 19; verify_case(4, Arg2, theOutcome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PrimeCompositeGame test;

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
