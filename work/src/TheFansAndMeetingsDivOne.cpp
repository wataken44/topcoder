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

class TheFansAndMeetingsDivOne {

 public:
  double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB, int k)
  {
    // -- main code --

    map<int, double> expJ;
    map<int, double> expB;

    int sz = minJ.size();
    
    FOR(i, 0, sz) {
      int rJ = maxJ[i] - minJ[i] + 1;
      UPTO(j, minJ[i], maxJ[i]) {
        if(expJ.find(j) == expJ.end()) expJ[j] = 0;
        expJ[j] += k * 1.0 / (rJ * sz);
      }

      int rB = maxB[i] - minB[i] + 1;
      UPTO(j, minB[i], maxB[i]) {
        if(expB.find(j) == expB.end()) expB[j] = 0;
        expB[j] += k * 1.0 / (rB * sz);
      }
    }

    DUMP(expJ);DUMP(expB);
    double result = 0;

    EACH(expJ, it) {
      int e = it->first;
      double pJ = it->second;

      if(expB.find(e) == expB.end()) {
        continue;
      }
      result += pJ * expB[e];
      DUMP(result);DUMP(expB[e]);DUMP(e);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
John and Brus have become very famous people all over the world, especially in Bolivia.
Stories written about them by a Bolivian man have become very popular in that country.
John and Brus have decided to visit their fans in Bolivia, but unfortunately, they only have time to visit k cities each.



John will randomly choose k distinct cities.
Each set of k cities has the same probability of being chosen.
If he chooses the i-th city, he will meet between minJ[i] and maxJ[i] fans there, inclusive.
Each possible number of fans is equally likely.
Brus will go through the exact same process, but in his case, the number of fans he would meet in the i-th city is between minB[i] and maxB[i], inclusive.
Return the probability that John and Brus will each meet the same total number of fans.



DEFINITION
Class:TheFansAndMeetingsDivOne
Method:find
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB, int k)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-minJ will contain between 1 and 40 elements, inclusive.
-minJ, maxJ, minB and maxB will contain the same number of elements.
-Each element of minJ, maxJ, minB and maxB will be between 1 and 40, inclusive.
-The i-th element of minJ will be less than or equal to the i-th element of maxJ.
-The i-th element of minB will be less than or equal to the i-th element of maxB.
-k will be between 1 and the number of elements in minJ, inclusive.


EXAMPLES

0)
{1}
{9}
{5}
{5}
1

Returns: 0.1111111111111111

Brus will definitely meet five fans, and the probability of John meeting five fans as well is 1/9.

1)
{5, 2, 5, 1, 1, 2, 4, 1}
{7, 6, 7, 3, 4, 3, 5, 1}
{8, 9, 7, 11, 12, 7, 8, 40}
{9, 10, 9, 33, 14, 7, 11, 40}
2

Returns: 4.724111866969009E-5

The only possible same total number of fans that John and Brus can meet is 14. In order for them to meet 14 fans, John must visit cities 0 and 2 and Brus must visit cities 2 and 5. In each of these cities they must meet exactly 7 fans.

2)
{4, 7, 4}
{7, 7, 7}
{40, 40, 40}
{40, 40, 40}
1

Returns: 0.0

No chance to meet the same number of fans.

3)
{3, 6, 2, 1, 1, 10, 3}
{6, 9, 5, 6, 5, 10, 9}
{1, 1, 1, 1, 8, 3, 1}
{3, 9, 7, 3, 10, 6, 5}
4

Returns: 0.047082056525158976

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; double Arg5 = 0.1111111111111111; verify_case(0, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {5, 2, 5, 1, 1, 2, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 6, 7, 3, 4, 3, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 9, 7, 11, 12, 7, 8, 40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 10, 9, 33, 14, 7, 11, 40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; double Arg5 = 4.724111866969009E-5; verify_case(1, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {4, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40, 40, 40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {40, 40, 40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; double Arg5 = 0.0; verify_case(2, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {3, 6, 2, 1, 1, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 9, 5, 6, 5, 10, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 8, 3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 9, 7, 3, 10, 6, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; double Arg5 = 0.047082056525158976; verify_case(3, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TheFansAndMeetingsDivOne test;

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
