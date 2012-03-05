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

class CharSwaps {

 public:
  int bits;
  
  int bit(int n, int k)
  {
    return (n >> k) & 1;
  }

  int toInt(string& s)
  {
    int r = 0;
    TIMES(i, bits) {
      r = r * 2 + (s[i] == 'b' ? 1 : 0);
    }
    return r;
  }

  int mask(int a)
  {
    return ~(1 << a);
  }
  
  int swapBit(int n, int a, int b)
  {
    n = (n & mask(a) & mask(b) ) | (bit(n, a) << b) | (bit(n, b) << a);
    return n & ((1 << bits) - 1);
  }

  bool isGoal(int n)
  {
    if(n == 0) return true;
    while(n % 2 == 0) { n /= 2; }

    int one = (1 << bits) - 1; 
    if((n & one) == one) return true;
    while(bit(n, bits-1) == 1) { n = (n * 2 + 1) & (one); }
    
    while(n > 0) {
      if((n & 1) == 0) {
        return false;
      }
      n /= 2;
    }
    return true;
  }
  
  int getMinCount(string s)
  {
    bits = s.size();

    typedef pair<int, int> pii;
    set< pii > queue;
    map<int, int> visited;
    
    int start = toInt(s);
    queue.insert(make_pair(0, start));
    visited[start] = 0;

    DUMP(start);
    DUMP(isGoal(start));
    
    while(!queue.empty()) {
      set<pii>::iterator it = queue.begin();
      int step = it->first;
      int now = it->second;
      queue.erase(it);
      visited[now] = step;

      if(isGoal(now)) return step;
      
      TIMES(i, bits) {
        FOR(j, i+1, bits) {
          int next = swapBit(now, i, j);
          if(next == now) continue;
          if(visited.find(next) != visited.end()) continue;
          queue.insert(make_pair(step + 1, next));
        }
      }
    }
    
    int result = 5;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
You are given a string s containing only the letters 'a' and 'b'.  The letters are arranged in a circle, so the last and first characters are adjacent.


You will perform a series of swaps until all the 'a's form one consecutive sequence and all the 'b's form another consecutive sequence.  In each swap, you can select any two characters and swap them.  Return the minimal number of swaps necessary to reach your goal.


DEFINITION
Class:CharSwaps
Method:getMinCount
Parameters:string
Returns:int
Method signature:int getMinCount(string s)


CONSTRAINTS
-s will contain between 1 and 15 characters, inclusive.
-s will contain the letters 'a' and 'b' only.


EXAMPLES

0)
"ba"

Returns: 0

The letters are already arranged properly in this string.

1)
"aaaabbbbba"

Returns: 0

The letters are already arranged properly in this string as well.

2)
"abab"

Returns: 1

Swap the first two letters.


3)
"aabbaaabaaba"

Returns: 2



4)
"abababababababa"

Returns: 3

The case with the largest possible answer.

5)
"aaaa"

Returns: 0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ba"; int Arg1 = 0; verify_case(0, Arg1, getMinCount(Arg0)); }
	void test_case_1() { string Arg0 = "aaaabbbbba"; int Arg1 = 0; verify_case(1, Arg1, getMinCount(Arg0)); }
	void test_case_2() { string Arg0 = "abab"; int Arg1 = 1; verify_case(2, Arg1, getMinCount(Arg0)); }
	void test_case_3() { string Arg0 = "aabbaaabaaba"; int Arg1 = 2; verify_case(3, Arg1, getMinCount(Arg0)); }
	void test_case_4() { string Arg0 = "abababababababa"; int Arg1 = 3; verify_case(4, Arg1, getMinCount(Arg0)); }
	void test_case_5() { string Arg0 = "aaaa"; int Arg1 = 0; verify_case(5, Arg1, getMinCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  CharSwaps test;

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
