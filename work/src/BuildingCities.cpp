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

template<typename PT, typename DT>
class PQ {
 public:
  typedef PT priority_type;
  typedef DT data_type;
  typedef std::pair<priority_type, data_type> pair_type;
  typedef std::list<pair_type> list_type;
  typedef typename list_type::iterator iterator;
  typedef typename list_type::const_iterator const_iterator;
  
  PQ() {}
  virtual ~PQ() {}

  int size() const { return m_body.size(); }
  bool empty() const { return size() == 0; }
  void pop() { m_body.pop_front(); }
  data_type& front() { return m_body.front().second; }

  iterator begin() { return m_body.begin(); }
  iterator end() { return m_body.end(); }
  const_iterator begin() const { return m_body.begin(); }
  const_iterator end() const { return m_body.end(); }

  void push(const priority_type& p, const data_type& d)
  {
    iterator iter = find(d);
    if(iter != end()) {
      if(iter->first > p) {
        m_body.erase(iter);
        add(p, d);
      }
    }else {
      add(p, d);
    }
  }
  
  void add(const priority_type& p, const data_type& d)
  {
    for(iterator iter = begin(); iter != end(); ++iter) {
      if(iter->first > p) {
        m_body.insert(iter, std::make_pair(p, d));
        return;
      }
    }
    m_body.push_back(std::make_pair(p, d));
  }

  void remove(const data_type& d) {
    iterator iter = find(d);
    if(iter != end()) {
      m_body.erase(iter);
    }
  }

  iterator find(const data_type& d)
  {
    for(iterator iter = begin(); iter != end(); ++iter) {
      if(iter->second == d) {
        return iter;
      }
    }
    return end();
  }
  
 private:
  list_type m_body;
};


class BuildingCities {

 public:
  int findMinimumCities(int maxDirect, int maxTravel, vector <int> cityX, vector <int> cityY)
  {
    double eps = 1e-5;

    int sz = cityX.size();
    double ut = dd(cityX[0], cityY[0], cityX[sz-1], cityY[sz-1]);

    DUMP(maxTravel);DUMP(ut);
    if(maxTravel + eps < ut) {
      return -1;
    }
    
    // -- main code --

    int result = -1;

    PQ<int, int> queue;
    queue.push(0, 0);

    vector<bool> visited(sz, false);
    visited[0] = true;

    vector<int> prev(sz, 0);
    prev[0] = -1;
    
    int total = 0;

    while(queue.size() > 0) {
      int d = queue.begin()->first;
      int f = queue.front();
      queue.pop();

      if(f == sz - 1) {
        total = d;
        break;
      }

      FOR(i, 0, sz) {
        int di = dist(cityX[f], cityY[f], cityX[i], cityY[i]);

        if(f == i || visited[i] || di > maxDirect) continue;
        PQ<int, int>::iterator it = queue.find(i);
        if(it == queue.end() || (it->first > d + di)) {
          queue.add(d+di, i);
          prev[i] = f;
        }
        visited[i] = true;
      }
    }

    DUMP(prev);

    return result;	
  }

  int dist(int x0, int y0, int x1, int y1)
  {
    return abs(x0 - x1) + abs(y0 - y1);
  }

  double dd(int x0, int y0, int x1, int y1)
  {
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1)*(y0 - y1));
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// There is a country with N cities. The cities are located on a two-dimensional plane. The coordinates of the i-th city are given in cityX[i] and cityY[i]. The 0-th city is the capital city while the (N-1)-th city is the center of the market (0-based indexing). Each city is assumed to be a point.


The distance that a citizen needs to travel from one city to another is equal to the Euclidian distance between them. A citizen can travel directly from one city to another if the Euclidian distance does not exceed maxDirect (since they can only carry a limited amount of supplies). Hence, if a citizen wants to go from the capital city to the center of the market then he may need to visit some cities in the journey to restock some supplies.


The king wants to reduce the minimum total distance that a citizen needs to travel from the capital city to the center of the market. He wants this minimum distance to not exceed maxTravel. In order to do so he will create some new cities in the country (he can do so at any coordinates not necessarily integer).


Return the minimum number of new cities needed to be built to achieve his target or -1 if it is impossible.

DEFINITION
Class:BuildingCities
Method:findMinimumCities
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int findMinimumCities(int maxDirect, int maxTravel, vector <int> cityX, vector <int> cityY)


NOTES
-The Euclidian distance between two points (X1,Y1) and (X2,Y2) is defined as the square root of ((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)).


CONSTRAINTS
-maxDirect and maxTravel will be between 1 and 2000, inclusive.
-cityX and cityY will contain between 2 and 50 elements, inclusive.
-cityX and cityY will contain the same number of elements.
-Each element of cityX and cityY will be between 0 and 2000, inclusive.
-All cities will have distinct locations.
-To avoid precision problems, if the answer for an input is X >= 0, then it will be possible to build X cities in such way that the minimal travel distance between the capital city and the center of the market is at most maxTravel - 1e-5, and any way of building fewer than X cities will result in this minimal distance being at least maxTravel + 1e-5.


EXAMPLES

0)
1
5
{0,0,0,1,2,2,3}
{0,1,2,2,2,1,1}

Returns: 1

Without adding new cities the minimum distance is 6. By building a city at (1,1) the minimum distance can be reduced to 4.

1)
3
15
{2,6,10,14}
{2,6,2,6}

Returns: 3



2)
2
15
{0,5,2,3,1,8,6,4,7,9,10}
{0,5,2,3,1,8,6,4,7,9,10}

Returns: 0

Sometimes no new cities need to be built.

3)
2
5
{0,5}
{0,5}

Returns: -1

The minimum distance between the two cities will always exceed 5.

4)
5
1500
{0,1000}
{0,1000}

Returns: 282



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arr2[] = {0,0,0,1,2,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,2,2,2,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 15; int Arr2[] = {2,6,10,14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,6,2,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 15; int Arr2[] = {0,5,2,3,1,8,6,4,7,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,5,2,3,1,8,6,4,7,9,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 5; int Arr2[] = {0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(3, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 1500; int Arr2[] = {0,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 282; verify_case(4, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BuildingCities test;

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
