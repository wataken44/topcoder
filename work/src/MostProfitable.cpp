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

class MostProfitable {
 public:
  string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items) {
    // -- main code --
    int max_profit = 0;
    int max_profit_id = -1;
    
    TIMES(i, costs.size()) {
      int profit = (prices[i] - costs[i]) * sales[i];
      if(profit > max_profit) {
        max_profit = profit;
        max_profit_id = i;
      }
    }
    return max_profit_id == -1 ? "" : items[max_profit_id];
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// When selling goods, it is important to know exactly how much it costs to acquire each item.  A number of distributed costs, such as marketing often make this difficult, but not impossible.  If a business can figure out how much an item costs, with some accuracy, then it can easily calculate the profit margins for the item.  This information, combined with sales figures, can be used to determine which items are the most important to a business.  In this problem you will be given the costs, prices, and number of sales for a number of items.  Each element of costs represents the total costs accrued from selling a single item.  The corresponding elements (ones with the same index) of prices and sales represent the prices at which single items are sold, and the number of sales of each item that have occurred in some time period, respectively.  You are to return the name of the item (the corresponding element of items) that provides the business with the most profits.  If there is a tie for the most profitable item, return the one that comes earliest in items (lowest index).  If no item provides the business with positive profits you should return the empty string.



DEFINITION
Class:MostProfitable
Method:bestItem
Parameters:vector <int>, vector <int>, vector <int>, vector <string>
Returns:string
Method signature:string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items)


CONSTRAINTS
-costs, prices, sales, and items will all contain the same number of elements.
-costs, prices, sales, and items will contain between 1 and 50 elements, inclusive.
-Each element of costs and prices will be between 1 and 1,000,000, inclusive.
-Each element of sales will be between 0 and 1,000, inclusive.
-Each element of items will have between 1 and 50 characters, inclusive.
-Each character of each element of items will have ASCII value between 32 and 126, inclusive.  (All of the characters that can be easily made with a regular keyboard.)


EXAMPLES

0)
{100,120,150,1000}
{110,110,200,2000}
{20,100,50,3}
{"Video Card","256M Mem","CPU/Mobo combo","Complete machine"}

Returns: "Complete machine"

This business makes 200 on video cards, loses 1000 on memory, makes 2500 on CPU/Mobo combos, and makes 3000 on complete machines.  Since 3000 is the highest, you should return "Complete machine".

1)
{100}
{100}
{134}
{"Service, at cost"}

Returns: ""

The only product given is sold at cost, so there are no items which give positive profit.

2)
{38,24}
{37,23}
{1000,643}
{"Letter","Postcard"}

Returns: ""

3)
{10,10}
{11,12}
{2,1}
{"A","B"}

Returns: "A"

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,120,150,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {110,110,200,2000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,100,50,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"Video Card","256M Mem","CPU/Mobo combo","Complete machine"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Complete machine"; verify_case(0, Arg4, bestItem(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {134}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"Service, at cost"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = ""; verify_case(1, Arg4, bestItem(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {38,24}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {37,23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000,643}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"Letter","Postcard"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = ""; verify_case(2, Arg4, bestItem(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"A","B"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "A"; verify_case(3, Arg4, bestItem(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  MostProfitable test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
