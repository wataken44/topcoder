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

class RandomColoring {

 public:
  double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)
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
// Little Arthur has built a new fence around his house and now it is time to color it.

The fence consists of N planks numbered 0 to N-1 such that i-th plank is adjacent to planks i-1 and i+1 (modulo N) for all i between 0 and N-1, inclusive.

Each of the planks in the fence has to be colored using a single color. Different planks may have different colors. Each color is defined by three integer components: R, G, and B (meaning red, green, and blue, respectively), where 0 <= R < maxR, 0 <= G < maxG, and 0 <= B < maxB. Arthur can use any of the maxR*maxG*maxB possible colors.

Arthur likes random patterns. Therefore he has devised the following randomized method of coloring the fence:

In the first step he colors plank 0 using the color with components startR, startG, startB.
Next, for each i from 1 to N-1, in this order, he does the following: He looks at the (already determined) color C of the plank (i-1). The color for plank i is chosen uniformly at random among all colors that make a good transition from the color C. (Good transitions are defined below.)


A transition from color (R, G, B) to color (R', G', B') is called good if all components differ by at most d2 units (formally, |R - R'| <= d2, |G - G'| <= d2, |B - B'| <= d2) and at least one component differs by at least d1 units (formally, at least one of the conditions |R - R'| >= d1, |G - G'| >= d1, |B - B'| >= d1 holds). Intuitively, a transition between two colors is called good if they are neither too similar, nor too different.

Unfortunately, Arthur hasn't realized that after coloring all planks the transition from plank (N-1) to plank 0 does not have to be good. (Note that the fence is cyclic and thus these two planks are adjacent.) If that happens, the fence will look ugly.

Given ints N, maxR, maxG, maxB, startR, startG, startB, d1, and d2, return the probability that the fence will be ugly. (I.e., the probability that the transition from the color of plank (N-1) to the color of plank 0 is not good.)

DEFINITION
Class:RandomColoring
Method:getProbability
Parameters:int, int, int, int, int, int, int, int, int
Returns:double
Method signature:double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)


NOTES
-Your return value must have an absolute or relative error less than 1e-9.
-It is given that there exists at least one color that makes a good transition from the color (startR, startG, startB). Using this fact it can be proven that during the coloring process it is impossible to reach a state where there is no color that makes a good transition from the current plank's color. I.e. the coloring process cannot stop before coloring all the planks.


CONSTRAINTS
-N will be between 2 and 40, inclusive.
-maxR, maxG, maxB, will be between 1 and 50, inclusive.
-startR will be between 0 and maxR-1, inclusive.
-startG will be between 0 and maxG-1, inclusive.
-startB will be between 0 and maxB-1, inclusive.
-d1 and d2 will be between 0 and 50, inclusive.
-d1 will be less than or equal to d2.
-It is guaranteed that there will exist at least one valid color that makes a good transition from color (startR, startG, startB).


EXAMPLES

0)
2
5
1
1
2
0
0
0
1

Returns: 0.0

In this test case there are only two planks. Plank 1 will surely be colored using a color that makes a good transition from the color of plank 0. By symmetry, the transition from plank 1 color to plank 0 color has to be good as well. The fence will never be ugly.

1)
3
5
1
1
2
0
0
0
1

Returns: 0.22222222222222227

Only the R component can change here. There are nine ways how to color the planks 0, 1, and 2: 
(2, 0, 0) - (1, 0, 0) - (0, 0, 0)
(2, 0, 0) - (1, 0, 0) - (1, 0, 0)
(2, 0, 0) - (1, 0, 0) - (2, 0, 0)
(2, 0, 0) - (2, 0, 0) - (1, 0, 0)
(2, 0, 0) - (2, 0, 0) - (2, 0, 0)
(2, 0, 0) - (2, 0, 0) - (3, 0, 0)
(2, 0, 0) - (3, 0, 0) - (2, 0, 0)
(2, 0, 0) - (3, 0, 0) - (3, 0, 0)
(2, 0, 0) - (3, 0, 0) - (4, 0, 0)

All of these ways are equally likely. In two of them the transition from the color of plank 2 to the color of plank 0 is not good. Thus the probability of having an ugly fence is 2/9.

2)
7
4
2
2
0
0
0
3
3

Returns: 1.0

As the number of planks is odd, Arthur will certainly have an ugly fence.

3)
10
7
8
9
1
2
3
0
10

Returns: 0.0

For any pair of colors the transition between them is good. The fence cannot be ugly.

4)
10
7
8
9
1
2
3
4
10

Returns: 0.37826245943967396

5)
3
3
2
2
1
0
0
1
2

Returns: 0.09090909090909148



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.0; verify_case(0, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.22222222222222227; verify_case(1, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 3; int Arg8 = 3; double Arg9 = 1.0; verify_case(2, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 0; int Arg8 = 10; double Arg9 = 0.0; verify_case(3, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 4; int Arg8 = 10; double Arg9 = 0.37826245943967396; verify_case(4, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 2; double Arg9 = 0.09090909090909148; verify_case(5, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RandomColoring test;

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
