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

class CoinMachinesGame {
 public:
  int maxGames(int coins, vector <int> need, vector <int> give) {
    // -- main code --

    int sz = need.size();
    
    TIMES(i, sz) {
      FOR(j, i + 1, sz) {
        if(need[i] - give[i] > need[j] - give[j]) {
          swap(need[i], need[j]);
          swap(give[i], give[j]);
        }
      }
    }

    /*
    TIMES(i, sz) {
      DUMP(need[i]);
      DUMP(give[i]);
    }
    */
    

    int game = 0;

    TIMES(i, sz) {
      if(coins < need[i]) continue;

      int p = (coins - need[i]) / (need[i] - give[i]);

      game += p;
      coins -= p * (need[i] - give[i]);

      while(coins >= need[i]) {
        game += 1;
        coins -= need[i] - give[i];
      }

    }
    
    return game;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In an arcade palace, there are several machines with games that you like to play. It costs some number of coins to play a single game on each machine. However, these machines have a peculiarity: after each game, they give back some of the coins that you inserted. You wonder how many games in total you can play with the coins you have. It is possible to play the  game on the same machine many times.

You will be given an int coins, the number of coins you start with. You will also be given the description of the machines in two vector <int>s, need and give. Element i of need is the number of coins you need to put in machine i for the game to start, and element i of give is the number of coins machine i gives back after the game ends.

Return the maximum possible number of games that you can play.


DEFINITION
Class:CoinMachinesGame
Method:maxGames
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int maxGames(int coins, vector <int> need, vector <int> give)


CONSTRAINTS
-coins will be between 1 and 1000000000 (10^9), inclusive.
-need will contain between 1 and 50 elements, inclusive.
-need and give will contain the same number of elements.
-Each element of need and give will be between 1 and 1000, inclusive.
-Element i of give will be strictly less than element i of need.


EXAMPLES

0)
10
{5,3}
{4,1}

Returns: 7

You can play 5 times on the first machine and 2 times on the second machine, in that order. There are other ways to get 7 games in total.

1)
1000
{16,14,11,7}
{15,12,8,3}

Returns: 988



2)
1000000000
{1000,900,800,700,600,500,400,300,200,100}
{701,802,503,604,405,306,107,208,1,1}

Returns: 10869564



3)
12345678
{342,234,65,76,85,734,67,345,70,234}
{45,78,3,10,45,12,45,57,1,230}

Returns: 3086370



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, maxGames(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1000; int Arr1[] = {16,14,11,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,12,8,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 988; verify_case(1, Arg3, maxGames(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000000; int Arr1[] = {1000,900,800,700,600,500,400,300,200,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {701,802,503,604,405,306,107,208,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10869564; verify_case(2, Arg3, maxGames(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12345678; int Arr1[] = {342,234,65,76,85,734,67,345,70,234}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {45,78,3,10,45,12,45,57,1,230}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3086370; verify_case(3, Arg3, maxGames(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CoinMachinesGame test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
