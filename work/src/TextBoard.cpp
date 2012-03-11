#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
#define EACH(c, i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(cont, it, cond, ret) \
  bool ret = true; EACH(cont, it) { if(!(cond)) {ret=false;break;} }
#define ANY(cont, it, cond, ret) \
  bool ret = false; EACH(cont, it) { if(cond) {ret=true;break;} }

using namespace std;
// debug
// BEGIN CUT HERE
#define DUMP(x) std::cerr << #x << " = " << to_s(x) << std::endl;
template<typename T> string to_s(const T& v);
template<> string to_s(const string& v);
template<> string to_s(const bool& v);
template<typename T> string to_s(const vector<T>& v);
template<typename T> string to_s(const list<T>& v);
template<typename T> string to_s(const set<T>& v);
template<typename F, typename S> string to_s(const pair<F,S>& v);
template<typename K, typename V> string to_s(const map<K,V>& v);
// END CUT HERE
#ifndef DUMP
#define DUMP(x) 
#endif

class TextBoard {

 public:
  vector <string> draw(vector <string> pieces)
  {
    vector <string> result(8, "........");
    // -- main code --

    TIMES(y, 8) {
      TIMES(x, 8) {
        if( (x + y) % 2 == 0 ) result[y][x] = '#';
      }
    }

    // DUMP(result);

    TIMES(k, pieces.size()) {
      string& p = pieces[k];
      istringstream iss(p);
      string color, pos;

      iss >> color >> pos;

      int x = pos[0] - 'A';
      int y = pos[1] - '1';

      result[y][x] = (color == "WHITE" ? 'W' : 'B');
      
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are working on a text-based checkers program, and you need to write a module to display the state of the board to the user.  The board has 8 rows labeled 1 to 8 from top to bottom, and 8 columns labeled A to H from left to right.  The cells alternate colors black and white, and no two horizontally or vertically adjacent cells can have the same color.  Cell A1 is black.  Each piece on the board is either black or white, depending on the player who owns it.  You want to draw the board by printing 8 rows of 8 characters where each character is one of the following:

'.' - an empty white cell.
'#' - an empty black cell.
'W' - a cell with a white piece on it.
'B' - a cell with a black piece on it.

For example, the initial state of the board would be printed like:

B.B.B.B.
.B.B.B.B
B.B.B.B.
.#.#.#.#
#.#.#.#.
.W.W.W.W
W.W.W.W.
.W.W.W.W

You are given a vector <string> pieces where each element describes the color and position of one piece on the board. Each element is formatted "<COLOR> <C><R>", where <COLOR> is either "WHITE" or "BLACK", <C> is the column ('A'-'H'), and <R> is the row ('1'-'8') (all quotes for clarity). Return a vector <string> containing exactly 8 elements, where the first element is the text representation of row 1, the second element is row 2, and so on.

DEFINITION
Class:TextBoard
Method:draw
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> draw(vector <string> pieces)


NOTES
-Even though in a regular checkers game pieces are never placed on the white cells, your playing program may contain bugs so you want to print the pieces that landed up on the white cells too.
-Similarly you might get more than the usual 12 each of white or black pieces.


CONSTRAINTS
-pieces will contain between 0 and 50 elements, inclusive.
-Each element of pieces will be formatted as described in the problem statement.
-No two pieces will be on the same cell.


EXAMPLES

0)
{"WHITE B2", "BLACK A3"}

Returns: {"#.#.#.#.", ".W.#.#.#", "B.#.#.#.", ".#.#.#.#", "#.#.#.#.", ".#.#.#.#", "#.#.#.#.", ".#.#.#.#" }

A board with two pieces on it, a white one on B2 and a black one on A3.

1)
{"BLACK A1", "BLACK C1", "BLACK E1", "BLACK G1", "BLACK B2", "BLACK D2",
 "BLACK F2", "BLACK H2", "BLACK A3", "BLACK C3", "BLACK E3", "BLACK G3",
 "WHITE B6", "WHITE D6", "WHITE F6", "WHITE H6", "WHITE A7", "WHITE C7",
 "WHITE E7", "WHITE G7", "WHITE B8", "WHITE D8", "WHITE F8", "WHITE H8"}

Returns: {"B.B.B.B.", ".B.B.B.B", "B.B.B.B.", ".#.#.#.#", "#.#.#.#.", ".W.W.W.W", "W.W.W.W.", ".W.W.W.W" }

The example from the problem statement.

2)
{"BLACK A1", "BLACK A2", "BLACK A3", "BLACK A4", "BLACK A5", "BLACK A6",
 "BLACK A7", "BLACK A8", "BLACK B1", "WHITE B2", "WHITE B3", "WHITE B4",
 "WHITE B5", "WHITE B6", "WHITE B7", "BLACK B8", "BLACK C1", "WHITE C2",
 "WHITE C7", "BLACK C8", "BLACK D1", "WHITE D2", "WHITE D7", "BLACK D8",
 "BLACK E1", "WHITE E2", "WHITE E7", "BLACK E8", "BLACK F1", "WHITE F2",
 "WHITE F7", "BLACK F8", "BLACK G1", "WHITE G2", "WHITE G3", "WHITE G4",
 "WHITE G5", "WHITE G6", "WHITE G7", "BLACK G8", "BLACK H1", "BLACK H2",
 "BLACK H3", "BLACK H4", "BLACK H5", "BLACK H6", "BLACK H7", "BLACK H8"}

Returns: {"BBBBBBBB", "BWWWWWWB", "BW#.#.WB", "BW.#.#WB", "BW#.#.WB", "BW.#.#WB", "BWWWWWWB", "BBBBBBBB" }

Not really a valid situation.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"WHITE B2", "BLACK A3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"#.#.#.#.", ".W.#.#.#", "B.#.#.#.", ".#.#.#.#", "#.#.#.#.", ".#.#.#.#", "#.#.#.#.", ".#.#.#.#" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, draw(Arg0)); }
	void test_case_1() { string Arr0[] = {"BLACK A1", "BLACK C1", "BLACK E1", "BLACK G1", "BLACK B2", "BLACK D2",
 "BLACK F2", "BLACK H2", "BLACK A3", "BLACK C3", "BLACK E3", "BLACK G3",
 "WHITE B6", "WHITE D6", "WHITE F6", "WHITE H6", "WHITE A7", "WHITE C7",
 "WHITE E7", "WHITE G7", "WHITE B8", "WHITE D8", "WHITE F8", "WHITE H8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B.B.B.B.", ".B.B.B.B", "B.B.B.B.", ".#.#.#.#", "#.#.#.#.", ".W.W.W.W", "W.W.W.W.", ".W.W.W.W" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, draw(Arg0)); }
	void test_case_2() { string Arr0[] = {"BLACK A1", "BLACK A2", "BLACK A3", "BLACK A4", "BLACK A5", "BLACK A6",
 "BLACK A7", "BLACK A8", "BLACK B1", "WHITE B2", "WHITE B3", "WHITE B4",
 "WHITE B5", "WHITE B6", "WHITE B7", "BLACK B8", "BLACK C1", "WHITE C2",
 "WHITE C7", "BLACK C8", "BLACK D1", "WHITE D2", "WHITE D7", "BLACK D8",
 "BLACK E1", "WHITE E2", "WHITE E7", "BLACK E8", "BLACK F1", "WHITE F2",
 "WHITE F7", "BLACK F8", "BLACK G1", "WHITE G2", "WHITE G3", "WHITE G4",
 "WHITE G5", "WHITE G6", "WHITE G7", "BLACK G8", "BLACK H1", "BLACK H2",
 "BLACK H3", "BLACK H4", "BLACK H5", "BLACK H6", "BLACK H7", "BLACK H8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BBBBBBBB", "BWWWWWWB", "BW#.#.WB", "BW.#.#WB", "BW#.#.WB", "BW.#.#WB", "BWWWWWWB", "BBBBBBBB" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, draw(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TextBoard test;

  if(argc == 1) {
    test.run_test(-1);
  }else {
    std::string arg(argv[1]);
    if(arg[0] != '-') {
      test.run_test(arg[0] - '0');
    }else {
      test.debug();
    }
  }
  
  return 0;
}

template<typename T> string to_s(const T& v) { ostringstream oss; oss << v; return oss.str(); }
template<> string to_s(const string& v) { ostringstream oss; oss << '"' << v << '"'; return oss.str(); }
template<> string to_s(const bool& v) { ostringstream oss; oss << ( v ? "true" : "false") ; return oss.str(); } 
template<typename T> string to_s(const vector<T>& v) { ostringstream oss; oss << "["; EACH(v,i) oss << to_s(*i) << ","; oss << "]"; return oss.str(); }
template<typename T> string to_s(const list<T>& v) { ostringstream oss; oss << "("; EACH(v,i) oss << to_s(*i) << ","; oss << ")"; return oss.str(); }
template<typename T> string to_s(const set<T>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(*i) << ","; oss << "}"; return oss.str(); }
template<typename F, typename S> string to_s(const pair<F,S>& v) { ostringstream oss; oss << "<" << to_s(v.first) << " " << to_s(v.second) << ">"; return oss.str(); }
template<typename K, typename V> string to_s(const map<K,V>& v) { ostringstream oss; oss << "{"; EACH(v,i) oss << to_s(i->first) << " => " << to_s(i->second) << ","; oss << "}"; return oss.str(); }

// END CUT HERE
