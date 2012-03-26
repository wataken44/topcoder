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

class KingXMagicSpells {

 public:
  double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K)
  {
    double result = 0;
    // -- main code --

    int sz = ducks.size();
    vector< vector<int> > ducksXor(sz, vector<int>(sz, 0));

    TIMES(y, sz) {
      TIMES(x, sz) {
        ducksXor[y][x] = ducks[y] ^ spellOne[x];
      }
    }

    UPTO(one, 0, K) {
      int two = K - one;
      double prob = combprob(K, two);
      DUMP(prob);

      vector<int> cur(sz, 0);
      TIMES(k, sz) {
        cur[k] = k;
      }
      TIMES(t, two) {
        vector<int> nex(cur);
        TIMES(k, sz) {
          nex[spellTwo[k]] = cur[k];
        }
        cur = nex;
      }
    }
    
    return result;	
  }

  double combprob(int n, int r)
  {
    double p = 1;
    r = min(r, n - r);

    int nn = n - r;

    TIMES(k, r) {
      p = p * 1.0 * (n - k) / (k + 1.0) / 2.0;
    }

    TIMES(k, nn) {
      p = p / 2.0;
    }
    
    return p;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.

King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.

The palace has N rooms, conveniently numbered 0 through N-1. The rooms are occupied by the ducks King Dengklek loves the most. There are ducks[i] ducks in room i.

Today, King Dengklek realized that two magic spells are affecting the palace. Being a perfect king, he quickly learned that on each day, exactly one of the two magic spells will take place with the same probability (i.e., 50%). The effects of the two magic spells are as follows:

Spell 1: For each i, let D be the number of ducks in room i right before the spell's effect takes place. The number of ducks in room i will become D XOR spellOne[i] (see the Notes section for the definition of XOR).
Spell 2: For each i, all ducks in room i will move to room spellTwo[i]. All these movements will happen simultaneously. This will permute the ducks (i.e., no two elements of spellTwo will be equal).


King Dengklek is worried about these odd magic spells. He is especially worried about room 0, because he has promised that he will grant all ducks in this room to his successor. You are given the vector <int>s ducks, spellOne, spellTwo, and the int K. Return the expected number of ducks in room 0 after the magic spells have affected the palace for K days.

DEFINITION
Class:KingXMagicSpells
Method:expectedNumber
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K)


NOTES
-The returned value must have an absolute or relative error less than 10-9.
-If a and b are single bits then a XOR b is defined as (a + b) modulo 2. For two integers, A and B, in order to calculate A XOR B, they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different, the shorter one is prepended with the necessary number of leading zeroes). Then A XOR B = C = (cn...c1)2, where ci = ai XOR bi. For example, 10 XOR 3 = (1010)2 XOR (0011)2 = (1001)2 = 9.


CONSTRAINTS
-ducks, spellOne, and spellTwo will contain the same number of elements, between 1 and 50, inclusive.
-Each element of ducks will be between 0 and 1,000,000,000, inclusive.
-Each element of spellOne will be between 0 and 1,000,000,000, inclusive.
-Each element of spellTwo will be between 0 and N-1, inclusive, where N is the number of elements in ducks.
-All elements of spellTwo will be distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
{5, 3, 7}
{1, 7, 4}
{1, 0, 2}
1

Returns: 3.5

We want to know the expected number of ducks in room 0 after K=1 day. Exactly one spell will take place. Depending on which spell takes place, there are two possible outcomes:

Spell 1: The numbers of ducks in the rooms become {5 XOR 1, 3 XOR 7, 7 XOR 4} = {4, 4, 3}.
Spell 2: The numbers of ducks in the rooms become {3, 5, 7}.

Therefore, the expected number of ducks in room 0 is (4 + 3)/2 = 3.5.

1)
{5, 8}
{53, 7}
{1, 0}
2

Returns: 21.5

There are four possible outcomes, depending on which two spells take place:

Spell 1 and then spell 1: {48, 15} and then {5, 8}.
Spell 1 and then spell 2: {48, 15} and then {15, 48}.
Spell 2 and then spell 1: {8, 5} and then {61, 2}.
Spell 2 and then spell 2: {8, 5} and then {5, 8}.

Therefore, the expected number of ducks in room 0 is (5 + 15 + 61 + 5)/4 = 21.5.

2)
{123, 456, 789, 1234, 56789}
{0, 0, 0, 0, 0}
{0, 1, 2, 3, 4}
50

Returns: 123.0

In this case, the number of ducks in each room will never change.

3)
{83291232, 3124231, 192412, 3813249, 629231, 9998989}
{58, 37, 44, 66, 72, 19}
{2, 0, 1, 5, 4, 3}
11

Returns: 2.888186784716797E7



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; double Arg4 = 3.5; verify_case(0, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {53, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 21.5; verify_case(1, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {123, 456, 789, 1234, 56789}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; double Arg4 = 123.0; verify_case(2, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 37, 44, 66, 72, 19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 1, 5, 4, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 11; double Arg4 = 2.888186784716797E7; verify_case(3, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  KingXMagicSpells test;

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
