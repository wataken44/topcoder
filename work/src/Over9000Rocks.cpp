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

class Over9000Rocks {

 public:
  int countPossibilities(vector <int> lowerBound, vector <int> upperBound)
  {
    int sz = lowerBound.size();

    // vector< pair<int, int> > bound;
    map<int, int> bound;
    
    FOR(i, 1, (1 << sz)) {
      int u = 0;
      int l = 0;
      TIMES(k, sz) {
        if((1 & (i >> k)) == 1) {
          l += lowerBound[k];
          u += upperBound[k];
        }
      }

      if(u < 9001) continue;
      if(l < 9001) l = 9001;
      
      // bound.push_back(make_pair(l, u));

      if(bound.find(l) == bound.end()) {
        bound[l] = u;
      }else {
        bound[l] = max(bound[l], u);
      }

    }


    int result = 0;
    int counted = 0;
    EACH(bound, it) {
      // DUMP(it->first); DUMP(it->second);
      int l = it->first;
      int u = it->second;

      if(counted < l) {
        result += u - l + 1;
        counted = u;
      }else if(l <= counted && counted <= u) {
        result += u - (counted + 1) + 1;
        counted = u;
      }else {

      }
    }
    
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You used to have only 30 rocks, but now you have plenty of them. In fact, we will assume that you have a potentially infinite supply of rocks. You would like to show that you own over 9000 rocks.
You have a set of boxes. You will choose a subset of those boxes and fill them with rocks so that the total number of rocks will be over 9000. Each box has a lower and an upper bound on the number of rocks it may contain.

You are given the vector <int>s lowerBound and upperBound. For each i, the values lowerBound[i] and upperBound[i] have the following meaning: If you decide to use box i, the number of rocks you may put inside the box must be between lowerBound[i] and upperBound[i], inclusive.

X is a positive integer that has two properties:

X is over 9000.
It is possible to select some of the boxes and fill them with appropriate numbers of rocks in such a way that the total number of rocks used is exactly X.

Compute and return the number of possible values of X.

DEFINITION
Class:Over9000Rocks
Method:countPossibilities
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countPossibilities(vector <int> lowerBound, vector <int> upperBound)


CONSTRAINTS
-lowerBound will contain between 1 and 15, elements, inclusive.
-upperBound will contain the same number of elements as lowerBound.
-Each element of lowerBound will be between 1 and 1,000,000 (10^6), inclusive.
-Each element i of upperBound will be between lowerBound[i] and 1,000,000 (10^6), inclusive.


EXAMPLES

0)
{9000}
{9001}

Returns: 1

You can place 9000 or 9001 rocks in the single box. Of the allowed values, only 9001 is over 9000.

1)
{9000, 1, 10}
{9000, 2, 20}

Returns: 15

You have to choose box 0 and at least one other box, otherwise you have no chance of placing over 9000 rocks.
If you only choose boxes 0 and 1, you can place 9001 or 9002 rocks.
If you only choose boxes 0 and 2, you can place between 9010 and 9020 rocks, inclusive.
If you choose all three boxes, you can place between 9011 and 9022 rocks, inclusive.
Hence all possible values of X are 9001, 9002, and everything from 9010 to 9022, inclusive.

2)
{1001, 2001, 3001, 3001}
{1003, 2003, 3003, 3003}

Returns: 9



3)
{9000,90000,1,10}
{9000,90000,3,15}

Returns: 38



4)
{1,1,1,1,1,1}
{3,4,5,6,7,8}

Returns: 0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9001}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {9000, 1, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9000, 2, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(1, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1001, 2001, 3001, 3001}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1003, 2003, 3003, 3003}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {9000,90000,1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9000,90000,3,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 38; verify_case(3, Arg2, countPossibilities(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countPossibilities(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Over9000Rocks test;

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
