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
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class PermutationSignature {
 public:
  vector <int> reconstruct(string signature) {
    // -- main code --

    vector<int> ret(1, 1);
    int cur_max = 1;
    
    TIMES(i, signature.size()) {
      if(signature[i] == 'I') {
        ++cur_max;
        ret.push_back(cur_max);
      }else {
        // D
        int back = ret.back();
        
        TIMES(j, ret.size()) {
          if(ret[j] >= back) {
            ++ret[j];
          }
        }
        ret.push_back(back);
        ++cur_max;
      }
    };
    
    return ret;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The signature of a permutation is a string that is computed as follows: for each pair of consecutive elements of the permutation, write down the letter 'I' (increasing) if the second element is greater than the first one, otherwise write down the letter 'D' (decreasing).



For example, the signature of the permutation {3,1,2,7,4,6,5} is "DIIDID".



Your task is to reverse this computation: You are given a string signature containing the signature of a permutation.
Find and return the lexicographically smallest permutation with the given signature.
If no such permutation exists, return an empty vector <int> instead.


DEFINITION
Class:PermutationSignature
Method:reconstruct
Parameters:string
Returns:vector <int>
Method signature:vector <int> reconstruct(string signature)


NOTES
-For any positive integer N, a permutation of N elements is a sequence of length N that contains each of the integers 1 through N exactly once.
-To compare two permutations A and B, find the smallest index i such that A[i] and B[i] differ. If A[i] < B[i], we say that A is lexicographically smaller than B, and vice versa.


CONSTRAINTS
-signature will contain between 1 and 50 characters, inclusive.
-Each character in signature will be either 'I' or 'D'.


EXAMPLES

0)
"IIIII"

Returns: {1, 2, 3, 4, 5, 6 }



1)
"DI"

Returns: {2, 1, 3 }

There are two permutations with this signature: {3,1,2} and {2,1,3}. You must return the lexicographically smaller one.

2)
"IIIID"

Returns: {1, 2, 3, 4, 6, 5 }



3)
"DIIDID"

Returns: {2, 1, 3, 5, 4, 7, 6 }

This is the signature from the problem statement. Note that the correct answer is not the permutation from the problem statement.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "IIIII"; int Arr1[] = {1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "DI"; int Arr1[] = {2, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "IIIID"; int Arr1[] = {1, 2, 3, 4, 6, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "DIIDID"; int Arr1[] = {2, 1, 3, 5, 4, 7, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PermutationSignature test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
