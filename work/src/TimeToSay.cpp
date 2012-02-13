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

class TimeToSay {

 public:
  int maximumJoy(vector <int> lostHealth, vector <int> joy)
  {
    int sz = lostHealth.size();
    const int N = 3000;
    
    vector< vector<int> > dp(sz+1, vector<int>(N, -1) );

    dp[0][0] = 0;

    UPTO(p, 1, sz) {
      int pp = p - 1;
      TIMES(j, N) {
        int ch = lostHealth[pp];
        int cj = joy[pp];
        
        dp[p][j] = dp[p-1][j];
        if(j - cj >= 0 && dp[pp][j-cj] >= 0) {
          int tmp = dp[pp][j - cj]+ch;
          if(dp[p][j] >= 0) {
            dp[p][j] = min(dp[p][j], tmp);
          }else {
            dp[p][j] = tmp;
          }
        }
      }
    }
 
    DOWNTO(j, N-1, 0) {
      if(dp[sz][j] >= 0 && dp[sz][j] < 100 ) return j;
    }
    
    int result = 0;
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
You've been patient for too long.  Now it's time to tell everybody what you think about them.


You are given vector <int>s lostHealth and joy.  After you talk to person i, you will lose lostHealth[i] units of health and gain joy[i] units of joy.  You can talk to each person at most once.  You do not have to talk to people in any particular order.


Your goal is to gain as much joy as possible.  You initially have 100 units of health and 0 units of joy.  If your health ever becomes zero or negative, you will die and end up having no joy at all.  Return the maximum amount of joy you can get.


DEFINITION
Class:TimeToSay
Method:maximumJoy
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maximumJoy(vector <int> lostHealth, vector <int> joy)


CONSTRAINTS
-lostHealth will contain between 1 and 20 elements, inclusive.
-joy will contain between 1 and 20 elements, inclusive.
-lostHealth and joy will contain the same number of elements.
-Each element of lostHealth will be between 0 and 100, inclusive.
-Each element of joy will be between 0 and 100, inclusive.


EXAMPLES

0)
{1, 21, 79}
{20, 30, 25}

Returns: 50

In this case, we cannot talk to both the 2nd and 3rd people because we would die.

1)
{100}
{20}

Returns: 0



2)
{100, 15, 1, 2, 3, 4, 6, 5}
{49, 40, 1, 2, 3, 4, 5, 4}

Returns: 59



3)
{100, 50, 20, 13}
{20, 30, 40, 50}

Returns: 120



4)
{100, 26, 13, 17, 24, 33, 100, 99}
{34, 56, 21, 1, 24, 34, 100, 99}

Returns: 135



5)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}

Returns: 1200



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 21, 79}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 30, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; verify_case(0, Arg2, maximumJoy(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, maximumJoy(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 15, 1, 2, 3, 4, 6, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {49, 40, 1, 2, 3, 4, 5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; verify_case(2, Arg2, maximumJoy(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 50, 20, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 30, 40, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 120; verify_case(3, Arg2, maximumJoy(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100, 26, 13, 17, 24, 33, 100, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {34, 56, 21, 1, 24, 34, 100, 99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 135; verify_case(4, Arg2, maximumJoy(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1200; verify_case(5, Arg2, maximumJoy(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TimeToSay test;

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
