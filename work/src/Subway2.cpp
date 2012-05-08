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

class Subway2 {

 public:
  double minTime(int length, int mA, int mV)
  {
    double result = 0;
    // -- main code --

    double len = 1.0 * length / 2.0;
    double ma = mA;
    double mv = mV;
    
    // len = 0.5 * mA * tt^2
    double tt = sqrt(len * 2.0 / mA);
    double mt = mv / ma;

    if(tt < mt) {
      result = 2 * tt;
    }else {
      double at = mt;
      double rl = len - 0.5 * ma * mt * mt;

      at += rl / mv;
      
      result = 2 * at;
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
Subway trains can move people quickly from one station to the next. It is known that the distance between two consecutive stations is length meters. For safety, the train can't move faster than maxVelocity meters/sec. For comfort, the absolute acceleration can't be larger than maxAcceleration meters/sec^2. The train starts with velocity 0 meters/sec, and it must stop at the next station (i.e., arrive there with a velocity of 0 meters/sec). Return the minimal possible time to get to the next station.


DEFINITION
Class:Subway2
Method:minTime
Parameters:int, int, int
Returns:double
Method signature:double minTime(int length, int maxAcceleration, int maxVelocity)


NOTES
-Your return value must be accurate to within an absolute or relative tolerance of 1E-9.
-If the train's speed at time 0 is v0 and the acceleration is always a, then at time t the speed will be (v0 + t * a) and the train will be (v0 * t + 0.5 * a * t^2) away.


CONSTRAINTS
-length, maxAcceleration and maxVelocity will each be between 1 and 1000, inclusive.


EXAMPLES

0)
1
2
10

Returns: 1.4142135623730951

maxVelocity is very large. So the train can keep speeding up until it reaches position 0.5.

1)
1
1
1

Returns: 2.0



2)
10
1
1

Returns: 11.0

The train reaches its maximum velocity after 1 second, while traveling 0.5 meters.  It then travels the next 9 meters in 9 seconds, and takes 1 second to decelerate to 0 m/s while covering the final 0.5 meters.

3)
1
10
1

Returns: 1.1



4)
778
887
384

Returns: 2.458961621570838

5)
336
794
916

Returns: 1.301036207838119

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 10; double Arg3 = 1.4142135623730951; verify_case(0, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; double Arg3 = 2.0; verify_case(1, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; double Arg3 = 11.0; verify_case(2, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; double Arg3 = 1.1; verify_case(3, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 778; int Arg1 = 887; int Arg2 = 384; double Arg3 = 2.458961621570838; verify_case(4, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 336; int Arg1 = 794; int Arg2 = 916; double Arg3 = 1.301036207838119; verify_case(5, Arg3, minTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Subway2 test;

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
