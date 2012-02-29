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

class EllysNumbers {

 public:
  typedef long long ll;
  vector<ll> m_special;

  long long getSubsets(long long n, vector <string> special)
  {
    m_special.clear();

    string s;
    TIMES(i, special.size()) {
      s += special[i];
    }

    istringstream iss(s);
    bool has1 = false;

    while(!iss.eof()) {
      ll k;
      iss >> k;
      if(k == 1) {
        has1 = true;
      }else if(n >= k && n % k == 0){
        m_special.push_back(k);
      }
    }

    sort(m_special.begin(), m_special.end());
    
    return go(n, has1);	
  }

  ll go(ll n, bool has1) {
    ll ret = 0;

    //DUMP(m_special);

    int sz = m_special.size();
    TIMES(i, sz) {
      if(n > m_special[i]) {
        ret += rec(n / m_special[i], i + 1, m_special[i]);
      }else if(n == m_special[i]){
        ret += 1;
      }
    }
    
    return has1 ? ret * 2 : ret;
  }

  ll rec(ll n, int p, ll d) {
    int sz = m_special.size();
    ll ret = 0;
    FOR(k, p, sz) {
      ll pk = m_special[k];
      if(n % pk == 0) {
        if(gcd(d, pk) == 1) {
          if(n > pk) {
            ret += rec(n / pk, k + 1, d * pk);
          }else if(n == pk) {
            ++ret;
          }
        }
      }
    }
    return ret;
  }

  ll gcd(ll a, ll b) {
    if(a > b) swap(a, b);
    while(a != b && a > 0) {
      ll t = b % a;
      b = a;
      a = t;
    }
    return b;
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Elly's favourite number is n. She also has a list of distinct positive integers. We will call these integers special. She would like to know in how many ways she can represent n as a product of some pairwise relatively prime special integers.

You are given the long long n and a vector <string> special. Concatenate the elements of special to obtain a space-separated list of Elly's special integers.
Return the number of ways in which the desired product can be formed.


DEFINITION
Class:EllysNumbers
Method:getSubsets
Parameters:long long, vector <string>
Returns:long long
Method signature:long long getSubsets(long long n, vector <string> special)


NOTES
-When forming the product, the order of the special integers does not matter.
-There may be pairs of special integers that are not relatively prime. This just means that each valid product may contain at most one of those two special integers.
-You may assume that for each valid input the correct output fits into a long long.
-Two positive integers are relatively prime if the only positive integer that divides both of them is 1. For example (5, 7) and (6, 35) are relatively prime, while (12, 18) and (7, 42) are not.


CONSTRAINTS
-n will be between 2 and 10^18, inclusive.
-Each special integer will be between 1 and 10^9, inclusive.
-All special integers will be distinct.
-The number of special integers will be between 1 and 500, inclusive.
-special will contain between 1 and 50 elements, inclusive.
-Each element of special will contain between 1 and 50 characters, inclusive.
-Each character in each element of special will be either a digit or a space ('0'-'9', ' ').
-The concatenation of elements of special will represent a valid single-space separated list of integers (with no leading or trailing spaces). Each special integer will be written with no leading zeros.


EXAMPLES

0)
12
{"4 2 5 6 3"}

Returns: 1

There are two ways to represent 12 as a product of special integers: 3*4 and 2*6.
Only the first way is valid because 2 and 6 are not relatively prime.

1)
42
{"1 2 3 4 5 6 7 13 14 21 42"}

Returns: 10

Forty-two can be represented as 2*3*7, 1*2*3*7, 2*21, 1*2*21, 3*14, 1*3*14, 6*7, 1*6*7, 42 and 1*42. All of those products contain only relatively prime special numbers, so the answer is 10.

2)
1337
{"1 13 42 666 2674"}

Returns: 0

Sometimes it is impossible to represent n as a product of special integers.

3)
1073741824
{"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
 "6384 32768 65536 131072 262144 524288 1048576 2097",
 "152 4194304 8388608 16777216 33554432 67108864 134",
 "217728 268435456 536870912"}

Returns: 0

Although n can be represented in many ways, none of them is using only relatively prime special integers.

4)
7420738134810
{"435 625199055 4199 33263 17 222870 284870433 72093",
 "2379 7 11 31 247110827 23 1771 81809 851968487 13 ", 
 "476379795 1001 5 435274114 38264554 7429 239906525",
 " 3 227183706 887045414 606786670 3795 797605175 29",
 " 30 747186719 19 2 562347843 74 2294 588002688 743",
 "6429 703 591740547 36657492 37 444178205 1002001 2",
 "17626404"}

Returns: 110

Don't forget to concatenate the elements of special.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 12LL; string Arr1[] = {"4 2 5 6 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 42LL; string Arr1[] = {"1 2 3 4 5 6 7 13 14 21 42"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(1, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1337LL; string Arr1[] = {"1 13 42 666 2674"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1073741824LL; string Arr1[] = {"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
 "6384 32768 65536 131072 262144 524288 1048576 2097",
 "152 4194304 8388608 16777216 33554432 67108864 134",
 "217728 268435456 536870912"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 7420738134810LL; string Arr1[] = {"435 625199055 4199 33263 17 222870 284870433 72093",
 "2379 7 11 31 247110827 23 1771 81809 851968487 13 ", 
 "476379795 1001 5 435274114 38264554 7429 239906525",
 " 3 227183706 887045414 606786670 3795 797605175 29",
 " 30 747186719 19 2 562347843 74 2294 588002688 743",
 "6429 703 591740547 36657492 37 444178205 1002001 2",
 "17626404"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 110LL; verify_case(4, Arg2, getSubsets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  EllysNumbers test;

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
