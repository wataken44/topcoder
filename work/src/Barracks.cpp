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

class Barracks {

 public:
  int attack(int myUnits, int barHp, int unitsPerRound)
  {
    int result = 0;
    // -- main code --

    int hisUnits = 0;
    
    while(true) {
      ++result;

      if(myUnits >= hisUnits) {
        myUnits -= hisUnits;
        hisUnits = 0;
        barHp = max(0, barHp - myUnits);
      } else {
        return -1;
      }

      if(barHp > 0) {
        hisUnits += unitsPerRound;
      }
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// As a serious strategy-games player, you decided to solve one of the most common problems - attacking your
opponent's building (barracks), which constantly produces new soldiers.

Before the attack, you've got myUnits soldiers. In a single round, each soldier can either kill one of your opponent's soldiers or inflict 1 hit point of damage to the barracks.

Your opponent doesn't have any soldiers initially.  However, his barracks has barHp hit points and produces unitsPerRound soldiers per round.

The course of one round:
1. Each solider from your army either kills one of your opponent's soldiers or inflicts 1 hit point of damage to the barracks.  Each soldier can choose to do something different.  When the barracks loses all of its hit points, it is destroyed. 
2. Your opponent attacks. He will kill k of your soldiers, where k is the number of remaining soldiers he has.
3. If the barracks are not yet destroyed, your opponent will produce unitsPerRound new soldiers.

Your task is to destroy the barracks and kill all your opponent's soldiers. If it is possible, return the minimum number of rounds you need to do this.
Otherwise return -1.



DEFINITION
Class:Barracks
Method:attack
Parameters:int, int, int
Returns:int
Method signature:int attack(int myUnits, int barHp, int unitsPerRound)


CONSTRAINTS
-myUnits, barHp, unitsPerRound will each be between 1 and 5000, inclusive.


EXAMPLES

0)
10
11
15

Returns: 4

Round 1:
- All your soldiers attack the barracks, leaving it with 1 hit point.
- Your opponent has no soldiers, so he cannot kill any of your soldiers.
- Your opponent's army increases from 0 soldiers to 15 soldiers.

Round 2:
- One of your soldiers destroys the barracks. The other nine kill 9 of your opponent's soldiers.
- Your opponent has 6 soldiers, so he kills 6 of your soldiers.
- The barracks have been destroyed, so no new soldiers are produced.

Round 3:
- You have got 4 soldiers, so you decrease your opponent's army to 2 soldiers.
- Your opponent kills 2 of your soldiers.
- The barracks have been destroyed, so no new soldiers are produced.

Round 4:
- You kill 2 remaining soldiers. 

1)
1
2
1

Returns: -1



2)
1
1
1

Returns: 1



3)
25
200
10

Returns: 13



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 15; int Arg3 = 4; verify_case(0, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = -1; verify_case(1, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = 200; int Arg2 = 10; int Arg3 = 13; verify_case(3, Arg3, attack(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Barracks test;

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
