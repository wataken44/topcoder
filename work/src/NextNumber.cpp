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

class NextNumber {

 public:
  int getNextNumber(int N)
  {
    vector<int> bin;

    while(N > 0) {
      bin.push_back(N % 2);
      N /= 2;
    }

    bin.push_back(0);

    //DUMP(bin);
    reverse(bin.begin(), bin.end());
    //DUMP(bin);
    
    next_permutation(bin.begin(), bin.end());
    //DUMP(bin);
    
    int result = 0;

    FOR(i, 0, bin.size()) {
      result = result * 2 + bin[i];
      //DUMP(bin[i]);
      //DUMP(result);
    }

    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// The binary weight of a positive integer is the number of 1's in its binary representation. For example, the decimal number 1 has a binary weight of 1, and the decimal number 1717 (which is 11010110101 in binary) has a binary weight of 7.

Given a positive integer N, return the smallest integer greater than N that has the same binary weight as N.

DEFINITION
Class:NextNumber
Method:getNextNumber
Parameters:int
Returns:int
Method signature:int getNextNumber(int N)


NOTES
-The result is guaranteed to fit in a signed 32-bit integer.


CONSTRAINTS
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1717

Returns: 1718

Example from the problem statement.

1)
4

Returns: 8

4 is 100 in its binary representation and weighs 1. The next number is 1000(in binary) which represents 8.

2)
7

Returns: 11

The decimal 7 is binary 111, so it has binary weight of 3. The next number with the same binary weight is 11, which is 1011 in binary.

3)
12

Returns: 17

12 in decimal is 1100 in binary. The next number with the same binary weight is 10001 in binary, which is 17.

4)
555555

Returns: 555557



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1717; int Arg1 = 1718; verify_case(0, Arg1, getNextNumber(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 8; verify_case(1, Arg1, getNextNumber(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 11; verify_case(2, Arg1, getNextNumber(Arg0)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 17; verify_case(3, Arg1, getNextNumber(Arg0)); }
	void test_case_4() { int Arg0 = 555555; int Arg1 = 555557; verify_case(4, Arg1, getNextNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  NextNumber test;

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
