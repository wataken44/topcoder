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

class EvilRobot {

 public:
  int gcd(int a, int b)
  {
    if(a > b) swap(a, b);
    while(a != 0 && a != b) {
      int t = b % a;
      b = a;
      a = t;
    }
    return b;
  }

  typedef long long ll;
  
  string createProgram(int N, int robotX, int robotY, int trapX, int trapY)
  {
    string result = "I'LL GET YOU NEXT TIME";
    // -- main code --

    int dx = trapX - robotX;
    int dy = trapY - robotY;

    if(dx < 0 || dy < 0) return result;
    if(dx == 0 && dy == 0) return string(N, 'R');
 
    if(dx + dy <= N) return string(dx, 'R') + string(dy, 'U') + string(N - dx - dy, 'R');
    
    if(dx == 0) return string(N, 'U');
    if(dy == 0) return string(N, 'R');

    string ret = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
    
    UPTO(xx, 1, N - 1) {
      int yy = N - xx;

      int step = min(dy / yy, dx / xx);

      int ty = step * yy;
      int tx = step * xx;

      int ry = dy - ty;
      int rx = dx - tx;
      
      if(ry > yy || rx > xx || ry < 0 || rx < 0) continue;
      DUMP(rx);DUMP(ry);DUMP(xx);DUMP(yy);
      ret = min(ret, string(rx, 'R') + string(ry, 'U') + string(xx - rx, 'R') + string(yy - ry, 'U'));
    }

    if(ret[0] != 'Z') result = ret;
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
An evil robot has been tormenting your land for years.  You decided to get rid of him by creating a deadly trap.  The trap is now ready, and the only problem left is to make the robot walk inside it.  Luckily, you managed to hack into the robot's movement system, and you can reprogram it to move the way you want.


The land is represented by an infinite grid of cells.  The robot is currently standing in cell (robotX, robotY), and the trap is set in cell (trapX, trapY).  The robot's program is very simple and consists of N commands, where each command is one of:


 'U': the robot moves from coordinates (x, y) to coordinates (x, y + 1).
 'R': the robot moves from coordinates (x, y) to coordinates (x + 1, y).

The commands are executed in order, starting from the first one, and the program is cyclical (i.e., after the last command is executed, it will start over from the first command).

As soon as the robot walks into the trap, the program will stop executing.  Write a program with exactly N commands that will make the robot walk into the trap.  Return this program as a string, where the i-th character is the i-th command.  If there are multiple possible programs, return the one among them that comes first alphabetically.  If no such program exists, return "I'LL GET YOU NEXT TIME" (quotes for clarity) instead.


DEFINITION
Class:EvilRobot
Method:createProgram
Parameters:int, int, int, int, int
Returns:string
Method signature:string createProgram(int N, int robotX, int robotY, int trapX, int trapY)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-robotX will be between 0 and 1000000000, inclusive.
-robotY will be between 0 and 1000000000, inclusive.
-trapX will be between 0 and 1000000000, inclusive.
-trapY will be between 0 and 1000000000, inclusive.


EXAMPLES

0)
3
1
1
3
4

Returns: "RUU"

The robot starts at point (1,1).  After executing the commands RUURU, he steps into the trap at (3,4).  There is one more program that leads to the trap (URU), but RUU comes earlier alphabetically.


1)
10
1
1
1
4

Returns: "UUURRRRRRR"

Here the trap is straight above the robot, so the first three of his moves must be U.

2)
3
2
1
1
1

Returns: "I'LL GET YOU NEXT TIME"

The robot is already to the right of the trap. This time there is nothing you can do.

3)
5
2
2
12
12

Returns: "I'LL GET YOU NEXT TIME"

Even though the robot hasn't passed the trap yet, it's not possible to create a program with 5 commands that leads into it.

4)
48
3
0
3000000
5000000

Returns: "RRRRRRRRRUUUUUUUUUUUUUUUUUUUURRRRRRRRRUUUUUUUUUU"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 4; string Arg5 = "RUU"; verify_case(0, Arg5, createProgram(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 4; string Arg5 = "UUURRRRRRR"; verify_case(1, Arg5, createProgram(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; string Arg5 = "I'LL GET YOU NEXT TIME"; verify_case(2, Arg5, createProgram(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 2; int Arg3 = 12; int Arg4 = 12; string Arg5 = "I'LL GET YOU NEXT TIME"; verify_case(3, Arg5, createProgram(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 48; int Arg1 = 3; int Arg2 = 0; int Arg3 = 3000000; int Arg4 = 5000000; string Arg5 = "RRRRRRRRRUUUUUUUUUUUUUUUUUUUURRRRRRRRRUUUUUUUUUU"; verify_case(4, Arg5, createProgram(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  EvilRobot test;

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
