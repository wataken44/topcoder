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

// -- utility --
#define FOR(x, a, b) for(int x = static_cast<int>(a); x < static_cast<int>(b); ++x)
#define FORN(x,n) FOR(x, 0, n)
#define UPTO(x, a, b) for(int x = static_cast<int>(a); x <= static_cast<int>(b); ++x)
#define DOWNTO(x, a, b) for(int x = static_cast<int>(a); x >= static_cast<int>(b) ++x)

using namespace std;

class CircleGame {
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Tommy is learning a simple card game called Circle.  To play the game, the single player shuffles a deck of cards.  He or she then flips through the deck, removing all instances of the 'K' card, and all consecutive pairs of cards that add up to 13.  The deck does wrap around, so that if the last card remaining in the deck and the first card remaining in the deck add up to 13, they are both removed.  The player keeps cycling through the deck until no more cards can be removed.
Create a class CircleGame containing the method cardsLeft that takes a string deck representing a not-necessarily complete nor correct deck of cards.  Each character of deck represents the value of a card without the suit.  The values shown on the card represent the following numerical values:

'A' - 1
'2' - 2
'3' - 3
'4' - 4
'5' - 5
'6' - 6
'7' - 7
'8' - 8
'9' - 9
'T' - 10
'J' - 11
'Q' - 12
'K' - 13

Given deck, return the number of cards remaining after the game has been played to its fullest such that no more cards can be removed.

DEFINITION
Class:CircleGame
Method:cardsLeft
Parameters:string
Returns:int
Method signature:int cardsLeft(string deck)


NOTES
-There are no guarantees made about the contents of the deck.  For example, there can be more than four of a given value of card.
-Note that if a particular card can make a sum of 13 with the card before or after it, it does not matter which is chosen.  For example, 38582, whether you use the first 8 or the second 8, will still become 382 after the two cards (5 and 8) are removed.


CONSTRAINTS
-deck will have between 10 and 50 characters, inclusive.
-each character of deck will be a character from the set {'2'-'9','A','T','J','Q','K'}.


EXAMPLES

0)
"KKKKKKKKKK"

Returns: 0

All K cards are always removed from the deck.

1)
"KKKKKAQT23"

Returns: 1

The K cards are removed, leaving AQT23.  AQ are then removed because they add up to 13, leaving T23.  Since the deck wraps around and T and 3 add up to 13, they are also removed, just leaving the 2.


2)
"KKKKATQ23J"

Returns: 6

Only the K cards can be removed.

3)
"AT68482AK6875QJ5K9573Q"

Returns: 4

The remaining deck is 6875.

4)
"AQK262362TKKAQ6262437892KTTJA332"

Returns: 24

*/
// END CUT HERE

 public:
  int cardsLeft(string deck) {
    int result = 0;
    // -- main code --
    list<int> cards;
    FORN(i, deck.size()) {
      if(deck[i] >= '2' and deck[i] <= '9' ) {
        cards.push_back(deck[i] - '2' + 2);
      }else if(deck[i] == 'T') {
        cards.push_back(10);
      }else if(deck[i] == 'J') {
        cards.push_back(11);
      }else if(deck[i] == 'Q') {
        cards.push_back(12);
      }else if(deck[i] == 'K') {
        cards.push_back(13);
      }else if(deck[i] == 'A') {
        cards.push_back(1);
      }
    }

    while(true) {
      bool removed_any = false;

      for(list<int>::iterator it = cards.begin(); it != cards.end();) {
        if(*it == 13) {
          it = cards.erase(it);
          removed_any = true;
        }else {
          list<int>::iterator next = it;
          ++next;
          if(next == cards.end()) {
            next = cards.begin();
          }
          if(*it + *next == 13) {
            cards.erase(it);
            it = cards.erase(next);
            removed_any = true;
          }else {
            ++it;
          }
        }
      }
      
      if(!removed_any) break;
    }
    result = cards.size();
    return result;	
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "KKKKKKKKKK"; int Arg1 = 0; verify_case(0, Arg1, cardsLeft(Arg0)); }
	void test_case_1() { string Arg0 = "KKKKKAQT23"; int Arg1 = 1; verify_case(1, Arg1, cardsLeft(Arg0)); }
	void test_case_2() { string Arg0 = "KKKKATQ23J"; int Arg1 = 6; verify_case(2, Arg1, cardsLeft(Arg0)); }
	void test_case_3() { string Arg0 = "AT68482AK6875QJ5K9573Q"; int Arg1 = 4; verify_case(3, Arg1, cardsLeft(Arg0)); }
	void test_case_4() { string Arg0 = "AQK262362TKKAQ6262437892KTTJA332"; int Arg1 = 24; verify_case(4, Arg1, cardsLeft(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CircleGame test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE

