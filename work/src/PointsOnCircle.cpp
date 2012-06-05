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

class PointsOnCircle {

 public:
  typedef long long ll;

  long long count(int r)
  {
    // -- main code --

    vector<ll> dr;
    for(int k = 1; k * k <= r; ++k) {
      if(r % k != 0) continue;
      dr.push_back(k);
      if(r / k != k) dr.push_back(r / k);
    }
    sort(dr.begin(), dr.end());

    set<ll> drr;
    TIMES(y, dr.size()) {
      TIMES(x, dr.size()) {
        drr.insert(dr[y] * dr[x]);
      }
    }

    // DUMP(drr);
    
    long long d1 = 0;
    long long d3 = 0;
    EACH(drr, it) {
      ll k = *it;
      if((1LL * r * r) % k != 0) continue;
      ll q = 1LL * r * r / k;

      if(k > q) break;
      
      if(k % 4 == 1) {
        ++d1;
      }else if(k % 4 == 3) {
        ++d3;
      }

      if(k == q) continue;
      if(q % 4 == 1) {
        ++d1;
      }else if(q % 4 == 3) {
        ++d3;
      }
      
    }
    
    return 4LL * (d1 - d3);	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are given the radius r of a circle centered at the origin.  Your task is to return the number of lattice points (points whose coordinates are both integers) on the circle.  The number of pairs of integers (x, y) that satisfy x^2 + y^2 = n is given by the formula 4*(d1(n) - d3(n)), where di(n) denotes the number of divisors of n that leave a remainder of i when divided by 4.

DEFINITION
Class:PointsOnCircle
Method:count
Parameters:int
Returns:long long
Method signature:long long count(int r)


CONSTRAINTS
-r will be between 1 and 2*10^9, inclusive.


EXAMPLES

0)
1

Returns: 4

The only lattice points on the circle are (0, 1), (1, 0), (-1, 0), (0, -1).

1)
2000000000

Returns: 76



2)
3

Returns: 4

The number of lattice points on the circle of radius 3 is the same as the number of integer solutions of the equation x^2 + y^2 = 9. Using the formula from the problem statement we can calculate this number as 4*(d1(9) - d3(9)). It is easy to see that d1(9) = 2 (divisors 1 and 9) and d3(9) = 3 (divisor 3). So the answer is 4*(2 - 1) = 4.

3)
1053

Returns: 12



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2000000000; long long Arg1 = 76LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 1053; long long Arg1 = 12LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PointsOnCircle test;

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
