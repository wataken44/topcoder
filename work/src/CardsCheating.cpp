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

class CardsCheating {

 public:
  int numberOfShuffles(vector <int> cards, vector <int> shuffle)
  {
    int sz = cards.size();

    vector<int> cur(sz, 0);
    vector<int> tmp(sz, 0);
    FOR(i, 0, sz) cur[i] = i;

    int c = 0;
    
    while(true) {
      bool ok = true;
      FOR(i, 0, sz) {
        if(i % 3 != cards[cur[i]]) {
          ok = false;
        }
      }
      if(ok) {
        //DUMP(cur);
        //DUMP(cards);
        return c;
      }
      ++c;
      
      // perform shuffle

      FOR(i, 0, sz) {
        tmp[shuffle[i]] = cur[i];
      }
      FOR(i, 0, sz) {
        cur[i] = tmp[i];
      }

      bool last = true;
      FOR(i, 0, sz) {
        if(cur[i] != i) {
          last = false;
          break;
        }
      }
      if(last) break;
    }
    
    return -1;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are a dealer in some card game for 3 players (numbered 0, 1, 2). The game uses a deck of N cards, numbered 0 to N-1. First you perform a few shuffles of the deck and then give cards to the players. The card at position 0 goes to player 0, the card at position 1 goes to player 1, the card at position 2 goes to player 2, the card at position 3 goes to player 0, and so on. But you want to cheat. You know the initial order of the cards in the deck, and you want each card to go to a specific player.  You want to know the minimal number of shuffles required to give the cards to the desired players. You can only perform the shuffle given in the vector <int> shuffle.  After performing one shuffle, the card that was at position i in the deck will be at position shuffle[i].  You want the card that's initially at position i in the deck to go to player cards[i]. Return the minimal number of shuffles needed to achieve the goal or -1 if it is impossible.

DEFINITION
Class:CardsCheating
Method:numberOfShuffles
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int numberOfShuffles(vector <int> cards, vector <int> shuffle)


CONSTRAINTS
-cards will contain between 3 and 48 elements, inclusive. 
-Each element of cards will be 0, 1 or 2. 
-The number of elements in cards will be a multiple of 3. 
-shuffle and cards will contain the same number of elements. 
-All elements in shuffle will be distinct. 
-Each element of shuffle will be between 0 and N-1, inclusive, where N is the number of elements in  shuffle..


EXAMPLES

0)
{0,1,2,0,1,2}
{1,4,0,3,2,5}

Returns: 0

No shuffles are needed.

1)
{2,0,1}
{1,2,0}

Returns: 2

Shuffle the deck two times.

2)
{1,1,2,0,2,0,1,0,2,2,1,0}
{5,0,9,7,1,8,3,10,4,11,6,2}

Returns: 59

3)
{1,0,2}
{0,2,1}

Returns: -1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,0,3,2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, numberOfShuffles(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfShuffles(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,2,0,2,0,1,0,2,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,0,9,7,1,8,3,10,4,11,6,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; verify_case(2, Arg2, numberOfShuffles(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, numberOfShuffles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  CardsCheating test;

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
