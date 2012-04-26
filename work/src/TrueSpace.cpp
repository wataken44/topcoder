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

class TrueSpace {

 public:
  long long calculateSpace(vector <int> sizes, int cSize)
  {
    long long result = 0;
    // -- main code --
    EACH(sizes, it) {
      int size = *it;

      result += size % cSize != 0 ? (size / cSize + 1) * cSize : size;
      
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In some filesystems, the disk space used by a file is not always equal to the file's size.  This is because the disk is divided into clusters of equal size, and each cluster can only be used by a single file.  For example, if the cluster size is 512 bytes, and we have a file of size 600 bytes, it would have to be stored in two clusters.  Those two clusters cannot be shared with any other files, so the file ends up using 1024 bytes of disk space.

You are given a vector <int> sizes, where each element is the size of a single file, and an int clusterSize, the cluster size of the filesystem.  Return the total disk space used by the given files.

DEFINITION
Class:TrueSpace
Method:calculateSpace
Parameters:vector <int>, int
Returns:long long
Method signature:long long calculateSpace(vector <int> sizes, int clusterSize)


CONSTRAINTS
-sizes will contain between 1 and 50 elements, inclusive.
-clusterSize will be between 1 and 1,048,576, inclusive.
-Each element of sizes will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{600}
512

Returns: 1024

From the problem statement.


1)
{16,32,128,128,0}
32768

Returns: 131072

We waste a lot of space here. (Note that we don't need any clusters for a file of size 0.)


2)
{4096, 33792, 76800}
1024

Returns: 114688

We don't waste any space here.

3)
{1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000}

1048576

Returns: 50017075200



4)
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
8

Returns: 0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 512; long long Arg2 = 1024LL; verify_case(0, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {16,32,128,128,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32768; long long Arg2 = 131072LL; verify_case(1, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4096, 33792, 76800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1024; long long Arg2 = 114688LL; verify_case(2, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000, 1000000000, 1000000000,
 1000000000, 1000000000}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1048576; long long Arg2 = 50017075200LL; verify_case(3, Arg2, calculateSpace(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; long long Arg2 = 0LL; verify_case(4, Arg2, calculateSpace(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TrueSpace test;

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
