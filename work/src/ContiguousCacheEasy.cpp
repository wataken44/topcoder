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

class ContiguousCacheEasy {

 public:
  int bytesRead(int n, int k, vector <int> addresses)
  {
    int result = 0;
    // -- main code --

    int base = 0;

    int asz = addresses.size();

    TIMES(m, asz) {
      int addr = addresses[m];

      if(base <= addr && addr < base + k) {

      }else if(addr < base) {
        result += min(base - addr, k);
        base = addr;
      }else {
        // addr >= base + k -> base + k - 1 == addr
        int nb = min(addr - k + 1, n - k);

        result += min(nb - base, k);
        base = nb;
      }
      //DUMP(result);
    }
        
    return result;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In order to make their newest microcontroller as cheap as possible, the ACME
Widget Company designed it with a very simple cache. The processor is
connected to a slow memory system that contains n bytes, numbered
0 to n - 1. The cache holds a copy of k of these bytes at a time, for fast access. It has a base address (referred to as base below), and it holds a copy of the bytes numbered base, base+1, ..., base+k-1. When a program
reads a byte, the cache controller executes the following algorithm:

Find a new range of k bytes which contains the requested byte, such that the difference between the old and new base addresses is minimized. Note that if the
requested byte was already in the cache, then the base address will not change.
Update the cache to the new range by reading from the memory system any
bytes that are in the new range but not the old range, and discarding any
bytes that were in the old range but not the new range.
Return the requested byte to the program.


To analyze the performance of a program, you wish to know how many bytes
are read from the memory system. The numbers of the bytes that the program
reads are given in addresses, in the order that they are read. When the
program starts, the base address is 0.

DEFINITION
Class:ContiguousCacheEasy
Method:bytesRead
Parameters:int, int, vector <int>
Returns:int
Method signature:int bytesRead(int n, int k, vector <int> addresses)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.
-k will be between 1 and n, inclusive.
-addresses will contain between 1 and 50 elements, inclusive.
-Each element of addresses will be between 0 and n-1, inclusive.


EXAMPLES

0)
100
5
{6, 0, 3, 20, 22, 16}

Returns: 13

When the program starts, the cache holds 0-4 (all ranges are inclusive). Accessing 6 updates the range to hold 2-6, reading two bytes. Accessing 0 resets the range to 0-4, reading another two bytes. Accessing 3 has no effect, since it is already cached. Accessing 20 and then 22 causes another seven bytes to be read, and the cache to hold 18-22. Finally, accessing 16 updates the cache to hold 16-20 (the closest range to 18-22 containing 16), for another two bytes.

1)
100
1
{0, 4, 6, 6, 4, 10}

Returns: 4

When the cache only holds one byte, every access causes a read, except where the cache already held the correct byte.

2)
1000
999
{0, 4, 123, 987, 999, 500, 0}

Returns: 2

In this case, all but one byte is cached.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 5; int Arr2[] = {6, 0, 3, 20, 22, 16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; verify_case(0, Arg3, bytesRead(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 1; int Arr2[] = {0, 4, 6, 6, 4, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, bytesRead(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 999; int Arr2[] = {0, 4, 123, 987, 999, 500, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, bytesRead(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ContiguousCacheEasy test;

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
