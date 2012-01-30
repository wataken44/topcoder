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

class BinaryCards {

 public:
  long long largestNumber(long long A, long long B)
  {
    long long result = A;
    // -- main code --

    typedef unsigned long long ULL;

    int k = 0;
    DOWNTO(i, 63, 0) {
      if((A >> i) < (B >> i)) {
        k = i;
        break;
      }
    }
 
    if(k == 0) {
      return B;
    }

    UPTO(i, 1, k + 1) {
      ULL mask0 = ((ULL)1 << i) - 1;
      ULL mask1 = (ULL)1 << (i - 1);
      ULL mask2 = ((ULL)1 << (i - 1)) - 1;

      ULL C = (A | mask1) & (~mask2);
      ULL D = A | mask0;
      if( C <= static_cast<ULL>(B) ) {
        result = max(result, static_cast<long long>(D));
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
// Karel is a robot. He has a set of 64 cards: for each x between 0 and 63, he has a card that is blank on one side and has 2^x dots on the other side.

Karel's cards are placed on a table. At any moment, the cards show some integer between 0 and (2^64)-1, inclusive. To read the number, you just count all the dots you see.

Karel is using the cards to count from A to B. That is, he is flipping some of the cards in such a way that the numbers A, A+1, ..., B appear in this order.

Of course, Karel is using the shortest possible sequence of flips. Additionally, he always flips the cards one at a time. Sometimes, changing the number from some Z to Z+1 requires Karel to flip more than one card. In that case, he flips the necessary cards ordered by the number of dots they have, starting with the one with the most dots.

For example, if A=6 and B=8, the following will happen:


In the beginning, the card with 4 dots and the card with 2 dots are showing the dots, all other cards are blank side up. This shows the number 6.
Karel flips the card with 1 dot. Now the number 7 is shown.
Karel flips the card with 8 dots.
Karel flips the card with 4 dots.
Karel flips the card with 2 dots.
Karel flips the card with 1 dot. Now the number 8 is shown and Karel is done.



Given are long longs A and B. Your method must return the largest number that will be shown at any moment during Karel's counting.


DEFINITION
Class:BinaryCards
Method:largestNumber
Parameters:long long, long long
Returns:long long
Method signature:long long largestNumber(long long A, long long B)


CONSTRAINTS
-A will be between 1 and 10^18, inclusive.
-B will be between A and 10^18, inclusive.


EXAMPLES

0)
6
6

Returns: 6



1)
6
7

Returns: 7



2)
6
8

Returns: 15

This is the example from the problem statement. When flipping cards to create the number 8 from the number 7, Karel starts by flipping the card with 8 dots. At this moment, the number shown on the cards is 15.

3)
1
11

Returns: 15



4)
35
38

Returns: 39



5)
1125899906842630
1125899906842632

Returns: 1125899906842639



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 6LL; long long Arg1 = 6LL; long long Arg2 = 6LL; verify_case(0, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 7LL; long long Arg2 = 7LL; verify_case(1, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 6LL; long long Arg1 = 8LL; long long Arg2 = 15LL; verify_case(2, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 11LL; long long Arg2 = 15LL; verify_case(3, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 35LL; long long Arg1 = 38LL; long long Arg2 = 39LL; verify_case(4, Arg2, largestNumber(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 1125899906842630LL; long long Arg1 = 1125899906842632LL; long long Arg2 = 1125899906842639LL; verify_case(5, Arg2, largestNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BinaryCards test;

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
