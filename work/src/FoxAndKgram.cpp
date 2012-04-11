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

class FoxAndKgram {

 public:
  int maxK(vector <int> len)
  {
    int result = 0;
    // -- main code --

    vector<int> pen(10000, 0);

    int sum = 0;
    
    TIMES(i, len.size()) {
      ++pen[len[i]];
      sum += len[i];
    }

    UPTO(k, 1, sum) {
      int count = k;

      count -= pen[k];
      if(count <= 0) {
        result = max(result, k);
        continue;
      }

      FOR(i, 1, k) {
        int l = i;
        int r = k - i - 1;
        
        if(r <= 0 || l > r) continue;

        int t = 0;
        t = l == r ? (pen[r] / 2) : min(pen[l], pen[r]);

        count -= t;
        if(count <= 0) {
          result = max(result, k);
          continue;
        }
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
// Fox Ciel has some pencils.
Before she'll start writing her homework, she wants to place them into a mystic pattern for fun.
Different pencils she has may have different lengths.
You are given a vector <int> len. For each i, the length of i-th pencil is len[i]



The pattern she wants to create is called a k-gram.
A k-gram is a pattern consisting of k rows, each of length k.
There are only two types of valid rows:

Yang: A row containing a single pencil of length k.
Yin: A row containing two pencils such that the sum of their lengths is (k-1). The pencils will be separated by a space of length 1.




Compute and return the largest positive integer k such that Fox Ciel can use some of her pencils to form a k-gram.
If she is unable to form any k-grams, return 0 instead.

DEFINITION
Class:FoxAndKgram
Method:maxK
Parameters:vector <int>
Returns:int
Method signature:int maxK(vector <int> len)


CONSTRAINTS
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,1,1,1,3}

Returns: 3

All pencils can be used to form a 3-gram. One valid 3-gram follows:

- -
---
- -


1)
{2,2,1,3,5,5,5}

Returns: 5

One of the valid 5-grams:

-----
-- --
- ---
-----
-----


2)
{1}

Returns: 1



3)
{2,2,2,2,2,2,2,2,2,2}

Returns: 5



4)
{1,2,3,1,2,4,2,3,1}

Returns: 4

Note that it is not necessary to use all of the pencils.

5)
{2,3,5,7,11,13,17,19,23,29}

Returns: 0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maxK(Arg0)); }
	void test_case_1() { int Arr0[] = {2,2,1,3,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, maxK(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxK(Arg0)); }
	void test_case_3() { int Arr0[] = {2,2,2,2,2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maxK(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,1,2,4,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, maxK(Arg0)); }
	void test_case_5() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, maxK(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxAndKgram test;

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
