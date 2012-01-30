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

class Rumor {

 public:
  int getMinimum(string knowledge, vector <string> graph)
  {
    typedef unsigned long long ULL;
    // -- main code --

    int sz = knowledge.size();
    
    vector< set<ULL> > state(2 * sz + 1);

    int init = 0;
    FOR(i, 0, sz) {
      if(knowledge[i] == 'Y') {
        init = init | (3 << (i * 2));
      }
    }
    state[0].insert(init);

    int goal = (1 << (2 * sz)) - 1; 
    
    FOR(d, 1, state.size() - 1) {
      EACH(state[d - 1], it) {
        ULL prev = *it;

        vector< set<ULL> > next(sz+1);
        next[0].insert(prev);
        
        FOR(y, 1, sz+1) {
          DUMP(next[y-1]);
          int yy = y - 1;
          EACH(next[yy], it) { 
            ULL p = *it;
            int k = (p >> (yy * 2)) & 3;
            if(k & 1 == 1) {
              FOR(x, 0, sz) {
                if(graph[yy][x] == 'Y') {
                  next[yy+1].insert(p | (1 << (x * 2)));
                }
              }
            }
            if(k & 2 == 2) {
              FOR(x, 0, sz) {
                if(graph[yy][x] == 'Y') {
                  next[yy+1].insert(p | (2 << (x * 2)));
                }
              }
            }
          }
        }
        
        EACH(next[sz], it) {
          ULL n = *it;
          if(find(state[d-1].begin(), state[d-1].end(), n) == state[d-1].end()) {
            state[d].insert(n);
          }
        }
      }
      DUMP(state[d]);
      if(find(state[d].begin(), state[d].end(), goal) != state[d].end()) {
        return d;
      }
    }
    
    return -1;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// There are N rabbits who like to gossip. They are numbered from 0 to N-1.

There are two rumors. Let's call them A and B. At this moment, each rabbit either knows both rumors or no rumors at all. The rabbits want to spread the rumors to everyone as quickly as possible.

Rabbits are very picky when it comes to spreading rumors. Each rabbit only trusts some of the other rabbits. Moreover, the situation is not necessarily symmetric - there may be rabbits A and B such that A trusts B, but B does not trust A.

At the beginning of each day, each rabbit who knows at least one rumor chooses a rumor X it knows. The rabbit then spends the day spreading rumor X. A rabbit will learn a new rumor if it is spreaded by someone it trusts. Note that a rabbit may learn both rumors in the same day (from two different other rabbits). Also note that a rabbit may spread one rumor and learn the other rumor on the same day.

You are given a string knowledge and a vector <string> graph. The string knowledge has exactly N characters. Character i of knowledge is 'Y' if rabbit i already knows both rumors, or 'N' if it does not know the rumors yet. The vector <string> graph contains N strings with N characters each. Element i of graph describes rabbits who trust rabbit i: character j of element i of graph is 'Y' if rabbit j trusts rabbit i, or 'N' if rabbit j does not trust rabbit i. In other words, graph[i][j] is 'Y' if and only if rabbit i will spread rumors to rabbit j.

Return the minimum number of days needed to spread both rumors so that each of the N rabbits will know both rumors. If it is impossible, return -1.

DEFINITION
Class:Rumor
Method:getMinimum
Parameters:string, vector <string>
Returns:int
Method signature:int getMinimum(string knowledge, vector <string> graph)


CONSTRAINTS
-knowledge will contain between 1 and 16 characters, inclusive.
-Each character of knowledge will be either 'Y' or 'N'.
-knowledge will contain at least one 'Y' character.
-graph will contain N elements, where N is the length of knowledge.
-Each element of graph will contain N characters.
-Each character of graph will be either 'Y' or 'N'.
-i-th character of i-th element of graph will be 'N'.


EXAMPLES

0)
"YNN"
{"NYN"
,"NNY"
,"NNN"}

Returns: 3

Initially, there are 3 rabbits. Rabbit 0 knows rumor A and B, and other rabbits know nothing.

One of the optimal ways is as follows.

On day 1, rabbit 0 sends information about rumor A to rabbit 1.
On day 2, rabbit 1 sends information about rumor A to rabbit 2, and rabbit 0 sends information about rumor B to rabbit 1.
On day 3, rabbit 1 sends information about rumor B to rabbit 2.

As a result, it takes 3 days.

1)
"YNNY"
{"NYYN"
,"YNNY"
,"YNNY"
,"NYYN"}

Returns: 1

One of the optimal ways is as follows.

On day 1, rabbit 0 sends information about rumor A to rabbit 1 and rabbit 2, and rabbit 3 sends information about rumor B to rabbit 1 and rabbit 2.


2)
"YYYY"
{"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"}

Returns: 0

All rabbits already know the rumors, so no day is required.

3)
"YYYYYN"
{"NYYYYN"
,"YNYYYN"
,"YYNYYN"
,"YYYNYN"
,"YYYYNN"
,"NNNNNN"}

Returns: -1

It is impossible to make rabbit 5 know the rumors.

4)
"NNNY"
{"NNNN"
,"YNNN"
,"YNNN"
,"NYYN"}

Returns: 3



5)
 "NNNNNNNYYY"
{"NYNNYNNYNN"
,"NNYNYNNNNY"
,"YYNNNYNNNN"
,"YNNNYNYNNN"
,"NNYNNYNNYN"
,"NNNNYNNNYY"
,"NYNYNYNNNN"
,"NNNNNNYNYY"
,"NNNYNNNYNY"
,"NYYNNNNYNN"}


Returns: 2



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNN"; string Arr1[] = {"NYN"
,"NNY"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "YNNY"; string Arr1[] = {"NYYN"
,"YNNY"
,"YNNY"
,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "YYYY"; string Arr1[] = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "YYYYYN"; string Arr1[] = {"NYYYYN"
,"YNYYYN"
,"YYNYYN"
,"YYYNYN"
,"YYYYNN"
,"NNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "NNNY"; string Arr1[] = {"NNNN"
,"YNNN"
,"YNNN"
,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_5() { string Arg0 =  "NNNNNNNYYY"; string Arr1[] = {"NYNNYNNYNN"
,"NNYNYNNNNY"
,"YYNNNYNNNN"
,"YNNNYNYNNN"
,"NNYNNYNNYN"
,"NNNNYNNNYY"
,"NYNYNYNNNN"
,"NNNNNNYNYY"
,"NNNYNNNYNY"
,"NYYNNNNYNN"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Rumor test;

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
