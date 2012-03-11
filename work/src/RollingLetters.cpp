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

class RollingLetters {

 public:
  long long getTime(vector <string> reels, string requiredText)
  {
    long long result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
A display mechanism is built from several spinning reels arranged in a line, from left to right.  Each reel has a number of distinct letters on its perimeter, and only one of them is visible at a time.  The visible letter changes every second.  Each reel may have a different number of letters.


You are given a vector <string> reels, where reels[k] represents the letters on the k-th reel.


At time 0, each reel shows the letter at index 0 from the corresponding element of reels.  At every second, the visible letter changes from the letter at index i to the letter at index i+1.  Since reels are circular, the first letter shows up again after the last one.


Return the first second when the text displayed is equal to requiredText, or -1 if this will never happen.


DEFINITION
Class:RollingLetters
Method:getTime
Parameters:vector <string>, string
Returns:long long
Method signature:long long getTime(vector <string> reels, string requiredText)


NOTES
-The return value will fit in a signed 64 bit integer.


CONSTRAINTS
-reels will contain between 1 and 50 elements, inclusive.
-Each element of reels will contain between 2 and 26 uppercase letters ('A'-'Z'), inclusive.
-Characters in each element of reels will be distinct.
-requiredText will contain exactly N uppercase letters ('A'-'Z'), where N is the number of elements in reels.


EXAMPLES

0)
{"XYZ", "DEF", "OPRS"}
"YES"

Returns: 7

The message displayed at each second is:
0: XDO
1: YEP
2: ZFR
3: XDS
4: YEO
5: ZFP
6: XDR
7: YES

1)
{"ABC","ABC"}
"AB"

Returns: -1

The only possible messages are "AA", "BB", "CC".

2)
{"ABC"}
"X"

Returns: -1

There is no 'X' on the reel.

3)
{"CPKHFQEYXVMODNRTSGUBLJ", "TJLSURVHFQPAXGCEI", "JXNSGADPEWICKLFMVOQ", "UOFVKGQIJRECMWXADTPNL",
"OREWASJFLY", "HBEC", "ESDRVXCNQUFWKGTOLH", "CPLTAMBHYSQDVJIORNW", "CG"}
"CAIIEHLQC"

Returns: 4088392



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"XYZ", "DEF", "OPRS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; long long Arg2 = 7LL; verify_case(0, Arg2, getTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABC","ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AB"; long long Arg2 = -1LL; verify_case(1, Arg2, getTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "X"; long long Arg2 = -1LL; verify_case(2, Arg2, getTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"CPKHFQEYXVMODNRTSGUBLJ", "TJLSURVHFQPAXGCEI", "JXNSGADPEWICKLFMVOQ", "UOFVKGQIJRECMWXADTPNL",
"OREWASJFLY", "HBEC", "ESDRVXCNQUFWKGTOLH", "CPLTAMBHYSQDVJIORNW", "CG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CAIIEHLQC"; long long Arg2 = 4088392LL; verify_case(3, Arg2, getTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RollingLetters test;

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
