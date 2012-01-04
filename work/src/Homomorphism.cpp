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

class Homomorphism {

 public:
  int count(string u, string v)
  {
    // -- main code --

    if(u[0] == '1') {
      FOR(i, 0, u.size()) {
        u[i] = '1' - u[i] + '0';
      }
    }

    int pos1 = -1;

    FOR(i, 0, u.size()) {
      if(u[i] == '1') {
        pos1 = i;
        break;
      }
    }

    if(pos1 < 0) {
      if(v.size() % u.size() != 0) {
        return 0;
      } else {
        return -1;
      }
    }

    int result = 0;

    FOR(w0, 1, v.size()) {
      string h0 = v.substr(0, w0);
      //DUMP(h0);

      //if(IsHomorphism(u, v, h0, "")) return -1;

      int vpos1 = w0 * pos1;
      for(int w1 = 1; w1 + vpos1 <= static_cast<int>(v.size()); ++w1) {
        string h1 = v.substr(vpos1, w1);
        //DUMP(h1);
        if(IsHomorphism(u, v, h0, h1)) ++result;
      }
    }
    
    return result;
    
  }

  bool IsHomorphism(const string& u, const string& v, const string& h0, const string& h1)
  {
    ostringstream oss;

    FOR(i, 0, u.size()) {
      if(u[i] == '0') {
        oss << h0;
      }else {
        oss << h1;
      }
    }

    return oss.str() == v;
  }
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A binary string is a non-empty finite sequence of 0's and 1's. Given two binary strings, u and v, their concatenation, u * v, is defined to be the binary string obtained by appending v to the end of u. For example, if u = 01100 and v = 110, then u * v = 01100110.

Consider a function, h, that maps binary strings to other binary strings. Suppose that for every string u with digits a1, a2, ..., ak in that order, it is true that h(u) = h(a1) * h(a2) *
... * h(ak). Then, h is called a non-degenerate homomorphism. In general, this means that h is uniquely determined by the values of h(0) and h(1). For example, if h(0) = 001, and h(1) = 10, then,

  - h(110) = h(1) * h(1) * h(0) = 1010001.
  - h(00) = h(0) * h(0) = 001001.
  - h(0101) = h(0) * h(1) * h(0) * h(1) = 0011000110.


Create a class Homomorphism that contains a method count, which is a given a string u and a string v. The method should return the number of distinct non-degenerate homomorphisms, h, which satisfy h(u) = v. If there are infinitely many such non-degenerate homomorphisms, the method should return -1.

DEFINITION
Class:Homomorphism
Method:count
Parameters:string, string
Returns:int
Method signature:int count(string u, string v)


NOTES
-Two non-degenerate homomorphisms, h and h' are considered distinct if and only if h(u) is different from h'(u) for at least one binary string, u.


CONSTRAINTS
-u and v will each contain between 1 and 50 characters inclusive.
-Each character in both u and v will be either '0' or '1'.


EXAMPLES

0)
"10"
"11001"

Returns: 4

Since h(0) and h(1) cannot be empty strings, there are precisely 4 legal non-degenerate homomorphisms:


1. h(1) = 1 and h(0) = 1001.
2. h(1) = 11 and h(0) = 001.
3. h(1) = 110 and h(0) = 01.
4. h(1) = 1100 and h(0) = 1.

1)
"00"
"11111"

Returns: 0

If h is a valid non-degenerate homomorphism, then h(00) = h(0) * h(0), which implies that h(00) has an even length. Thus, there are no non-degenerate homomorphisms satisfying h(00) = 11111.

2)
"11"
"00"

Returns: -1

Any non-degenerate homomorphism, h, satisfying h(1) = 0 will also satisfy h(11) = 00. This leaves no restrictions at all on h(0), so there are an infinite number of such non-degenerate homomorphisms.

3)
"001"
"1010001"

Returns: 1

The unique non-degenerate homomorphism, h, satisfying h(001) = 1010001 is given by h(0) = 10 and h(1) = 001.

4)
"101"
"11111111111111111111111111111111111111111111111111"

Returns: 24

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "10"; string Arg1 = "11001"; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "00"; string Arg1 = "11111"; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "11"; string Arg1 = "00"; int Arg2 = -1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "001"; string Arg1 = "1010001"; int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "101"; string Arg1 = "11111111111111111111111111111111111111111111111111"; int Arg2 = 24; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Homomorphism test;

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
