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

class Painting {

 public:
  int largestBrush(vector <string> pic)
  {
    // -- main code --
    
    vector<string> picture;

    picture.push_back(string(pic[0].size()+2, 'W'));
    
    TIMES(y, pic.size()) {
      picture.push_back("W" + pic[y] + "W");
    }

    picture.push_back(string(pic[0].size()+2, 'W'));

    DUMP(pic);
    
    int xsz = picture[0].size();
    int ysz = picture.size();
    
    int result = min(xsz, ysz);

    TIMES(y, ysz) {
      DUMP(picture[y]);
      TIMES(x, xsz) {
        if(picture[y][x] == 'W') {
          if(y != ysz - 1 && picture[y+1][x] != 'W') {
            result = min(result, ysz - y - 1);
            for(int i = 1; i + y < ysz; ++i) {
              if(picture[y+i][x]=='W') {
                result = min(result, i-1);
                break;
              }
            }
          }
          if(x != xsz - 1 && picture[y][x+1] != 'W') {
            result = min(result, xsz - x - 1);
            for(int i = 1; i + x < xsz; ++i) {
              if(picture[y][x+i]=='W') {
                result = min(result, i-1);
                break;
              }
            }
          }
        }
      }
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Normally Mr. Grey is not a painter, but he recently had an absolutely brilliant idea for a picture. He thinks that once drawn, it will bring him world-wide fame.

The picture will be painted on an NxM sheet of white paper consisting of 1x1 squares. Its rows are numbered from 0 to N-1 and the columns are numbered from 0 to M-1. The cell in row i, column j is denoted as (i, j).

Of course, Mr. Grey already has a picture plan in his mind. It is given in a vector <string> picture, which contains exactly N elements, where each element contains exactly M characters. „Rharacter j in element i of picture will be 'B' if the cell (i, j) must be painted black, and it will be 'W' if this cell must be left white.

Mr. Grey has a lot of black paint, but unfortunately he doesn't have a brush, so he went to a local shop to buy one. The shop offers square brushes of different sizes. More exactly, for each positive integer S, one can buy an SxS brush in the shop. Using an SxS brush, Mr. Grey will be able to paint entirely black SxS squares on the sheet of paper. In other words, he can choose row R and column C such that 0 <= R <= N - S, 0 <= C <= M - S, and then paint all cells (r, c) such that R <= r < R + S and C <= c < C + S in black paint. He can repeat this operation infinitely many times. If a cell must be black according to picture, it may be painted black several times. However, if a cell must be white, then it must never be painted black.

It's easy to see that every picture can be drawn using a 1x1 brush, but it will be impossible to draw some pictures using larger brushes. Buying a 1x1 brush seems to be the most practical choice. However, Mr. Grey is sure that big masters must use big brushes. Therefore, he would like to buy the largest possible brush that will still allow him to draw the picture that he has in mind.

Return the maximum value of S such that it's possible to draw picture using a brush of size SxS.

DEFINITION
Class:Painting
Method:largestBrush
Parameters:vector <string>
Returns:int
Method signature:int largestBrush(vector <string> picture)


CONSTRAINTS
-picture will contain between 1 and 50 elements, inclusive.
-Each element of picture will contain between 1 and 50 characters, inclusive.
-All elements of picture will contain the same number of characters.
-Each character in picture will be 'B' or 'W'.
-There will be at least one 'B' character in picture.


EXAMPLES

0)
{"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"}

Returns: 4

It's easy to see that a solid 4x4 black square can be drawn using a 4x4 brush.

1)
{"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"}

Returns: 1

This time we have only a border of a 4x4 square and it's necessary to have a 1x1 brush in order to draw it.

2)
{"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}


Returns: 3

A completely black 4x6 rectangle can be drawn using a 4x4 brush. However, if we want just one cell within it to remain white, the size of the brush will have to be reduced. In this example, a 3x3 brush would work.

3)
{"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}


Returns: 2

This is very similar to the previous example, but the white cell is in a different location. Mr. Grey will have to buy a 2x2 brush in this case.

4)
{"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}


Returns: 5



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, largestBrush(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, largestBrush(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, largestBrush(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, largestBrush(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, largestBrush(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Painting test;

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
