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

class FoxAndDoraemon {

 public:
  vector<int> work;

  typedef pair<int, pair<int, int> > pipii;
  map<pipii, bool> memo;
  
  int minTime(vector <int> workCost, int splitCost)
  {
    sort(workCost.begin(), workCost.end());

    work = workCost;
    memo.clear();
    
    int sz = workCost.size();

    int nsp = 0;
    int nn = 1;
    while(nn < sz) {
      nsp += 1;
      nn *= 2;
    }

    set<int> cand;
    TIMES(s, nsp + 1) {
      TIMES(i, sz) {
        cand.insert(work[i] + splitCost * s);
      }
    }
    
    EACH(cand, it) {
      int limit = *it;
      if(can(limit, 0, sz - 1, splitCost)) {
        return limit;
      }
    }
    
    int result = -1;
    // -- main code --
    
    return result;	
  }

  bool can(int limit, int from, int to, int splitCost)
  {
    if(from > to) return true;
    if(limit < 0) return false;
    if(from == to) return limit >= work[from];

    pipii key = make_pair(limit, make_pair(from, to));
    if(memo.find(key) != memo.end()) return memo[key];
    
    UPTO(i, from, to) {
      bool left_can = can(limit - splitCost, from, i, splitCost);
      bool right_can = can(limit - splitCost, i+1, to, splitCost);
      if(left_can && right_can) {
        if(memo.size() < 1000000U) memo[key] = true;
        return true;
      }
    }

    if(memo.size() < 1000000U) memo[key] = false;
    return false;
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Fox Ciel has lots of homework to do.
The homework consists of some mutually independent tasks. Different tasks may take different amounts of time to complete.
You are given a vector <int> workCost. For each i, the i-th task takes workCost[i] seconds to complete.
She would like to attend a party and meet her friends, thus she wants to finish all tasks as quickly as possible.



The main problem is that all foxes, including Ciel, really hate doing homework.
Each fox is only willing to do one of the tasks.
Luckily, Doraemon, a robotic cat from the 22nd century, gave Fox Ciel a split hammer: 
a magic gadget which can split any fox into two foxes.



You are given an int splitCost.
Using the split hammer on a fox is instantaneous.
Once a hammer is used on a fox, the fox starts to split.
After splitCost seconds she will turn into two foxes -- the original fox and another completely new fox.
While a fox is splitting, it is not allowed to use the hammer on her again.



The work on a task cannot be interrupted: once a fox starts working on a task, she must finish it.
It is not allowed for multiple foxes to cooperate on the same task.
A fox cannot work on a task while she is being split using the hammer.
It is possible to split the same fox multiple times.
It is possible to split a fox both before and after she solves one of the tasks.



Compute and return the smallest amount of time in which the foxes can solve all the tasks.

DEFINITION
Class:FoxAndDoraemon
Method:minTime
Parameters:vector <int>, int
Returns:int
Method signature:int minTime(vector <int> workCost, int splitCost)


CONSTRAINTS
-workCost will contain between 1 and 50 elements, inclusive.
-Each element in workCost will be between 1 and 3,600, inclusive.
-splitCost will be between 1 and 3,600, inclusive.


EXAMPLES

0)
{1,2}
1000

Returns: 1002

Fox Ciel is only willing to do one task. She is given two tasks, therefore she must split once. 
The optimal strategy is to use the split hammer immediately.
After 1000 seconds we have two foxes. 
Each of them will do one of the tasks in parallel.

1)
{3,6,9,12}
1000

Returns: 2012



2)
{1000,100,10,1}
1

Returns: 1001

One optimal solution:

We start with a single fox A.
Immediatelly, we use the split hammer.
In 1 second we will have foxes A and B.
Fox A will start working on task 0.
At the same time, fox B will start working on task 1.
Fox B will be done 101 seconds from the start.
As she already solved a task, we need more foxes to do tasks 2 and 3.
Therefore we use the split hammer on B.
At 102 seconds from the start we will get a new fox C and let her solve task 2.
We use the split hammer on B again.
At 103 seconds from the start we will get a new fox D and let her solve task 3.


3)
{1712,1911,1703,1610,1697,1612}
100

Returns: 2012



4)
{3000,3000,3000,3000,3000,3000,3000,3000,3000,3000}
3000

Returns: 15000



5)
{58}
3600

Returns: 58



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 1002; verify_case(0, Arg2, minTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,6,9,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2012; verify_case(1, Arg2, minTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000,100,10,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1001; verify_case(2, Arg2, minTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1712,1911,1703,1610,1697,1612}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 2012; verify_case(3, Arg2, minTime(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3000; int Arg2 = 15000; verify_case(4, Arg2, minTime(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3600; int Arg2 = 58; verify_case(5, Arg2, minTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxAndDoraemon test;

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
