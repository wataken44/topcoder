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

class Hieroglyphs {

 public:
  int minimumVisible(vector <string> hier1, vector <string> hier2)
  {
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Hieroglyphs were widely used for writing in ancient times and they are used in some languages even now. In this problem, we will consider a simplified model of hieroglyphs.
Let's call a hieroglyph a two-dimensional figure that consists of several segments, each of which has a positive length and is either horizontal or vertical. The segments in the same hieroglyph can touch or intersect each other, but no two segments may overlap. That is, there are no two segments such that the length of their intersection is positive. The segments are considered to be infinitely thin.
You will be given two hieroglyphs in vector <string> hier1 and hier2. Both of them are drawn on the same plane with a Cartesian coordinate system. Each element of hier1 will be a comma-separated list of segments. Each segment is formatted "x1 y1 x2 y2" (quotes for clarity), where (x1, y1) and (x2, y2) are the coordinates of its two endpoints (x1 ? x2, y1 ? y2). The set of all segments of the first hieroglyph is the union of all segments presented in elements of hier1. The set of all segments of the second hieroglyph is given in the same format in elements of hier2. It is guaranteed that both hier1 and hier2 describe valid hieroglyphs as defined in the previous paragraph.
You are allowed to move each of the hieroglyphs to an arbitrary place on the plane via translation (See notes). No other operations like applying rotation or symmetry are allowed.
Once the positions for each hieroglyph are chosen, their union is defined as a set of points on the plane that belong to at least one of them. It's easy to see that union of two hieroglyphs can be represented as a set of non-overlapping segments. You are to minimize the total length of these segments.
Return this minimum possible total length.

DEFINITION
Class:Hieroglyphs
Method:minimumVisible
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int minimumVisible(vector <string> hier1, vector <string> hier2)


NOTES
-Translation is an operation that moves every point a constant distance in a specified direction. More exactly, an arbitrary vector (dx, dy) is first chosen, and then translation works as moving each point (x, y) to (x + dx, y + dy).


CONSTRAINTS
-hier1 and hier2 will each contain between 1 and 50 elements, inclusive.
-Each element of hier1 and hier2 will contain between 1 and 50 characters, inclusive.
-Each element of hier1 and hier2 will be a single comma separated list of between 1 and 4 segment descriptions, inclusive, without leading and trailing commas.
-Each segment description will be formatted "x1 y1 x2 y2" (quotes for clarity), where x1, y1, x2 and y2 are integers between 0 and 80, inclusive, with no extra leading zeros.
-In each segment description, x1 will be less than or equal to x2 and y1 will be less than or equal to y2.
-Each segment will be either horizontal or vertical and will have a positive length.
-No two segments of the same hieroglyph will overlap (as defined in the statement).


EXAMPLES

0)
{"0 0 10 0,10 0 10 3"}
{"0 1 10 1","5 1 5 4"}

Returns: 16
     
Here it's better to combine the horizontal line segments than the vertical ones.

1)
{"1 1 1 5"}
{"3 2 5 2"}

Returns: 6

There is no way to combine the hieroglyphs in such a way that segments overlap.

2)
{"0 2 6 2"}
{"5 1 6 1,8 1 9 1"}

Returns: 6




3)
{"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"}
{"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"}


Returns: 65



4)
{"10 10 10 20,10 30 10 40","10 10 20 10"}
{"10 0 10 20,10 27 10 35","10 0 20 0"}

Returns: 45



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0 10 0,10 0 10 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 10 1","5 1 5 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(0, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 1 1 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 2 5 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 2 6 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 1 6 1,8 1 9 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 65; verify_case(3, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"10 10 10 20,10 30 10 40","10 10 20 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10 0 10 20,10 27 10 35","10 0 20 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 45; verify_case(4, Arg2, minimumVisible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Hieroglyphs test;

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
