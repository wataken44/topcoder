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

class TheLuckySequence {

 public:
  bool isLucky(int n)
  {
    if(n == 0) return false;
    while(n > 0) {
      int m = n % 10;
      if(m != 4 && m != 7) return false;
      n /= 10;
    }
    return true;
  }

  int first(int n)
  {
    while(n >= 10) n /= 10;
    return n;
  }

  int last(int n)
  {
    return n % 10;
  }
  
  int count(vector <int> numbers, int length)
  {
    int modulo = 1234567891;
    // -- main code --

    vector<int> lucky;
    TIMES(i, numbers.size()) {
      int n = numbers[i];
      if(!isLucky(n)) continue;
      if(find(lucky.begin(), lucky.end(), n) == lucky.end()) {
        lucky.push_back(n);
      }
    }

    sort(lucky.begin(), lucky.end());

    int lsz = lucky.size();
    vector< vector<int> > graph(lsz, vector<int>(lsz, 0));

    TIMES(y, lsz) {
      TIMES(x, lsz) {
        if(last(lucky[y]) != first(lucky[x])) continue;
        graph[y][x] = 1;
      }
    }

    //DUMP(lucky);
    //DUMP(graph);

    typedef long long ll;
    vector< vector<ll> > dp(length, vector<ll>(lsz, 0));

    TIMES(x, lsz) {
      dp[0][x] = 1;
    }

    FOR(z, 1, length) {
      FOR(x, 0, lsz) {
        FOR(y, 0, lsz) {
          if(graph[y][x] == 1) {
            dp[z][x] = (dp[z][x] + dp[z - 1][y]) % modulo;
          }
        }
      }
    }

    ll result = 0;

    TIMES(x, lsz) {
      result = (result + dp[length - 1][x]) % modulo;
    }
    
    return result;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
John thinks 4 and 7 are lucky digits, and all other digits are not lucky.  A lucky number is a number that contains only lucky digits in decimal notation.



A lucky sequence is a sequence of length numbers A[0], A[1], ..., A[length - 1] that satisfies all of the following properties:

Each number A[i] is lucky, where 0 <= i < length.
For each i, where 0 <= i < length, there exists at least one j such that A[i] = numbers[j].
For each i, where 0 <= i < length - 1, the last digit of A[i] is the same as the first digit of A[i + 1].




You are given a vector <int> numbers and an int length.  Return the number of distinct lucky sequences modulo 1234567891. 



DEFINITION
Class:TheLuckySequence
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> numbers, int length)


NOTES
-Two lucky sequences A[0], A[1], ..., A[length - 1] and B[0], B[1], ..., B[length - 1] are considered distinct if there exists i, 0 <= i < length, such that A[i] ­ B[i].


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will be between 1 and 1,000,000,000, inclusive.
-length will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
1

Returns: 2

There are only two lucky numbers among these ten integers.

1)
{47, 74, 47}
3

Returns: 2

We can construct only two different sequences (47, 74, 47) and (74, 47, 74).

2)
{100, 4774, 200, 747, 300}
47

Returns: 2



3)
{44, 47, 74, 77}
2

Returns: 8



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {47, 74, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 4774, 200, 747, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {44, 47, 74, 77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 8; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TheLuckySequence test;

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
