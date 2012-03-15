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

class AllCycleLengths {

 public:
  string findAll(vector <string> arcs)
  {
    int sz = arcs.size(); 
    
    vector< vector<bool> > graph(sz, vector<bool>(sz, false));

    const int INF = 1 << 16;
    vector< vector<int> > dist(sz, vector<int>(sz, INF));
    
    TIMES(y, sz) {
      TIMES(x, sz) {
        if(arcs[y][x] == 'Y') {
          graph[y][x] = true;
          dist[y][x] = 1;
        }
      }
    }

    TIMES(z, sz) {
      TIMES(y, sz) {
        TIMES(x, sz) {
          dist[y][x] = min(dist[y][x], dist[y][z] + dist[z][x]);
        }
      }
    }

    TIMES(y, sz) {
      TIMES(x, sz) {
        if(dist[y][x] > INF) dist[y][x] = INF;
      }
    }

    DUMP(dist);
    
    string result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// There are several cities in a country, and some pairs of those cities are connected by one-way roads (although it is possible that there are one-way roads both from A to B and from B to A). It is possible to get from any city to any other city using roads. A traveler starts from some city, and travels along one of the roads every day. A number x is called vacation-friendly if a traveler can have an x-day long vacation.  That means he can start from some city, travel exactly x roads, and be back at the city where he started.

A vacation string is an infinite string of '0' and '1' digits, which has a '1' in the x-th (1-based) position if and only if x is a vacation-friendly number.
For example, consider the country shown in the following picture.

Its vacation string is "0011011111111...": 0->1->3->0 is a 3-day vacation, 0->1->2->3->0 is a 4-day vacation, 0->1->3->0->1->3->0 is a 6-day vacation, 0->1->2->3->0->1->3->0 is a 7-day vacation, and so on.
It turns out that every vacation string becomes periodic at some point. We will enclose the period in parentheses to obtain a finite representation for a vacation string. For example, the above vacation string can be represented by "00110(1)" or "00110111(11)". We will call the shortest possible representation canonical.
Given a description of a country as a vector <string> arcs, where the j-th character of the i-th element of arcs is 'Y' if there is a road from city i to city j, and 'N' otherwise, return the canonical representation of its vacation string.

DEFINITION
Class:AllCycleLengths
Method:findAll
Parameters:vector <string>
Returns:string
Method signature:string findAll(vector <string> arcs)


CONSTRAINTS
-arcs will contain between 2 and 30 elements, inclusive.
-Each element of arcs will contain exactly n characters, where n is the number of elements in arcs.
-Each character of each element of arcs will be either 'Y' or 'N'.
-The i-th character of the i-th element of arcs will always be 'N'.
-arcs will define a network of roads where it is possible to get from any city to any other city using the roads.


EXAMPLES

0)
{"NYNN", "NNYY", "NNNY", "YNNN"}

Returns: "00110(1)"

The example from the problem statement.

1)
{"NY", "YN"}

Returns: "(01)"

Only even numbers are vacation-friendly here.

2)
{"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"}

Returns: "0(1)"

Every vacation length except 1 is possible here.

3)
{"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"}

Returns: "010(1)"

The vacation can start from any vertex.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN", "NNYY", "NNNY", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "00110(1)"; verify_case(0, Arg1, findAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"NY", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(01)"; verify_case(1, Arg1, findAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0(1)"; verify_case(2, Arg1, findAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010(1)"; verify_case(3, Arg1, findAll(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  AllCycleLengths test;

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
