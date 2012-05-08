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

class ArithmeticProgression {

 public:
  double minCommonDifference(int a0, vector <int> seq)
  {
    // -- main code --
    vector<double> cand;

    TIMES(i, seq.size()) {
      int ii = i + 1;
      int b = seq[i];

      double c = (b - a0) * 1.0 / ii;
      if(c < 0.0) continue;
      // DUMP(c);
      
      bool ok = true;
      TIMES(k, seq.size()) {
        int kk = k + 1;
        if(seq[k] != a0 + static_cast<int>(floor(1e-8 +  c * kk))) {
          ok = false;
          break;
        }
      }
      if(ok) cand.push_back(c);
    }

    sort(cand.begin(), cand.end());

    if(seq.empty()) {
      return 0.0;
    }else if(cand.empty()) {
      return -1;
    }else {
      return cand.front();
    }
  }

// BEGIN CUT HERE
  void debug()
  {
    
    int Arg0 = 885027;
    int Arr1[] = {885116, 885206, 885296, 885385, 885475, 885565, 885654, 885744, 885834, 885924, 886013, 886103, 886193, 886282, 886372, 886462, 886552, 886641, 886731, 886821, 886910, 887000, 887090, 887179, 887269, 887359, 887449, 887538, 887628, 887718, 887807, 887897, 887987, 888077, 888166, 888256, 888346, 888435, 888525, 888615, 888704, 888794, 888884};

    vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    double Arg2 = 6.75;
    verify_case(-1, Arg2, minCommonDifference(Arg0, Arg1));

  }
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains subscripts that may not display properly if viewed outside of the applet.

In mathematics, an arithmetic progression or arithmetic sequence is a sequence of numbers such that the difference of any two successive members of the sequence is a constant. For instance, the sequence 3, 5, 7, 9, 11, 13... is an arithmetic progression with common difference 2. An arithmetic sequence can always be represented as an=a0+n*d.


You will be given a sequence seq, where seqi = [ai+1] for some nondecreasing arithmetic sequence a (both indices are 0-based). [x] denotes the floor function (see Notes). The sequence a is defined as a0+i*d. Return the minimal possible value for d. If no possible value exists for d, return -1 instead.


DEFINITION
Class:ArithmeticProgression
Method:minCommonDifference
Parameters:int, vector <int>
Returns:double
Method signature:double minCommonDifference(int a0, vector <int> seq)


NOTES
-[x] denotes the floor function of x which returns the highest integer less than or equal to x. For example, [3.4] = 3, [0.6] = 0, [-1.2] = -2 and [-0.6] = -1.
-Your return value must be accurate to within an absolute or relative tolerance of 1E-9.


CONSTRAINTS
-seq will contain between 0 and 50 elements, inclusive.
-Each element of seq will be between -10^6 and 10^6, inclusive.
-a0 will be between -10^6 and 10^6, inclusive.


EXAMPLES

0)
0
{6, 13, 20, 27}

Returns: 6.75



1)
1
{2, 3, 4, 5, 6}

Returns: 1.0



2)
3
{}

Returns: 0.0

Since the sequence a is nondecreasing, d must be at least 0.

3)
3
{3, 3, 3, 3, 4}

Returns: 0.2



4)
1
{-3}

Returns: -1.0



5)
0
{6, 14}

Returns: -1.0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arr1[] = {6, 13, 20, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.75; verify_case(0, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {3, 3, 3, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.2; verify_case(3, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(4, Arg2, minCommonDifference(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {6, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(5, Arg2, minCommonDifference(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ArithmeticProgression test;

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
