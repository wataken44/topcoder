#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
// debug
#define DUMP(x) std::cout << #x << " = " << x << std::endl;

using namespace std;

class ToastXToast {
 public:
  vector< vector<int> > memo;
  
  int bake(vector <int> ut, vector <int> ot) {
    // -- main code --

    sort(ut.begin(), ut.end());
    sort(ot.begin(), ot.end());

    memo = vector< vector<int> >(ut.size(), vector<int>(ot.size(), -2)); 

    vector< pair<int, bool> > toasts;

    int ui = 0;
    int oi = 0;
    while(true) {
      if(ui == ut.size() and oi == ot.size()) {
        break;
      }
      if(ui == ut.size()) {
        toasts.push_back(make_pair(ot[oi], true));
        ++oi;
        continue;
      }
      if(oi == ot.size()) {
        toasts.push_back(make_pair(ut[ui], false));
        ++ui;
        continue;
      }
      if(ut[ui] > ot[oi]) {
        toasts.push_back(make_pair(ot[oi], true));
        ++oi;
        continue;
      }else {
        toasts.push_back(make_pair(ut[ui], false));
        ++ui;
        continue;
      }
      
    }
    
    return breads.size();	
  }

  int go(vector< pair<int, bool> >& toasts, int from, int to) {
    if(memo[from][to] != -2) {
      return memo[from][to];
    }

    if(from == to) {
      memo[from][to] = 1;
      return memo[from][to];
    }

    
    
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


Toastman is going to create several eye-popping slices of toast out of several types of bread. 



Each type of bread has a positive number X (not necessarily integer) such that if a slice of bread of that type is toasted for less than X minutes, it becomes under toasted and if it is toasted for more than X minutes, it becomes over toasted. A slice of bread that is toasted for exactly X minutes becomes an eye-popping slice of toast.  



Note that the number X for different types of bread may be different, but such numbers will be the same for every slice of bread of a particular bread type. 


Toastman has toasted several slices of bread with the hope of creating an eye-popping slice of toast from several types of bread. Unfortunately he didn't know the exact value of X for any type of bread so all the slices of bread that he toasted became either under toasted or over toasted. You are given vector <int>s undertoasted and overtoasted denoting the slices of toast that were under toasted and over toasted, respectively. Each element will be an integer denoting the number of minutes that the corresponding slice of bread was toasted. 


Toastman does not have a very good memory (his brain is made out of bread!). Although he forgot which type of bread was used for each slice of toast, he thinks that the following condition was satisfied:

Each type of bread was used for at least one under toasted slice of toast and at least one over toasted slice of toast.

Return the minumum number of types of bread that could statisfy this condition. If the condition can not be satisified return -1.

DEFINITION
Class:ToastXToast
Method:bake
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int bake(vector <int> undertoasted, vector <int> overtoasted)


NOTES
-Assume that for any positive number X, there exists a bread type that needs to be toasted for exactly X minutes in order to become an eye-popping toast.


CONSTRAINTS
-undertoasted will contain between 1 and 50 elements, inclusive.
-Each element of undertoasted will be between 1 and 1,000,000, inclusive.
-All the elements of undertoasted will be distinct.
-overtoasted will contain between 1 and 50 elements, inclusive.
-Each element of overtoasted will be between 1 and 1,000,000, inclusive.
-All the elements of overtoasted will be distinct.
-overtoasted and undertoasted will not have an element in common.


EXAMPLES

0)
{2,4}
{5,6,3}

Returns: 2

Two types of bread is sufficient as illustrated below.


1)
{5}
{4}

Returns: -1



2)
{1,2,3}
{5,6,7}

Returns: 1



3)
{1,3,5}
{2,4,6}

Returns: 2



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,6,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, bake(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, bake(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, bake(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, bake(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ToastXToast test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
