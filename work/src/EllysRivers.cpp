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

class EllysRivers {

 public:
  double getMin(int length, int walk, vector <int> width, vector <int> speed)
  {
    double result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Shopping is by no means an easy task. Yes, sure, if you want to buy shoes or some clothes that's no problem at all. But what happens if you would like an extremely rare poison, found only in the mists of Amazonia? Now you see, Elly's life is not as easy as you would think. She has almost reached her final destination, but unfortunately she can only use boats and travel by foot for the final part.

There are N+1 really long, but narrow parallel islands, going from South to North, numbered from 0 to N, inclusive. There are also N rivers between the islands, numbered from 0 to N-1, inclusive. River i is width[i] kilometers wide and flows between islands i and i+1. The speed of the current in each river is negligible. For river i, the maximum speed at which Elly can sail is speed[i] kilometers per hour, regardless of the direction in which she sails.

All islands are length kilometers long. Starting from the southmost point, each one has boat docks one kilometer apart throughout its entire coastline. Thus, there are length + 1 docks on each island (at kilometer 0, 1, É, length). The islands are so narrow, that you can assume the same dock serves the boats on both sides of the island, and that walking horizontally from one side of the island to the other takes no time.

For simplicity we can represent the islands as parallel vertical line segments, and the docks as points on the plane. Island 0 goes from point (0, 0) to (0, length), island 1 from (width[0], 0) to (width[0], length), island 2 from (width[0] + width[1], 0) to (width[0] + width[1], length), and so on, where width[i] gives the width of the i-th river. The docks on island 0 are with coordinates (0, 0), (0, 1), É (0, length); the ones on island 1 are with coordinates (width[0], 0), (width[0], 1), É, (width[0], length); these on island 2 are with coordinates (width[0] + width[1], 0), (width[0] + width[1], 1), É, (width[0] + width[1], length) and so on.

Elly can only take boats from dock to dock (i.e. she can neither depart from nor arrive at non-integer coordinates). She can also walk (vertically) along any island with a constant speed of walk kilometers per hour. The girl is currently on the southmost point of the westmost island and wants to reach the northmost point of the eastmost island. Elly wonders what is the minimal time required to travel to her destination. Help her by writing a method that calculates this for her.

You are given the length of the islands in the int length and the walking speed in the int walk. The widths of the rivers will be given in the vector <int> width and the maximal sailing speeds in the vector <int> speed. Return a double giving the shortest time in which she can reach her destination.

DEFINITION
Class:EllysRivers
Method:getMin
Parameters:int, int, vector <int>, vector <int>
Returns:double
Method signature:double getMin(int length, int walk, vector <int> width, vector <int> speed)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.


CONSTRAINTS
-length will be between 1 and 100,000, inclusive.
-walk will be between 1 and 1,000,000, inclusive.
-width will contain between 1 and 50 elements, inclusive.
-speed will contain between 1 and 50 elements, inclusive.
-width and speed will contain the same number of elements.
-Each element of width will be between 1 and 1,000,000, inclusive.
-Each element of speed will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
10
3
{5, 2, 3}
{5, 2, 7}

Returns: 3.231651964071508

Elly will not walk on any of the islands. She will sail four kilometers to the north in the first river,
reaching the second island at point (5, 4). Then she sails another one kilometer to the north in the second river,
going to (7, 5) on the third island. In the end she will sail to her destination at (10, 10).
The required times for her journey are as follows:

(0, 0) -> (5, 4) = 6.403124237433 / 5 = 1.280624847487 hours
(5, 4) -> (7, 5) = 2.236067977499 / 2 = 1.118033988749 hours
(7, 5) -> (10, 10) = 5.830951894845 / 7 = 0.832993127835 hours



1)
10000
211
{911}
{207}

Returns: 48.24623664712219

Don't forget that Elly can walk on the islands.

2)
1337
2
{100, 200, 300, 400}
{11, 12, 13, 14}

Returns: 128.57830549575695



3)
77
119
{11, 12, 13, 14}
{100, 200, 300, 400}

Returns: 0.3842077071089629



4)
7134
1525
{11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}
{1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}

Returns: 214.6509731258811

A large random example.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {5, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 2, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.231651964071508; verify_case(0, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10000; int Arg1 = 211; int Arr2[] = {911}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {207}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 48.24623664712219; verify_case(1, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1337; int Arg1 = 2; int Arr2[] = {100, 200, 300, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11, 12, 13, 14}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 128.57830549575695; verify_case(2, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 77; int Arg1 = 119; int Arr2[] = {11, 12, 13, 14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100, 200, 300, 400}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.3842077071089629; verify_case(3, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7134; int Arg1 = 1525; int Arr2[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 214.6509731258811; verify_case(4, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  EllysRivers test;

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
