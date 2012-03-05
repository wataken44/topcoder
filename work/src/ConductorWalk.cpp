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

class ConductorWalk {

 public:
  vector <int> getObserverRecords(vector <int> orderSeat, vector <int> orderTime, int inspectorSeat)
  {
    vector <int> result;
    // -- main code --
    

    int pos = 0;
    int state = 0; // 0: wait, 1: serve, 2: return
    
    list<int> rest;

    int served = 0;

    int sz = orderTime.size();
    
    UPTO(t, 0, 1050000) {
      FOR(k, served, sz) {
        if(t == orderTime[k]) {
          rest.push_back(orderSeat[k]);
        }
      }

      if(state == 1) {
        pos += 1;
        if(pos == rest.front()) {
          state = 2;
          ++served;
        }
      }else if(state == 2) {
        pos -= 1;
        if(pos == 0) {
          rest.pop_front();
          if(rest.empty()) {
            state = 0;
          }else {
            state = 1;
          }
        }
      } else {
        if(!rest.empty()) {
          state = 1;
        }
        if(sz == served) break;
      
      }

      if(pos == inspectorSeat) {
        result.push_back(t);
      }

      DUMP(t);DUMP(pos);DUMP(state);
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
The seats are enumerated from 1 to 100, and the i-th seat is located exactly i meters from the conductor's place.  The seats are arranged in a straight line, so there are exactly |i-j| meters between the i-th and j-th seats.


During the trip some passengers may order a tea. The orders are described by vector <int>s orderSeat and orderTime. The i-th order comes from the passenger at the orderSeat[i]-th seat orderTime[i] seconds after the departure. The orders will be given in chronological order, which means that the (i+1)-th order will always occur later then the i-th.


The conductor can carry at most one cup at once, so to satisfy each order he must walk to the passenger's seat, give him the tea and return back to his own place. He satisfies the orders in chronological order, i.e. in exactly the same order as they are given in the input. The conductor tries to satisfy each order as soon as possible. That is, if he has already satisfied all previous orders by the moment orderTime[i], then he will start satisfying the i-th order exactly at the moment orderTime[i]. Otherwise, he will start satisfying it immediately after all the chronologically earlier orders are satisfied. The conductor walks 1 meter per second and giving tea to a passenger takes no time, so delivering tea to the i-th passenger takes 2 * i seconds.


The passenger seated at seat inspectorSeat is an inspector. Every time the conductor passes by the inspector's seat, the inspector will write down the current time in seconds in his book. Return a vector <int> containing all times written down by the inspector in increasing order.


DEFINITION
Class:ConductorWalk
Method:getObserverRecords
Parameters:vector <int>, vector <int>, int
Returns:vector <int>
Method signature:vector <int> getObserverRecords(vector <int> orderSeat, vector <int> orderTime, int inspectorSeat)


CONSTRAINTS
-orderSeat will contain between 1 and 50 elements, inclusive.
-orderTime and orderSeat will contain the same number of elements.
-Each element of orderSeat will be between 1 and 100, inclusive.
-Each element of orderTime will be between 0 and 10000, inclusive.
-Each element of orderTime will be strictly greater than the previous one.
-inspectorSeat will be between 1 and 100, inclusive.


EXAMPLES

0)
{1, 3}
{5, 105}
2

Returns: {107, 109 }

Two passengers (at seats 1 and 3) request tea during the trip. The sequence of the conductor's actions is given in the following list:

Time			Event
5			Gets the first order
6                       Delivers the tea to the first passenger
7			Returns back to his place
105			Gets the second order
107			Walks by inspector's seat
108                     Delivers the tea to the second passenger
109                     Walks by inspector's seat on the way back
111			Returns to his place


1)
{10, 20, 30}
{0, 5, 10}
1

Returns: {1, 19, 21, 59, 61, 119 }


Time			Event
0			Gets order number 1
1			Walks by inspector
10                      Delivers the tea to the first passenger
19                      Walks by inspector
20			Order number 1 processed, starts processing order number 2
21                      Walks by inspector
40                      Delivers the tea to the second passenger
59                      Walks by inspector
60			Order number 2 processed, starts processing order number 3
61			Walks by inspector
90                      Delivers the tea to the third passenger
119                     Walks by inspector
120			All orders processed


2)
{1}
{0}
1

Returns: {1 }

The inspector ordered a tea for himself.

3)
{1}
{0}
100

Returns: { }

The inspector is sitting farther away from the conductor than the one passenger who places an order.  Therefore, the conductor will never walk by the inspector, and the inspector's book will be empty.

4)
{5, 5, 4, 5, 10, 5, 3, 7, 4}
{4, 18, 36, 43, 61, 78, 90, 101, 113}
4

Returns: {8, 10, 22, 24, 40, 48, 50, 65, 77, 85, 87, 105, 111, 119 }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 105}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = {107, 109 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getObserverRecords(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = {1, 19, 21, 59, 61, 119 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getObserverRecords(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = {1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getObserverRecords(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getObserverRecords(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {5, 5, 4, 5, 10, 5, 3, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 18, 36, 43, 61, 78, 90, 101, 113}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arr3[] = {8, 10, 22, 24, 40, 48, 50, 65, 77, 85, 87, 105, 111, 119 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getObserverRecords(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ConductorWalk test;

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
