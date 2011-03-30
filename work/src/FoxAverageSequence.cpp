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

class FoxAverageSequence {
 public:
  typedef long long  llong ;
  //vector< vector< vector<llong> > > memo;
  
  int theCount(vector <int> seq) {
    // -- main code --
    /*
    memo = vector< vector<vector<llong> > >(
        seq.size(), vector< vector<llong> >(41, vector<llong>(41, -1)) );
    */
    const llong modulo = 1000000007;

    int sz = seq.size();

    vector<int> maxseq(sz);

    TIMES(i, seq.size()) {
      if(seq[i] == -1) {

        maxseq[i] = 40;
        double r = 0;
        if(i >= 1) {
          TIMES(j, i ) {
            r += maxseq[j];
            DUMP(maxseq[j]);
          }
          maxseq[i] = (int)floor(r / i);
        }
        if(i > 2) {
          if(maxseq[i-2]>maxseq[i-1] and maxseq[i-1]>maxseq[i]) {
            return 0;
          }
        }
      }else {
        maxseq[i] = seq[i];
        double r = 0;
        if(i >= 1) {
          TIMES(j, i) {
            r += maxseq[j] / (double)i;
          }
          if(maxseq[i] > r) {
            return 0;
          }
        }
        if(i > 2) {
          if(maxseq[i-2]>maxseq[i-1] and maxseq[i-1]>maxseq[i]) {
            return 0;
          }
        }
      }
    }

    int result = 1;
    TIMES(i, sz) {
      result = result * (maxseq[i] - (seq[i] == -1 ? -1 : seq[i] - 1)) % modulo;
    }
    
    return result;
  }


// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel likes sequences of integers. She especially likes sequences which she considers to be beautiful. A sequence (A[0], A[1], ..., A[N-1]), N >= 1, is beautiful if and only if it satisfies the following conditions:

Each element of the sequence is an integer between 0 and 40, inclusive.
Each element of the sequence is less than or equal to the arithmetic mean of the previous elements. That is, for each i, 1 <= i < N, we have A[i] <= (A[0] + A[1] + ... + A[i-1]) / i.
There are no three consecutive elements in the sequence that follow in strictly decreasing order. In other words, there must be no index i, 0 <= i < N-2, such that A[i] > A[i+1] > A[i+2].

You are given a vector <int> seq that describes some sequences. Each element in seq is between -1 and 40, inclusive. You can change each occurrence of -1 in seq into an arbitrary integer between 0 and 40, inclusive. Different occurrences can be changed into different integers.

Return the number of different beautiful sequences that can be obtained in this way, modulo 1,000,000,007.


DEFINITION
Class:FoxAverageSequence
Method:theCount
Parameters:vector <int>
Returns:int
Method signature:int theCount(vector <int> seq)


NOTES
-Two sequences of the same length are different if there is at least one position at which their elements are different.


CONSTRAINTS
-seq will contain between 1 and 40 elements, inclusive.
-Each element of seq seq will be between -1 and 40, inclusive.


EXAMPLES

0)
{3, -1}

Returns: 4

{3, 0}, {3, 1}, {3, 2} and {3, 3} are valid sequences.

1)
{5, 3, -1}

Returns: 2

{5, 3, 3} and {5, 3, 4} are valid sequences.

2)
{-1, 0, 40}

Returns: 0

There are no valid sequences.

3)
{-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}

Returns: 579347890



4)
{-1, 12, 25, 0, 18, -1}

Returns: 58



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 579347890; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 12, 25, 0, 18, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  FoxAverageSequence test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
