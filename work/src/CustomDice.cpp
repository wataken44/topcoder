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

class CustomDice {

 public:
  typedef long long ll;
  static const ll modulo = 1000000007;

  map< pair<int, int>, ll > memo;

  int part(int n, int r)
  {
    pair<int, int> key = make_pair(n, r);
    if(memo.find(key) != memo.end()) return memo[key];

    if(n < r) return 0;
    if(r == n || r == 1) return 1;
    
    memo[key] = (part(n-r,r) % modulo + part(n-1, r-1)%modulo) % modulo ;
    return memo[key];
  }
  
  int countDice(int M)
  {
    memo.clear();
    
    if(M <= 3) return 0;

    int result = 0;

    UPTO(s, 21, M*6) {
      result = (result + part(s, 6)) % modulo; 
      //DUMP(result);
    }

    DUMP(memo);
    
    return (result * 30) % modulo;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
In a Las Vegas casino, a new type of six-sided die is being introduced. These dice may have any positive integers written its sides, but no two sides of the same die can contain the same number. For each die, the casino owner wants the mean value of the numbers written on its sides to not exceed M.



Compute the total number of allowed dice. Two dice are considered different if one can't be obtained from the other using rotations. Since the resulting number may be quite large, return it modulo 1000000007.


DEFINITION
Class:CustomDice
Method:countDice
Parameters:int
Returns:int
Method signature:int countDice(int M)


CONSTRAINTS
-M will be between 1 and 1000000, inclusive.


EXAMPLES

0)
3

Returns: 0

The die with the smallest possible mean is {1,2,3,4,5,6}.  Its mean is 3.5, which is greater than M=3.

1)
4

Returns: 210

There are 30 different dice with numbers {1,2,3,4,5,6} on their sides, they each have a mean of 3.5.
There are 30 different dice with numbers {1,2,3,4,5,7} on their sides, they each have a mean of 22/6=3.(6).
There are 60 different dice with {1,2,3,4,5,8} or {1,2,3,4,6,7} on their sides, they each have a mean of 23/6=3.8(3).
There are 90 different dice with {1,2,3,4,5,9}, {1,2,3,4,6,8} or {1,2,3,5,6,7} on their sides, they each have a mean of 24/6=4.

2)
10

Returns: 863010



3)
50

Returns: 375588112



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; verify_case(0, Arg1, countDice(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 210; verify_case(1, Arg1, countDice(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 863010; verify_case(2, Arg1, countDice(Arg0)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 375588112; verify_case(3, Arg1, countDice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  CustomDice test;

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
