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

class FIELDDiagrams {

 public:
  long long countDiagrams(int fieldOrder)
  {
    typedef long long ll;
    // -- main code --

    int sz = fieldOrder + 1;
    vector< vector< ll > > dp(sz, vector<ll>(sz, 0));

    UPTO(i, 0, fieldOrder) {
      dp[fieldOrder - 1][i] = 1;
    }

    DUMP(dp);

    DOWNTO(x, fieldOrder - 2, 0) {
      UPTO(y, 0, x + 1) {
        UPTO(z, y, x + 2) {
          dp[x][y] += dp[x + 1][z];
        }
      }
    }
    
    DUMP(dp);
    
    return dp[0][0] + dp[0][1] - 1;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A Ferrers diagram of the partition of positive number n = a1 + a2 + ... + ak, for a list a1, a2, ..., ak of k positive integers with a1 ³ a2 ³ ... ³ ak is an arrangement of n boxes in k rows, such that the boxes are left-justified, the first row is of length a1, the second row is of length a2, and so on, with the kth row of length ak. Let's call a FIELD diagram of order fieldOrder a Ferrers diagram with a1 ² fieldOrder, a2 ² fieldOrder - 1, ..., ak ² fieldOrder - k + 1, so a FIELD diagram can have a number of rows which is less than or equal to fieldOrder. Your method will be given fieldOrder, it should return the total number of FIELD diagrams of order fieldOrder. 

DEFINITION
Class:FIELDDiagrams
Method:countDiagrams
Parameters:int
Returns:long long
Method signature:long long countDiagrams(int fieldOrder)


CONSTRAINTS
-fieldOrder will be between 1 and 30, inclusive


EXAMPLES

0)
2

Returns: 4

There are four possible FIELD diagrams for fieldOrder equal to 2, corresponding to partitions: (1), (2), (1, 1), (2,1). They are shown in the picture below. There white stands for unused space in a row and red for boxes, corresponding to FIELD diagrams. 



1)
3

Returns: 13

2)
5

Returns: 131

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; verify_case(0, Arg1, countDiagrams(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 13LL; verify_case(1, Arg1, countDiagrams(Arg0)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 131LL; verify_case(2, Arg1, countDiagrams(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FIELDDiagrams test;

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
