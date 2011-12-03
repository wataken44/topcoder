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

class TheCoffeeTimeDivTwo {

 public:
  int serve(vector<int> seats)
  {
    if(seats.size() == 0) return 0;
    int t = 0;

    int i = 0;
    int sz = seats.size();

    while(i < sz) {
        int nServe = (i == 0 ? (sz % 7 == 0 ? 7 : sz % 7) : 7);

      t += 47;
      t += nServe * 4;

      t += seats[i + nServe - 1] * 2;
      
      i += nServe;
    }
    return t;
  }

  int find(int n, vector<int> tea)
  {
    // -- main code --
    vector<int> coffee;
    UPTO(i, 1, n) {
      if(std::find(tea.begin(), tea.end(), i) == tea.end()) {
        coffee.push_back(i);
      }
    }

    sort(tea.begin(), tea.end());
    sort(coffee.begin(), coffee.end());

    int tc = serve(coffee);
    int tt = serve(tea);

    DUMP(tc);DUMP(tt);
    
    return tc + tt;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// John and Brus are flying on an airplane and now it's coffee time.

There are n seats in the plane numbered from 1 to n, one seat in each row. All seats are occupied, thus there are n passengers overall (including John and Brus). A stewardess will serve a cup of coffee or tea to each passenger. She needs to serve tea to all passengers whose seat numbers are listed in vector <int> tea, and she needs to serve coffee to all other passengers.

A coffee and tea machine is located just before the first seat of the plane. The stewardess has a flask that can contain enough coffee or tea to serve at most 7 passengers. Initially, the stewardess is located near the coffee and tea machine and the flask is empty.

The stewardess can perform the following kinds of actions:

Move from the coffee and tea machine to seat 1 or move from seat 1 to the coffee and tea machine. Each of these two actions takes 1 second.
Move from seat i, i > 1, to seat i-1. It takes 1 second.
Move from seat i, i < n, to seat i+1. It takes 1 second.
If she is near seat i, the passenger at this seat has not yet been served and the current type of drink in the flask is the same as the drink this passenger wants, she can serve this passenger with a cup of drink he/she wants. It takes 4 seconds.
If she is near the coffee and tea machine and the flask is empty, she can fill the flask with either tea or coffee (but not both simultaneously). It takes 47 seconds. Note that she can fill the flask partially (to serve less than 7 passengers), but it still takes 47 seconds.


Given int n and vector <int> tea, return the minimal time needed for the stewardess to serve all passengers with proper drinks and return to the coffee and tea machine.

DEFINITION
Class:TheCoffeeTimeDivTwo
Method:find
Parameters:int, vector <int>
Returns:int
Method signature:int find(int n, vector <int> tea)


CONSTRAINTS
-n will be between 2 and 1000, inclusive.
-tea will contain between 1 and 47 elements, inclusive.
-Each element of tea will be between 1 and n, inclusive.
-All elements of tea will be distinct.


EXAMPLES

0)
2
{1}

Returns: 108

The stewardess will serve coffee in 47+2+4+2=55 seconds and tea in 47+1+4+1=53 seconds.

1)
2
{2, 1}

Returns: 59

Here she only needs to serve tea.

2)
15
{1, 2, 3, 4, 5, 6, 7}

Returns: 261

The stewardess will fill the flask three times overall: once with tea and two times with coffee.

3)
47
{1, 10, 6, 2, 4}

Returns: 891

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 108; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arr1[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 261; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arr1[] = {1, 10, 6, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 891; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TheCoffeeTimeDivTwo test;

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
