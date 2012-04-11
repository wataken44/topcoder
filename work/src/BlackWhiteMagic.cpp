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

class BlackWhiteMagic {

 public:
  int count(string creatures)
  {
    int n = creatures.size();
    int wc = 0;

    TIMES(i, n) {
      if(creatures[i] == 'W') ++wc;
    }

    int result = 0;
    // -- main code --

    TIMES(i, wc) {
      if(creatures[i] == 'B') ++result;
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Powerful sorceress Camomile has N magical creatures sitting in cages in a row. Each creature is either black or white. Cages are conveniently numbered from 1 to N. Camomile's dark twin sister Romashka has shuffled these creatures. Their order after they have been shuffled is given in the string creatures, where the i-th (1-based) character is 'B' if the creature in cage i is black and 'W' if it is white.

Now Camomile wants to put the creatures back in order. The creatures are considered to be in order if the white creatures all sit in cages with numbers from 1 to W, where W is the total number of white creatures, and the black creatures all sit in cages with numbers from W+1 to N. To achieve the necessary order, Camomile can use N different spells, also numbered from 1 to N. The spell with number i can swap creatures from two cages if the distance between those cages is exactly equal to i. The distance between cages with numbers a and b is calculated as |a - b|. She can use each spell at most once and each spell can swap only one pair of creatures. 

Return the minimum number of spells that she needs to use in order to put creatures back in order. If it is impossible, return -1.

DEFINITION
Class:BlackWhiteMagic
Method:count
Parameters:string
Returns:int
Method signature:int count(string creatures)


CONSTRAINTS
-creatures will contain between 1 and 50 characters, inclusive.
-Each character in creatures will be either 'B' or 'W'.


EXAMPLES

0)
"WBBW"

Returns: 1

By using the second spell and swapping the creatures in the second and last cages we will obtain the required order: "WWBB".

1)
"WWWWBBBB"

Returns: 0

Here all creatures are already in the required order, so no spells are needed.

2)
"BBWW"

Returns: 2

One possible way is to start with swapping the first and third creatures:
BBWW -> [spell 2 on creatures 1 and 3] -> WBBW
WBBW -> [spell 1 on creatures 1 and 2] -> BWBW 
BWBW -> [spell 3 on creatures 1 and 4] -> WWBB
However, a better solution can be obtained if you start with swapping the second and third creatures:
BBWW -> [spell 1 on creatures 2 and 3] -> BWBW
BWBW -> [spell 3 on creatures 1 and 4] -> WWBB 


3)
"BWWWWWWWBBBBBBBW"

Returns: 1



4)
"WBWBWBWBWWBWBWBWBBBWBW"

Returns: 5



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WBBW"; int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "WWWWBBBB"; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "BBWW"; int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "BWWWWWWWBBBBBBBW"; int Arg1 = 1; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "WBWBWBWBWWBWBWBWBBBWBW"; int Arg1 = 5; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BlackWhiteMagic test;

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
