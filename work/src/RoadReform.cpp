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

class RoadReform {

 public:
  int bits;

  int bit(int n, int k)
  {
    return (n >> k) & 1;
  }

  int countZero(int n)
  {
    int count = 0;
    TIMES(k, bits) {
      if(bit(n, k) == 0) ++count;
    }
    return count;
  }
  
  int findMaxDeadendCount(vector <string> roads)
  {
    bits = roads.size();

    int result = 0;

    FOR(m, 1, 1 << bits) {
      

      result = max(result, countZero(m));
    }
    
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
There are n cities in the Kingdom. Some pairs of cities are connected by bidirectional roads, and there exists a path between every pair of cities.


The King thinks that supporting so many roads is very expensive, so he decided to close some of them.
He wants to close as many roads as possible, but, of course, he still wants each city to be reachable from any other city.


A city is a dead end if it is connected to only one other city by a direct road. You will be given a vector <string> roads, with the j-th character of the i-th element of roads being '1' (one) if the i-th and j-th cities are connected by a direct road, and '0' (zero) otherwise. Return the maximal number of dead ends the Kingdom may have after the reform.



DEFINITION
Class:RoadReform
Method:findMaxDeadendCount
Parameters:vector <string>
Returns:int
Method signature:int findMaxDeadendCount(vector <string> roads)


CONSTRAINTS
-roads will contain between 2 and 15 elements, inclusive.
-Each element of roads will contain exactly n characters, where n is the number of elements in roads.
-Each element of roads will contain digits '0' and '1' only.
-The j-th character in the i-th element of roads will be equal to the i-th character in the j-th element.
-The i-th character in the i-th element of roads will be '0'.
-Each pair of cities in the input will be connected by a path.


EXAMPLES

0)
{"01",
 "10"}

Returns: 2

Two cities are connected by a road. The King can't close this road and both cities will still be dead ends.

1)
{"01000", 
 "10100",
 "01010",
 "00101",
 "00010"}

Returns: 2

The cities of the Kingdom are aligned in a chain. As in example 0, no road can be closed without splitting the Kingdom.

2)
{"01111",
 "10000",
 "10000",
 "10000",
 "10000"}

Returns: 4



3)
{"0111",
 "1011",
 "1101",
 "1110"}

Returns: 3

Each pair of cities is connected by a direct road. The King can close roads 1<->2, 2<->3 and 1<->3, thus making cities 1, 2 and 3 dead ends.

4)
{"0100000001",
 "1010000000",
 "0101000000",
 "0010100000",
 "0001010000",
 "0000101000",
 "0000010100",
 "0000001010",
 "0000000101",
 "1000000010"}

Returns: 2



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, findMaxDeadendCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"01000", 
 "10100",
 "01010",
 "00101",
 "00010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, findMaxDeadendCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"01111",
 "10000",
 "10000",
 "10000",
 "10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, findMaxDeadendCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"0111",
 "1011",
 "1101",
 "1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findMaxDeadendCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"0100000001",
 "1010000000",
 "0101000000",
 "0010100000",
 "0001010000",
 "0000101000",
 "0000010100",
 "0000001010",
 "0000000101",
 "1000000010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, findMaxDeadendCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RoadReform test;

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
