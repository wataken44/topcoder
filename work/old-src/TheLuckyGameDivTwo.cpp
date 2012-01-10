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

class TheLuckyGameDivTwo {

 public:
  int find(int a, int b, int jLen, int bLen)
  {
    int result = 0;
    // -- main code --

    vector<bool> lucky(b+1, false);

    UPTO(i, a, b) {
      lucky[i] = isLucky(i); 
    }

    for(int s = a; s + jLen - 1 <= b; ++s) {
      int m = INT_MAX;
      for(int u = 0; u + bLen - 1 < jLen; ++u) {
        int c = 0;
        for(int t = 0; t < bLen; ++t) {
          //DUMP(s);DUMP(s+t);DUMP(lucky[s+t]);
          c += lucky[s + u + t] ? 1 : 0;
        }
        m = min(m, c);
      }
      result = max(result, m);
    }
    
    return result;	
  }

  bool isLucky(int n) {
    while(n > 0) {
      if((n % 10 != 4) && (n % 10 != 7)) return false;
      n = n / 10;
    }
    return true;
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
John and Brus believe that the digits 4 and 7 are lucky and all others are not.
According to them, a lucky number is a number that contains only lucky digits in its decimal representation.

	

John and Brus play the following game.
Initially, there is an interval of integers between a and b, inclusive.
Then, John choose a subinterval of the initial interval that contains exactly jLen numbers.
Finally, Brus chooses a subinterval of John's subinterval that contains exactly bLen numbers.
The outcome of the game is the total number of lucky numbers in Brus's subinterval.



John follows the optimal strategy that maximizes the outcome.
Brus follows the optimal strategy that minimizes the outcome.
Return the outcome of the game.



DEFINITION
Class:TheLuckyGameDivTwo
Method:find
Parameters:int, int, int, int
Returns:int
Method signature:int find(int a, int b, int jLen, int bLen)


CONSTRAINTS
-a will be between 1 and 4747, inclusive.
-b will be between a and 4747, inclusive.
-jLen will be between 1 and b-a+1, inclusive.
-bLen will be between 1 and jLen, inclusive.


EXAMPLES

0)
1
10
2
1

Returns: 0

John will choose a subinterval containing two consecutive numbers. Then Brus will choose a subinterval containing just one of these two numbers. Since no two lucky numbers are consecutive, Brus will always be able to choose a subinterval containing no lucky numbers, so the outcome is 0.

1)
1
100
100
100

Returns: 6

Here, John and Brus have no choice. The outcome of the game is the number of lucky numbers between 1 and 100, inclusive.

2)
4
8
3
2

Returns: 1

John can choose one of the intervals [4; 6], [5; 7] or [6; 8]. In the first two cases Brus can choose a subinterval that contains no lucky numbers. However, in the last case, Brus will have to choose a subinterval that contains the lucky number 7. Therefore it is optimal for John to choose [6; 8], and the outcome is 1.

3)
1
100
75
50

Returns: 2

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; int Arg3 = 1; int Arg4 = 0; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 100; int Arg3 = 100; int Arg4 = 6; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 3; int Arg3 = 2; int Arg4 = 1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 75; int Arg3 = 50; int Arg4 = 2; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TheLuckyGameDivTwo test;

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
