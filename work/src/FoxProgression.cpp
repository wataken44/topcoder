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

class FoxProgression {

 public:
  int theCount(vector <int> seq)
  {
    if(static_cast<int>(seq.size()) == 1) return -1;

    // -- main code --
    int result = 0;

    // arith
    bool aok = true;
    int d = seq[1] - seq[0];
    
    FOR(i, 0, seq.size() - 1) {
      if(d != seq[i+1] - seq[i]) {
        aok = false;
        break;
      }
    }
    if(aok) ++result;
    
    // geo
    if(seq[0] <= seq[1] && seq[1] % seq[0] == 0) {
      bool gok = true;
      FOR(i, 0, seq.size() - 1) {
        if(seq[i+1] * seq[0] != seq[i] * seq[1]) {
          gok = false;
          break;
        }
      }
      if(gok) {
        if(aok && (seq.back() + d) * seq[0] == seq.back() * seq[1] ) {
        }else {
          ++result;
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
// Fox Ciel likes sequences of integers. She especially likes sequences that are either an arithmetic progression of integers or a geometric progression of integers with an integer common ratio. She calls these beautiful sequences. An arithmetic progression is a sequence of numbers such that the difference of any two consecutive numbers of the sequence is a constant. A geometric progression is a sequence of numbers where each number after the first is found by multiplying the previous one by a constant non-zero number which is called the common ratio.

Ciel has a sequence of integers. She says that an integer is good if she can obtain a beautiful sequence by appending the integer to the end of the sequence. You are given a vector <int> seq. Calculate the number of good integers for the given sequence. If there are infinitely many good integers, return -1.

DEFINITION
Class:FoxProgression
Method:theCount
Parameters:vector <int>
Returns:int
Method signature:int theCount(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 500, inclusive.


EXAMPLES

0)
{1, 2, 4, 8}

Returns: 1

This sequence can become a geometric progression with ratio 2 if you append 16.

1)
{5, 3, 1}

Returns: 1

This sequence can become an arithmetic progression with difference -2 if you append -1. Note that neither the difference/ratio nor the appended integer has to be strictly positive.

2)
{1, 1}

Returns: 1

If you append 1, this sequence becomes a geometric progression (with ratio 1) and an arithmetic progression (with ratio 0) simultaneously. Despite the two reasons to call the resulted sequence "beautiful", there is still only one good integer.

3)
{8, 4}

Returns: 1

This sequence can become an arithmetic progression if you append 0. It can also become a geometric progression with ratio 0.5 if you append 2, but progressions with non-integer ratio are not beautiful.

4)
{1}

Returns: -1

Every integer is good for the given sequence.

5)
{4, 8}

Returns: 2

There are two good integers: appending 12 turns this sequence into an arithmetic progression with difference 4, and appending 16 turns it into a geometric progression with ratio 2.

6)
{1, 3, 4}

Returns: 0

This sequence is already neither an arithmetic nor a geometric progression, so nothing that you append can fix it.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, theCount(Arg0)); }
	void test_case_5() { int Arr0[] = {4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, theCount(Arg0)); }
	void test_case_6() { int Arr0[] = {1, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxProgression test;

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
