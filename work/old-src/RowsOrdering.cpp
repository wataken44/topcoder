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

class RowsOrdering {

 public:
  int order(vector <string> rows)
  {
    int result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are given a table where each row contains exactly M columns, numbered 0 through M-1.  Each value in the table is an integer between 1 and 50, inclusive.  Each row of the table is distinct, and the table contains all possible distinct rows.  Two rows are considered distinct if there is at least one column where the rows have a different value.  Hence, the table contains exactly 50^M rows.

The rows of the table can be sorted using the following scheme:

First, for each column, assign a permutation of all the integers between 1 and 50, inclusive.  Note that this permutation may differ for each column.
Next, pick a permutation of all M columns.
Finally, sort the rows in ascending order.  Compare each pair of rows as follows:

Consider the first column in the permutation chosen in step 2.  Compare the values in both rows in this column.
If the values in this column are the same in both rows, check the values in the next column in the permutation instead.  Repeat this until the values for the chosen column are different.
The row which contains the value that comes earlier in the permutation chosen in step 1 for this column is considered to be smaller than the other row.

You are given a vector <string> rows that contains a description of several rows of the table described above. Each element represents a single row and contains exactly M characters. The i-th character in each element represents the value in column i for that row and is one of the following letters:

'a'-'z' corresponds to values 1-26
'A'-'X' corresponds to values 27-50

For each of the given rows, define P as the 1-based index of that row in a table sorted as described above. For any given ordering, where an ordering is defined by the permutations chosen in steps 1 and 2 above, define S as the sum of all P for the given rows. Find the minimum possible value of S and return it modulo 1,000,000,007.

DEFINITION
Class:RowsOrdering
Method:order
Parameters:vector <string>
Returns:int
Method signature:int order(vector <string> rows)


NOTES
-The number that you should minimize is the number before the modulo and not after the modulo. That is, 1,000,000,010 is larger than 20 even though 1,000,000,010 modulo 1,000,000,007 = 3 < 20.
-Duplicate elements are allowed in rows. In case rows contains C > 1 occurrences of a certain row, the value of P for this row must be added towards S for C times (see example 4).


CONSTRAINTS
-rows will contain between 1 and 50 elements, inclusive.
-Each element of rows will contain between 1 and 50 characters, inclusive.
-All the elements of rows will contain the same number of characters.
-Each character in rows will be either 'a'-'z' or 'A'-'X'.


EXAMPLES

0)
{"bb", "cb", "ca"}

Returns: 54

One possible ordering is as follows:

For the first column, choose the permutation {c, b, ...}.
For the second column, choose the permutation {b, a, ...}.
Then, choose the permutation {1, 0} for the columns.

The rows will then be indexed as follows:
"cb" = 1
"bb" = 2
...
"ca" = 51
"ba" = 52
...


The sum is 1+2+51 = 54.

1)
{"abcd", "ABCD"}

Returns: 127553

Lowercase and uppercase letters are considered distinct.

2)
{"Example", "Problem"}

Returns: 943877448



3)
{"a", "b", "c", "d", "e", "f", "g"}

Returns: 28



4)
{"a", "a"}

Returns: 2

Duplicate elements are allowed. The value of P for each such element should be added towards S separately.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bb", "cb", "ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(0, Arg1, order(Arg0)); }
	void test_case_1() { string Arr0[] = {"abcd", "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 127553; verify_case(1, Arg1, order(Arg0)); }
	void test_case_2() { string Arr0[] = {"Example", "Problem"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 943877448; verify_case(2, Arg1, order(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "b", "c", "d", "e", "f", "g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, order(Arg0)); }
	void test_case_4() { string Arr0[] = {"a", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, order(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  RowsOrdering test;

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
