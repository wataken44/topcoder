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
#define DUMP(x) std::cout << #x << " = " << x << std::endl;

using namespace std;

class Stackol {
 public:
  int countPrograms(vector <string> outputFragments, int k) {
    // -- main code --
    
    return ;	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Stackol is a programming language for printing strings. A program is a string containing 'A', 'B' or 'C' as characters (quotes for clarity). A program is evaluated from i = 0 to length(program)-1 using the following rules:


For i = 0 to length(program)-1 :
    If (i==0) or (program[i-1]!='B') then
        push program[i] to the top of stack1.
    Else
        push program[i] to the top of stack2.
    EndIf
    If (program[i]=='C') then 
        printAndEmptyStack(stack1)
        printAndEmptyStack(stack2)
    EndIf
EndFor
printAndEmptyStack(stack) is defined as follows:

While (stack is not empty):
    If (top character in stack) is 'A' or 'B' then
        Print (top character in stack)
    EndIf
    Remove the top character from the stack.
EndWhile


We will consider a valid program to be one that ends with 'C'. We are interested in counting the total number of valid programs that can generate a given output string that contains only 'A' or 'B' characters. Since we would also like the program lengths to be reasonably small we will count only the programs that contain at most k 'C' characters.

The output is given in fragments described by vector <string> outputFragments. In order to generate the output, concatenate the elements of outputFragments. Return the total number of programs that can generate the given output using at most k 'C' characters modulo 1000000007.

DEFINITION
Class:Stackol
Method:countPrograms
Parameters:vector <string>, int
Returns:int
Method signature:int countPrograms(vector <string> outputFragments, int k)


CONSTRAINTS
-The total number of characters in outputFragments will be between 1 and 2500, inclusive.
-outputFragments will contain between 1 and 50 elements, inclusive.
-Each element of outputFragments will contain between 1 and 50 characters, inclusive.
-Each element of outputFragments will contain only 'A' or 'B' characters.
-k will be between 1 and 10, inclusive.


EXAMPLES

0)
{"A"}
2

Returns: 3

The 3 programs that produce "A" as output are:


CAC ACC AC



1)
{"AAAA","BABA"}
1

Returns: 0

There is no program that produces the given output.

2)
{"AB"}
2

Returns: 1

The only possible program that can generate "AB" using at most two 'C' characters is: ACBC.

3)
{"AAABABABAABA", "AA", "BBAB"}
3

Returns: 94



4)
{"AAAAAAAAAAAA","B"}
4

Returns: 120



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AAAA","BABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAABABABAABA", "AA", "BBAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 94; verify_case(3, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"AAAAAAAAAAAA","B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 120; verify_case(4, Arg2, countPrograms(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  Stackol test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
