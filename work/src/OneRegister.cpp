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

class OneRegister {

 public:
  int sim(string& p, int s)
  {
    int r = s;
    TIMES(k, p.size()) {
      if(p[k] == '+') {
        r *= 2;
      }else if(p[k] == '-') {
        r = 0;
      }else if(p[k] == '*') {
        r = r * r;
      }else if(p[k] == '/') {
        r = 1;
      }
    }
    return r;
  }
  
  string getProgram(int s, int t)
  {
    // -- main code --
    
    
    
    return ":-(";	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
You've designed a computer and implemented all the common arithmetic operators: addition, subtraction, multiplication and integer division.  However, your budget was very limited, so you could only afford to place a single register in the computer.  The register can store any non-negative integer value.  Since there is only one register, there is no need to identify the store location or the operands of each operation or its result.  The programming language has four instructions: '+', '-', '*' and '/'.  Each instruction performs the corresponding operation using the value in the register as both its parameters.  It then stores the result in the same register, overwriting the previous content.

A program for your computer is a sequential list of zero or more instructions.  You want to show that, even with its limitations, your newly constructed computer is powerful.  You will be given two ints s and t.  Return the shortest program that finishes with a value of t in the register if it contained s before executing.  If there is more than one possible answer, return the one that comes earliest lexicographically.  If there is no program that can do the job, return ":-(" (quotes for clarity) instead.


DEFINITION
Class:OneRegister
Method:getProgram
Parameters:int, int
Returns:string
Method signature:string getProgram(int s, int t)


NOTES
-A string comes lexicographically earlier than another one of the same length if and only if it contains a symbol with a lower ASCII code in the first position at which they differ. The operators in ascending order of ASCII code are: '*', '+', '-' and '/'.
-If the division operation is used when the register contains a zero, the program will give an error and terminate with a zero value in the register.


CONSTRAINTS
-s and t will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
7
392

Returns: "+*+"

The program executes as follows:

 Reg | Ins | Res
-----+-----+-----
   7 |  +  |  14
  14 |  *  | 196
 196 |  +  | 392


1)
7
256

Returns: "/+***"



2)
4
256

Returns: "**"



3)
7
7

Returns: ""

A trivial program.

4)
7
9

Returns: ":-("

No solution.

5)
10
1

Returns: "/"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 392; string Arg2 = "+*+"; verify_case(0, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 256; string Arg2 = "/+***"; verify_case(1, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 256; string Arg2 = "**"; verify_case(2, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 7; string Arg2 = ""; verify_case(3, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 9; string Arg2 = ":-("; verify_case(4, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "/"; verify_case(5, Arg2, getProgram(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  OneRegister test;

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
