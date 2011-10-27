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

class FoxSequence {

 public:
  string isValid(vector <int> seq)
  {
    // -- main code --

    int sz = seq.size();
    if(seq.size() == 1) return "NO";
    

    int ptr = 0;

    {
      int d = seq[ptr + 1] - seq[ptr];
      if(d <= 0) return "NO";

      while(ptr + 1 < sz) {
        if(seq[ptr + 1] - seq[ptr] != d) break;
        ++ptr;
      }

      if(ptr == sz - 1) return "NO";
    }
    {
      int d = seq[ptr + 1] - seq[ptr];
      if(d >= 0) return "NO";

      while(ptr + 1 < sz) {
        if(seq[ptr + 1] - seq[ptr] != d) break;
        ++ptr;
      }
      if(ptr == sz - 1) return "NO";
    }
    {
      int d = seq[ptr + 1] - seq[ptr];
      // if(d != 0) return "NO";
      if(d == 0) {
        while(ptr + 1 < sz) {
          if(seq[ptr + 1] - seq[ptr] != d) break;
          ++ptr;
        }
        if(ptr == sz - 1) return "NO";
      }
    }
    {
      int d = seq[ptr + 1] - seq[ptr];
      if(d <= 0) return "NO";

      while(ptr + 1 < sz) {
        if(seq[ptr + 1] - seq[ptr] != d) break;
        ++ptr;
      }
      if(ptr == sz - 1) return "NO";
    }
    {
      int d = seq[ptr + 1] - seq[ptr];
      if(d >= 0) return "NO";

      while(ptr + 1 < sz) {
        if(seq[ptr + 1] - seq[ptr] != d) break;
        ++ptr;
      }
      // if(ptr == sz - 1) return "NO";
    }

    return ptr == sz - 1 ? "YES" : "NO";	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Fox Ciel likes sequences.  One day, she invented a new type of sequence and named it the fox sequence.  A sequence seq containing N elements is called a fox sequence if and only if there exist four integers a, b, c and d such that 0 < a < b <= c < d < N-1 and the following five conditions are met:

seq[0], seq[1], ... , seq[a] forms an arithmetic progression with a positive common difference.  An arithmetic progression is a sequence where the difference between successive elements is equal.  The difference between successive elements is called the common difference.  Note that 0 is neither positive nor negative.
seq[a], seq[a+1], ... , seq[b] forms an arithmetic progression with a negative common difference.
seq[b], seq[b+1], ... , seq[c] are all equal.
seq[c], seq[c+1], ... , seq[d] forms an arithmetic progression with a positive common difference.
seq[d], seq[d+1], ... , seq[N-1] forms an arithmetic progression with a negative common difference.


In the following image, the top 3 sequences are fox sequences, while the bottom 3 sequences are not:



You are given a sequence seq.  Return "YES" if it is a fox sequence, or "NO" if it is not (all quotes for clarity).

DEFINITION
Class:FoxSequence
Method:isValid
Parameters:vector <int>
Returns:string
Method signature:string isValid(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 2,000, inclusive.


EXAMPLES

0)
{1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}


Returns: "YES"

This is the top-left sequence of the image shown in the statement.  The next five examples are also from that image.

1)
{1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}


Returns: "YES"



2)
{3,6,9,1,9,5,1}


Returns: "YES"



3)
{1,2,3,2,1,2,3,2,1,2,3,2,1}


Returns: "NO"



4)
{1,3,4,3,1,1,1,1,3,4,3,1}


Returns: "NO"



5)
{6,1,6}


Returns: "NO"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxSequence test;

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
