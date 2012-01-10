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

class BuyingFlowers {

 public:
  int buy(vector <int> roses, vector <int> lilies)
  {
    int result = INT_MAX;
    // -- main code --

    int sz = roses.size();

    UPTO(i, 1, (1 << sz) - 1) {
      int nr = 0;
      int nl = 0;

      TIMES(j, sz) {
        if((i >> j) & 1 == 1) {
          nr += roses[j];
          nl += lilies[j];
        }
      }

      int n = nr + nl;
      
      int ys = (int)ceil(pow(n, 0.5));

      DOWNTO(y, ys, 1) {
        if(n % y != 0) continue;
        int x = n / y;

        if(n % 2 == 0 && nr != nl) continue;
        if(n % 2 == 1 && abs(nr - nl) != 1) continue;

        result = min(result, abs(x - y));

        break;
      }
    }
    
    return result == INT_MAX ? -1 : result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Teddy loves roses and Tracy loves lilies. They wish to plant these flowers in a large garden.  

However, the only florist in town sells these flowers in packets which are represented by vector <int>s roses and lilies. The i-th packet contains roses[i] roses and lilies[i] lilies. Each packet can be bought only once.

Teddy and Tracy wish to buy some flowers and arrange them into a rectangular grid. This grid must be arranged such that each cell contains exactly one flower, and any two cells which share an edge must contain different kinds of flowers. Additionally, Teddy and Tracy must use all the flowers they buy.

Teddy and Tracy love square-shaped grids, so they wish to buy a set of packets such that they can arrange the flowers into the most square-like grid possible. More precisely, they wish to arrange the flowers into an R x C grid, where R and C are positive integers, such that |R-C| (|R-C| denotes the absolute value of R-C) is minimized. Return this minimum absolute value, or -1 if no valid arrangement exists.

DEFINITION
Class:BuyingFlowers
Method:buy
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int buy(vector <int> roses, vector <int> lilies)


CONSTRAINTS
-roses and lilies will contain the same number of elements, between 1 and 16, inclusive.
-Each element of roses and lilies will be between 0 and 10000, inclusive.
-The total number of flowers in each packet represented by roses and lilies will be greater than 0.


EXAMPLES

0)
{2, 4}
{4, 2}

Returns: 1

Buying all the packets to get 6 roses and 6 lilies, they can create a 3 x 4 grid with the following arrangement:

  RLRL
  LRLR
  RLRL

The difference of the height and the width of this arrangement is 1.

1)
{2, 7, 3}
{3, 4, 1}

Returns: 0

Buying the first and the third packets, they can create the following square arrangement:

  RLR
  LRL
  RLR


2)
{4, 5, 2, 1}
{6, 10, 5, 9}

Returns: -1

No valid grid can be created.

3)
{1, 208, 19, 0, 3, 234, 1, 106, 99, 17}
{58, 30, 3, 5, 0, 997, 9, 615, 77, 5}

Returns: 36



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, buy(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, buy(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 5, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 10, 5, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, buy(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 208, 19, 0, 3, 234, 1, 106, 99, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 30, 3, 5, 0, 997, 9, 615, 77, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36; verify_case(3, Arg2, buy(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BuyingFlowers test;

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
