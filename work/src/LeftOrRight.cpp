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

class LeftOrRight {

 public:
  int maxDistance(string program)
  {
    int result = 0;
    // -- main code --
    int pos;
    
    int sz = program.size();
    pos = 0;
    TIMES(k, sz) {
      if(program[k] == 'L' || program[k] == '?') {
        --pos;
      }else {
        ++pos;
      }
      result = max(result, abs(pos));
    }

    pos = 0;
    TIMES(k, sz) {
      if(program[k] == 'R' || program[k] == '?') {
        --pos;
      }else {
        ++pos;
      }
      result = max(result, abs(pos));
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// The Very Heterogeneous State of Feudalia's army is designing a new spy robot. Currently, the robot can only accept two commands: L and R. L moves the robot one unit of distance to the left, and R moves the robot one unit to the right. A program for the robot is a sequence of commands. For a given program, its reach is the distance between the starting point and the farthest point visited during the execution of the program. For example, the reach of the program "LLLR" is 3, because after the first three steps we reach a location 3 units away from the starting point.

Unfortunately, Feudalia is world famous for the ineptitude of its public officials. Some coffee was spilled all over the program before it could be installed to the robot. Therefore, some of the commands may now be illegible.
Your task is to repair the program by replacing each illegible command with an L or an R. 
If there are multiple ways to repair the program, you have to pick one that maximizes its reach.

You are given a string program which describes the program in its current state. The i-th character in program represents the i-th command that is executed and will be 'L', 'R' or '?' (quotes for clarity). 'L' represents a legible move left, 'R' a legible move right and '?' a command that is illegible so you can choose 'L' or 'R' in its place. Return the largest reach a repaired program can have.

DEFINITION
Class:LeftOrRight
Method:maxDistance
Parameters:string
Returns:int
Method signature:int maxDistance(string program)


CONSTRAINTS
-program will contain between 1 and 50 characters, inclusive.
-Each character of program will be 'L', 'R' or '?' (quotes for clarity).


EXAMPLES

0)
"LLLRLRRR"

Returns: 3

All commands are legible. The reach of this program is 3: both after three steps and after five steps we are 3 units to the left of the starting location.

1)
"R???L"

Returns: 4

We can replace all of the question marks with a right command.

2)
"??????"

Returns: 6



3)
"LL???RRRRRRR???"

Returns: 11



4)
"L?L?"

Returns: 4



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLLRLRRR"; int Arg1 = 3; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arg0 = "R???L"; int Arg1 = 4; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arg0 = "??????"; int Arg1 = 6; verify_case(2, Arg1, maxDistance(Arg0)); }
	void test_case_3() { string Arg0 = "LL???RRRRRRR???"; int Arg1 = 11; verify_case(3, Arg1, maxDistance(Arg0)); }
	void test_case_4() { string Arg0 = "L?L?"; int Arg1 = 4; verify_case(4, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  LeftOrRight test;

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
