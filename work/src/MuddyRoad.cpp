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

class MuddyRoad {

 public:
  double getExpectedValue(vector <int> road)
  {

    int sz = road.size();
    vector< double > exp(sz, 0);

    exp[sz-1] = 0;
    exp[sz-2] = 0;
    
    DOWNTO(i, sz - 3, 0) {
      exp[i] = road[i + 1] / 100.0 * (road[i + 2] / 100.0 + exp[i + 2]);
      exp[i] += (1.0 - road[i + 1] / 100.0) * exp[i + 1];
    }
    
    return exp[0] + road[0] / 100.0;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Fox Ciel is going to walk through an unpaved road to meet her friend. The road is one-dimensional. It is separated into N parts numbered from 0 to N-1, where part 0 is Ciel's current part and part N-1 is her destination part.
Ciel will perform her trip tomorrow. Unfortunately today it is raining, so tomorrow some parts of the road will be muddy. You are given a vector <int> road containing N elements. The probability that the i-th part of the road will be muddy tomorrow is road[i]/100.

Ciel can walk along the road using any combination of strides with lengths 1 and 2. If she is at part i, a stride of length 1 will move her to part i+1 and a stride of length 2 will move her to part i+2 (skipping part i+1). If there are many ways to reach part N-1 from part 0, Ciel will choose the one among them where the number of visited muddy parts is minimal.

Return the expected number of muddy parts that she will visit tomorrow.


DEFINITION
Class:MuddyRoad
Method:getExpectedValue
Parameters:vector <int>
Returns:double
Method signature:double getExpectedValue(vector <int> road)


NOTES
-Assume that events "i-th part of the road will be muddy tomorrow" are totally independent.
-Ciel has very good sight, so when starting her trip at part 0, she is already able to see for each part whether it is muddy or not.


CONSTRAINTS
-road will contain between 2 and 50 elements, inclusive.
-Each element of road will be between 0 and 100, inclusive.
-The first element and the last element of road will be 0.


EXAMPLES

0)
{0, 60, 60, 0}

Returns: 0.36

There can be four different states of the road tomorrow:

.... with probability = 0.16, 0 steps to muddy parts
.M.. with probability = 0.24, 0 steps to muddy parts
..M. with probability = 0.24, 0 steps to muddy parts
.MM. with probability = 0.36, 1 step to muddy parts

(Here, '.' represents a non-muddy part and 'M' represents a muddy part.)
Thus, the expected number of steps is 0*0.16+0*0.24+0*0.24+1*0.36=0.36.

1)
{0, 50, 50, 50, 50, 0}

Returns: 0.5625



2)
{0, 0, 100, 100, 100, 100, 100, 100, 0, 0, 100, 0}

Returns: 3.0



3)
{0, 12, 34, 56, 78, 91, 23, 45, 67, 89, 0}

Returns: 1.7352539420031923



4)
{0, 50, 50, 100, 50, 100, 50, 50, 100, 66, 0}

Returns: 2.288125



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 60, 60, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.36; verify_case(0, Arg1, getExpectedValue(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 50, 50, 50, 50, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5625; verify_case(1, Arg1, getExpectedValue(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 100, 100, 100, 100, 100, 100, 0, 0, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(2, Arg1, getExpectedValue(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 12, 34, 56, 78, 91, 23, 45, 67, 89, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.7352539420031923; verify_case(3, Arg1, getExpectedValue(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 50, 50, 100, 50, 100, 50, 50, 100, 66, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.288125; verify_case(4, Arg1, getExpectedValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MuddyRoad test;

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
