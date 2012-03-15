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

class FoldThePaper {

 public:
  int getValue(vector <string> paper)
  {
    int xsz = paper[0].size();
    int ysz = paper.size();
    
    vector< vector<int> > num(ysz, vector<int>(xsz, 0));

    int cut = INT_MIN;
    TIMES(y, ysz) {
      istringstream iss(paper[y]);
      TIMES(x, xsz) {
        iss >> num[y][x];
        cut = max(num[y][x], cut);
      }
    }
    
    int result = go(num, cut);
    // -- main code --
    
    return result;	
  }

  int go(vector< vector<int> >& num, int cut)
  {
    int ysz = num.size();
    int xsz = num[0].size();

    int ret = cut;
    FOR(fy, 1, ysz - 1) {
      int nysz = max(fy, ysz - fy);
      vector< vector<int> > nn(nysz, xsz);
      TIMES(y, nysz) {
        TIMES(x, xsz) {
          nn[y][x] = num[y + fy][x];
        }
      }
    }
  }
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You have a rectangular piece of paper that's divided into 1x1 cells, each of which has an integer value.  The paper will be described by a vector <string> paper.  The ith element of paper will be a space delimited list of integers, where the jth integer of the ith element of paper represents the value of the jth cell of the ith row of the paper.

 You want to perform a sequence of folds on the paper, where you may fold anywhere along an axis that is in between two rows or columns of the paper.  After performing a fold, we wish to model the folded paper as a new, flat piece of paper.  We will do this by considering two overlapping cells as a single cell, with a value that is the sum of the individual cells.

You wish to perform a sequence of folds such that the value of some single cell in the resulting piece of paper is as large as possible.  Return this value.

DEFINITION
Class:FoldThePaper
Method:getValue
Parameters:vector <string>
Returns:int
Method signature:int getValue(vector <string> paper)


CONSTRAINTS
-paper will contain between 1 and 12 elements, inclusive.
-Each element of paper will be a single-space delimited list of integers with no leading or trailing spaces.
-Each element of paper will contain between 1 and 12 integers, inclusive.
-Each element of paper will contain the same number of integers.
-Each element of paper will contain between 1 and 50 characters, inclusive.
-Each integer in paper will be between -100 and 100, inclusive.
-Each integer in paper will have no leading zeros.
-An integer in paper equal to zero will not have a preceding negative sign.


EXAMPLES

0)
{
"1 1 1",
"1 1 1"
}

Returns: 6

We can collapse every cell onto the upper-left cell.

1)
{
"1 -1",
"1 -1"
}

Returns: 2

We should perform only the fold between the two rows, and take the resulting left column.

2)
{
"1 -1 -1 1",
"-1 -1 -1 -1",
"-1 -1 -1 -1",
"1 -1 -1 1"
}

Returns: 4

Folding between the middle rows then the middle columns allows us to combine the four corner cells.

3)
{
"20 13 -2 100",
"-12 0 4 -3",
"4 1 -36 21"
}

Returns: 131



4)
{
"0"
}

Returns: 0



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"1 1 1",
"1 1 1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getValue(Arg0)); }
	void test_case_1() { string Arr0[] = {
"1 -1",
"1 -1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getValue(Arg0)); }
	void test_case_2() { string Arr0[] = {
"1 -1 -1 1",
"-1 -1 -1 -1",
"-1 -1 -1 -1",
"1 -1 -1 1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, getValue(Arg0)); }
	void test_case_3() { string Arr0[] = {
"20 13 -2 100",
"-12 0 4 -3",
"4 1 -36 21"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 131; verify_case(3, Arg1, getValue(Arg0)); }
	void test_case_4() { string Arr0[] = {
"0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoldThePaper test;

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
