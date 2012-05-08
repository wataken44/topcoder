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

class Embassy {

 public:
  vector<int> frm;
  int dl;
  int ot;

  int go(int o)
  {
    int r = frm[0];
    
    int sz = frm.size();
    FOR(i, 1, sz) {
      int f = frm[i];
      if(o >= f) {
        o -= f;
        r += f;
      }else {
        f -= o;
        r += o;

        int m = f % dl;

        if(m <= dl - ot) {
          r += (f / dl) * dl + dl - ot;
          o = ot;
        }else {
          r += (f / dl) * dl + dl - ot;
          r += m - (dl - ot);
          o = ot - (m - (dl - ot));
        }
      }
    }

    return r;
  }
  
  int visaApplication(vector <int> forms, int dayLength, int openTime)
  {
    // -- main code --
    frm = forms;
    dl = dayLength;
    ot = openTime;

    int r = INT_MAX;

    TIMES(t, ot + 1) {
      r = min(r, go(t));
    } 
    
    return r;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You've just qualified for the on-site round of a major coding tournament! You now need to sort out a visa to allow you to travel to the event. You know that this is likely to be a long process, but are determined to sort it out as quickly as possible, even if it means working day and night. The process involves filling out a series of forms, which then have to be approved by the embassy. When the last form is approved your visa is granted. The approval process is very quick (instantaneous for the purpose of this problem), but there is a catch: each form has to be approved by the embassy before they will give you the next form to fill out. The embassy opens at exactly the same time each day and remains open for openTime time units. By the non-standard embassy clocks, a day is dayLength time units long, so the embassy then remains closed for dayLength - openTime time units before it opens the next day. Forms can be approved at any point in time between the time that the embassy opens and the time it closes, inclusive. However, if you finish filling in a form when the embassy is closed, you have to wait until it opens again before the form can be approved. The length of time it takes you to fill out form i is forms[i] units and the forms must be completed in the order they are given in forms. You already have the first form in your possession and can start filling it out at any time. Return the minimum length of time between starting to fill out the first form and getting your visa granted.

DEFINITION
Class:Embassy
Method:visaApplication
Parameters:vector <int>, int, int
Returns:int
Method signature:int visaApplication(vector <int> forms, int dayLength, int openTime)


CONSTRAINTS
-forms will contain between 1 and 50 elements, inclusive.
-Each element of forms will be between 1 and 1,000,000 (10^6), inclusive.
-dayLength will be between 1 and 1,000,000 (10^6), inclusive.
-openTime will be between 1 and dayLength, inclusive.


EXAMPLES

0)
{4,4,4}
24
8

Returns: 12

The embassy is open for 8 hours out of a 24 hour day. Each of the three forms takes 4 hours to fill in. If you start filling in the first form 4 hours before the embassy opens, you can get it approved just as the embassy opens. The embassy will still be open 4 hours later to approve the second form and the third form can be approved just as the embassy shuts. Since you never have to wait, the total time is 12 hours.

1)
{4,4,4,4}
24
8

Returns: 28

Now there is an additional form to fill in. You can't complete the process in a single day.

2)
{2,2,2,2}
24
1

Returns: 73

The embassy is only open for one hour each day, so you can only get one form approved per day.

3)
{25,500,630,2500,1000,350,22,58,100,400,500,5000}
1440
360

Returns: 16945

Time is now measured in minutes. It's optimal to start filling in the first form 335 minutes after the embassy first opens.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 8; int Arg3 = 12; verify_case(0, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 8; int Arg3 = 28; verify_case(1, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 1; int Arg3 = 73; verify_case(2, Arg3, visaApplication(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {25,500,630,2500,1000,350,22,58,100,400,500,5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1440; int Arg2 = 360; int Arg3 = 16945; verify_case(3, Arg3, visaApplication(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Embassy test;

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
