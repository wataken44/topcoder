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

class MagicBlizzard {

 public:
  double expectation(vector <int> range, vector <int> amount)
  {
    range.push_back(0);
    amount.push_back(0);

    int n = range.size();
    
    swap(range[0], range[n-1]);
    swap(amount[0], amount[n-1]);


    //DUMP(range);DUMP(amount);
    FOR(i, 1, n) {
      FOR(k, i+1, n) {
        if(range[i] > range[k]) {
          swap(range[i], range[k]);
          swap(amount[i], amount[k]);
        }
      }
    }
    DUMP(range);DUMP(amount);

    vector<int> area(1, 0);
    FOR(i, 1, n) {
      int len = 1 + 2 * (range[i] - range[i - 1]);
      int a = len * len;
      area.push_back(a);
    }
    
    double result = 0;
    // -- main code --

    FOR(i, 1, n) {
      FOR(k, i, n) {
        int a = area[i] - area[i-1];

        double tmp = 1.0 * amount[k];
        double r = tmp * tmp / area[k];
        FOR(m, k, n) {
          if(m == k) continue;
          r += (2.0 * amount[m] / area[m]) * (1.0 * amount[k] / area[k]);
        }
        result += r * a;
      }
      DUMP(result);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Today is the Christmas Eve. People around the world celebrate this 
holiday. The following story takes place in the land of reindeer, where Santa Claus resides.



For Christmas, the land should be covered by snow, but there was no snowfall yet. Luckily, the reindeer know a spell called Magic Blizzard that can make it snow.



The land can be imagined as an infinite grid of unit squares with integer coordinates. When a reindeer casts Magic Blizzard, the effect depends on two parameters: the range of the spell R and the amount A. The spell will generate A snowballs. Each snowball will fall on some square with coordinates (x,y) such that -R <= x, y <= R. For each snowball, the target square is chosen uniformly at random. Targets for snowballs are chosen independently of each other. (Hence it is possible that multiple snowballs will hit the same square.)



N reindeer are going to cast Magic Blizzard, one after another. You are given two vector <int>s range and amount of length N. The spell by reindeer i will have range equal to range[i] and the amount of snowballs it produces will be amount[i].



The beauty of the landscape can be computed as the total beauty of all squares. The beauty of a square that was hit by x snowballs is x^2.



Your method must compute and return the expected value of the beauty of the landscape.

DEFINITION
Class:MagicBlizzard
Method:expectation
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double expectation(vector <int> range, vector <int> amount)


NOTES
-The returned value must be accurate to within a relative or absolute error of 1e-9.


CONSTRAINTS
-range will contain between 1 and 50 elements, inclusive.
-amount will contain between 1 and 50 elements, inclusive.
-range and amount will contain the same number of elements.
-Each element in range will be between 0 and 10,000, inclusive.
-Each element in amount will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{1,0}
{1,1}

Returns: 2.2222222222222223

The second snowball will surely fall on the square (0,0). The first snowball will fall on the same square with probability 1/9. If that happens, the beauty of the landscape will be 2^2 = 4. Otherwise, we will have two squares containing one snowball each, for a total beauty of 1^2 + 1^2 = 2. So the expected beauty is (1/9) * 4 + (8/9) * 2 = 20/9.

1)
{1,0}
{2,1}

Returns: 3.666666666666667



2)
{5,2,6,5}
{1,2,2,3}

Returns: 8.46525111252384



3)
{7,11,2,13,3,19,5,17}
{16,8,4,15,12,9,10,6}

Returns: 98.55659436211914



4)
{0,0,0,0,0,0,0,0,0,0}
{10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}

Returns: 1.0E10

Note that the answer can be very large.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.2222222222222223; verify_case(0, Arg2, expectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.666666666666667; verify_case(1, Arg2, expectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,2,6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.46525111252384; verify_case(2, Arg2, expectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7,11,2,13,3,19,5,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16,8,4,15,12,9,10,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 98.55659436211914; verify_case(3, Arg2, expectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0E10; verify_case(4, Arg2, expectation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MagicBlizzard test;

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
