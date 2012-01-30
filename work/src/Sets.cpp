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

class Sets {
 public:
  vector <int> operate(vector <int> A, vector <int> B, string operation) {
    // -- main code --

    vector<int> r;
    typedef vector<int>::iterator Iter;
    
    if(operation == "UNION") {
      TIMES(i, A.size()) {
        Iter it = find(r.begin(), r.end(), A[i]);
        if (it == r.end()){
          r.push_back(A[i]);
        }
      }
      TIMES(i, B.size()) {
        Iter it = find(r.begin(), r.end(), B[i]);
        if (it == r.end()){
          r.push_back(B[i]);
        }
      }
    }else if(operation == "INTERSECTION") {
      TIMES(i, A.size()) {
        Iter it = find(B.begin(), B.end(), A[i]);
        if (it != B.end()){
          r.push_back(A[i]);
        }
      }
    }else if(operation == "SYMMETRIC DIFFERENCE") {
      TIMES(i, A.size()) {
        Iter it = find(B.begin(), B.end(), A[i]);
        if (it == B.end()){
          r.push_back(A[i]);
        }
      }
      TIMES(i, B.size()) {
        Iter it = find(A.begin(), A.end(), B[i]);
        if (it == A.end()){
          r.push_back(B[i]);
        }
      }
    }

    sort(r.begin(), r.end());
    
    return r;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A set of numbers is a collection of numbers with no repeated elements. We can define the following set operations:
The UNION of two sets A and B is a set containing all the elements that are either in A or in B.
The INTERSECTION of two sets A and B is a set containing all the elements that are in both A and B.
The SYMMETRIC DIFFERENCE of two sets A and B is a set containing all the elements that are either in A or in B, but not containing elements that are in both A and B.
Given two vector <int>s representing sets A and B, and an operation applied on them, return a vector <int> representing the resulting set sorted in ascending order. If the result is an empty set then return an empty vector <int>. operation will be one of the following: "UNION", "INTERSECTION", "SYMMETRIC DIFFERENCE".

DEFINITION
Class:Sets
Method:operate
Parameters:vector <int>, vector <int>, string
Returns:vector <int>
Method signature:vector <int> operate(vector <int> A, vector <int> B, string operation)


CONSTRAINTS
-A will have between 0 and 50 elements inclusive.
-B will have between 0 and 50 elements inclusive.
-each element in A will be between -1000000 and 1000000 inclusive.
-each element in B will be between -1000000 and 1000000 inclusive.
-A will not have any repeated elements.
-B will not have any repeated elements.
-operation will be one of the following: "UNION", "INTERSECTION", "SYMMETRIC DIFFERENCE".


EXAMPLES

0)
{1,2,3,4}
{3,4,5,6}
"INTERSECTION"

Returns: { 3,  4 }

The only elements that are both in A and in B are 3 and 4.

1)
{1,2,3,4}
{3,4,5,6}
"UNION"

Returns: { 1,  2,  3,  4,  5,  6 }

Here we return all the elements that are either in A or in B.

2)
{432,756,123}
{534,76,1209}
"INTERSECTION"

Returns: { }

There are no common elements, so we must return an empty set.

3)
{6,5,7,4}
{7,6,4,10}
"SYMMETRIC DIFFERENCE"

Returns: { 5,  10 }

Elements 4, 6, 7 are in both sets, thus they cannot be in our answer. However we can include elements 5 and 10.

4)
{342,654,897,312,76,23,78}
{21,43,87,98,23,756,897,234,645,876,123}
"SYMMETRIC DIFFERENCE"

Returns: { 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INTERSECTION"; int Arr3[] = { 3,  4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "UNION"; int Arr3[] = { 1,  2,  3,  4,  5,  6 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {432,756,123}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {534,76,1209}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INTERSECTION"; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {6,5,7,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,6,4,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SYMMETRIC DIFFERENCE"; int Arr3[] = { 5,  10 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {342,654,897,312,76,23,78}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {21,43,87,98,23,756,897,234,645,876,123}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SYMMETRIC DIFFERENCE"; int Arr3[] = { 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, operate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Sets test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
