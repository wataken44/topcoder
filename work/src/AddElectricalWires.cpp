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

class AddElectricalWires {

 public:
  int maxNewWires(vector <string> wires, vector <int> gc)
  {
    int result = 0;
    // -- main code --

    int sz = wires.size();
    int INF = 300000;
    
    vector< vector<int> > dist(sz, vector<int>(sz, INF));

    TIMES(y, sz) {
      TIMES(x, sz) {
        if(wires[y][x] == '1') {
          dist[y][x] = 1;
          dist[x][y] = 1;
        }
      }
    }
    
    TIMES(z, sz) {
      TIMES(y, sz) {
        TIMES(x, sz) {
          if(y == x) continue;
          dist[y][x] = min(dist[y][x], dist[y][z] + dist[z][x]);
        }
      }
    }

    DUMP(dist);
    
    map< int, vector<int> > group;
    vector<bool> used(sz, false);
    
    TIMES(i, gc.size()) {
      int y = gc[i];

      group[y] = vector<int>(1, y);
      used[y] = true;

      TIMES(x, sz) {
        if(x == y) continue;
        if(dist[y][x] < INF) {
          group[y].push_back(x);
          used[x] = true;
        }
      }
    }

    TIMES(i, gc.size()) {
      map< int, vector<int> > ng(group);

      TIMES(k, sz) {
        if(used[k]) continue;
        ng[gc[i]].push_back(k);
      }

      DUMP(ng);
      
      int cnt = 0;
      EACH(ng, it) {
        vector<int>& v = it->second;

        TIMES(y, v.size()) {
          FOR(x, y + 1, v.size()) {
            if(wires[y][x] != '1') ++cnt;
          }
        }
      }

      DUMP(cnt);
      
      result = max(cnt, result);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are given an electrical circuit for a home, with a number of nodes possibly connected by wires.  Any pair of nodes may be connected by at most one wire, and a node can't be connected to itself.  Each node on the circuit is either an electrical outlet for the house or a connection to the main electrical grid.  The vector <string> wires tells you the wires that are already in place; the xth character of the yth element is '1' (one) if nodes x and y have a wire between them, '0' (zero) otherwise.  The vector <int> gridConnections lists the indices of the nodes that are connections to the main electrical grid.

You'd like to make the circuit safer and more redundant by adding as many extra wires to it as possible.  The one complication is that no two main grid connections are currently wired together (directly or indirectly), and you must preserve this, or else disaster will result.  Determine the maximum number of new wires you can add to the circuit.

DEFINITION
Class:AddElectricalWires
Method:maxNewWires
Parameters:vector <string>, vector <int>
Returns:int
Method signature:int maxNewWires(vector <string> wires, vector <int> gridConnections)


CONSTRAINTS
-wires will contain between 1 and 50 elements, inclusive.
-Each element of wires will have the same length as wires.
-Each element of wires will contain only the characters '0' and '1'.
-Character i of element i of wires will be a '0'.
-Character i of element j of wires will be the same as character j of element i.
-gridConnections will contain between 1 and 50 elements, inclusive.
-Each element of gridConnections will be an integer between 0 and length(wires)-1, inclusive.
-Each element of gridConnections will be distinct.
-Each pair of elements of gridConnections will not index nodes connected by a path of '1's in wires.


EXAMPLES

0)
{"000","000","000"}
{0}

Returns: 3

Every valid wire can be added.

1)
{"000","000","000"}
{0,1}

Returns: 1

0 and 1 can't be connected, but 0 and 2 (or 1 and 2) still can be.

2)
{"01","10"}
{0}

Returns: 0

This circuit is already complete.

3)
{"00000","00000","00000","00000","00000"}
{0,1,2,3,4}

Returns: 0

Any connections would be disastrous.

4)
{"01000","10100","01010","00100","00000"}
{2,4}

Returns: 3



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00000","00000","00000","00000","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"01000","10100","01010","00100","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, maxNewWires(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  AddElectricalWires test;

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
