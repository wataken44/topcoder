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

class SafeReturn {

 public:
  int minRisk(int N, vector <string> streets)
  {
    int T = streets.size();
    int INF = N * 10000;
    
    vector< vector<int> > graph(T, vector<int>(T, 0));
    vector< vector<int> > dist(T, vector<int>(T, INF));
    
    TIMES(i, T) {
      TIMES(k, T) {
        if(streets[i][k] == '-') {
          graph[i][k] = INF;
        }else {
          graph[i][k] = streets[i][k] - '0';
          dist[i][k] = graph[i][k];
        }
      }
    }

    TIMES(z, T) {
      TIMES(y, T) {
        TIMES(x, T) {
          dist[y][x] = min(dist[y][x], dist[y][z] + dist[z][x]);
          dist[y][x] = min(dist[y][x], INF);
        }
      }
    }

    // DUMP(graph);
    // DUMP(dist);
    
    vector<bool> visited(T, false);
    visited[0] = true;
    TIMES(k, T) {
      if(dist[0][k] == INF) visited[k] = true;
    }

    
    vector< vector<bool> > tree(T, vector<bool>(T, false));

    while(true) {
      bool ok = true;
      TIMES(i, T) {
        if(visited[i] == false) {
          ok = false;
          break;
        }
      }
      if(ok) break;
      
      int from = 0;
      int to = 0;
      int dist = INF;
      TIMES(f, T) {
        if(visited[f] == false) continue;
        TIMES(t, T) {
          if(visited[t] == true) continue;
          if(dist > graph[f][t]) {
            from = f;
            to = t;
            dist = graph[f][t];
          }
        }
      }
      tree[from][to] = true;
      visited[to] = true;
    }

    // DUMP(tree);
    
    int result = 0;

    UPTO(i, 1, N) {
      int cnt = 0;
      TIMES(k, T) {
        if(tree[i][k]) ++cnt;
      }
      if(cnt == 0) ++result;
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
// You used to worry about your popularity with the troops, but not anymore. Your priority is their safety. You are the commander of N soldiers. Each soldier has an assignment to visit a different fort. They all leave fort 0 at the same time and travel through the streets of the city at the same time until each reaches his assigned destination. This is very risky and you would want each soldier to to reach his fort as soon as possible. It is also very dangerous to go alone, thus as a secondary objective, you must minimize the number of soldiers that are exposed to risk by going over at least one street alone.

There are T locations, where T >= N+1. The locations are numbered 0 to T-1. Location 0 is the fort where all soldiers start at time 0. For each i between 1 and N, inclusive, location i is the destination fort for one of the soldiers.
The remaining locations have no specific meaning. Some pairs of locations are connected by bidirectional streets. The streets are given as a vector <string> streets. If there is no street connecting locations i and j, streets[i][j] will be '-' (quotes for clarity). Otherwise, streets[i][j] will be a digit between '1' and '9', inclusive. The digit represents the number of minutes it takes any soldier to walk along the street in either direction.

All soldiers can move at the same time, and multiple soldiers can move along the same street. If a group of soldiers reaches a fort that is the destination for one of them, that soldier enters the fort in zero time and the remaining ones keep on walking to other locations.

A soldier is safe if at each moment of his walk through the city he is accompanied by at least one other soldier.
A soldier is endangered if he is not safe, i.e., if he walks alone for some time. Remember that the primary requirement is that each soldier must use one of the (possibly many) fastest paths to his destination fort. Given this requirement, you want to choose the paths in such a way that the number of soldiers in danger is minimized. Return the smallest possible number of endangered soldiers.

DEFINITION
Class:SafeReturn
Method:minRisk
Parameters:int, vector <string>
Returns:int
Method signature:int minRisk(int N, vector <string> streets)


CONSTRAINTS
-N will be between 1 and 49, inclusive.
-streets will contain T elements, where T is between N+1 and 50, inclusive.
-Each element of streets will contain T characters.
-Each character in each element of streets will either be '-', or one of '1'-'9'.
-For each i, streets[i][i] will be '-'.
-For each pair (i,j), streets[i][j] will be equal to streets[j][i].
-For each  1 <= i <= N, there will always be at least one way of reaching location i from location 0 by using one or more streets.


EXAMPLES

0)
3
{"-234",
 "2---",
 "3---",
 "4---"}

Returns: 3

There are 3 soldiers assigned to 3 forts and 3 direct connections going from the starting fort to each of them. It is not possible for a soldier to accompany any other without losing the opportunity to reach his own fort in the minimum time possible.

1)
2
{"-12",
 "1-1",
 "21-"}

Returns: 1

The minimum time after which soldier #1 can reach fort is 1 minute and the minimum time for soldier #2 is 2 minutes. It is possible for soldier #2 to first drop soldier #1 off in his assigned fort before reaching his own one and both soldiers still reach their assigned fort in the minimum time.


2)
3
{"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"}

Returns: 1



3)
2
{"-11",
 "1-1",
 "11-"}

Returns: 2



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"-234",
 "2---",
 "3---",
 "4---"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"-12",
 "1-1",
 "21-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, minRisk(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; string Arr1[] = {"-11",
 "1-1",
 "11-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minRisk(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SafeReturn test;

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
