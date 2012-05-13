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

class AlternatingLane {

 public:
  double expectedBeauty(vector <int> low, vector <int> high)
  {
    double result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Mr. Green owns a beautiful park full of trees. Recently, he arranged a new lane in the park and planted N trees along the lane.
The trees are numbered from 0 to N-1 in the order that they occur along the lane. It is known that once the i-th tree
grows up, its height in meters will be a random integer uniformly distributed between low[i] and high[i],
inclusive.



Mr. Green has quite a strange conception about beauty. In particular, he is very fond of so called alternating sequences of
integers, which are defined by the following rules:


Every sequence of 1 integer is alternating.
A sequence of 2 integers (A, B) is alternating if and only if A is not equal to B.
A sequence of 3 integers (A, B, C) is alternating if and only if (A < B and B > C) or (A > B and B < C).
A sequence of L, L > 3, integers (A[0], A[1], ..., A[L-1]) is alternating if and only if each triple of consecutive integers
in the sequence form an alternating sequence. In other words, each of the sequences (A[0], A[1], A[2]), (A[1], A[2], A[3]), ...,
(A[L-3], A[L-2], A[L-1]) must be alternating.


Mr. Green measures the beauty of an alternating sequence as the sum of absolute differences between all pairs of its consecutive elements.
In other words, for a sequence (A[0], A[1], ..., A[L-1]), its beauty is equal to |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[L-2] - A[L-1]|.
Note that the beauty of a sequence consisting of 1 element is equal to 0.




Once all the trees grow up, Mr. Green will write down their heights in the order that they occur along the lane. If the resulted sequence of integers
is alternating, then he will be satisfied with the resulting lane. Otherwise, he will cut some trees down 
so that the sequence formed by the remaining trees is alternating. If there are several ways to obtain an alternating sequence, he will choose a way among them that results in a sequence with maximum possible beauty.



Return the expected value of the beauty of the resulting sequence.


DEFINITION
Class:AlternatingLane
Method:expectedBeauty
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double expectedBeauty(vector <int> low, vector <int> high)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-low will contain between 1 and 50 elements, inclusive.
-high will contain the same number of elements as low.
-Each element of low and high will be between 1 and 100,000, inclusive.
-For each valid index i, low[i] will be less than or equal to high[i].


EXAMPLES

0)
{1}
{100}

Returns: 0.0

Here we have only 1 tree, so the beauty of the resulting sequence will be 0.


1)
{1, 1, 1}
{2, 2, 2}

Returns: 1.0

Once all the trees grow up, 8 different lanes are possible with equal probability. In cases (1, 1, 1) and (2, 2, 2), Mr. Green will cut 2 trees and the beauty will be 0. In cases (1, 1, 2), (2, 2, 1), (1, 2, 2), (2, 1, 1), he will cut the middle tree and the beauty will be 1. Finally, in cases (1, 2, 1) and (2, 1, 2), he won't cut any trees and the beauty will be 2. Therefore, the answer is (4/8) * 1 + (2/8) * 2 = 1.

2)
{1, 3, 5, 7, 9}
{2, 4, 6, 8, 10}

Returns: 8.0

Here, Mr. Green will always leave only the first and the last trees.

3)
{4, 3, 3, 7}
{10, 7, 7, 7}

Returns: 6.171428571428572



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 5, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 6, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(2, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4, 3, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.171428571428572; verify_case(3, Arg2, expectedBeauty(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  AlternatingLane test;

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
