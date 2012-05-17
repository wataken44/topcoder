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

class PickGuitars {

 public:
  typedef unsigned long long ull;
  map< pair<int, int>, ull > memo;
  vector<int> value;
  int vsz;
  
  ull choose(int i, int size)
  {
    if(size == 1) {
      return 1 << i;
    }
    
    if(size == 2) {
      int s = value[i] > value[(i + 1) % vsz] ? i : (i + 1) % vsz;
      return 1 << s;
    }

    pair<int, int> key = make_pair(i, size);
    if(memo.find(key) != memo.end()) return memo[key];

    ull& ret = memo[key];

    int mc = -1;
    int mv = -1;

    ull mask = ((1 << size) - 1) << i;
    
    for(int a = 0; a < size; ++a) {
      int c = (i + a) % vsz;
      ull hl = 0;
      if(a > 0) {
        hl = ~choose(i, a - 1);
      }
      ull hr = 0;
      if(a < size - 1) {
        hr = ~choose(c + 1, size - a - 1);
      }
      ull h = hl | hr | (1 << c);
      int v = 0;
      TIMES(k, vsz) {
        if(((h >> k) & 1) == 1) {
          v += value[k];
        }
      }
    }
    
    return ret;
  }
  
  int maxValue(vector <int> guitarValues)
  {
    value = guitarValues;
    vsz = value.size();
    
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You have been invited to a TV game show where you will play against another contestant to win free guitars.  At the start of the game, there are n guitar cases arranged in a circle, each of which contains a single guitar.  You make the first move by choosing one guitar and removing it from its case.  The other player then chooses a guitar and removes it from its case.  At this point, there might be one or two groups, where a group is defined as a maximal contiguous set of non-empty cases.  You continue to take turns choosing guitars, and on each turn, the current player chooses exactly one guitar from each group.  The game ends when all the guitars have been chosen.

Each player gets to keep all the guitars that he chooses during the game.  Your goal is to maximize the total value of the guitars you choose.  The guitars in the circle are numbered 0 to n-1 in clockwise order (guitar 0 is next to guitar n-1).  You are given a vector <int> guitarValues, the i-th element of which is the value of guitar i.  Return the maximum possible total value you can get, assuming your opponent plays a perfect strategy.


DEFINITION
Class:PickGuitars
Method:maxValue
Parameters:vector <int>
Returns:int
Method signature:int maxValue(vector <int> guitarValues)


CONSTRAINTS
-guitarValues will contain between 2 and 50 elements, inclusive.
-Each element of guitarValues will be between 1 and 10000, inclusive.


EXAMPLES

0)
{1,5,3,4,5}

Returns: 10

You first choose guitar 4 (which has a value of 5).  Your opponent chooses guitar 1 (which also has a value of 5).  There are now two groups of guitars - one group contains guitar 0 and the other group contains guitars 2 and 3.  You must choose one guitar from each group, so you choose guitar 0 from the first group (which has value 1) and guitar 3 from the second group (which has value 4).  Your opponent will then choose the last remaining guitar, and the game is over.

1)
{4,8,4}

Returns: 12

Take guitar 1 (which has value 8).  Your opponent will choose one of the remaining guitars (both of which have a value of 4), and you will get the other.

2)
{2,1,4,1,2,1,8,1}

Returns: 12

Choose guitar 6 (which has value 8).  Your opponent will choose guitar 2 (which has value 4).  There are now two groups of guitars.  You choose guitars 0 and 4 (both of which have a value of 2).  There are now four groups, each containing one guitar, so your opponent will take all the remaining guitars.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, maxValue(Arg0)); }
	void test_case_1() { int Arr0[] = {4,8,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, maxValue(Arg0)); }
	void test_case_2() { int Arr0[] = {2,1,4,1,2,1,8,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, maxValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PickGuitars test;

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
