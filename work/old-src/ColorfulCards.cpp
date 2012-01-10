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

class ColorfulCards {

 public:
    
  
  vector <int> theCards(int N, string colors)
  {
    vector<int> sieve;
    vector<int> p;
    vector<int> np;
    vector<int> result;

    // -- main code --
    result = vecotr<int>(colors.size(), -2);
    
    sieve = vector<int>(N+1, 1);
    sieve[0] = 0; sieve[1] = 0;

    p.clear();
    np.clear();

    for(int i = 2; (i - 1) * (i - 1) <= N; ++i) {
      if(sieve[i] == 1) {
        for(int j = 1; i ** j <= N; ++j) {
          sieve[i] = 0;
        }
      }
    }

    TIMES(i, N+1) {
      if(sieve[i] == 1) {
        p.push_back(i);
      }else {
        np.push_back(i);
      }
    }

    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Rabbit Hanako has N cards numbered 1 through N. Each card's number is written on its front side. The back side of each card is colored red if the number is prime, and blue if it is not prime.


Cat Taro has chosen a subset of these cards and arranged them face down in a row. The cards are sorted in increasing order from left to right. He wants Hanako to guess the numbers written on the cards. Hanako can only see the colored back side of each card. You are given a string colors, where the i-th character is 'R' if the i-th card from the left is red, and 'B' if it is blue.


Return a vector <int> containing exactly K elements, where K is the number of characters in colors. The i-th element of the return must be the number written on the i-th card if it can be uniquely determined. Otherwise, the i-th element must be -1. It is guaranteed that there exists at least one sequence that matches colors.


DEFINITION
Class:ColorfulCards
Method:theCards
Parameters:int, string
Returns:vector <int>
Method signature:vector <int> theCards(int N, string colors)


NOTES
-A positive integer number is called prime if it has exactly two divisors, 1 and itself. By convention, 1 is not considered to be a prime number.


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-colors will contain between 1 and 50 characters, inclusive.
-Each character in colors will be 'R' or 'B'.
-There will exist at least one sequence that matches colors.


EXAMPLES

0)
5
"RRR"

Returns: {2, 3, 5 }

The numbers written on these cards are primes less than or equal to 5, so the only possibility is {2, 3, 5}.


1)
7
"BBB"

Returns: {1, 4, 6 }

The numbers written on these cards are not primes less than or equal to 7, so the only possibility is {1, 4, 6}.


2)
6
"RBR"

Returns: {-1, 4, 5 }

There are two possibilities:
{2, 4, 5}
{3, 4, 5}


3)
58
"RBRRBRBBRBRRBBRRBBBRRBBBRR"

Returns: {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 }



4)
495
"RBRRBRBBRBRRBBRRBBBRRBBBRR"

Returns: {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arg1 = "RRR"; int Arr2[] = {2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, theCards(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; string Arg1 = "BBB"; int Arr2[] = {1, 4, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, theCards(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arg1 = "RBR"; int Arr2[] = {-1, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, theCards(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, theCards(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 495; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, theCards(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ColorfulCards test;

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
