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

class CompositeSmash {

 public:

  string thePossible(int N, int target)
  {
    // -- main code --
    if(N == target) return "Yes";
    if(N % target != 0) return "No";

    UPTO(i, 2, target - 1) {
      if(N % i != 0) continue;
      if(thePossible(N / i, target) == "No") return "No";
    }

    return "Yes";
  }
  
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Toastwoman wants to be a magical girl. As training, she wants to make a ball that contains an integer target.


Initially she has a ball that contains an integer N. She can smash a ball that contains a composite number (see notes for definition) and break it into two balls. Each new ball will also contain an integer. If she smashes a ball that contains a composite number x and it breaks into two balls that contain y and z, it satisfies y &ge 2, z &ge 2 and yz = x. For example, if she smashes a ball that contains 12, it breaks into 2 and 6 or 3 and 4. Toastwoman can control the ball she smashes, but she can't control the numbers in the two new balls when there are multiple pairs of (y, z) that satisfy the above conditions. She can apply the described ball smash operation arbitrary number of times, but she can't smash a ball that contains a non-composite number.


If she can always make a ball that contains target, return "Yes" (quotes for clarity). Otherwise, return "No" (quotes for clarity).


DEFINITION
Class:CompositeSmash
Method:thePossible
Parameters:int, int
Returns:string
Method signature:string thePossible(int N, int target)


NOTES
-A positive integer x is called a composite number if it has at least one divisor other than 1 and x. For example, 4 and 6 are composite numbers, while 1 and 5 are not composite numbers.


CONSTRAINTS
-N will be between 2 and 100,000, inclusive.
-target will be between 2 and 100,000, inclusive.


EXAMPLES

0)
517
47

Returns: "Yes"

If?she?smashes?517,?it?breaks?into?11?and?47.

1)
8
4

Returns: "Yes"

If?she?smashes?8,?it?breaks?into?2?and?4.

2)
12
6

Returns: "No"

If?she?smashes?12?and?it?breaks?into?3?and?4,?she?can't?make?6.

3)
5
8

Returns: "No"



4)
100000
100000

Returns: "Yes"

She already has target.

5)
5858
2

Returns: "Yes"



6)
81461
2809

Returns: "No"



7)
65536
256

Returns: "No"

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 517; int Arg1 = 47; string Arg2 = "Yes"; verify_case(0, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; string Arg2 = "Yes"; verify_case(1, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 6; string Arg2 = "No"; verify_case(2, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "No"; verify_case(3, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; string Arg2 = "Yes"; verify_case(4, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 5858; int Arg1 = 2; string Arg2 = "Yes"; verify_case(5, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 81461; int Arg1 = 2809; string Arg2 = "No"; verify_case(6, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 65536; int Arg1 = 256; string Arg2 = "No"; verify_case(7, Arg2, thePossible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  CompositeSmash test;

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
