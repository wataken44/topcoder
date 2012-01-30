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

class LuckyRemainder {

 public:
  int getLuckyRemainder(string X)
  {
    // -- main code --

    vector<int> num(X.size(), 0);

    int sum = 0;
    TIMES(i, X.size()) {
      num[i] = X[i] - '0';
      sum = (sum + num[i]) % 9;
    }

    //DUMP(X);
    //DUMP(num);
    //DUMP(X.size());
    
    int ret = 0;
    UPTO(i, 0, X.size() - 1) {
      //DUMP(i);
      //DUMP(comp(X.size(), i));
      ret = (ret + sum * comp(X.size() - 1, i)) % 9;
    }
    
    return ret % 9;	
  }

  int comp(int n, int k) {
    if(k == 0) return 1;
    int c = 1;

    UPTO(i, 1, k) {
      c = c * (n - i + 1) / i; 
    }
    return c;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Little Arthur loves numbers and 9 is his most favorite. When encountering a number, he always calculates its lucky remainder - the remainder after division by 9. 

This time Arthur is given a number X of length N which contains no zeros. He is asked to find the supersum of X: super(X).

super(X) is defined as follows. For a given non-full set S of digit positions in X we erase the digits in these positions to obtain a sub-number. For example, if X = 12345 and S = {2, 4} we erase 2nd and 4th digits and obtain a sub-number 135. Supersum of X is simply the sum of sub-numbers for all valid sets S.

For example, if X is 123, then super(X) = 123 + 12 + 13 + 23 + 1 + 2 + 3 = 177.

Calculating super(X) is very difficult for Arthur. However, before getting to work he is wondering if it is possible to quickly tell what the lucky reminder of the supersum of X is. You have to help him.

Given string X, which contains the decimal representation of the number X, return super(X)'s lucky remainder.

DEFINITION
Class:LuckyRemainder
Method:getLuckyRemainder
Parameters:string
Returns:int
Method signature:int getLuckyRemainder(string X)


CONSTRAINTS
-X will contain between 1 and 50 characters, inclusive.
-Each character of X will be one of the following: '1', '2', '3', '4', '5', '6', '7', '8', '9'.


EXAMPLES

0)
"123"

Returns: 6

Example?from?the?problem?statement.?super(123)?=?177,?which?gives?remainder?6?after?division?by?9.

1)
"24816"

Returns: 3

Supersum of 24816 is 43986.

2)
"8"

Returns: 8



3)
"11235813213455"

Returns: 7

Supersum is 43950094900477.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; int Arg1 = 6; verify_case(0, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_1() { string Arg0 = "24816"; int Arg1 = 3; verify_case(1, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_2() { string Arg0 = "8"; int Arg1 = 8; verify_case(2, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_3() { string Arg0 = "11235813213455"; int Arg1 = 7; verify_case(3, Arg1, getLuckyRemainder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  LuckyRemainder test;

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
