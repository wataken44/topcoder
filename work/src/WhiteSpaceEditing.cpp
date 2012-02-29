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

class WhiteSpaceEditing {

 public:
  int getMinimum(vector <int> lines)
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
// You want to type a document containing only spaces and new lines. 
Let SP and NL denote a space character and a new line character, respectively. 
You are given a vector <int> lines describing the desired document. 
The elements of lines represent the number of SP characters in each line, 
in order. 
Each line must end with a NL character. 
In other words, the document should look like this: 
lines[0] SP characters, followed by a NL, 
followed by lines[1] SP characters, followed by a NL, 
..., lines[N-1] SP characters, followed by a NL 
(where N is the number of elements in lines).


The editor has a cursor, which can be positioned 
between two adjacent characters or at the beginning or end of the document. 
You can move this cursor freely.


The editor has three special keys: 

	
		SPACE: inserts a SP at the position of the cursor. 
	
	
		DELETE: deletes a SP character immediately to the right of the cursor. 
		This key cannot be used if the character to the right of the cursor is a NL.
	
	
		RETURN: inserts a NL followed by some number of SP characters. 
		This key can only be used when the character 
		immediately to the right of the cursor is a NL. 
		The number of SP characters that get inserted 
		is equal to the number of SP characters in the line where the cursor is. 
		For example, if the document is "SP NL SP SP NL SP SP SP NL", 
		and the cursor is immediately to the left of the second NL, 
		it will become "SP NL SP SP NL SP SP NL SP SP SP NL" after pressing RETURN. 
	

The document initially contains nothing but a single NL character. 
Return the minimum number of times 
you must press SPACE, DELETE or RETURN to complete the document.


DEFINITION
Class:WhiteSpaceEditing
Method:getMinimum
Parameters:vector <int>
Returns:int
Method signature:int getMinimum(vector <int> lines)


CONSTRAINTS
-lines will contain between 1 and 50 elements, inclusive. 
-Each element of lines will be between 0 and 1,000,000, inclusive. 


EXAMPLES

0)
{ 3, 2, 3 }

Returns: 6

You can edit the document as follows: 

	NL
	SP NL
	SP SP NL
	SP SP SP NL
	SP SP SP NL SP SP SP NL
	SP SP SP NL SP SP SP NL SP SP SP NL
	SP SP SP NL SP SP NL SP SP SP NL



1)
{ 0 }

Returns: 0

You have to do nothing. 


2)
{ 1, 2, 4 }


Returns: 6



3)
{ 250, 105, 155, 205, 350 }


Returns: 499



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3, 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 2, 4 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = { 250, 105, 155, 205, 350 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 499; verify_case(3, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  WhiteSpaceEditing test;

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
