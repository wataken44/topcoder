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

class UnluckyIntervals {

 public:

#define SZ(x) static_cast<int>((x).size())
  
  vector <int> getLuckiest(vector <int> luckySet, int n)
  {
    vector <int> result;
    // -- main code --

    TIMES(k, min(n, (int)luckySet.size())) {
      result.push_back(luckySet[k]);
    }

    if(SZ(result) == n) return result;

    luckySet.push_back(0);

    const int INF = INT_MAX;
    luckySet.push_back(INF);

    sort(luckySet.begin(), luckySet.end());

    vector< pair<int,int> > range;

    FOR(k, 0, luckySet.size() - 1)
    {
      range.push_back(
          make_pair(luckySet[k] + 1, luckySet[k+1] - 1));
    }
    
    DUMP(range);

    while(SZ(result) < n) {
      int k = range.size() - 1;
      int mw = range[k].second - range[k].first;
      TIMES(i, range.size()) {
        int iw = range[i].second - range[i].first;
        if(iw < 0) continue;
        if(mw > iw) {
          k = i;
          mw = iw;
        }
      }

      pair<int, int>& r = range[k];
      DUMP(r);DUMP(result);DUMP(range);

      if(r.first > r.second) continue;
      result.push_back(r.first);
      ++r.first;

      if(SZ(result) == n) return result;
        
      if(r.first > r.second) continue;
      if(r.second == INF - 1) continue;
        
      result.push_back(r.second);
      --r.second;
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are given a set of integers called luckySet.  An interval [A,B], where B is greater than A, and A and B are positive integers, is considered unlucky if none of the integers between A and B, inclusive, belongs to luckySet.

An integer x is considered to be luckier than another integer y if the number of unlucky intervals that contain x is smaller than the number of unlucky intervals that contain y.  In case both x and y belong to an equal number of unlucky intervals, or both belong to an infinite number of unlucky intervals, the smallest of them is considered to be luckier than the other.

Given a vector <int> luckySet, return the top n luckiest positive integers sorted in descending order by luckiness (in other words, each element of the vector <int> must be luckier than the next element).

DEFINITION
Class:UnluckyIntervals
Method:getLuckiest
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> getLuckiest(vector <int> luckySet, int n)


CONSTRAINTS
-luckySet will contain between 1 and 50 elements, inclusive.
-Each element of luckySet will be between 1 and 1000000000, inclusive.
-Each element of luckySet will be distinct.
-n will be between 1 and 100, inclusive.


EXAMPLES

0)
{3}
6

Returns: {3, 1, 2, 4, 5, 6 }

0 unlucky intervals contain 3.
1 unlucky interval contains 1: [1,2].
1 unlucky interval contains 2: [1, 2].
Since 1 and 2 are inside an equal number of intervals, 1 is considered luckier because it is less than 2.
For every number greater than 3, there is an infinite number of unlucky intervals that contain it. However, 4 and 5 are considered to be the luckiest among them, as they are smallest.

1)
{5, 11, 18}
9

Returns: {5, 11, 18, 1, 4, 6, 10, 2, 3 }

3 unlucky intervals: [1,2], [1,3] and [1,4] include 1. 
3 unlucky intervals: [1,4], [2,4] and [3,4] include 4. 
4 unlucky intervals: [6,7], [6,8], [6,9] and [6,10] include 6. 
4 unlucky intervals: [6,10], [7,10], [8,10] and [9,10] include 10. 
5 unlucky intervals: [1,2], [1,3], [1,4], [2,3] and [2,4] include 2. 
5 unlucky intervals: [1,3], [1,4], [2,3], [2,4] and [3,4] include 3. 



2)
{7, 13, 18}
9

Returns: {7, 13, 18, 14, 17, 8, 12, 1, 6 }



3)
{1000, 1004, 4000, 4003, 5000}
19

Returns: {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }



4)
{1000000000}
8

Returns: {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {3, 1, 2, 4, 5, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 11, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {5, 11, 18, 1, 4, 6, 10, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {7, 13, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {7, 13, 18, 14, 17, 8, 12, 1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000, 1004, 4000, 4003, 5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arr2[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getLuckiest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  UnluckyIntervals test;

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
