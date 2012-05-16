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

class RandomSwaps {

 public:
  double getProbability(int aL, int sC, int a, int b)
  {
    double pp = a == b ? 1.0 : 0;

    TIMES(c, sC) {
      pp = ((aL - 2.0) / aL) * pp + (2.0 / aL / (aL - 1)) * ( 1 - pp);
    }

    return pp;
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
Suppose that we have an array with arrayLength distinct elements.
A quite common task in programming is to randomly permute this array.
Novices who encounter this situation often implement the following algorithm:



Choose a positive integer swapCount.
swapCount times randomly choose two distinct indices and swap the corresponding elements.



This method of permuting an array is bad, because some permutations of the array will be more likely than others.
In this problem, you shall compute how bad this method is for a given situation.



You will be given four ints: arrayLength, swapCount, a and b. 
Consider the element of the array that initially had the index a. 
Write a method that will compute the probability that this element will have the index b at the end of the process described above.



DEFINITION
Class:RandomSwaps
Method:getProbability
Parameters:int, int, int, int
Returns:double
Method signature:double getProbability(int arrayLength, int swapCount, int a, int b)


NOTES
-The indices of elements that are going to be swapped are generated with a uniform probability distribution, i.e., each pair of indices has got the same probability of being chosen.
-The indices are zero-based, i.e., the array contains elements with indices 0 to arrayLength-1, inclusive.
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-arrayLength will be between 2 and 1,000, inclusive.
-swapCount will be between 1 and 100,000, inclusive.
-a and b will be between 0 and arrayLength-1, inclusive.


EXAMPLES

0)
5
1
0
0

Returns: 0.6

There are ten possible pairs of indices to swap: (0,1), (0,2), (0,3), (0,4), (1,2), (1,3), (1,4), (2,3), (2,4), and (3,4). Out of these ten, the last six leave the element 0 untouched. Thus the probability is 6/10.

1)
5
1
0
3

Returns: 0.1

Only the swap (0,3) will move the element from position 0 to position 3.
The probability of choosing this swap is 1/10.

2)
5
2
0
0

Returns: 0.4

Now there are two possibilities: Either the 0-th element stays in its place for the whole time, or it is swapped away and back again.

The probability of the first possibility is (6/10)^2, for the second possibility it is (4/10)*(1/10).

3)
100
500
3
3

Returns: 0.010036635745123007

For 100 elements, even after 500 swaps, the permutation won't be random enough.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.6; verify_case(0, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 3; double Arg4 = 0.1; verify_case(1, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.4; verify_case(2, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 500; int Arg2 = 3; int Arg3 = 3; double Arg4 = 0.010036635745123007; verify_case(3, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RandomSwaps test;

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
