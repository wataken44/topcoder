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

class ThePriceIsRight {
 public:
  vector <int> howManyReveals(vector <int> prices) {
    // -- main code --

    int dpsz = prices.size() + 1;
    vector<int> dp(dpsz, 1);

    FOR(y, 1, dpsz) {
      int yy = y - 1;
      FOR(x, 1, y) {
        int xx = x - 1;
        
        if(prices[yy] > prices[xx]) {
          dp[y] = max(dp[y], dp[x] + 1);
        }
      }
    }

    int lcs = 0;
    TIMES(y, dpsz) {
      //DUMP(dp[y]);
      lcs = max(lcs, dp[y]);
    }
    //DUMP(lcs);
    cout.flush();

    // pivot
    dp.push_back(lcs+1);
    prices.push_back(10000001);
    
    int c = count(prices, dp, dp.size() - 1);
    
    vector<int> r;
    r.push_back(lcs);
    r.push_back(c);
    
    return r;
  }

  int count(vector<int>& prices, vector<int>& dp, int i) {
    if(dp[i] == 1) {
      return 1;
    }
    
    int r = 0;
    FOR(j, 1, i) {
      if(dp[j] == dp[i] - 1 and prices[j-1] < prices[i-1]) {
        r += count(prices, dp, j);
      }
    }
    
    return r;
  }
  
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The Price Is Right is a television game show. In the final round of competition, the contestant is shown the prizes which he can win. To win everything, he must make an educated guess and arrange the prizes in increasing order of price.

Once the contestant has completed ordering prizes, the host begins to reveal the price of each prize in any order that he wishes. To make the show more interesting however, the host reveals prices in such a way that as many prices are revealed as possible before an error in the order is revealed.

Each element in prices represents the price of a prize. The order of prices represents what the contestant thought the order was when arranging prices.

Given a vector <int> of prices as ordered by the contestant, return a vector <int> with two elements. The first element should be the maximum possible number of prices revealed before the order of prices is broken, while the second element should be the total number of ways of achieving that maximum number.

For example, prices = {30, 10, 20, 40, 50}
The host could reveal the following prices: 30 * * 40 50. The next price revealed (either 10 or 20) will cause an error in the ordering to be revealed. In this case, 3 prices were revealed. Alternatively, the host could reveal the following prices: * 10 20 40 50. Once again, the next price revealed will cause an error in the ordering to be revealed. However, in this case, 4 prices were revealed and thus the host would prefer to reveal the prices this way. Note that there is only 1 way of revealing 4 prices. The method should return {4,1}.


DEFINITION
Class:ThePriceIsRight
Method:howManyReveals
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> howManyReveals(vector <int> prices)


NOTES
-The host DOES NOT work out any intermediate deductions. He reveals prices until the sequence order is broken. See examples 5 and 6.


CONSTRAINTS
-prices will have between 1 and 50 elements inclusive.
-prices will not have any repeated elements.
-each element in prices will be between 1 and 1000000 inclusive.


EXAMPLES

0)
{30,10,20,40,50}

Returns: { 4,  1 }

See above.

1)
{39,88,67,5,69,87,82,64,58,61}

Returns: { 4,  2 }

The maximum number of prices that can be revealed is 4, and there are 2 ways of achieving it. The host could either reveal 39 * 67 * 69 87 * * * * or 39 * 67 * 69 * 82 * * *. The method should return {4,2}.

2)
{1,2,3,4,5,6,7,8,9,10}

Returns: { 10,  1 }

3)
{10,9,8,7,6,5,4,3,2,1}

Returns: { 1,  10 }

4)
{29,31,73,70,14,5,6,34,53,30,15,86}

Returns: { 5,  2 }

The host could either reveal 29 31 * * * * * 34 53 * * 86 or * * * * * 5 6 34 53 * * 86. The method should return {5,2}

5)
{100,99,1,2,3}

Returns: { 3,  1 }

In theory, because elements in prices are at least 1 (due to constraints), it is enough to reveal any of 1, 2 or 3 to know that the sequence of prices is broken. However, the host DOES NOT make these intermediate deductions and will reveal * * 1 2 3.


6)
{10,20,11,12}

Returns: { 3,  1 }

In theory, because there can be no price between 10 and 11, it is enough to reveal both 10 and 11 to know that the sequence of prices is broken. However, the host DOES NOT make these intermediate deductions and will reveal 10 * 11 12.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {30,10,20,40,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, howManyReveals(Arg0)); }
	void test_case_1() { int Arr0[] = {39,88,67,5,69,87,82,64,58,61}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, howManyReveals(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 10,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, howManyReveals(Arg0)); }
	void test_case_3() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, howManyReveals(Arg0)); }
	void test_case_4() { int Arr0[] = {29,31,73,70,14,5,6,34,53,30,15,86}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, howManyReveals(Arg0)); }
	void test_case_5() { int Arr0[] = {100,99,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, howManyReveals(Arg0)); }
	void test_case_6() { int Arr0[] = {10,20,11,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, howManyReveals(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ThePriceIsRight test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
