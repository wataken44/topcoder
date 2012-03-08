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

class FoxAndBusiness {

 public:
  double minimumCost(int K, int totalWork, vector <int> a, vector <int> p)
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
// Fox Jiro and Eel Saburo are good friends. They work in the same company as partners.
Currently, they have totalWork units of work that needs to be done.
The work can be divided arbitrarily, even into pieces containing a non-integer number of units.

Jiro and Saburo will not be doing the work themselves.
They have N employees, numbered 0 through N-1.
Each employee has two parameters:

The ability a[i]: the number of units of work he or she can do in one hour.
The pay p[i]: the amount (in yen) he or she has to be paid for each unit of work done.

Jiro and Saburo have to select exactly K of their employees to do the work.
Due to the local laws, they are not allowed to divide the work among the employees arbitrarily:
Each of the K employees must work for exactly the same time.
(Note that different employees may make different amounts of work in that time.)

Additionally, all the work has to be done on a single machine.
Jiro and Saburo do not own such a machine, but they can rent one.
The machine can be rented for an arbitrary (possibly also non-integer) number of seconds, and the rent is 1 yen per second.
(Note that the employees will have to use the machine sequentially, i.e., one after another.)

You are given the int K, the int totalWork, the vector <int> a, and the vector <int> p.
Find and return the smallest amount for which Jiro and Saburo can get all the work done. (Note that the total amount consists of two parts: the money paid to the selected employees, and the money paid for renting the machine.)

DEFINITION
Class:FoxAndBusiness
Method:minimumCost
Parameters:int, int, vector <int>, vector <int>
Returns:double
Method signature:double minimumCost(int K, int totalWork, vector <int> a, vector <int> p)


NOTES
-The returned value must be accurate to within a relative or absolute error of 1e-9.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-a and p will each contain exactly N elements.
-Each element of a will be between 1 and 100,000, inclusive.
-Each element of p will be between 1 and 100,000, inclusive.
-K will be between 1 and N, inclusive.
-totalWork will be between 1 and 100,000, inclusive.


EXAMPLES

0)
1
10
{10}
{20}

Returns: 3800.0

We have to select the only employee.
For 10 units of work we have to pay him 10 * 20 = 200 yen.
The work will take him 10/10 = 1 hour.
We need to rent the machine for 1 hour = 3600 seconds, this will cost 3600 yen.
The total amount is 200 + 3600 = 3800 yen.

1)
1
100
{50, 60}
{1000, 2000}

Returns: 107200.0

Employee 0 is the better choice.

2)
2
300
{10, 20, 47}
{15, 20, 98765}

Returns: 77500.0

Employee 2 is the fastest worker, but she is way too expensive.
The optimal solution is to select employees 0 and 1.
Out of the 300 units of work, employee 0 will get 100 and employee 1 will get 200.
This way, each of them will work for exactly 10 hours.
The total we have to pay: 100*15 yen to employee 0, 200*20 yen to employee 1, and 72000 yen for renting the machine for 20 hours.

3)
4
1000
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
{20, 30, 40, 58, 60, 70, 80, 90, 100, 150}

Returns: 531764.705882353



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3800.0; verify_case(0, Arg4, minimumCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 100; int Arr2[] = {50, 60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000, 2000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 107200.0; verify_case(1, Arg4, minimumCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 300; int Arr2[] = {10, 20, 47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {15, 20, 98765}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 77500.0; verify_case(2, Arg4, minimumCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 1000; int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20, 30, 40, 58, 60, 70, 80, 90, 100, 150}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 531764.705882353; verify_case(3, Arg4, minimumCost(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxAndBusiness test;

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
