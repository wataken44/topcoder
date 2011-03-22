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

class CardCount {
 public:
  vector <string> dealHands(int numPlayers, string deck) {
    // -- main code --

    vector<string> r(numPlayers, "");

    TIMES(i, deck.size() / numPlayers) {
      TIMES(p, numPlayers) {
        r[p] += deck[i * numPlayers + p];
      }
    }
    
    return r;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are dealing cards to a group of players.  In this game, the cards are numbered 0-9 and have no distinguishing 
characteristics other than their numbers.  A given deck may have many cards that share the same number.  You are given an  
int numPlayers that represents the number of people playing.  You are also given a string 
deck which contains the cards to be used (0th character is the top of the deck, and the last character is the bottom). 
 You will deal the cards starting with player 0, then player 1, until you reach player numPlayers-1, dealing one card 
at a time.  Then you repeat this process until the cards are exhausted.  Cards are always dealt from the top of the deck.  

You will return a vector <string> that shows each of the players' cards in the order they were dealt (cards dealt 
earlier show up earlier in the particular string).  Player k's hand corresponds to element k of 
the returned vector <string>.  One added constraint is that each player must be dealt the same number of cards.  To  enforce this 
constraint you will not deal extra cards that will unbalance the players' hands (cards held).  In other words, if you have 
dealt to the last player, and don't have enough cards to deal another to every player, stop dealing.  The returned vector <string> must contain exactly numPlayers elements, each element containing exactly the same number of characters.

DEFINITION
Class:CardCount
Method:dealHands
Parameters:int, string
Returns:vector <string>
Method signature:vector <string> dealHands(int numPlayers, string deck)


CONSTRAINTS
-numPlayers will be between 1 and 50 inclusive
-deck will contain between 0 and 50 characters inclusive, all of which are numeric (0-9)


EXAMPLES

0)
6
"012345012345012345"

Returns: { "000",  "111",  "222",  "333",  "444",  "555" }

Exactly enough to deal 3 to each player.

1)
4
"111122223333"

Returns: { "123",  "123",  "123",  "123" }

2)
1
"012345012345012345"

Returns: { "012345012345012345" }

Only a single player.

3)
6
"01234"

Returns: { "",  "",  "",  "",  "",  "" }

Not enough cards to deal 1 to each player.

4)
2
""

Returns: { "",  "" }

No cards.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; string Arg1 = "012345012345012345"; string Arr2[] = { "000",  "111",  "222",  "333",  "444",  "555" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, dealHands(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; string Arg1 = "111122223333"; string Arr2[] = { "123",  "123",  "123",  "123" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, dealHands(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; string Arg1 = "012345012345012345"; string Arr2[] = { "012345012345012345" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, dealHands(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; string Arg1 = "01234"; string Arr2[] = { "",  "",  "",  "",  "",  "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, dealHands(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; string Arg1 = ""; string Arr2[] = { "",  "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, dealHands(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CardCount test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
