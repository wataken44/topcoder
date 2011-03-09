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

class ProfitCalculator {
 public:
  int percent(vector <string> items) {
    // -- main code --
    double c = 0.0;
    double p = 0.0;
    double tc = 0.0;
    double tp = 0.0;

    TIMES(i, items.size()) {
      istringstream iss(items[i]);
      iss >> p;
      iss >> c;
      //cout << p << " " << c << endl;
      tc += c;
      tp += p;
    }
    //cout << tp << " " << tc << endl;
    //cout.flush();
          
    return floor(100.0*(tp - tc)/tp) ;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Margin is defined as the percentage of the selling price of an item or group of items which is profit.  For example, if an item costs $80 and is sold for $100, then there is $20 profit, or 20% margin.

You will be given a vector <string>, items, which is all of the items sold in a single transaction.  Each string in items will be formatted as follows: "nnn.nn nnn.nn" (quotes for clarity), where each n is a digit between '0' and '9' inclusive.  Each string will be exactly 13 characters in length.  The first number listed is the price the customer paid for the item.  The second number is what the cost to the store of the item was.

You will create a class ProfitCalculator with a method percent which will calculate the percentage of margin on the transaction and return it as an int, rounded down to the greatest integer less than the actual value.

For example, let's say you were given the following vector <string>:
   { "012.99 008.73",
     "099.99 050.00",
     "123.45 101.07" }

The total cost is $159.80.  The total price is $236.43.  That means $76.63 was made on this sale.  This would be a 32.41128% margin.  Since we are rounding down, you would return 32.

DEFINITION
Class:ProfitCalculator
Method:percent
Parameters:vector <string>
Returns:int
Method signature:int percent(vector <string> items)


NOTES
-The cost for some items may be greater than the price they was sold for.  However, the sum of the prices of all the items in the transaction will be greater than the sum of the costs of all items.


CONSTRAINTS
-items will contain between 1 and 50 elements, inclusive.
-Every string in items will be exactly 13 characters in length.
-Every string in items will be formatted as "nnn.nn nnn.nn" where each n is a digit between '0' and '9' inclusive, thus the range for each price will be between "000.00" and "999.99" inclusive (all quotes for clarity).
-The total price of all items will be greater than the total cost of all items.
-The total price of all items will be greater than 0.
-The percent of margin, prior to rounding, will not be within 1e-5 of an integer.


EXAMPLES

0)
{"012.99 008.73","099.99 050.00","123.45 101.07"}

Returns: 32

This is the example from above.

1)
{"000.00 049.99","999.99 936.22","033.99 025.64","249.99 211.87"}

Returns: 4

The total price is $1283.97.  The total cost is $1223.72.  The margin prior to rounding is 4.6924772%.

2)
{"822.77 704.86","829.42 355.45","887.18 949.38"}

Returns: 20

The margin prior to rounding is 20.8587169%.

3)
{"612.72 941.34","576.46 182.66","787.41 524.70","637.96 333.23","345.01 219.69",
 "567.22 104.77","673.02 885.77"}

Returns: 23

The margin prior to rounding is 23.9925711%.

4)
{"811.22 275.32","433.89 006.48","141.28 967.41","344.47 786.23","897.47 860.61",
 "007.42 559.29","255.72 460.00","419.35 931.19","419.25 490.52","199.78 114.44",
 "505.63 276.58","720.96 735.00","719.90 824.46","816.58 195.94","498.68 453.05",
 "399.48 921.39","930.88 017.63","422.20 075.39","380.22 917.27","630.83 995.87",
 "821.07 126.87","715.73 985.62","246.23 134.64","168.28 550.33","707.28 046.72",
 "117.76 281.87","595.43 410.45","345.28 532.42","554.24 264.34","195.73 814.87",
 "131.98 041.28","595.13 939.47","576.04 107.70","716.00 404.75","524.24 029.96",
 "673.49 070.97","288.09 849.43","616.34 236.34","401.96 316.33","371.18 014.27",
 "809.63 508.33","375.68 290.84","334.66 477.89","689.54 526.35","084.77 316.51",
 "304.76 015.91","460.63 636.56","357.84 436.20","752.24 047.64","922.10 573.12"}

Returns: 10

The margin prior to rounding is 10.4737522%.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"012.99 008.73","099.99 050.00","123.45 101.07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, percent(Arg0)); }
	void test_case_1() { string Arr0[] = {"000.00 049.99","999.99 936.22","033.99 025.64","249.99 211.87"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, percent(Arg0)); }
	void test_case_2() { string Arr0[] = {"822.77 704.86","829.42 355.45","887.18 949.38"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, percent(Arg0)); }
	void test_case_3() { string Arr0[] = {"612.72 941.34","576.46 182.66","787.41 524.70","637.96 333.23","345.01 219.69",
 "567.22 104.77","673.02 885.77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(3, Arg1, percent(Arg0)); }
	void test_case_4() { string Arr0[] = {"811.22 275.32","433.89 006.48","141.28 967.41","344.47 786.23","897.47 860.61",
 "007.42 559.29","255.72 460.00","419.35 931.19","419.25 490.52","199.78 114.44",
 "505.63 276.58","720.96 735.00","719.90 824.46","816.58 195.94","498.68 453.05",
 "399.48 921.39","930.88 017.63","422.20 075.39","380.22 917.27","630.83 995.87",
 "821.07 126.87","715.73 985.62","246.23 134.64","168.28 550.33","707.28 046.72",
 "117.76 281.87","595.43 410.45","345.28 532.42","554.24 264.34","195.73 814.87",
 "131.98 041.28","595.13 939.47","576.04 107.70","716.00 404.75","524.24 029.96",
 "673.49 070.97","288.09 849.43","616.34 236.34","401.96 316.33","371.18 014.27",
 "809.63 508.33","375.68 290.84","334.66 477.89","689.54 526.35","084.77 316.51",
 "304.76 015.91","460.63 636.56","357.84 436.20","752.24 047.64","922.10 573.12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, percent(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  ProfitCalculator test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
