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

class FoxProgression {
 public:
  int theCount(vector <int> seq) {
    // -- main code --

    if((int)seq.size() == 1) return -1;
    int c = 0;
    int a = seq[1] - seq[0];
    bool arith = true;

    TIMES(i, seq.size() - 1) {
      if(seq[i+1] - seq[i] != a) {
        arith = false;
      }
    }

    int aa = -100000;
    if(arith) {
      aa = seq[seq.size() - 1] + a;
      ++c;
    }

    if(seq[0] < seq[1]) {
      int r = seq[1] / seq[0];
      bool geo = true;
      TIMES(i, seq.size() - 1) {
        if(seq[i+1]/seq[i] != r or seq[i+1]%seq[i] != 0) {
          geo = false;
        }
      }

      //int gg = -200000;
      if(geo) {
        if(aa != seq[seq.size()-1] * r) ++c;
        
      }
    }
    
    return c;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel likes sequences of integers. She especially likes sequences that are either an arithmetic progression of integers or a geometric progression of integers with an integer common ratio. She calls these beautiful sequences. An arithmetic progression is a sequence of numbers such that the difference of any two consecutive numbers of the sequence is a constant. A geometric progression is a sequence of numbers where each number after the first is found by multiplying the previous one by a constant non-zero number which is called the common ratio.

Ciel has a sequence of integers. She says that an integer is good if she can obtain a beautiful sequence by appending the integer to the end of the sequence. You are given a vector <int> seq. Calculate the number of good integers for the given sequence. If there are infinitely many good integers, return -1.

DEFINITION
Class:FoxProgression
Method:theCount
Parameters:vector <int>
Returns:int
Method signature:int theCount(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 500, inclusive.


EXAMPLES

0)
{1, 2, 4, 8}

Returns: 1

This sequence can become a geometric progression with ratio 2 if you append 16.

1)
{5, 3, 1}

Returns: 1

This sequence can become an arithmetic progression with difference -2 if you append -1. Note that neither the difference/ratio nor the appended integer has to be strictly positive.

2)
{1, 1}

Returns: 1

If you append 1, this sequence becomes a geometric progression (with ratio 1) and an arithmetic progression (with ratio 0) simultaneously. Despite the two reasons to call the resulted sequence "beautiful", there is still only one good integer.

3)
{8, 4}

Returns: 1

This sequence can become an arithmetic progression if you append 0. It can also become a geometric progression with ratio 0.5 if you append 2, but progressions with non-integer ratio are not beautiful.

4)
{1}

Returns: -1

Every integer is good for the given sequence.

5)
{4, 8}

Returns: 2

There are two good integers: appending 12 turns this sequence into an arithmetic progression with difference 4, and appending 16 turns it into a geometric progression with ratio 2.

6)
{1, 3, 4}

Returns: 0

This sequence is already neither an arithmetic nor a geometric progression, so nothing that you append can fix it.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, theCount(Arg0)); }
	void test_case_5() { int Arr0[] = {4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, theCount(Arg0)); }
	void test_case_6() { int Arr0[] = {1, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  FoxProgression test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
