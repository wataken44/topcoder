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

class TheJackpotDivOne {
 public:
  void dump(vector<long long>& m) {
    TIMES(i, m.size()) {
      cerr << m[i] << " ";
    }
    cerr << endl;
  }
  
  vector<long long> find(vector<long long> money, long long jackpot) {
    // -- main code --

    typedef long long ll;

    sort(money.begin(), money.end());
    int sz = money.size();
    
    while(jackpot > 0) {

      unsigned long long sum = 0;
      bool same = true;
      
      TIMES(i, sz) {
        sum += money[i];
        if(money[i] != money[0]) same = false;
      }

      ll a = sum / sz + 1;
      
      if(a - money[0] >= jackpot) {
        money[0] += jackpot;
        jackpot = 0;
        break;
      }

      if(same) {
        if(jackpot > sz) {
          ll div = jackpot / sz;
          TIMES(i, sz) {
            money[i] += div;
          }
          jackpot -= div * sz;
        }else {
          TIMES(i, jackpot) {
            money[i] += 1;
          }
          jackpot = 0;
        }
      }else {
        ll x = a - money[0];
        money[0] += x;
        jackpot -= x;
      }

      // sort
      TIMES(i, sz-1) {
        if(money[i] > money[i+1]) {
          swap(money[i], money[i+1]);
        }else {
          break;
        }
      }
    }

    sort(money.begin(), money.end());
    
    return money;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John has recently won a jackpot, but he doesn't need the money.
He decided to share it with his friends instead.
He knows how much money each of his friends has, and he will use this information to perform the distribution.
While he still has money left, he will repeat the following steps:

Calculate the average amount of money each of his friends has.  Call this value A.
Choose the poorest friend.  If there are multiple poorest friends, choose one of them randomly.  P is the amount of money owned by the chosen friend.
Determine the value of X, where X is the smallest integer such that P + X is strictly greater than A.
If John has at least X dollars, give X dollars to the chosen friend.  Otherwise, give all the remaining money to that friend.




You are given a long long jackpot, the number of dollars John has won, and a vector<long long> money, where the i-th element is the number of dollars currently owned by the i-th friend.
Return a vector<long long> containing the same number of elements as money.
The return value must contain the number of dollars owned by each friend after John has performed the above distribution, sorted in non-decreasing order.



DEFINITION
Class:TheJackpotDivOne
Method:find
Parameters:vector<long long>, long long
Returns:vector<long long>
Method signature:vector<long long> find(vector<long long> money, long long jackpot)


CONSTRAINTS
-money will contain between 1 and 47 elements, inclusive.
-Each element of money will be between 1 and 10^18, inclusive.
-jackpot will be between 1 and 10^18, inclusive.


EXAMPLES

0)
{1, 2, 3, 4}
2

Returns: {2, 3, 3, 4 }

The average is 2.5. John will give all his money to the first friend with a single action.

1)
{4}
7

Returns: {11 }

There is just one friend here.

2)
{4, 44, 7, 77}
47

Returns: {24, 34, 44, 77 }

Iniitially, the average is 33, so John will give 30 dollars to the first friend, who will then have 34 dollars total.  The average then becomes 40.5, and John will give the rest of the money to the third friend.

3)
{4, 10, 8, 3, 6, 5, 8, 3, 7, 5}
1000

Returns: {105, 106, 106, 106, 106, 106, 106, 106, 106, 106 }

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long Arr0[] = {1, 2, 3, 4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; long Arr2[] = {2, 3, 3, 4 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; long Arr2[] = {11 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {4, 44, 7, 77}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; long Arr2[] = {24, 34, 44, 77 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {4, 10, 8, 3, 6, 5, 8, 3, 7, 5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000LL; long Arr2[] = {105, 106, 106, 106, 106, 106, 106, 106, 106, 106 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  TheJackpotDivOne test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
