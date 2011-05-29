#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
// debug
#define DUMP(x) std::cout << #x << " = " << x << std::endl;

using namespace std;

class CubeRoll {
 public:
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
    data_type& front() const { return m_body.front()->second; }

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
  
  int getMinimumSteps(int initPos, int goalPos, vector <int> holePos) {
    // -- main code --

    if(initPos > goalPos) swap(initPos, goalPos);

    int lhole = INT_MIN;
    int rhole = INT_MAX;

    // simple case
    TIMES(i, holePos.size()) {
      if(initPos < holePos[i] and holePos[i] < goalPos) return -1;

      if(holePos[i] < initPos) lhole = max(holePos[i], lhole);
      if(holePos[i] > goalPos) rhole = min(holePos[i], rhole);
    }

    DUMP(initPos);
    DUMP(goalPos);
    DUMP(lhole);
    DUMP(rhole);

    int dist = goalPos - initPos;
    int lim_p = 2 + dist / 2;

    int lim_s = 0;
    int tmp = dist;
    while(tmp > 0) {
      ++lim_s;
      int sq = (int)floor(pow(lim_s, 0.5)); 
      tmp -= sq * sq;
    }

    PQ<int, int> pq;
    pq.push(0, 0);
    pq.push(1, 1);
    pq.push(1, -1);

    while(not pq.empty()) {
      PQ<int, int>::iterator iter = pq.begin();
      if(iter->second == dist) return iter->first;

      int cur_pos = iter->second;
      int cur_step = iter->first;

      pq.pop();
      
      UPTO(i, 1, lim_p) {
        int next_pos = cur_pos + i*i;
        int next_step = cur_step + 1;

        if(lhole < next_pos and next_pos < rhole and next_step <= lim_s) {
          pq.push(next_step, next_pos);
        }
      }

      UPTO(i, 1, lim_p) {
        int next_pos = cur_pos - i*i;
        int next_step = cur_step + 1;

        if(lhole < next_pos and next_pos < rhole and next_step <= lim_s ) {
          pq.push(next_step, next_pos);
        }
      }

      DUMP(cur_pos);
      dump(pq);
    }
    return -1;
  }

  void dump(PQ<int,int>& pq)
  {
    for(PQ<int, int>::iterator iter = pq.begin();
        iter != pq.end(); ++iter)
    {
      cout << "<" << iter->first << " " << iter->second << "> ";
    }
    cout << endl;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Fox Ciel is competing against Fox Jiro in a game called cube roll.

Cube roll is played on a horizontal row of cells.  Cells are numbered consecutively, increasing from left to right.  The row is infinitely long, so all integers, including negative ones, are valid cell numbers.  Certain cells contain holes, and they are given in the vector <int> holePos.
Initially, a cube is placed at cell initPos.  The objective of the game is to move the cube to cell goalPos using the least possible number of turns.  On each turn, the player will choose a direction (left or right) and roll the cube in that direction by x number of cells, where x is a perfect square (1, 4, 9, 16, ...).  If at any time during the roll, the cube lands on a cell containing a hole, the cube will fall into the hole.  Once the cube falls into a hole, it can never be moved again.


Return the minimum number of turns required to move the cube to cell goalPos.  If it is impossible, return -1 instead.


DEFINITION
Class:CubeRoll
Method:getMinimumSteps
Parameters:int, int, vector <int>
Returns:int
Method signature:int getMinimumSteps(int initPos, int goalPos, vector <int> holePos)


CONSTRAINTS
-initPos and goalPos will each be between 1 and 100,000, inclusive.
-holePos will contain between 1 and 50 elements, inclusive.
-Each element of holePos be between 1 and 100,000, inclusive.
-initPos and goalPos and all elements of holePos will be distinct.


EXAMPLES

0)
5
1
{3}

Returns: -1

There is a hole between initPos and goalPos, so the cube cannot be moved from initPos to goalPos.

1)
36
72
{300, 100, 200, 400}

Returns: 1

The distance between initPos and goalPos is a perfect square, and there are no holes between them, so the cube can be moved in a single turn.

2)
10
21
{38,45}

Returns: 2

One of the optimal solutions is to move the cube to 10 -> -15 -> 21. (Note that the coordinate of the cube can be a negative integer.)

3)
98765
4963
{10,20,40,30}

Returns: 2



4)
68332
825
{99726,371,67,89210}

Returns: 2



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 36; int Arg1 = 72; int Arr2[] = {300, 100, 200, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 21; int Arr2[] = {38,45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 98765; int Arg1 = 4963; int Arr2[] = {10,20,40,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 68332; int Arg1 = 825; int Arr2[] = {99726,371,67,89210}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CubeRoll test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
