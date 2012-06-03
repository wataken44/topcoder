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

class SlayingDeer {

 public:
  int getTime(int A, int B, int C)
  {
    // -- main code --
    if(A * 45 <= B * 30) return -1;

    int d = A * 45 - B * 30;

    int t = (C / d) * 45;
    int r = C - (C / d) * d;

    // DUMP(A);DUMP(B);
    // DUMP(d);DUMP(t);DUMP(r);

    if(r == 0) {
    } else if(A <= B) {
      r += B * 30;
      t += (r % A == 0 ? r / A : r / A + 1);
    } else {
      int v = A - B;
      if(r <= 30 * v) {
        t += (r % v == 0 ? r / v : r / v + 1);
      }else {
        r -= 30 * v;
        t += 30 + (r % A == 0 ? r / A : r / A + 1);
      }
    }
    
    return t;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Although TopCoder member Running Wild is a vegetarian, he has recently decided that he would eat venison if he could catch a deer himself. Before committing too much time and effort to this endeavor, Running Wild would like to estimate his chances at success. To do this, he assumes that he will run at a constant speed of A meters per minute without ever getting tired. Similarly, a deer will run at a constant speed of B meters per minute, but after every 30 minutes of running, it must stop and rest for 15 minutes. Finally, Running Wild also assumes that he will begin at a given distance of C meters behind the deer, and that they will always be running in the same fixed direction.

Create a class SlayingDeer that contains a method getTime, which is given an int A, an int B, and an int C, representing the quantities described above. The method should return the number of minutes (rounded up) it will take for Running Wild to catch the deer. If Running Wild will never catch the deer, the method should return -1.

DEFINITION
Class:SlayingDeer
Method:getTime
Parameters:int, int, int
Returns:int
Method signature:int getTime(int A, int B, int C)


NOTES
-If Running Wild and the deer are at precisely the same position, then Running Wild is considered to have caught the deer.


CONSTRAINTS
-A and B will be between 1 and 1000 inclusive.
-C will be between 1 and 100000 inclusive.


EXAMPLES

0)
5
4
20

Returns: 20

Running Wild gains one meter per minute over the first 20 minutes before catching the deer.

1)
5
4
47

Returns: 34

As in the previous example, Running Wild will gain 1 meter per minute for the first 30 minutes. Then, however, the deer stops and rests. Running Wild gains 5 meters per minute while the deer is resting. Note that the answer is rounded up.

2)
10
17
1

Returns: -1

3)
133
198
7515

Returns: 7515

4)
1
1000
15819

Returns: -1

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 20; int Arg3 = 20; verify_case(0, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 47; int Arg3 = 34; verify_case(1, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 17; int Arg2 = 1; int Arg3 = -1; verify_case(2, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 133; int Arg1 = 198; int Arg2 = 7515; int Arg3 = 7515; verify_case(3, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000; int Arg2 = 15819; int Arg3 = -1; verify_case(4, Arg3, getTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SlayingDeer test;

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
