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

class StampPads {
 public:
  int bestCombo(vector <string> pads, vector <string> wishlist) {
    // -- main code --

    vector< vector<string> > p(pads.size());

    TIMES(i, pads.size()) {
      istringstream iss(pads[i]);
      string c;
      iss >> c;
      p[i].push_back(c);
    }

    vector< vector<int> > dp(wishlist.size() + 1, vector<int>(p.size(), 0));

    UPTO(j, 1, 1+wishlist.size()) {
      TIMES(i, p.size()) {
        int ji = j - 1;
        string color = wishlist[ji];


      }
    }
    
    return ;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Note to plugin users: there is an image in this problem statement.  Please view the statement in the applet to see the image


There is a collection of multi-colored stamp pads at the local craft store.  Each pad has 5 colors on it, arranged as pie wedges (see picture).  The wedges can be switched out with other wedges, so you can create the ultimate blend of colors for your favorite stamp.  You have a wish list of certain colors, but each pad set is expensive, so you want to minimize the cost.  Given the colors of each pad and the colors you want, return the minimum number of pad sets that you must buy in order to get the right colors.



Here is an example of a stamp pad that you can buy:







You will be given a vector <string> pads, and a vector <string> wishlist.  Each element in pads represents a stamp pad with 5 colors on it.  Each pad will be in the format:



"<color> <color> <color> <color> <color>"



Each <color> will be a string of lower case letters 'a' - 'z', and the colors will be separated by single spaces.  For example, the above stamp pad would be represented by the string:



"yellow red purple blue cyan"



Each element of wishlist is a color that you wish to own.  Your method should return the minimum number of pads you must buy to get all the colors in wishlist, or -1 if it is not possible to do.


DEFINITION
Class:StampPads
Method:bestCombo
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int bestCombo(vector <string> pads, vector <string> wishlist)


CONSTRAINTS
-pads will have between 1 and 20 elements, inclusive.
-Each element in pads will have between 9 and 50 characters, inclusive.
-Each element in pads will consist of exactly 5 color names separated by single spaces.
-Each color name in pads will have between 1 and 15 characters, inclusive, and will consist of only lowercase letters 'a'-'z', inclusive.
-There will be no repeated color names in a single element of pads
-wishlist will have between 1 and 25 elements, inclusive.
-Each element of wishlist will have between 1 and 15 characters, inclusive, and will consist of only lowercase letters 'a'-'z', inclusive.
-There will be no repeated elements in wishlist.


EXAMPLES

0)
{"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}
{"orange", "yellow", "red", "blue", "magenta", "tan"}

Returns: 3


We can only get blue from the first pad, magenta from the second pad, and tan from the last.  Therefore, all three must be purchased.


1)
{"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}
{"orange", "yellow", "red", "blue", "tan"}

Returns: 2


Although we can get orange and yellow from the second pad, we can get orange, yellow, and tan from the last, so the second is unnecessary.


2)
{"yellow black blue green red",
 "yellow brown cyan magenta tan",
 "black grey fire maroon silver",
 "blue white neon tangerine rust",
 "green orange soot turquoise mint",
 "red cream opal chrome sky"}
{"yellow", "black", "blue", "green", "red",
 "brown", "grey", "white", "orange", "cream"}

Returns: 5


Although you can buy the first pad and get 5 colors on the wishlist, you still must buy the other 5 to get the rest of the colors.  However, if you just buy the last 5 pads, you get all the colors.


3)
{"red green orange magenta yellow"}
{"silver"}

Returns: -1


The single stamp pad available does not have silver, so the wishlist is impossible to fulfill.


4)
{"a i y d o", "t s k g e", "j u w i k", "u k l s j", "q s a c y",
 "q m d x a", "m s l h r", "s x q l n", "u r j s k", "e w v d p",
 "o l a b q", "f z g a m", "o g k b a", "c h g k t", "z v s n x",
 "z n b w c", "h p o u k", "t z o x m", "a w i v z", "u t v m y"}
{"x", "b", "u", "c", "h", "j", "t", "v", "d", "g",
 "k", "w", "y", "z", "a", "i", "m", "l", "n", "e"}

Returns: 6

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"orange", "yellow", "red", "blue", "magenta", "tan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"orange", "yellow", "red", "blue", "tan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"yellow black blue green red",
 "yellow brown cyan magenta tan",
 "black grey fire maroon silver",
 "blue white neon tangerine rust",
 "green orange soot turquoise mint",
 "red cream opal chrome sky"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"yellow", "black", "blue", "green", "red",
 "brown", "grey", "white", "orange", "cream"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"red green orange magenta yellow"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"silver"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a i y d o", "t s k g e", "j u w i k", "u k l s j", "q s a c y",
 "q m d x a", "m s l h r", "s x q l n", "u r j s k", "e w v d p",
 "o l a b q", "f z g a m", "o g k b a", "c h g k t", "z v s n x",
 "z n b w c", "h p o u k", "t z o x m", "a w i v z", "u t v m y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"x", "b", "u", "c", "h", "j", "t", "v", "d", "g",
 "k", "w", "y", "z", "a", "i", "m", "l", "n", "e"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(4, Arg2, bestCombo(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  StampPads test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
