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

class RestaurantManager {

 public:
  int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures)
  {
    int result = 0;
    // -- main code --

    sort(tables.begin(), tables.end());

    int tsz = tables.size();
    int gsz = groupSizes.size();

    vector<bool> occupied(tsz, false);
    vector<int> assigned(gsz, -1);

    TIMES(t, 1000) {
      TIMES(i, gsz) {
        if(assigned[i] == -1) continue;
        if(departures[i] == t) {
          occupied[assigned[i]] = false;
        }
      }
      TIMES(i, gsz) {
        if(arrivals[i] == t) {
          TIMES(k, tsz) {
            if(occupied[k] == false && tables[k] >= groupSizes[i]) {
              occupied[k] = true;
              assigned[i] = k;
              break;
            }
          }
        }
      }
    }

    TIMES(i, gsz) {
      if(assigned[i] == -1) result += groupSizes[i];
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are the manager in charge of service at a restaurant.  Over the course of an evening, groups of customers arrive and you need to allocate tables to them.  The restaurant has tables of various sizes in order to cope with different sized groups.  The tables are allocated as follows:

When a group of customers arrives, it is allocated the smallest unallocated table that is at least as big as the group.  Apart from their sizes, tables are otherwise the same, so if there are multiple appropriate tables, one is allocated arbitrarily.  If there is no appropriate table available when the group arrives, the group is immediately turned away, and it will not return again that evening.  When a group finishes eating and leaves, its table becomes available again to be allocated to a new group of customers.

You want to know how many customers will be turned away using this method of allocating tables.

The sizes of the tables in the restaurant are given in a vector <int> tables, in which each element gives the size of a single table.  The size, arrival time and departure time of group i will be represented by groupSizes[i], arrivals[i] and departures[i], respectively.  The groups will be listed in the order that they arrive at the restaurant, and no two groups will arrive at the same time.  If a group arrives at exactly the same time another group departs, the table of the departing group will be available to be allocated to the arriving group (see example 0).  Return the number of customers who are turned away.

DEFINITION
Class:RestaurantManager
Method:allocateTables
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures)


CONSTRAINTS
-tables will contain between 1 and 50 elements, inclusive.
-Each element of tables will be between 1 and 20, inclusive.
-groupSizes, arrivals and departures will each contain between 1 and 50 elements, inclusive.
-groupSizes, arrivals and departures will each contain the same number of elements.
-Each element of groupSizes will be between 1 and 20, inclusive.
-Each element of arrivals and departures will be between 0 and 200, inclusive.
-Element i of arrivals will be strictly less than element i of departures.
-The elements of arrivals will be distinct and in increasing order.


EXAMPLES

0)
{4}
{4,8,4,2,2,4}
{0,10,12,16,18,26}
{10,20,18,26,36,28}

Returns: 14

This restaurant only has a single table that will seat 4 people. The first group of 4 arrives at time 0 and leaves at time 10. The next group also arrives at time 10, so the table is available, but the group is too big for the table so they are turned away. Another group of 4 then turns up at time 12 and is allocated the table until time 18. The group of 2 that turns up at time 16 is therefore turned away. Another group of 2 comes along at time 18, just as the table becomes available. They are still sitting as the final group comes along, so this group is also turned away. The total number of customers turned away is 8 + 2 + 4 = 14.

1)
{4,4}
{4,8,4,2,2,4}
{0,10,12,16,18,26}
{10,20,18,26,36,28}

Returns: 8

With 2 tables, the only group turned away is the group of size 8, which is too big for either table.

2)
{4,8}
{4,8,4,2,2,4}
{0,10,12,16,18,26}
{10,20,18,26,36,28}

Returns: 2

Now the restaurant has a table big enough for the group of size 8. A different group of size 2 is turned away later on because a table isn't available when they turn up.

3)
{10,8,11,16}
{14,1,15,1,19,15,9,15,20,2}
{4,5,7,18,21,25,29,31,46,49}
{8,37,11,36,36,46,40,42,47,50}

Returns: 69

4)
{18,15,2,6}
{7,9,16,3,10,3,2,10,16,16}
{10,15,19,20,21,22,27,35,37,43}
{13,24,22,32,32,32,35,48,41,44}

Returns: 10

5)
{13,9,6,1,9,8,6,2,8,20}
{20,10,11,10,1,5,16,2,9,17}
{12,14,64,78,100,121,151,155,162,164}
{19,26,159,96,155,134,169,199,169,174}

Returns: 17

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,8,4,2,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,10,12,16,18,26}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,20,18,26,36,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 14; verify_case(0, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,8,4,2,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,10,12,16,18,26}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,20,18,26,36,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 8; verify_case(1, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {4,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,8,4,2,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,10,12,16,18,26}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,20,18,26,36,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(2, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10,8,11,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14,1,15,1,19,15,9,15,20,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,7,18,21,25,29,31,46,49}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8,37,11,36,36,46,40,42,47,50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 69; verify_case(3, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {18,15,2,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,9,16,3,10,3,2,10,16,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,15,19,20,21,22,27,35,37,43}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {13,24,22,32,32,32,35,48,41,44}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; verify_case(4, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {13,9,6,1,9,8,6,2,8,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,10,11,10,1,5,16,2,9,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,14,64,78,100,121,151,155,162,164}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {19,26,159,96,155,134,169,199,169,174}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 17; verify_case(5, Arg4, allocateTables(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RestaurantManager test;

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
