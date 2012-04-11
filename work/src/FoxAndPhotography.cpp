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

class FoxAndPhotography {

 public:
  int getMinimumSwaps(vector <int> heightsFront, vector <int> heightsBack)
  {
    vector<int> ff0(heightsFront);
    vector<int> bb0(heightsBack);
    
    sort(ff0.begin(), ff0.end());
    sort(bb0.begin(), bb0.end());

    int sz = ff0.size();
    TIMES(i, sz) {
      if(ff0[i] >= bb0[i]) return -1;
    }
    
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Fox Ciel is attending a party. During the party, people decided to take a commemorative photograph. Ciel picked up a camera to take a photograph.
In the party, there are 2*N people (not including Ciel).

For taking the photograph, people formed two rows, each containing N people.
In each row, Ciel numbered the people from 0 to N-1 from left to right.
The people were aligned so that for each i, person i in the back row was standing exactly behind person i in the front row.

Initially, the people lined up arbitrarily.
Therefore it is possible that some of the people in the back row are obscured by people in the front row.
You are given two vector <int>s: heightsFront and heightsBack.
For each i, heightsFront[i] is the height of person i in the front row and heightsBack[i] is the height of person i in the back row.
The person in the back row is obscured by the person in the front row if and only if heightsFront[i] >= heightsBack[i].

If there are some obscured people, Ciel wants to fix it.
The only operation she may do is to select two adjacent people in the same row and swap them.
Compute and return the smallest number of such operations necessary to rearrange the people so that nobody in the back row is obscured.
If no such sequence of operations exists, return -1.


DEFINITION
Class:FoxAndPhotography
Method:getMinimumSwaps
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getMinimumSwaps(vector <int> heightsFront, vector <int> heightsBack)


CONSTRAINTS
-heightsFront will contain between 2 and 16 elements, inclusive.
-heightsBack will contain the same number of elements with heightForward.
-Each element of heightsFront and heightsBack will be between 140 and 190, inclusive.


EXAMPLES

0)
{140, 150}
{160, 150}

Returns: 1

Initially, person 1 (0-based index) in the back row is obscured.
One optimal solution is to swap people 0 and 1 in the front row.
Another optimal solution is to swap people 0 and 1 in the back row.

1)
{140, 140, 140, 140}
{190, 190, 190, 190}

Returns: 0

Nobody is obscured, so no swaps are needed.

2)
{170, 170, 170}
{160, 170, 180}

Returns: -1

Person 0 in the back row is too short. Regardless of how we swap the people, this person will always be obscured.

3)
{140, 141, 142, 143}
{144, 143, 142, 141}

Returns: 6



4)
{140, 170, 140, 170, 140, 170, 140, 170, 140, 170}

{180, 180, 180, 180, 180, 150, 150, 150, 150, 150}

Returns: 15



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {140, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {160, 150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {140, 140, 140, 140}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {190, 190, 190, 190}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {170, 170, 170}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {160, 170, 180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {140, 141, 142, 143}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {144, 143, 142, 141}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, getMinimumSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {140, 170, 140, 170, 140, 170, 140, 170, 140, 170}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {180, 180, 180, 180, 180, 150, 150, 150, 150, 150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(4, Arg2, getMinimumSwaps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxAndPhotography test;

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
