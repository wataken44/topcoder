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

class GogoXMarisaKirisima {

 public:
  int solve(vector <string> choices)
  {

    int sz = choices.size();

    vector< vector<int> > fw(sz, vector<int>(sz, 10000));

    TIMES(y, sz) {
      TIMES(x, sz) {
        if(choices[y][x] == 'Y') {
          fw[y][x] = 1;
        }
      }
    }

    TIMES(z, sz) {
      TIMES(y,sz) {
        TIMES(x,sz) {
          fw[y][x] = min(fw[y][x], fw[y][z] + fw[z][x]);
        }
      }
    }

    TIMES(y, sz) {
      TIMES(x, sz) {
        if(fw[y][x] >= 10000 || x == y) {
          fw[y][x] = 0;
        }
      }
    }

    DUMP(fw);

    if(fw[0][sz - 1] == 0) return 0;

    int r = 2;
    
    TIMES(x, sz) {
      if(x!= 0 && fw[0][x] == 0) continue;
      if(x!= sz - 1 && fw[x][sz-1] == 0) continue;

      --r;
      TIMES(y, sz) {
        if(choices[x][y] == 'Y' && fw[y][sz-1] > 0) ++r;
      }
    }

    
    DUMP(fw);
    
    // -- main code --
    
    return r;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to "read" virtual novels. In particular, he's currently "reading" a novel titled Touhou, with Marisa Kirisima as its main protagonist. There are N stages in Touhou, numbered 0 through N-1. A playthrough of the novel always starts at the stage 0. The playthrough then may visit some other stages, based on the player's choices (a stage may be visited multiple times). A playthrough is successful if it terminates at the stage N-1.

In each stage, Gogo can either finish the playthrough or choose one of the available options that advance Marisa to other stages. You are given a vector <string> choices. If there is a choice that advances Marisa from stage i to stage j, choices[i][j] will be 'Y', otherwise it will be 'N'. For each pair of different stages i, j the game contains at most one such choice. While it may be possible to re-enter the same stage after a sequence of choices is made, there will never be an option that would let Marisa directly stay at the same stage (i.e., a self-loop).

Gogo wants to make as many successful playthroughs as possible, one after another. However, there is an additional constraint: Each playthrough must contain at least one choice Gogo never made in any of the previous playthroughs.

Return the maximum number of successful playthroughs that Gogo can play. If there are no such playthrough, return 0.

DEFINITION
Class:GogoXMarisaKirisima
Method:solve
Parameters:vector <string>
Returns:int
Method signature:int solve(vector <string> choices)


CONSTRAINTS
-choices will contain between 2 and 50 elements, inclusive.
-Each element of choices will contain N characters, where N is the number of elements in choices.
-Each character in choices will be either 'Y', or 'N'.
-For each i, choices[i][i] will be 'N'.


EXAMPLES

0)
{"NYN"
,"YNY"
,"NNN"}

Returns: 2

For example, he can perform the following two playthroughs (in the given order):
0 -> 1 -> 2
0 -> 1 -> 0 -> 1 -> 2
In the first playthrough, both choices (0->1 and 1->2) have never been made before. In the second playthrough, the choice 1->0 has never been made before. Note that the order of playing the playthroughs is important. Should Gogo start by performing the second playthrough, the first playthrough would then be invalid, as it would not contain any new choices.

1)
{"NNY"
,"YNY"
,"YNN"}

Returns: 2



2)
{"NN"
,"NN"}

Returns: 0



3)
{"NYYY"
,"NNNY"
,"NNNY"
,"NNNN"}

Returns: 3



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"YNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNY"
,"YNY"
,"YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYY"
,"NNNY"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  GogoXMarisaKirisima test;

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
