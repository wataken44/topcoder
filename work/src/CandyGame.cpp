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

class CandyGame {

 public:
  int maximumCandy(vector <string> graph, int target)
  {
    int INF = 100000;
    int LIM = 2000000000;
    int sz = graph.size();
    
    vector< vector<int> > dist(sz, vector<int>(sz, INF));

    TIMES(y, sz) {
      TIMES(x, sz) {
        dist[y][x] = graph[y][x] == 'Y' ? 1 : INF;
      }
      dist[y][y] = 0;
    }

    TIMES(z, sz) {
      TIMES(y, sz) {
        TIMES(x, sz) {
          dist[y][x] = min(dist[y][x], dist[y][z] + dist[z][x]);
          dist[y][x] = min(dist[y][x], INF);
        }
      }
    }

    // DUMP(dist);
    
    long long result = 0;
    // -- main code --

    vector<int> visited(1, target);

    while(visited.size() != graph.size()) {
      int dd = 0;
      int dx = -1;
      int dy = -1;

      TIMES(x, sz) {
        if(find(visited.begin(), visited.end(), x) != visited.end()) {
          continue;
        }
        int md = INF;
        int my = -1;
        TIMES(y, visited.size()) {
          if(md < dist[y][x]) {
            md = min(md, dist[y][x]);
            my = y;
          }
        }
        if(dd > md) {
          dd = max(md, dd);
          dx = x;
          dy = my;
        }
      }

      if(dd >= 31) return -1;
      result += (2 << dd) - 1;
      if(result >= LIM) return -1;

    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
Your brother is playing a new game he received for his birthday.  The game takes place on an acyclic, undirected graph, with pieces of candy located on some of the nodes.  On each turn, your brother picks a node with at least 2 pieces of candy on it.  He then picks up 2 pieces of candy from that node, eats one piece, and places the other piece on an adjacent node.  If at any time there is a piece of candy on the target node, then the game is over and your brother wins.  If he cannot put candy on that node through any sequence of moves, he loses.  Your brother is smart, and so if there is a winning sequence of moves he will find it.

You enjoy frustrating your brother and want to make him lose the game.  The graph will be given as a vector <string>.  The j-th character of element i will be 'Y' if nodes i and j are connected in the graph; otherwise, it will be 'N'.  Return the maximum number of pieces that can be placed on the board without your brother being able to win; if more than 2,000,000,000 pieces can be placed on the board without your brother winning, return -1 instead.


DEFINITION
Class:CandyGame
Method:maximumCandy
Parameters:vector <string>, int
Returns:int
Method signature:int maximumCandy(vector <string> graph, int target)


CONSTRAINTS
-graph will contain N elements, where N is between 1 and 50, inclusive.
-Each element of graph will contain exactly N characters.
-Each character in graph will be either 'Y' or 'N'.
-In graph, the j-th character of element i will equal the i-th character of element j.
-The i-th character of the i-th element of graph will be 'N'.
-The graph represented by graph will have no cycles.
-target will be between 0 and N-1, inclusive.


EXAMPLES

0)
{"NYN", "YNY", "NYN"}
1

Returns: 2

The graph is a straight line:

0-1-2

With node 1 as the target, we can only put one piece of candy each on nodes 0 and 2.  If you place a second piece on either, your brother can eat one and move the other to node 1.

1)
{"NYN", "YNY", "NYN"}
2

Returns: 3

The same graph as example 0, but now node 2 is the target.  The optimal strategy places 3 pieces of candy on node 0.

2)
{"NYYY", "YNNN", "YNNN", "YNNN"}
0

Returns: 3



3)
{"NYYY", "YNNN", "YNNN", "YNNN"}
1

Returns: 4



4)
{"NYNNNYN",
 "YNYNYNN",
 "NYNYNNN",
 "NNYNNNN",
 "NYNNNNN",
 "YNNNNNY",
 "NNNNNYN"}
0

Returns: 11



5)
{"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN"}
0

Returns: -1



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN", "YNY", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYN", "YNY", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYYY", "YNNN", "YNNN", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(2, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYYY", "YNNN", "YNNN", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(3, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNYN",
 "YNYNYNN",
 "NYNYNNN",
 "NNYNNNN",
 "NYNNNNN",
 "YNNNNNY",
 "NNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 11; verify_case(4, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(5, Arg2, maximumCandy(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  CandyGame test;

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
