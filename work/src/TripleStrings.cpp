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

class TripleStrings {

 public:
  int getMinimumOperations(string init, string goal)
  {
    int sz = init.size();
    
    DOWNTO(i, sz, 1) {
      if(init.substr(sz - i, i) == goal.substr(0, i)) {
        return (sz - i) * 2;
      }
    }
    
    return sz * 2;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You have three strings A, B, C. Initially, A is equal to a string init, and B and C are empty. Each character of init is either lowercase 'o' or lowercase 'x'.
Your task in this problem is to transform A from init into goal by applying the following operations to the strings.

If A is not an empty string, remove the leftmost character from A, and add it to the end of B.
If A is not an empty string, remove the leftmost character from A, and add it to the end of C.
If B is not an empty string, remove the leftmost character from B, and add it to the end of A.
If C is not an empty string, remove the leftmost character from C, and add it to the end of A.

You can apply the operations in any order and each operation can be used an arbitrary number of times. Return the minimal number of operations required to finish the task. The constraints guarantee that this is always possible.


DEFINITION
Class:TripleStrings
Method:getMinimumOperations
Parameters:string, string
Returns:int
Method signature:int getMinimumOperations(string init, string goal)


CONSTRAINTS
-init will contain between 1 and 50 characters, inclusive.
-init and goal will contain the same number of characters.
-Each character of init and goal will be either lowercase 'o' or lowercase 'x'.
-The number of 'o' characters in init will be equal to the number of 'o' characters in goal.


EXAMPLES

0)
"ooxxox"
"xoxoxo"

Returns: 6

One of the optimal solutions is as follows:

initial:         A=ooxxox B=  C=
use operation 1: A=oxxox  B=o C=
use operation 2: A=xxox   B=o C=o
use operation 2: A=xox    B=o C=ox
use operation 4: A=xoxo   B=o C=x
use operation 4: A=xoxox  B=o C=
use operation 3: A=xoxoxo B=  C=



1)
"oooxxoo"
"oooxxoo"

Returns: 0

init and goal are the same, so no operation is required.

2)
"ox"
"xo"

Returns: 2



3)
"ooxxooxx"
"xxoxoxoo"

Returns: 12



4)
"oxxoxxoooxooooxxxoo"
"oxooooxxxooooxoxxxo"

Returns: 16



5)
"xxxoxoxxooxooxoxooo"
"oxxooxxooxxoxoxooxo"

Returns: 36



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ooxxox"; string Arg1 = "xoxoxo"; int Arg2 = 6; verify_case(0, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "oooxxoo"; string Arg1 = "oooxxoo"; int Arg2 = 0; verify_case(1, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ox"; string Arg1 = "xo"; int Arg2 = 2; verify_case(2, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ooxxooxx"; string Arg1 = "xxoxoxoo"; int Arg2 = 12; verify_case(3, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "oxxoxxoooxooooxxxoo"; string Arg1 = "oxooooxxxooooxoxxxo"; int Arg2 = 16; verify_case(4, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "xxxoxoxxooxooxoxooo"; string Arg1 = "oxxooxxooxxoxoxooxo"; int Arg2 = 36; verify_case(5, Arg2, getMinimumOperations(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TripleStrings test;

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
