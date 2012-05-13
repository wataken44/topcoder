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

class PrimeSoccer {

 public:
  bool isPrime(int n)
  {
    if(n < 2) return false;

    FOR(i, 2, n) {
      if(n % i == 0) return false;
    }
    return true;
  }

  double getProbability(int skillOfTeamA, int skillOfTeamB)
  {
    double pA = 0.01 * skillOfTeamA;
    double pB = 0.01 * skillOfTeamB;

    vector< vector< double > > dpa(19, vector< double >(19, 0.0));
    vector< vector< double > > dpb(19, vector< double >(19, 0.0));

    dpa[1][0] = 1 - pA;
    dpa[1][1] = pA;

    dpb[1][0] = 1 - pB;
    dpb[1][1] = pB;
    
    UPTO(t, 2, 18) {
      UPTO(s, 0, 18) {
        dpa[t][s] = dpa[t - 1][s] * (1 - pA);
        if(s > 0) dpa[t][s] += dpa[t - 1][s - 1] * pA;

        dpb[t][s] = dpb[t - 1][s] * (1 - pB);
        if(s > 0) dpb[t][s] += dpb[t - 1][s - 1] * pB;
      }
    }
    
    double result = 0;
    // -- main code --

    TIMES(a, 19) {
      TIMES(b, 19) {
        if(isPrime(a) || isPrime(b)) {
          result += dpa[18][a] * dpb[18][b];
        }
      }
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are watching a soccer match, and you wonder what the probability is that at least one of the two teams will score a prime number of goals.  The game lasts 90 minutes, and to simplify the analysis, we will split the match into five-minute intervals.  The first interval is the first five minutes, the second interval is the next five minutes, and so on.  During each interval, there is a skillOfTeamA percent probability that team A will score a goal, and a skillOfTeamB percent probability that teamB will score a goal.  Assume that each team will score at most one goal within each interval.  Return the probability that at least one team will have a prime number as its final score.

DEFINITION
Class:PrimeSoccer
Method:getProbability
Parameters:int, int
Returns:double
Method signature:double getProbability(int skillOfTeamA, int skillOfTeamB)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-A prime number is a number that has exactly two divisors, 1 and itself. Note that 0 and 1 are not prime.


CONSTRAINTS
-skillOfTeamA will be between 0 and 100, inclusive.
-skillOfTeamB will be between 0 and 100, inclusive.


EXAMPLES

0)
50
50

Returns: 0.5265618908306351



1)
100
100

Returns: 0.0

Both teams will score a goal in each interval, so the final result will be 18 to 18.

2)
12
89

Returns: 0.6772047168840167



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PrimeSoccer test;

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
