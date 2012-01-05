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

class PolicePair {

 public:
  vector <int> bestSquad(vector <int> skillStart, vector <int> skillEnd)
  {
    // -- main code --
    int min_rest = 1000000;
    int max_skill = 0;

    int num_police = 0;

    int sz = skillStart.size();
    
    FOR(i, 0, sz) {
      num_police += skillEnd[i] - skillStart[i] + 1;
    }
    
    DOWNTO(s, 2000, 2) {
      bool changed = true;

      vector< pair<int, int> > range;
      FOR(i, 0, sz) {
        range.push_back(make_pair(skillStart[i], skillEnd[i]));
      }

      FOR(x, 0, sz) {
        int skmin = s - range.second;
        int skmax = s - range.first;
      }
      
      while(changed) {
        changed = false;

      }
    }
    
    vector <int> result;
    result.push_back(min_rest, max_skill / 2);
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A lot of new police officers have joined the force this year and you want to assign them to squad cars. Each of the squad cars is assigned two officers and its "skill" is the average of the skills of the two officers assigned to it. So, for example, if you have officers with skills 2, 3 and 4 then you can make a squad car having skill 2.5 (assign the officers with skills 2 and 3 to it) or 3.5 (assign the officers with skills 3 and 4 to it) or 3 (assign the officers with skills 2 and 4 to it).  When you assign this year's batch of officers you want to do it in a uniform manner, that is, you want all the squads formed to have the same skill. For example, if you have officers with skills 1, 2, 3, 4 and 5 you can make two squads each of skill 3 (2,4 and 1,5) but an assignment which results in one squad car of skill 3 (2,4) and another of skill 2 (1,3) is not allowed.  As you can see, many times officers are left unassigned. Naturally you want to avoid this. Given the skills of this year's batch of officers you have to find the assignment that minimizes the number of officers left over. If there is more than one such assignment, pick the one in which the squad skill is highest.  The police officers' skills are given as ranges. The ith elements skillStart[i] and skillEnd[i] together specify the range skillStart[i] to skillEnd[i], inclusive. If you are given a range 10 to 200, it means you have 191 officers of skills 10,11,12,...198,199,200. All the given ranges together specify the officers you have. For example, if skillStart = {2,8} and skillEnd = {3,8}, it would mean you have 3 officers of skills 2, 3 and 8. Note that it is possible for ranges to overlap. For instance, if skillStart = {2,2} and skillEnd = {3,3}, it would mean you have 4 officers of skills 2, 2, 3 and 3.  Return a vector <int> with exactly two elements, where the first element is the number of officers left unassigned and the second element is the squad skill (rounded down) of the optimal assignment.

DEFINITION
Class:PolicePair
Method:bestSquad
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> bestSquad(vector <int> skillStart, vector <int> skillEnd)


CONSTRAINTS
-skillStart contains between 1 and 50 elements, inclusive.
-skillStart contains the same number of elements as skillEnd.
-Each element of skillStart and skillEnd will be between 1 and 1000, inclusive.
-No element of skillStart will be larger than the corresponding element of skillEnd.
-The total number of officers will be between 2 and 50,000, inclusive.


EXAMPLES

0)
{2}
{4}

Returns: { 1,  3 }

You have 3 officers of skills 2, 3 and 4.The optimal arrangement is assigning the officers of skill 3 and 4 to one squad car and leaving the officer with skill 2 unassigned. This leaves one officer unassigned and results in a squad skill of (3+4)/2 = 3.5 which rounds down to 3. Hence, you should return {1,3}

1)
{2,4}
{3,4}

Returns: { 1,  3 }

The same case as above, except the input is given in a different manner.

2)
{1}
{5}

Returns: { 1,  3 }

3)
{2,3}
{3,4}

Returns: { 0,  3 }

4)
{2,100,200}
{5,100,200}

Returns: { 2,  3 }

5)
{2,5}
{3,5}

Returns: { 1,  4 }

6)
{100,100,100,1}
{200,300,400,800}

Returns: { 503,  250 }

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, bestSquad(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, bestSquad(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, bestSquad(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, bestSquad(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,100,200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,100,200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, bestSquad(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {2,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, bestSquad(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {100,100,100,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200,300,400,800}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 503,  250 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, bestSquad(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PolicePair test;

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
