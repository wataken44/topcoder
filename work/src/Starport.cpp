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

template<typename T>
T gcd(T a, T b)
{
  if(a > b) swap(a, b);
  return a == 0 ? b : gcd(b % a, a);
}

class Starport {

 public:
  double getExpectedTime(int N, int M)
  {
    // -- main code --

    int g = gcd(N, M);
    
    return (N - g) / 2.0 ;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// A new starport has just started working. Starting from some moment of time (call it minute 0), a new spaceship arrives at the starport every M minutes. In other words, spaceships arrive at the starport at minutes 0, M, 2*M, 3*M and so on. 

Similarly, starting from minute 0 and repeating each N minutes, all arrived spaceships that are still placed at the port are teleported to the shed. If a spaceship arrives at the exact same minute when such a teleportation happens, it will be teleported immediately. Otherwise it will need to wait until the next teleportation happens.

Let the waiting time of a spaceship be the time between its arrival and its teleportation to the shed. Return the average waiting time of a spaceship in minutes. See notes for an exact definition.


DEFINITION
Class:Starport
Method:getExpectedTime
Parameters:int, int
Returns:double
Method signature:double getExpectedTime(int N, int M)


NOTES
-Let W(i) be the waiting time for the spaceship that arrives at minute M * i. The average waiting time can be defined as the limit of (W(0) + W(1) + ... + W(P - 1)) / P when P tends to positive infinity. This limit will always exist.
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-N and M will each be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
4
2

Returns: 1.0

Spaceships arrive at the starport at minutes 0, 2, 4, 6, 8, and so on. Teleportations are done at minutes 0, 4, 8, and so on. The waiting times for the spaceships are, correspondingly, 0, 2, 0, 2, 0, and so on, so the expected waiting time is 1.

1)
5
3

Returns: 2.0



2)
6
1

Returns: 2.5



3)
12345
2345

Returns: 6170.0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3; double Arg2 = 2.0; verify_case(1, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 1; double Arg2 = 2.5; verify_case(2, Arg2, getExpectedTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12345; int Arg1 = 2345; double Arg2 = 6170.0; verify_case(3, Arg2, getExpectedTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Starport test;

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
