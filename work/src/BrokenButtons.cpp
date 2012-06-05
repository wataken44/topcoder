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

class BrokenButtons {

 public:
  bool ok(int n, int b)
  {
    if(n == 0) {
      return (b & 1) == 0;
    }
    while(n > 0) {
      int k = n % 10;
      if(1 == ((b >> k) & 1)) return false;
      n /= 10;
    }
    return true;
  }

  int count(int n)
  {
    int m = 10;
    int c = 1;
    while(m <= n) {
      ++c;
      m *= 10;
    }
    return c;
  }
  
  int minPresses(int page, vector <int> broken)
  {
    // -- main code --
    int b = 0;
    TIMES(i, broken.size()) {
      b |= (1 << broken[i]);
    }

    int ret = abs(page - 100);

    bool o = ok(page, b);
    
    if(o) {
      ret = min(ret, count(page));
    }

    int c = 1;
    int u = page + 1;
 
    while(!o) {
      if(ok(u, b)) {
        ret = min(ret, count(u) + c);
        break;
      }

      ++c;
      ++u;
      if(c > ret) break;
    }

    c = 1;
    int d = max(page - 1, 0);
    while(!o) {
      if(ok(d, b)) {
        ret = min(count(d) + c, ret);
        break;
      }

      ++c;
      if(d == 0) break;
      d = max(0, d-1);
      if(c > ret) break;
    }

    return ret;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You want to see some page on the teletext (information service on TV where we refer to pages of information by numbers). Unfortunately, some of the digit buttons on the remote control are broken. But you have an idea! If you can't enter the number of the page you want to see, you could enter some other number and with the buttons '+' and '-' (which are not broken) navigate to the desired page. Button '+' increases the number by 1 and button '-' decreases the number by 1. You are initially at page 100. To go to a different page, you may enter the page number using the digit buttons that aren't broken. Then, press the '+' and '-' buttons to navigate to your desired page.

You will be given an int page, the page you want to see, and a vector <int> broken, the list of broken digit buttons.  Return the minimum number of button presses required to navigate to the page.

DEFINITION
Class:BrokenButtons
Method:minPresses
Parameters:int, vector <int>
Returns:int
Method signature:int minPresses(int page, vector <int> broken)


CONSTRAINTS
-page will be between 0 and 500,000, inclusive.
-broken will contain between 0 and 10 elements, inclusive.
-Each element of broken will be between 0 and 9, inclusive.
-All elements of broken will be distinct.


EXAMPLES

0)
5457
{ 6, 7, 8 }

Returns: 6

You can go to page 5457 either by pressing "5455++" or "5459--".

1)
100
{ 1, 0, 5 }

Returns: 0

If you don't enter anything you'll get page 100.

2)
14124
{ }

Returns: 5



3)
1
{1, 2, 3, 4, 5, 6, 7, 8, 9}

Returns: 2

We can enter page 0.

4)
80000
{ 8, 9 }

Returns: 2228



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5457; int Arr1[] = { 6, 7, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = { 1, 0, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 14124; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minPresses(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 80000; int Arr1[] = { 8, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2228; verify_case(4, Arg2, minPresses(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BrokenButtons test;

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
