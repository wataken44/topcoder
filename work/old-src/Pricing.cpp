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

class Pricing {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Market differentiation in its simplest form is a system of charging different
prices to different customers for the same product.  To maximize the total
sales revenue, we would like to charge each customer individually, charging the 
highest price that that customer would be willing to pay.  Usually we have 
to divide the customers into a few groups, and charge the same 
price to everyone in a group (e.g. business class, economy class, etc.).

We have a list of all the potential customers for our product and the most 
that each customer is willing to pay.  We have decided to differentiate them 
into four or fewer (non-overlapping) groups. Everyone within each group
will be offered the same price. Our goal is to choose the groups and prices
optimally to maximize our total sales revenue.

Create a class Pricing that contains a method maxSales that takes a vector <int> 
price containing the highest price that each potential customer is willing 
to pay, and returns the maximum sales revenue we can generate by 
differentiating our customers into four or fewer groups. 



DEFINITION
Class:Pricing
Method:maxSales
Parameters:vector <int>
Returns:int
Method signature:int maxSales(vector <int> price)


CONSTRAINTS
-price must contain between 1 and 50 elements inclusive
-each element of price must be between 0 and 1000 inclusive


EXAMPLES

0)
{9,1,5,5,5,5,4,8,80}

Returns: 120


   Charge 80 to the one customer willing to pay 80.  
   Charge 8 to the 2 customers willing to pay 8 or 9.
   Charge 5 to the 4 customers willing to pay 5.
   Charge 4 to the one customer willing to pay 4.
   Total sales revenue = 1*80 + 2*8 + 4*5 + 1*4.
   (We can put the customer who is willing to pay 1 into any of these groups 
since he will not buy anything at these prices.)


1)
{17,50,2}

Returns: 69

We use just three groups, each containing one customer. We charge each customer the
most she is willing to pay.  Total sales revenue = 1*17 + 1*50 + 1*2

2)
{130,110,90,13,6,5,4,3,0}

Returns: 346

Charge each of the 4 customers willing to pay between 4 
and 13 a price of 4, thereby getting a total of 16 from them.
Then charge the most we can to each of the three customers who are willing to pay a lot. 4*4 + 90 + 110 + 130 = 346 

*/
// END CUT HERE

 public:
  int maxSales(vector <int> price) {
    int result = 0;
    // -- main code --

    sort(price.begin(), price.end());
    int n = price.size();
    FOR(a, 0, n) {
      FOR(b, a, n) {
        FOR(c, b, n) {
          FOR(d, c, n) {
            int sales = price[d] * (n - d)
                + price[c] * (d - c)
                + price[b] * (c - b)
                + price[a] * (b - a);
            result = max(result, sales);
          }
        }
      }
    }
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9,1,5,5,5,5,4,8,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 120; verify_case(0, Arg1, maxSales(Arg0)); }
	void test_case_1() { int Arr0[] = {17,50,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 69; verify_case(1, Arg1, maxSales(Arg0)); }
	void test_case_2() { int Arr0[] = {130,110,90,13,6,5,4,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 346; verify_case(2, Arg1, maxSales(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Pricing test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
