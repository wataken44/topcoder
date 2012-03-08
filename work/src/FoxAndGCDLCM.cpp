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

class FoxAndGCDLCM {

 public:
  long long get(long long G, long long L)
  {
    if(L % G != 0) return -1;

    typedef long long ll;
    
    vector<ll> gd;
    map<ll, int> ld;

    ll g = G;
    ll n = 2;
    while(g > 1) {
      if(g % n == 0) {
        gd.push_back(n);
        g /= n;
      }else {
        n += n != 2 ? 2 : 1;
      }
    }
    
    ll l = L / G;
    n = 2;
    while(l > 1) {
      if(l % n == 0) {
        ld[n] = 0;
        while(l % n == 0) {
          ++ld[n];
          l /= n;
        }
      }else {
        n += n != 2 ? 2 : 1;
      }
    }

    DUMP(gd);
    DUMP(ld);

    ll sum = LONG_LONG_MAX;

    int sz = ld.size();

    vector<ll> dd;
    EACH(ld, it) { dd.push_back(it->first); }

    DUMP(dd);
    TIMES(b, 1 << sz) {

      ll a = 1;
      TIMES(i, sz) {
        if( 1 == ((b >> i) & 1) ) {
          TIMES(k, ld[dd[i]]) {
            a *= dd[i];
          }
        }
      }

      //DUMP(b);DUMP(a);DUMP(L/G/a);
      
      ll s = a + (L / G) / a;
      sum = min(sum, s);
    }
    
    long long result = sum * G;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. One day Saburo found two interesting positive integers: A and B.

On the next day, Saburo met Jiro and wanted to tell him the two integers. However, he managed to forget their values. All Saburo could remember was their greatest common divisor G and their least common multiple L.

You are given two long longs: G and L. Find the original integers A and B, and return the value of A+B. If there are multiple pairs of A and B that correspond to G and L, pick the one that minimizes A+B. If it is impossible to find such A and B (i.e., Saburo made a mistake somewhere), return -1.

DEFINITION
Class:FoxAndGCDLCM
Method:get
Parameters:long long, long long
Returns:long long
Method signature:long long get(long long G, long long L)


NOTES
-The greatest common divisor of two integers a and b is the largest positive integer that divides both a and b without any remainder.
-The least common multiple of two integers a and b is the smallest positive integer that is a multiple of both a and b.


CONSTRAINTS
-G will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-L will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2
20

Returns: 14

The possible pairs of A and B are {2, 20} and {4, 10}. We need to pick {4, 10} since 4+10 is the smallest sum of A and B.

1)
5
8

Returns: -1

There are no pairs of A and B such that their greatest common divisor is 5 and their least common multiple is 8.

2)
1000
100

Returns: -1



3)
100
1000

Returns: 700



4)
10
950863963000

Returns: 6298430



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 20LL; long long Arg2 = 14LL; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 8LL; long long Arg2 = -1LL; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1000LL; long long Arg1 = 100LL; long long Arg2 = -1LL; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 100LL; long long Arg1 = 1000LL; long long Arg2 = 700LL; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 10LL; long long Arg1 = 950863963000LL; long long Arg2 = 6298430LL; verify_case(4, Arg2, get(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxAndGCDLCM test;

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
