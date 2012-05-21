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

class MonstersAndBunnies {

 public:
  struct State {
    double p;
    int m;
    int b;

    State(double p_, int m_, int b_) : p(p_), m(m_), b(b_) {}
  };
  
  double survivalProbability(int M, int B)
  {

    vector< vector<State> > dp
        (2, vector<State>());
    
    double killed = 0;
    int cycle = 0;

    dp[0].push_back(State(1.0, M, B));
    
    while(true) {
      bool updated = false;
      
      int r = cycle % 2;
      int u = (cycle + 1) % 2;

      vector< State >& rdp = dp[r];
      vector< State >& udp = dp[u];

      udp.clear();
      
      TIMES(i, rdp.size()) {
        State& s = rdp[i];

        double rp = s.p;
        int m = s.m;
        int b = s.b;

        if(m == 0) continue;
        
        if(rp > 1e-5) {
          updated = true;

          // 1 + m + b
          int all = 1 + m + b;
          int ac = comb(all, 2);
          
          // ym
          killed += rp * m / ac;

          // mm
          if(m > 1) {
            udp.push_back(State(rp * comb(m, 2) / ac, m - 2, b));  
          }
            
          // mb
          if(b > 0) {
            udp.push_back(State(rp * m * b / ac, m, b - 1));  
          }
          
          // yb or bb
          int bb = 0;
          if(b > 1) bb = comb(b, 2);
          udp.push_back(State(rp * (b + bb)/ ac, m, b)); 
          
        }
      }
      
      ++cycle;
      if(!updated) break;
    }
    
    return 1 - killed;	
  }

  long long comb(int n, int k)
  {
    int r = 1;

    UPTO(kk, 1, k) {
      r = r * (n + 1 - kk) / kk;
    }
    
    return r;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
You just entered a strange town. The town is currently inhabited by M monsters and B bunnies.



The inhabitants interact in the following way: Whenever two bunnies meet, nothing happens.
Whenever a monster meets a bunny, the monster eats the bunny.
Whenever two monsters meet, they start fighting and they both die in the fight.



Whenever you meet a bunny, you can decide whether you kill it or not.
A bunny will never kill you. You can not kill a monster. However, if you meet a monster, it will kill you without
hesitation.



All the town's inhabitants roam the town at random. More precisely, we will make the following assumptions.



Meetings will occur at different moments in time.
Each time exactly two beings will meet.
Those two beings are always chosen uniformly at random from the set of all living beings in town, including you.



You win if at some moment you can not be killed anymore.
You are not allowed to leave the town until you either win or get killed.



Write a method that will calculate the expected probability that you will win.


DEFINITION
Class:MonstersAndBunnies
Method:survivalProbability
Parameters:int, int
Returns:double
Method signature:double survivalProbability(int M, int B)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-When deciding whether to kill a bunny you just met, your only goal is to maximize your winning probability.


CONSTRAINTS
-M will be between 0 and 1,000, inclusive.
-B will be between 0 and 1,000, inclusive.


EXAMPLES

0)
0
0

Returns: 1.0

This town is empty. As soon as you enter it, you win.

1)
0
47

Returns: 1.0

Peaceful bunny pastures, you will not get killed here.

2)
1
0

Returns: 0.0

Sooner or later the monster will find you and kill you.

3)
1
47

Returns: 0.0

The bunnies won't help you. Sooner or later the monster will find you and kill you.

4)
2
0

Returns: 0.3333333333333333

In 1/3 of all cases the two monsters meet first, kill each other and you win. In the other 2/3 cases, one of the two monsters meets you first and kills you.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; double Arg2 = 1.0; verify_case(0, Arg2, survivalProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 47; double Arg2 = 1.0; verify_case(1, Arg2, survivalProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; double Arg2 = 0.0; verify_case(2, Arg2, survivalProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 47; double Arg2 = 0.0; verify_case(3, Arg2, survivalProbability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 0; double Arg2 = 0.3333333333333333; verify_case(4, Arg2, survivalProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MonstersAndBunnies test;

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
