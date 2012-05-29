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

class ExtraordinarilyLarge {

 public:
  string compare(string x, string y)
  {
    int xb = 0;
    int xe = 0;
    istringstream issx(x);
    issx >> xb;
    TIMES(i, x.size()) {
      if(x[i] == '!') ++xe;
    }
    if(xb == 0 && xe > 0) {
      xb = 1;
      xe = 0;
    }
    
    int yb = 0;
    int ye = 0;
    istringstream issy(y);
    issy >> yb;
    TIMES(i, y.size()) {
      if(y[i] == '!') ++ye;
    }
    if(yb == 0 && ye > 0) {
      yb = 1;
      ye = 0;
    }
 
    int me = min(xe, ye);
    xe -= me;
    ye -= me;

    if(xe + ye == 0) {
      if(xb > yb) {
        return "x>y";
      }else if(xb < yb) {
        return "x<y";
      }else {
        return "x=y";
      }
    }else if(xe == 0) {
      int c = compare(xb, yb, ye);

      if(c < 0) {
        return "x>y";
      }else if(c > 0) {
        return "x<y";
      }else {
        return "x=y";
      }
      
    }else if(ye == 0) {
      int c = compare(yb, xb, xe);

      if(c < 0) {
        return "x<y";
      }else if(c > 0) {
        return "x>y";
      }else {
        return "x=y";
      }
    }

    
    string result = "?";
    // -- main code --
    
    return result;	
  }

  int compare(int n, int b, int e)
  {
    if(e == 0) {
      return b - n;
    }

    if(largeFactorial(n, b)) return 100;

    return compare(n, factorial(b), e - 1);
  }

  bool largeFactorial(int n, int b)
  {
    long long r = 1;
    
    while(b > 1) {
      r *= b;
      --b;
      if(r > n) return true;
    }
    return false;
  }

  int factorial(int b)
  {
    int r = 1;
    UPTO(k, 1, b) {
      r *= k;
    }
    
    return r;      
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You need to handle two extraordinarily large integers. 
The good news is that you don't need to perform any arithmetic operation on them.  You just need to compare them and see whether they are equal or one is greater than the other.

Given two strings x and y, return either "x<y", "x>y" or "x=y" depending on the values represented by x and y. x and y each consist of a decimal integer followed zero or more '!' characters.  Each '!' represents the factorial operation.  For example, "3!!" represents 3!! = 6! = 720.

DEFINITION
Class:ExtraordinarilyLarge
Method:compare
Parameters:string, string
Returns:string
Method signature:string compare(string x, string y)


NOTES
-In case you don't know about factorials, here is a quick definition: 0! is defined as 1. For any positive integer n, n! is defined as n * [(n-1)!]. For example, 5! = 5 * 4 * 3 * 2 * 1 * 0! = 120.


CONSTRAINTS
-x and y will each contain between 1 and 50 characters, inclusive.
-x and y will each consist of a non-negative integer less than 109, with no extra leading zeros, followed by zero or more '!' characters.


EXAMPLES

0)
"0!"
"1"

Returns: "x=y"

1)
"9!"
"999999999"

Returns: "x<y"

2)
"9!!"
"999999999"

Returns: "x>y"

3)
"456!!!"
"123!!!!!!"

Returns: "x<y"

4)
"5!"
"120"

Returns: "x=y"

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0!"; string Arg1 = "1"; string Arg2 = "x=y"; verify_case(0, Arg2, compare(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "9!"; string Arg1 = "999999999"; string Arg2 = "x<y"; verify_case(1, Arg2, compare(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "9!!"; string Arg1 = "999999999"; string Arg2 = "x>y"; verify_case(2, Arg2, compare(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "456!!!"; string Arg1 = "123!!!!!!"; string Arg2 = "x<y"; verify_case(3, Arg2, compare(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "5!"; string Arg1 = "120"; string Arg2 = "x=y"; verify_case(4, Arg2, compare(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ExtraordinarilyLarge test;

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
