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

using namespace std;

class MergeSort {
 public:
  int count ;
  
  int howManyComparisons(vector <int> numbers) {
    count = 0;
    // -- main code --

    merge_sort(numbers);
    
    return count;	
  }

  void merge_sort(vector<int>& va) {
    if(va.size() <= 1) return;
    
    vector<int> vb;
    vector<int> vc;

    int sz = va.size();
    int k = sz / 2;

    TIMES(i, k) {
      vb.push_back(va[i]);
    }

    FOR(i, k, sz) {
      vc.push_back(va[i]);
    }

    merge_sort(vb);
    merge_sort(vc);
    
    int bi = 0;
    int ci = 0;
    int ai = 0;
    
    while(bi < (int)vb.size() and ci < (int)vc.size()) {

      if(vb[bi] < vc[ci]) {
        va[ai] = vb[bi];
        ++bi;
        ++ai;
      }else if(vb[bi] > vc[ci]) {
        va[ai] = vc[ci];
        ++ci;
        ++ai;
      }else {
        va[ai] = vb[bi];
        ++bi;
        ++ai;
        va[ai] = vc[ci];
        ++ci;
        ++ai;
      }
      ++count;
    }

    while(bi < (int)vb.size()) {
      va[ai] = vb[bi];
      ++bi;
      ++ai;
    }
    while(ci < (int)vc.size()) {
      va[ai] = vc[ci];
      ++ci;
      ++bi;
    }

  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// MergeSort is a classical sorting algorithm following the divide-and-conquer paradigm. Sorting n elements, it has a worst-case
complexity of O(n*log(n)), which is optimal for sorting algorithms based on comparisons.

Basically, it sorts a list with more than one element the following way (a list containing only one element is always sorted):

1. divide the list into two sublists of about equal size (divide)
2. sort each of the two sublists (conquer)
3. merge the two sorted sublists into one sorted list (combine)


A pro of MergeSort is that it is stable, i.e. elements with the same key value keep their relative order during sorting.
A con is that it is not in-place since it needs additional space for temporarily storing elements.

Given a vector <int> numbers, return the number of comparisons the MergeSort algorithm
(as described in pseudocode below) makes in order to sort that list. In this context, a single comparison takes two numbers x, y
(from the list to be sorted) and determines which of x < y, x = y and x > y holds.

List mergeSort(List a)

1. if size(a) <= 1, return a
2. split a into two sublists b and c
   if size(a) = 2*k, b contains the first k elements of a, c the last k elements
   if size(a) = 2*k+1, b contains the first k elements of a, c the last k+1 elements
3. List sb = mergeSort(b)
   List sc = mergeSort(c)
4. return merge(sb, sc)


List merge(List b, List c)

1. create an empty list a
2. while both b and c are not empty, compare the first elements of b and c
   first(b) < first(c): remove the first element of b and append it to the end of a
   first(b) > first(c): remove the first element of c and append it to the end of a
   first(b) = first(c): remove the first elements of b and c and append them to the end of a
3. if either b or c is not empty, append that non-empty list to the end of a
4. return a


DEFINITION
Class:MergeSort
Method:howManyComparisons
Parameters:vector <int>
Returns:int
Method signature:int howManyComparisons(vector <int> numbers)


NOTES
-Be sure to exactly follow the algorithm as described, as a different implementation of MergeSort might lead to a different number of comparisons.


CONSTRAINTS
-numbers contains between 0 and 50 elements, inclusive.
-Each element of numbers is an int in its 'natural' (signed 32-bit) range from -(2^31) to (2^31)-1.


EXAMPLES

0)
{1, 2, 3, 4}

Returns: 4

{1, 2, 3, 4} is first split to {1, 2} and {3, 4}. {1, 2} is split to {1} and {2} and merging to {1, 2} takes one comparison. {3, 4} is split to {3} and {4} and merging to {3, 4} also takes one comparison. Merging {1, 2} and {3, 4} to {1, 2, 3, 4} takes two comparisons (first 1 is compared to 3 and then 2 is compared to 3). This makes a total of four comparisons.

1)
{2, 3, 2}

Returns: 2

{2, 3, 2} is split to {2} and {3, 2}. {3, 2} is split and then merged to {2, 3} making one comparison. {2} and {2, 3} are merged to {2, 2, 3} also making one comparison, which totals to two comparisons made.

2)
{-17}

Returns: 0

3)
{}

Returns: 0

4)
{-2000000000,2000000000,0,0,0,-2000000000,2000000000,0,0,0}

Returns: 19

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, howManyComparisons(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, howManyComparisons(Arg0)); }
	void test_case_2() { int Arr0[] = {-17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, howManyComparisons(Arg0)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, howManyComparisons(Arg0)); }
	void test_case_4() { int Arr0[] = {-2000000000,2000000000,0,0,0,-2000000000,2000000000,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(4, Arg1, howManyComparisons(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  MergeSort test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
