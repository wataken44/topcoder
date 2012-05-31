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

class PlayGame {

 public:
  int saveCreatures(vector <int> you, vector <int> computer)
  {
    // -- main code --
    sort(you.begin(), you.end());
    sort(computer.begin(), computer.end());
    
    int result = 0;
    int sz = you.size();
    
    TIMES(a, sz + 2) {

      int saved = 0;
      TIMES(b, sz) {
        if(you[b] > computer[(b + a) % sz] ) saved += you[b];
      }
      result = max(saved, result);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are playing a computer game and a big fight is planned between two armies. 
You and your computer opponent will line up your respective units in two rows, with each of your units facing exactly one of your opponent's units and vice versa. Then, each pair of units, who face each other will fight and the stronger one will be victorious, while the weaker one will be captured. If two opposing units are equally strong, your unit will lose and be captured. You know how the computer will arrange its units, and must decide how to line up yours. You want to maximize the sum of the strengths of your units that are not captured during the battle.

You will be given a vector <int> you and a vector <int> computer that specify the strengths of the units that you and the computer have, respectively. The return value should be an int, the maximum total strength of your units that are not captured.

DEFINITION
Class:PlayGame
Method:saveCreatures
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int saveCreatures(vector <int> you, vector <int> computer)


CONSTRAINTS
-you and computer will have the same number of elements.
-you and computer will contain between 1 and 50 elements, inclusive.
-Each element of you and computer will be between 1 and 1000, inclusive.


EXAMPLES

0)
{5, 15, 100, 1, 5}
{5, 15, 100, 1, 5}

Returns: 120

Your units with strengths of 100 and 15, along with one of your strength 5 units, can avoid capture.

1)
{1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}
{1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}

Returns: 0

All units are equally strong, so all your units are captured.

2)
{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}
{2, 4, 6, 8, 10, 12, 14, 16, 18, 20}

Returns: 99

You assign your weakest unit to the computer's strongest unit. Then you assign all your other units in such a way that each of your units has a strength one higher than the opposing unit. So all your units except the weakest one avoid capture.

3)
{2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}

Returns: 65

All your units can win.

4)
{651, 321, 106, 503, 227, 290, 915, 549, 660, 115,
 491, 378, 495, 789, 507, 381, 685, 530, 603, 394,
 7, 704, 101, 620, 859, 490, 744, 495, 379, 781,
 550, 356, 950, 628, 177, 373, 132, 740, 946, 609,
 29, 329, 57, 636, 132, 843, 860, 594, 718, 849}
{16, 127, 704, 614, 218, 67, 169, 621, 340, 319,
 366, 658, 798, 803, 524, 608, 794, 896, 145, 627,
 401, 253, 137, 851, 67, 426, 571, 302, 546, 225,
 311, 111, 804, 135, 284, 784, 890, 786, 740, 612,
 360, 852, 228, 859, 229, 249, 540, 979, 55, 82}

Returns: 25084

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 15, 100, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 15, 100, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 120; verify_case(0, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 99; verify_case(2, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 65; verify_case(3, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {651, 321, 106, 503, 227, 290, 915, 549, 660, 115,
 491, 378, 495, 789, 507, 381, 685, 530, 603, 394,
 7, 704, 101, 620, 859, 490, 744, 495, 379, 781,
 550, 356, 950, 628, 177, 373, 132, 740, 946, 609,
 29, 329, 57, 636, 132, 843, 860, 594, 718, 849}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16, 127, 704, 614, 218, 67, 169, 621, 340, 319,
 366, 658, 798, 803, 524, 608, 794, 896, 145, 627,
 401, 253, 137, 851, 67, 426, 571, 302, 546, 225,
 311, 111, 804, 135, 284, 784, 890, 786, 740, 612,
 360, 852, 228, 859, 229, 249, 540, 979, 55, 82}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25084; verify_case(4, Arg2, saveCreatures(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PlayGame test;

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
