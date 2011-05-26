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
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class PalindromeGame {
 public:
  int getMaximum(vector <string> front, vector <int> back) {
    // -- main code --

    map<string, vector<int> > card;

    int sz = front.size();
    TIMES(i, sz) {
      if(card.find(front[i]) != card.end()) {
        card[front[i]].push_back(back[i]);
      }else {
        card[front[i]] = vector<int>(1, back[i]);
      }
    }

    for(map<string,vector<int> >::iterator iter = card.begin();
          iter != card.end(); ++iter) {
      string f = iter->first;
      sort(card[f].begin(), card[f].end());
    }
    
    int score = 0;

    vector<int> self_palindrome;
    
    for(map<string, vector<int> >::iterator iter = card.begin();
        iter != card.end(); ++iter) {
      string f = iter->first;
      string r = iter->first;
      reverse(r.begin(), r.end());

      if(r == f) {
        while(card[f].size() > 1) {
          score += card[f].back();
          card[f].pop_back();
          score += card[f].back();
          card[f].pop_back();
        } 
        if(card[f].size() == 1) {
          self_palindrome.push_back(card[f].back());
          card[f].pop_back();
        }
        continue ;
      }

      while(card[f].size() > 0) {
        if(card.find(r) == card.end() or card[r].size() == 0) break;

        score += card[f].back() + card[r].back();
        card[f].pop_back();
        card[r].pop_back();
      }
    }

    sort(self_palindrome.begin(), self_palindrome.end());
    if(self_palindrome.size() > 0) {
      score += self_palindrome.back();
    }
    
    return score;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are playing a simple one-player game in which you are given a set of cards. 
Each card has a string written on the front and a number on the back. 
The strings on all the cards have the same length. 
You must choose some of these cards (at least one, possibly all) 
and place them in a row with the front sides visible, 
such that the concatenated string is a palindrome. 
A palindrome is a string that reads the same forward and backward. 
Your score is the sum of the numbers on the back sides of the chosen cards. 


You are given a vector <string> front and a vector <int> back 
describing the set of cards you are given. 
The i-th card has front[i] written on the front and back[i] on the back. 
Return the maximum possible score you can achieve with these cards. 
If it is impossible to compose a palindrome from the given cards, return 0 instead.


DEFINITION
Class:PalindromeGame
Method:getMaximum
Parameters:vector <string>, vector <int>
Returns:int
Method signature:int getMaximum(vector <string> front, vector <int> back)


CONSTRAINTS
-front will contain between 1 and 50 elements, inclusive. 
-Each element of front will contain between 1 and 50 characters, inclusive. 
-Each element of front will contain the same number of characters. 
-Each character in front will be a lowercase letter ('a' - 'z'). 
-front and back will contain the same number of elements. 
-Each element of back will be between 1 and 1,000,000, inclusive. 


EXAMPLES

0)
{ "topcoder", "redcoder", "redocpot" }
{ 7, 5, 3 }

Returns: 10

You?can?choose?"topcoder"?with?7?and?"redocpot"?with?3?to?get?a?palindrome?"topcoderredocpot". 


1)
{ "rabbit" }
{ 1000000 }

Returns: 0

No palindrome can be made. 


2)
{ "abc", "abc", "def", "cba", "fed" }
{ 24, 7, 63, 222, 190 }

Returns: 499

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "topcoder", "redcoder", "redocpot" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 7, 5, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "rabbit" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "abc", "abc", "def", "cba", "fed" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 24, 7, 63, 222, 190 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 499; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  PalindromeGame test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
