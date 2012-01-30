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

class BombSweeper {
 public:
  double winPercentage(vector <string> board) {
    // -- main code --

    int bomb_count = 0;
    int safe_count = 0;

    TIMES(y, board.size()) {
      TIMES(x, board[y].size()) {
        if(isSafe(board, x, y)) {
          ++safe_count;
        }
        if(board[y][x] == 'B') {
          ++bomb_count;
        }
      }
    }
    
    return (double)safe_count*100.0/(double)(bomb_count+safe_count);
  }

  bool isSafe(const vector<string>& board, int x, int y)
  {
    UPTO(dy, -1, 1) {
      UPTO(dx, -1, 1) {
        int yi = y + dy;
        if(yi < 0) yi = 0;
        if(yi > (int)board.size() - 1) yi = board.size() - 1;

        int xi = x + dx;
        if(xi < 0) xi = 0;
        if(xi > (int)board[yi].size() - 1) xi = board[yi].size() - 1;

        if(board[yi][xi] == 'B') {
          return false;
        }
      }
    }
    
    return true;
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The game of BombSweeper is a single-player game played on a rectangular grid.  Each square in the grid is either a bomb (represented by 'B') or empty space (represented by '.').  The true identity of each square is hidden when the game begins.  The object of the game is to correctly determine both the number of bombs on the board and their positions.

You are trying to write a program which predicts the percent likelihood that you will win a given game of BombSweeper.  You've recently become so good at the game that your success or failure depends only on your first few moves.  To start, you pick a random square on the gameboard and uncover it.  If the square you uncover is a bomb, you lose the game.  If the square is not a bomb, but one or more of its horizontal, vertical, and diagonal neighbors is, you are no better off than when you started and you must take another turn.  If the square is not a bomb, and none of its (up to) eight neighbors are bombs either, then you win the game.

Given a vector <string> board, representing the game board, return a number between 0.0 and 100.0, inclusive, representing the percent likelihood of you winning the game.

DEFINITION
Class:BombSweeper
Method:winPercentage
Parameters:vector <string>
Returns:double
Method signature:double winPercentage(vector <string> board)


NOTES
-In calculating the probability, let wins be the number of non-bomb squares which have no bomb neighbors, and let losses be the number of bombs on the board.  The odds of winning are then (wins / (wins + losses)), which returns a number between 0.0 and 1.0, inclusive.
-As long as you calculate wins and losses correctly, you need not worry about minor double imprecisions.
-Your solution need only be accurate to 1e-9 (relative or absolute).  Thus, if your result is within 1e-9 (relative or absolute) of the result shown, your result will be judged correct.


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character in board will be either '.' or 'B'.


EXAMPLES

0)
{".....",
 ".....",
 "..B..",
 ".....",
 "....."}

Returns: 94.11764705882354

If you uncover the bomb in the center of the gameboard, you lose.  If you uncover one of the eight squares surrounding the bomb, you would need to take another turn.  If you uncover one of the 16 squares on the perimeter of the gameboard, you would win, since none of these squares has a neighboring square which is a bomb.  Since there are 16 ways to win and only 1 way to die, your odds of winning are 16/17, or about 94.1%.

1)
{"BBBBB",
 "B...B",
 "B...B",
 "B...B",
 "BBBBB"}

Returns: 5.882352941176471

As far as your odds of winning are concerned, this board is the opposite of the previous one.  The only way to win is to uncover the square in the exact center of the gameboard, while any of the 16 bombs on the perimeter will cause you to lose.  1/17 is about 0.0588, or about 5.88%.

2)
{".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 "........."}

Returns: 0.0

Every square on this board is either a bomb, or has a bomb as a neighbor.  Therefore, there is no way to win.

3)
{".........................",
 ".........................",
 ".........................",
 "........................."}

Returns: 100.0

Now there are no bombs, so any square you uncover will cause you to win.

4)
{"......B.......B..B...........................B....",
 "..............B..................BB..B............",
 "B.B.B.............B.....B..............B..........",
 "...................B...B....................BB....",
 "...B.....B.........................B.......B.....B",
 "B.B.........B.....B.......B..B......B.B...B.BB....",
 "..B...................BB...............B..........",
 ".........B...B................B..B................",
 ".......BB.......B....B................B.....BBB...",
 ".......BB..........B..............B......BB.......",
 "...................BB.....................B.......",
 "...B.B.B......B..............B...B......B.........",
 "B................B................................",
 "....B..........B.....B..BB....B...............BB..",
 "..B....B.....B.............B.....B............B...",
 "...................B.B........B..B.........B.B....",
 ".....B.....B......................................",
 "...........BB......BB...B.B........B...B..........",
 ".....BBB..........................................",
 ".B...........B....B...BB......B......B...B.B......",
 "..................B........BB................B....",
 "...............................B..B....BBB.B....B.",
 "..........B.......................................",
 ".....B..........B....BB......B.B......B......B....",
 ".....B..................B........B................",
 "............B.....B..B....BB...B....BB........B...",
 "..B.................B.........B...................",
 ".BB..............B................................",
 "...B....B..................B.................B....",
 "......B...B......B......................B.B.......",
 "..............B..................B.......B........",
 ".....B........BB...B.....B........................",
 ".......B......B.B..B..........B...........B....B..",
 "B...B...........B...B...B......B.B...B..B......B..",
 "....B..B.....B.B.......BB..B............B.B....B..",
 "B.......B..........B.........B...B.BB......B......",
 "....B...............................B.............",
 ".....B.B..........................................",
 "..........B............B......B.B..B....B.........",
 "....B...B.......................B.................",
 "B.................B...........B..B....B...........",
 "...B.....B........................................",
 "...B..B......................................BBB..",
 ".B...B....................................B....B..",
 "...B...B..........B...B.B.........................",
 ".....B.............B...BB..........B..BBB.BB......",
 "....................B.....B.......................",
 "........B..BB..........B.B....B...........B......B",
 ".........B.....BB..B.............B....BB..........",
 "....B..B..............B...B..B..........B........."}

Returns: 77.67558528428094

This board has 267 bombs, 1304 empty spaces with bomb neighbors, and 929 empty spaces without bomb neighbors.  (929 / (929 + 267)) is about 0.7768.

*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 ".....",
 "..B..",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 94.11764705882354; verify_case(0, Arg1, winPercentage(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBBB",
 "B...B",
 "B...B",
 "B...B",
 "BBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.882352941176471; verify_case(1, Arg1, winPercentage(Arg0)); }
	void test_case_2() { string Arr0[] = {".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, winPercentage(Arg0)); }
	void test_case_3() { string Arr0[] = {".........................",
 ".........................",
 ".........................",
 "........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 100.0; verify_case(3, Arg1, winPercentage(Arg0)); }
	void test_case_4() { string Arr0[] = {"......B.......B..B...........................B....",
 "..............B..................BB..B............",
 "B.B.B.............B.....B..............B..........",
 "...................B...B....................BB....",
 "...B.....B.........................B.......B.....B",
 "B.B.........B.....B.......B..B......B.B...B.BB....",
 "..B...................BB...............B..........",
 ".........B...B................B..B................",
 ".......BB.......B....B................B.....BBB...",
 ".......BB..........B..............B......BB.......",
 "...................BB.....................B.......",
 "...B.B.B......B..............B...B......B.........",
 "B................B................................",
 "....B..........B.....B..BB....B...............BB..",
 "..B....B.....B.............B.....B............B...",
 "...................B.B........B..B.........B.B....",
 ".....B.....B......................................",
 "...........BB......BB...B.B........B...B..........",
 ".....BBB..........................................",
 ".B...........B....B...BB......B......B...B.B......",
 "..................B........BB................B....",
 "...............................B..B....BBB.B....B.",
 "..........B.......................................",
 ".....B..........B....BB......B.B......B......B....",
 ".....B..................B........B................",
 "............B.....B..B....BB...B....BB........B...",
 "..B.................B.........B...................",
 ".BB..............B................................",
 "...B....B..................B.................B....",
 "......B...B......B......................B.B.......",
 "..............B..................B.......B........",
 ".....B........BB...B.....B........................",
 ".......B......B.B..B..........B...........B....B..",
 "B...B...........B...B...B......B.B...B..B......B..",
 "....B..B.....B.B.......BB..B............B.B....B..",
 "B.......B..........B.........B...B.BB......B......",
 "....B...............................B.............",
 ".....B.B..........................................",
 "..........B............B......B.B..B....B.........",
 "....B...B.......................B.................",
 "B.................B...........B..B....B...........",
 "...B.....B........................................",
 "...B..B......................................BBB..",
 ".B...B....................................B....B..",
 "...B...B..........B...B.B.........................",
 ".....B.............B...BB..........B..BBB.BB......",
 "....................B.....B.......................",
 "........B..BB..........B.B....B...........B......B",
 ".........B.....BB..B.............B....BB..........",
 "....B..B..............B...B..B..........B........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 77.67558528428094; verify_case(4, Arg1, winPercentage(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  BombSweeper test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
