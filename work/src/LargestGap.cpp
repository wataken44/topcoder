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

class LargestGap {

 public:
  struct Info {
    int x;
    int l;
    int r;
    Info(int x_, int l_, int r_) : x(x_), l(l_), r(r_) {};
  };

  int getLargest(vector <string> board)
  {
    string b;

    TIMES(i, board.size()) {
      b += board[i];
    }

    int len  = b.size();
    
    string bb = b;

    
    vector<Info> cand;

    TIMES(i, bb.size()) {
      if(bb[i] == 'X') {
        
        bb[i] = 'v';

        int r = i;
        while(bb[(r + 1) % len] == 'X') {
          r = (r + 1) % len;
          bb[r] = 'v';
        }

        int l = i;
        while(bb[(l - 1 + len) % len] == 'X') {
          l = (l - 1 + len) % len;
          bb[l] = 'v';
        }

        cand.push_back(Info(i, l, r));
      }
    }

    TIMES(k, cand.size()) {
      //DUMP(cand[k].x);DUMP(cand[k].l);DUMP(cand[k].r);
    }
    
    int mx = cand[0].x;
    int mg = -1;
    int sg = -2;
    
    int csz = cand.size();
    TIMES(k, csz) {
      Info& li = cand[k];
      Info& mi = cand[(k + 1) % csz];
      Info& ri = cand[(k + 2) % csz];

      DUMP(ri.l);DUMP(li.r);DUMP(mi.r);DUMP(mi.l);
                                                            
      int g = ((ri.l - li.r - 1) - (mi.r - mi.l + 1) + len * 2) % len;
      // DUMP(g);

      int s = -2;
      TIMES(y, csz) {
        if(y == k || y == (k + 1) %csz) continue;
        s = max(s, cand[(y + 1) % csz].l - cand[y].r - 1);
      }

      DUMP(g);DUMP(s);
      
      if(g > mg) {
        mx = mi.x;
        mg = g;
        sg = s;
      }else if(g == mg && s > sg) {
        mx = mi.x;
        mg = g;
        sg = s;
      }
    }
    // -- main code --
    
    return mx;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Given a vector <string> board, concatenate all its elements, in order, to get a single string representing a circular board consisting of uppercase 'X' and '.' characters. "Circular" means that the first and the last characters on the board are consecutive. Maximal consecutive groups of 'X' characters form blocks and maximal consecutive groups of '.' characters form gaps. The size of the gap is the number of '.' characters in it. 

You want to remove exactly one block from the board, getting a circular board of smaller size. For each possible block to be removed consider the board after its removal, construct an array of all gaps' sizes on the board and sort this array in non-ascending order. Choose the block for which the described array is lexicographically maximal (see notes for the description of lexicographical array comparison). Return the smallest 0-based index among all characters in this block (indices are taken in the concatenated string). In case of a tie choose the block which results in the smallest return value.

DEFINITION
Class:LargestGap
Method:getLargest
Parameters:vector <string>
Returns:int
Method signature:int getLargest(vector <string> board)


NOTES
-Let vector <int>s A and B contain the same number of elements. Then A is lexicographically larger than B if A contains a larger value at the first position where A and B differ.


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-board will contain only uppercase 'X' and '.' characters.
-board will contain at least two blocks.


EXAMPLES

0)
{".....X.X......."}

Returns: 5

Remove the first block.

1)
{"XXXX","....","XXXX","....","XXXX","...."}

Returns: 0

There are three blocks whose smallest indices are 0, 8, 16, respectively.
The board after removing each of the blocks look as follows:

The 1st block: "....XXXX....XXXX....".
The 2nd block: "XXXX........XXXX....".
The 3rd block: "XXXX....XXXX........".

All three results produce the same gaps array {8,4}. So we return the smallest index among {0,8,16}.

2)
{"XXX.........XX...........XX..X"}

Returns: 12

There are three gaps and three blocks (recall that the board is circular).

3)
{"XXX","X.....","....XX..XXXXXX","X........X..",".XXX."}

Returns: 32

There are 5 blocks and 5 gaps. There are two ways to maximize the largest gap, but only one of them also maxmizes the second largest one.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....X.X......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getLargest(Arg0)); }
	void test_case_1() { string Arr0[] = {"XXXX","....","XXXX","....","XXXX","...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getLargest(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXX.........XX...........XX..X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, getLargest(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXX","X.....","....XX..XXXXXX","X........X..",".XXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, getLargest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  LargestGap test;

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
