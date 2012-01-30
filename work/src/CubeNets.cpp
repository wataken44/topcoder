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

class CubeNets {

 public:
  string isCubeNet(vector <string> figure)
  {
    int ysz = figure.size();
    int xsz = figure[0].size();
    
    char c = '0';
    TIMES(y, ysz) {
      TIMES(x, xsz) {
        if(figure[y][x] == '#') {
          figure[y][x] = c;
          c += 1;
        }
      }
    }


    vector< vector<int> > edge(6, vector<int>(4, -1));

    TIMES(y, ysz) {
      TIMES(x, xsz) {
        if(figure[y][x] == '.') continue;

        int cur = figure[y][x] - '0';
        if(y > 0 && figure[y-1][x] != '.') {
          int next = figure[y-1][x] - '0';
          edge[cur][0] = next;
        }
        if(y < ysz - 1 && figure[y+1][x] != '.') {
          int next = figure[y+1][x] - '0';
          edge[cur][2] = next;
        }
        if(x > 0 && figure[y][x-1] != '.') {
          int next = figure[y][x-1] - '0';
          edge[cur][1] = next;
        }
        if(x < xsz - 1 && figure[y][x+1] != '.') {
          int next = figure[y][x+1] - '0';
          edge[cur][3] = next;
        }
      }
    }

    DUMP(edge);
    
    while(true) {
      bool changed = false;

      TIMES(i, edge.size()) {
        TIMES(k, 4) {
          int k0 = k;
          int k1 = (k + 1) % 4;
          if(edge[i][k0] == -1 || edge[i][k1] == -1) continue;

          int n0 = edge[i][k0];
          int n1 = edge[i][k1];

          if(edge[n0][k1] == -1) {
            changed = true;
            edge[n0][k1] = n1;
          }else if(edge[n0][k1] != n1) {
            DUMP(i);DUMP(k0);DUMP(k1);DUMP(n0);DUMP(n1);
            DUMP(figure);
            DUMP(edge);
            return "NO";
          }

          if(edge[n1][k0] == -1) {
            changed = true;
            edge[n1][k0] = n0;
          }else if(edge[n1][k0] != n0) {
            DUMP(i);DUMP(k0);DUMP(k1);DUMP(n0);DUMP(n1);
            DUMP(figure);
            DUMP(edge);
            return "NO";
          }
        }
      }
      
      if(!changed) break;
    }

    
    return "YES";	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In geometry a cube net is an arrangement of identical edge-joined squares in the plane which can be folded (along the edges) to become the faces of a cube.

In this problem you need to check if the given figure is a cube net. The given figure will be a union of six identical squares lying in the same plane and will be given to you as a vector <string> figure. Each element of figure will consist of '.' (dot) and '#' (sharp) characters only. A sharp represents one of the six squares, whereas a dot represents an empty space. Return "YES" if figure represents a cube net, or "NO" otherwise (all quotes for clarity).

DEFINITION
Class:CubeNets
Method:isCubeNet
Parameters:vector <string>
Returns:string
Method signature:string isCubeNet(vector <string> figure)


CONSTRAINTS
-figure will contain between 1 and 6 elements, inclusive.
-Each element of figure will contain between 1 and 6 characters, inclusive.
-Each element of figure will contain '.' (dot) and '#' (sharp) characters only.
-All elements of figure will contain the same number of characters.
-There will be exactly 6 '#' (sharp) characters among all the elements of figure.


EXAMPLES

0)
{"..#.",
 "####",
 "..#."}

Returns: "YES"

Here you can first fold across all the vertical edges to make the middle four squares become the down, right, up and left faces of the cube-to-be. One then finishes off the construction by folding across the remaining two edges to make the other two squares become the front and back faces of the cube.

1)
{"###",
 "###"}

Returns: "NO"

This is not a cube net.

2)
{"..#.",
"####",
".#.."}

Returns: "YES"



3)
{"##..",
 ".##.",
 "..##"}

Returns: "YES"



4)
{"####",
 "...#",
 "...#"}

Returns: "NO"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..#.",
 "####",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isCubeNet(Arg0)); }
	void test_case_1() { string Arr0[] = {"###",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isCubeNet(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#.",
"####",
".#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isCubeNet(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..",
 ".##.",
 "..##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, isCubeNet(Arg0)); }
	void test_case_4() { string Arr0[] = {"####",
 "...#",
 "...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isCubeNet(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  CubeNets test;

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
