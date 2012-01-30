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

class SRMIntermissionPhase {

 public:
  int countWays(vector <int> points, vector <string> description)
  {
    const int modulo = 1000000007;
    
    // -- main code --

    int sz = description.size();
    
    vector<int> maxp(sz, 0);
    vector<int> minp(sz, 0);

    TIMES(i, sz) {
      TIMES(k, sz) {
        if(description[i][k] == 'Y') {
          maxp[i] += points[k];
          minp[i] += 1;
        }
      }
    }

    FOR(i, 1, sz) {
      maxp[i] = min(maxp[i], maxp[i-1] - 1);
      if(maxp[i] < 0) return 0;
    }
    
    DOWNTO(i, sz - 2, 0) {
      if(minp[i] == 0) return 0;
      minp[i] = max(minp[i], minp[i + 1] + 1);
    }

    vector< vector<int> > dp(points[2] + 2, vector<int>(sz, 0));

    DUMP(minp);
    DUMP(maxp);
    
    UPTO(pt, minp[sz - 1], maxp[sz - 1]) {
      dp[pt][sz - 1] = 1;
    }

    DUMP(dp);

    vector< int > tmp(points[2] + 2);
    DOWNTO(i, sz - 2, 0) {
      FOR(pt, 0, maxp[i]) {
        tmp[pt] = 0;
      }

      //DUMP(i);
      //DUMP(minp[i]);
      UPTO(pt, 0, minp[i]) {
        dp[ minp[i] ][i] = (dp[ minp[i] ][i] + dp[pt][i + 1]) % modulo;
        if(pt > 0) {
          //DUMP(pt - 1);
          //DUMP(i + 1);
          //DUMP(dp[pt - 1][i + 1]);
          tmp[pt] = (tmp[pt - 1] + dp[pt - 1][i + 1]) % modulo;
        }
      }

      //DUMP(tmp);
      //DUMP(dp);
      UPTO(pt, minp[i] + 1, maxp[i]) {
        dp[ pt ][i] = (dp[pt-1][i] + tmp[pt-1]) % modulo;
      }
      //DUMP(dp);
    }

    //DUMP(dp);
    
    return dp[maxp[0]][0];
  }

// BEGIN CUT HERE
  void debug()
  {
    int Arr0[] = {4,5,6};
    vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    string Arr1[] = {"YNN",
 "NNN"};
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 25000;
    verify_case(0, Arg2, countWays(Arg0, Arg1));
  }
/*
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!

The coding phase is over, and you are now in the intermission phase of the contest. There were 3 problems in the contest. The i-th problem is worth between 1 and points[i] points, inclusive, depending on when a solution to the problem was submitted. The total score of a coder is the total points of all problems whose solutions were submitted by the coder.

The contest has a room summary containing a scoreboard of all coders in the contest. The coders in the scoreboard are sorted in decreasing order of their total score. For each coder, the scoreboard shows the points of each problem, or 0 if the coder didn't submit a solution to the problem.

Unfortunately, you lose your internet connection in this intermission phase. So, you ask your friend how the scoreboard is currently like. However, your friend only tells you the solutions submitted by each coder. This is given in description. The j-th character of the i-th element of description will be 'Y' if the i-th coder submitted a solution to the j-th problem, or 'N' otherwise. description describes the scoreboard from top to bottom, i.e., description[0] describes the coder with the highest score, description[1] (if any) describes the coder with the second highest score, and so on. Moreover, your friend also tells you that all coders have different total scores.

Return the number of different possible scoreboards that match your friend's description, modulo 1,000,000,007. Your friend's description may be inaccurate, so, if no scoreboards match it, return 0.

DEFINITION
Class:SRMIntermissionPhase
Method:countWays
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int countWays(vector <int> points, vector <string> description)


CONSTRAINTS
-points will contain exactly 3 elements.
-points[0] will be between 25000 and 30000, inclusive.
-points[1] will be between 45000 and 60000, inclusive.
-points[2] will be between 90000 and 110000, inclusive.
-description will contain between 1 and 20 elements, inclusive.
-Each element of description will contain exactly 3 characters.
-Each character in description will be 'Y' or 'N'.


EXAMPLES

0)
{25000, 50000, 100000}
{"YNN",
 "NNN"}

Returns: 25000

The first coder's total score can be between 1 and 25000, inclusive (25000 ways). The second coder's total score must be 0 (1 way). So, in total there are 25000 x 1 = 25000 different possible scoreboards.

1)
{30000, 60000, 90000}
{"NYN",
 "NYN"}

Returns: 799969993

If the first coder's total score is 2, then the second coder's total score must be 1. If the first coder's total score is 3, then the second coder's total score can be 1 or 2. If the first coder's total score is 4, then the second coder's total score can be 1, 2, or 3, and so on. So, there are (1 + 2 + 3 + ... + 59999) mod 1000000007 = 799969993 different possible scoreboards.

2)
{25000, 45000, 110000}
{"NNN",
 "YYY"}

Returns: 0

The first coder didn't submit anything, but ranked above the second coder who submitted all three problems. It is impossible.

3)
{25600, 51200, 102400}
{"NYY",
 "YNY",
 "YYY",
 "YNN",
 "YYN",
 "NNY",
 "NYN",
 "NNN"}

Returns: 867560805



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25000, 50000, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25000; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {30000, 60000, 90000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 799969993; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {25000, 45000, 110000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25600, 51200, 102400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY",
 "YNY",
 "YYY",
 "YNN",
 "YYN",
 "NNY",
 "NYN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 867560805; verify_case(3, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SRMIntermissionPhase test;

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
