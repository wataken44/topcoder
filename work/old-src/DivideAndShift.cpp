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

class DivideAndShift {

 public:
  map<int, vector<int> > div;
  
  int getLeast(int N, int M)
  {
    int result = go(N, M);

    // -- main code --

    div.clear();
    
    return result;
  }

  int go(int N, int M) {
    
    if(M == 1 or N == 1) {
      return 0;
    }else if(M == N) {
      return 1;
    }

    //DUMP(N); DUMP(M);

    if(div.find(N) == div.end()) { 
      int d = 2;
      int n = N;

      div[N] = vector<int>();
      
      while(n >= d) {
        if(n % d == 0) {
          if(div[N].size() == 0 or div[N].back() != d) {
            div[N].push_back(d);
            //DUMP(d);
          }
          n = n / d;
        }else {
          ++d;
        }
      }
    }
    
    int count = INT_MAX;

    // divide
    TIMES(i, div[N].size()) {
      int nn = N / div[N][i];
      //DUMP(N);DUMP(nn);
      //DUMP(div[N][i]);
      if(nn != 1) {
        int mm = (M % nn + i) % nn;
        if(mm != 0) {
          count = min(count, 1 + go(nn, mm));
          count = min(count, 2 + go(nn, mm+1));
          if(mm!=1) {
            count = min(count, 2 + go(nn, mm-1));
          }else {
            count = min(count, 2 + go(nn, nn));
          }
        }else {
          count = min(count, 1 + go(nn, nn));
        }
      }else {
        count = 1;
      }
    }

    // shift right
    // count = min(count, 1 + abs(N - M));
    //
    //count = min(count, M - 1);

    return count;
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Manao is playing a game called "Divide and Shift". There is a sequence of N slots in the game numbered from 1 to N. Initially each of them contains an object. Manao's goal is to obtain the object which is initially in slot M. At any time of the game, he can only obtain an object that is in slot 1 at that time. 

Manao can perform two types of moves. The first is choosing a prime number p which divides N and dividing the sequence of the slots in p contiguous subsequences, namely the slots from 1 to N/p, the slots from N/p+1 to 2N/p, etc. Then, Manao keeps the subsequence which contains the desired object and gets rid of the remaining slots. The length of the chosen subsequence is then assigned to N and the slots in it are renumbered from 1 to the new value of N.

The second type of move is shifting the objects in the slots. Manao can perform a left shift and a right shift. After a left shift, for each i &gt 1 the object in slot i is moved to slot i-1 and the object in slot 1 is moved to the last slot of the sequence. After a right shift, each object is moved to the slot to the right and the object in the last slot is moved to slot 1.

Determine the least number of moves in which Manao can reach the goal. Taking the object from slot 1 is not considered a move.

DEFINITION
Class:DivideAndShift
Method:getLeast
Parameters:int, int
Returns:int
Method signature:int getLeast(int N, int M)


NOTES
-A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-A prime number p divides N if the ratio N/p is an integer.


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.
-M will be between 1 and N, inclusive.


EXAMPLES

0)
56
14

Returns: 3

One possible way to obtain the object in slot 14 is to perform the following operations:
1. Divide by 2. N becomes equal to 28 now.
2. Shift right. The object moves to slot 15.
3.?Divide?by?2?again.?The?sequence?15..28?is?kept,?renumbered?as?1..14?and?the?object?appears?in?slot?1.


1)
49
5

Returns: 2

Manao divides by 7 twice and gets a single slot.

2)
256
7

Returns: 6

Shift?left?until?the?object?is?in?slot?1.

3)
6
1

Returns: 0

The object may be in slot 1 right in the beginning.

4)
77777
11111

Returns: 2



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 56; int Arg1 = 14; int Arg2 = 3; verify_case(0, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 49; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 256; int Arg1 = 7; int Arg2 = 6; verify_case(2, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 77777; int Arg1 = 11111; int Arg2 = 2; verify_case(4, Arg2, getLeast(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DivideAndShift test;

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

// END CUT HERE
