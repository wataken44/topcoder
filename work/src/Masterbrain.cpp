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
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

// -- utility --
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define FORN(x,n) FOR(x, 0, n)

using namespace std;

class Masterbrain {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Masterbrain is a two player board game in which one player decides on a secret combination of digits, while the other must figure it out in 10 guesses or less. The game differs from Mastermind in that the player making the secret combination is allowed to lie once.
The game consists of one player making a sequence of guesses about what the secret combination is, and the other player giving him or her certain information about the quality of the guess.  The following is how each guess is analyzed: if a digit is in the correct position then a black peg is given. If a digit is in the guess but in the wrong position then a white peg is given. For all other cases no pegs are given.
For example, if guess = "1234", secret = "2335". Analyzing the guess digit by digit; the '1' is not in secret - no pegs given. The '2' is in secret but not in the right place - white peg given. The '3' is in secret and in the right place - black peg given. The '4' is not in secret - no pegs given. Result should be "1b 1w", meaning one black peg and one white peg. Now, if guess is "2334" and secret is "3224", we have the following: '2' is in secret, but not in the right place - white peg given. The first '3' is in secret, but not in the right place - white peg given. Since the '3' in secret has been used, the second '3' in guess should return no pegs. The '4' is in secret and in the right place - black peg given. Result should be "1b 2w".
Given a vector <string> of guesses and a vector <string> of results for those guesses, return the total number of possible secret combinations, assuming that exactly one of the results is incorrect. Each element of results will be formatted as "<x>b <y>w", where <x> and <y> are the number of black and white pegs respectively.

DEFINITION
Class:Masterbrain
Method:possibleSecrets
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int possibleSecrets(vector <string> guesses, vector <string> results)


NOTES
-The second player must lie exactly once.
-Black pegs always take precedence over white pegs.  Thus, when analyzing a guess, black pegs are assigned first, and then white pegs are assigned.
-No digit in either a guess or a secret combination may be involved in giving more than one peg.


CONSTRAINTS
-guesses and results will have the same number of elements.
-guesses will have between 1 and 10 elements inclusive.
-results will have between 1 and 10 elements inclusive.
-each element in guesses will contain exactly 4 characters and will only contain digits between '1' and '7' inclusive.
-each element in results will contain exactly 5 characters.
-each element of results will be formatted as follows: "<x>b <y>w", where <x> represents the number of black pegs and <y> represents the number of white pegs in a guess. <x> and <y> are non-negative integers whose sum is less than or equal to 4.
-results will never have "3b 1w", because that is impossible.


EXAMPLES

0)
{"1575"} 
{"4b 0w"}

Returns: 2400

If the result was true, we would conclude that 1575 is the only possible combination. However, we know that the second player must lie exactly once, thus we know that 1575 is the only combination NOT possible. Since there are 7^4 = 2401 total combinations, the method should return 2401-1 = 2400.

1)
{"1234"}
{"0b 4w"}

Returns: 2392

If the result was true then the set of secret combinations would have 9 elements: {2143, 2341, 2413, 3142, 3412, 3421, 4123, 4312, 4321}. But since the result is false, we must subtract this number from the total. The method should return 2401-9 = 2392.

2)
{"6172","6162","3617"}
{"3b 0w","2b 1w","0b 3w"}

Returns: 14

If all results were true, then the secret must be 6176. If the first result is false then the set of secret combinations is {1362, 1762, 2163, 6123, 6136, 6176, 6361, 6761, 7166}. If the second result is false then set is {6132, 6171, 6174, 6175, 6176, 6372}. Finally, if the third result is false then the set is {6176, 6672}. Thus the method should return (9-1)+(6-1)+(2-1) = 14.

3)
{"1513","5654","4564","1377","1671","1342"}
{"1b 0w","0b 1w","1b 0w","1b 0w","0b 1w","0b 1w"}

Returns: 6

4)
{"2611", "1371", "7417", "2647", "3735", "4272", "2442", "3443", "1252", "3353"}
{"0b 2w","0b 2w","0b 1w","0b 2w","1b 0w","1b 0w","1b 0w","0b 1w","1b 1w","0b 1w"}

Returns: 1

*/
// END CUT HERE

 public:
  int possibleSecrets(vector <string> guesses, vector <string> results) {
    int result;
    // -- main code --
    
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1575"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4b 0w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2400; verify_case(0, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0b 4w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2392; verify_case(1, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"6172","6162","3617"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3b 0w","2b 1w","0b 3w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(2, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1513","5654","4564","1377","1671","1342"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1b 0w","0b 1w","1b 0w","1b 0w","0b 1w","0b 1w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"2611", "1371", "7417", "2647", "3735", "4272", "2442", "3443", "1252", "3353"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0b 2w","0b 2w","0b 1w","0b 2w","1b 0w","1b 0w","1b 0w","0b 1w","1b 1w","0b 1w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, possibleSecrets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Masterbrain test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

