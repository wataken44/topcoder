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

class RevealTriangle {

 public:
  vector <string> calcTriangle(vector <string> questionMarkTriangle)
  {
    vector <string> ret(questionMarkTriangle);
    // -- main code --

    while(true) {
      bool ok = true;
      TIMES(y, ret.size()) {
        TIMES(x, ret[y].size()) {
          if(ret[y][x] == '?') {
            ok = false;
            break;
          }
        }
        if(!ok) break;
      }
      if(ok) break;

      TIMES(y, ret.size() - 1) {
        TIMES(x, ret[y].size() - 1) {
          if(ret[y][x] == '?' && ret[y][x+1] != '?' && ret[y+1][x] != '?' ) {
            int a = to_i(ret[y][x+1]);
            int b = to_i(ret[y+1][x]);
            ret[y][x] = to_c((b - a + 20) % 10);
          }
          if(ret[y][x] != '?' && ret[y][x+1] == '?' && ret[y+1][x] != '?' ) {
            int a = to_i(ret[y][x]);
            int b = to_i(ret[y+1][x]);
            ret[y][x+1] = to_c((b - a + 20) % 10);
          }
          if(ret[y][x] != '?' && ret[y][x+1] != '?' && ret[y+1][x] == '?' ) {
            int a = to_i(ret[y][x]);
            int b = to_i(ret[y][x+1]);
            ret[y][x] = to_c((a + b) % 10);
          }
        }
      }
      DUMP(ret);
    }
    
    return ret;	
  }

  int to_i(char c) { return c - '0'; }
  char to_c(int i) { return i + '0'; }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
	Suppose there is a triangle of digits like the following:

74932
1325
457
92
1

	Each digit, with the exception of those in the top row, is equal to the last digit of the sum of 
	its upper and upper-right neighboring digits.


	You will be given a vector <string> questionMarkTriangle containing a triangle where 
	only one digit in each row is known and all others are represented by '?'s 
	(see example 0 for clarification).
	Each element of questionMarkTriangle represents a row of the triangle, and the rows are given 
	from top to bottom. Each element contains exactly one digit ('0'-'9') and 
	the remaining characters are all '?'s. Restore the triangle and return it as a 
	vector <string> without '?'s.



DEFINITION
Class:RevealTriangle
Method:calcTriangle
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> calcTriangle(vector <string> questionMarkTriangle)


CONSTRAINTS
-questionMarkTriangle will contain between 1 and 50 elements, inclusive.
-Element i (0 indexed) of questionMarkTriangle will contain exactly n-i characters, where n is the number of elements in questionMarkTriangle.
-Each element of questionMarkTriangle will contain exactly one digit ('0'-'9') and all others characters will be '?'s.


EXAMPLES

0)
{"4??", 
 "?2", 
 "1"}

Returns: {"457", "92", "1" }

Let's substitute '?'s with unknown variables:

4ab 
c2 
1


Having done that, we start solving for the variables from the bottom to the top. First, we know that the last digit of (c + 2) is 1. Therefore, c must be 9:


4ab 
92 
1

Now we know that the last digit of (4 + a) is 9, which means a is 5:

45b 
92 
1


And, finally, the last digit of (5 + b) is 2, so b is 7.

1)
{"1"}

Returns: {"1" }

2)
{"???2", "??2", "?2", "2"}

Returns: {"0002", "002", "02", "2" }

3)
{"??5?", "??9", "?4", "6"}

Returns: {"7054", "759", "24", "6" }

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"4??", 
 "?2", 
 "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"457", "92", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calcTriangle(Arg0)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calcTriangle(Arg0)); }
	void test_case_2() { string Arr0[] = {"???2", "??2", "?2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0002", "002", "02", "2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calcTriangle(Arg0)); }
	void test_case_3() { string Arr0[] = {"??5?", "??9", "?4", "6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7054", "759", "24", "6" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calcTriangle(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RevealTriangle test;

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
