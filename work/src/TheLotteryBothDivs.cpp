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

class TheLotteryBothDivs {
 public:
  double find(vector <string> goodSuffixes) {
    // -- main code --

    unsigned long long counts = 0;

    vector<string> suffixes;

    TIMES(i, goodSuffixes.size() - 1) {
      FOR(j, i + 1, goodSuffixes.size()) {
        if(goodSuffixes[i].size() > goodSuffixes[j].size()) {
          swap(goodSuffixes[i], goodSuffixes[j]);
        }
      }
    }

    TIMES(i, goodSuffixes.size()) {
      bool add = true;
      TIMES(j, suffixes.size()) {
        if(suffixes[j] == goodSuffixes[i].substr(goodSuffixes[i].size() - suffixes[j].size(),suffixes[j].size())) {
          add = false;
        }
      }
      if(add) suffixes.push_back(goodSuffixes[i]);
      
    }
    
    TIMES(i, suffixes.size()) {
      counts += p(10, 9 - suffixes[i].size());
    }
    
    return (double)counts / 1000000000.0;	
  }

  long long p(int b, int n) {
    long long r = 1;
    TIMES(i, n) {
      r *= b;
    }
    return r;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Farmer John wants to buy a lottery ticket. Before he buys a ticket, Fox Brus decided to calculate the probability that John will get a prize.


There are 1,000,000,000 types of lottery tickets. They are numbered "000000000" to "999999999" (they may have leading zeroes). Each type of ticket has an equal probability of being bought by John. You are given a vector <string> goodSuffixes. If the number written on John's ticket has at least one element of goodSuffixes as a suffix, he will get a prize.


Return the probability that John will get a prize.

DEFINITION
Class:TheLotteryBothDivs
Method:find
Parameters:vector <string>
Returns:double
Method signature:double find(vector <string> goodSuffixes)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.
-A suffix of a string is obtained by removing zero or more contiguous characters from the beginning of the string.


CONSTRAINTS
-goodSuffixes will contain between 1 and 50 elements, inclusive.
-Each element of goodSuffixes will contain between 1 and 9 characters, inclusive.
-Each character in goodSuffixes will be a digit ('0'-'9').


EXAMPLES

0)
{"4"}

Returns: 0.1

John will get a prize if the last digit is '4'. It happens with probability 0.1.

1)
{"4", "7"}

Returns: 0.2



2)
{"47", "47"}

Returns: 0.01

goodSuffixes may contain duplicate elements.

3)
{"47", "58", "4747", "502"}

Returns: 0.021



4)
{"8542861", "1954", "6", "523", "000000000", "5426", "8"}

Returns: 0.201100101



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"4", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"47", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"47", "58", "4747", "502"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.021; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.201100101; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  TheLotteryBothDivs test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
