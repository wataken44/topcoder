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

class StrangeDictionary2 {

 public:
  vector <double> getProbabilities(vector <string> words)
  {
    vector <double> result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A standard way of ordering words in a dictionary involves comparison of two words character by character, from left to right, until some two characters disagree. Jim thinks it's pretty boring, so he introduced a more complicated and less predictable scheme.

Given is a vector <string> words that contains N distinct words and each element is a single word. The length of each word is the same -- exactly L characters. To order words according to his scheme, Jim first generates a random permutation p[0], p[1], ..., p[L-1] of integers between 0 and L-1, inclusive. This permutation is generated only once and then considered to be fixed for the rest of the procedure. Using the permutation p, Jim can compare any two words as follows:


// returns -1, if A<B, 0, if A=B, and 1, if A>B
function Compare(Word A, Word B):
	for i = 0, 1, ..., L-1:
		a := character at position p[i] (0-based) in A
		b := character at position p[i] (0-based) in B
		if (a < b), return -1
		if (b < a), return 1

	return 0


Let Sorted be the list of the given words ordered according to Compare operator defined above. In other words, Compare(Sorted[i], Sorted[j]) = -1, for any i, j, 0 <= i < j < N.

Return a vector <double> that contains N elements and i-th element of the return is the probability that Sorted[0] is the same word as words[i]. Assume that permutation p is chosen uniformly at random.

DEFINITION
Class:StrangeDictionary2
Method:getProbabilities
Parameters:vector <string>
Returns:vector <double>
Method signature:vector <double> getProbabilities(vector <string> words)


NOTES
-Each element of the return value must have an absolute or relative error of less than 1e-9.


CONSTRAINTS
-words will contain between 1 and 16 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-All elements of words will contain the same number of characters.
-Each character in each element of words will be a lowercase letter ('a'-'z').
-All elements of words will be distinct.


EXAMPLES

0)
{"hardesttestever"}

Returns: {1.0 }

One word will always be at position 0 regardless of the permutation p.

1)
{"ab", "ba"}

Returns: {0.5, 0.5 }

If p = {0, 1}, then "ab" < "ba". If p = {1, 0}, then "ba" < "ab".

2)
{"aza", "aab", "bba"}

Returns: {0.3333333333333333, 0.5, 0.16666666666666666 }


p		Sorted
{0,1,2}		aab, aza, bba
{0,2,1}		aza, aab, bba
{1,0,2}		aab, bba, aza
{1,2,0}		aab, bba, aza
{2,0,1}		aza, bba, aab
{2,1,0}		bba, aza, aab


3)
{"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"}

Returns: {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"hardesttestever"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {1.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getProbabilities(Arg0)); }
	void test_case_1() { string Arr0[] = {"ab", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.5, 0.5 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getProbabilities(Arg0)); }
	void test_case_2() { string Arr0[] = {"aza", "aab", "bba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.3333333333333333, 0.5, 0.16666666666666666 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getProbabilities(Arg0)); }
	void test_case_3() { string Arr0[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getProbabilities(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  StrangeDictionary2 test;

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
