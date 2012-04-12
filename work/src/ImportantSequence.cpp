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

class ImportantSequence {

 public:
  int getCount(vector <int> B, string operators)
  {
    int result = INT_MAX;
    // -- main code --

    DUMP(B);
    DUMP(operators);
    //DUMP(range);

    
    int sz = B.size();

    typedef long long ll;
    vector< pair<ll, ll> > range(sz + 1, make_pair(1, INT_MAX)); 
    vector< bool > det(sz + 1, false);
    
    TIMES(i, sz) {
      if(operators[i] == '+') {
        range[i].first = 1;
        range[i].second = min(range[i].second, B[i] - 1LL);
        det[i] = true;
        range[i+1].first = 1;
        range[i+1].second = min(range[i].second, B[i] - 1LL);
        det[i+1] = true;
      }
    }
    DUMP(range);

    TIMES(k, sz + 1) {
      if(!det[k]) continue;
      DOWNTO(m, k-1, 0) {
        det[m] = true;
        //DUMP(range);
        if(operators[m] == '+') {
          range[m].first = max(range[m].first, B[m] - range[m+1].second);
          range[m].second = min(range[m].second, B[m] - range[m+1].first);
          if(range[m].second <= 0) return 0;
        }else {
          range[m].first = range[m+1].first + B[m];
          range[m].second = range[m+1].second + B[m];
          if(range[m].second <= 0) return 0;
          range[m].first = max(1LL, range[m].first);          
        }
      }
      FOR(m, k+1, sz+1) {
        det[m] = true;
        if(operators[m-1] == '+') {
          range[m].first = max(range[m].first, B[m-1] - range[m-1].second);
          range[m].second = min(range[m].second, B[m-1] - range[m-1].first);
          if(range[m].second <= 0) {
            return 0;
          }
        }else {
          range[m].first = range[m-1].first - B[m-1];
          range[m].second = range[m-1].second - B[m-1];
          if(range[m].second <= 0) return 0;
          range[m].first = max(1LL, range[m].first);          
        }
      }
    }

    
    bool ok = true;
    TIMES(k, sz + 1) {
      if(det[k] != true) {
        ok = false;
      }
    }
    if(!ok) return -1;
        
    TIMES(k, sz + 1) {
      result = min(result, (int)(1 + range[k].second - range[k].first)); 
    }

    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.

Little Rudolph had an important sequence of positive integers. The sequence consisted of N positive integers a0, a1, .., aN-1.

Rudolph wrote the sequence onto the blackboard in the classroom. While Rudolph had gone out, little Arthur came into the classroom and saw the sequence. Arthur likes to play with numbers as much as he likes to give his friends puzzles. So he did the following:

First, he wrote a '+' or a '-' between each pair of consecutive numbers (possibly using different signs for different pairs of numbers).
	
Next, for each sign he computed the result of the corresponding operation and wrote it under the sign.
I.e., if he used the '+' sign between ai and ai+1, he would write the sum ai+ai+1 under this '+' sign.
Similarly, if he used the '-' sign between ai and ai+1, he would write the difference ai-ai+1. In this way he obtained a new sequence of N-1 numbers b0, b1, .., bN-2.
Finally, he erased the original sequence. Now there was only the operator sequence o0, o1, .., oN-2 and the resulting number sequence b0, b2, .., bN-2 left on the blackboard.

For example, if the original sequence was {1, 2, 3, 4}, and Arthur wrote operators {+, -, +}, then the content of the blackboard changed like this:

1   2   3   4    ->    1 + 2 - 3 + 4    ->    1 + 2 - 3 + 4    ->     +  -  +
                                                3  -1   7             3 -1  7

When Rudolph returned, he was shocked as his important sequence had disappeared. Arthur quickly told him what operations he had performed and that Rudolph has to simply reconstruct the orginal sequence.

Unfortunately, little Arthur did not realize that it is not necessarily possible to determine the original sequence uniquely. For example, both original sequences {1, 2, 3, 4} and {2, 1, 2, 5} lead to the same sequence {3, -1, 7} when operator sequence is {+, -, +}.

The only thing Rudolph remembers about his original sequence is that all the integers were positive. Rudolph now wants to count all sequences of positive integers that match the blackboard. You are given vector <int> B and string operators  both containing N-1 elements. The i-th element of B is the number bi and i-th element of operators will be '+' or '-', meaning that the i-th operator is + or -, respectively. Return the number of different positive integer sequences A that lead to sequence B when operators operators are used in the way described. If there are infinitely many such sequences, return -1. Note that there may be test cases where no valid sequence A exists. For such test cases the correct return value is 0.

DEFINITION
Class:ImportantSequence
Method:getCount
Parameters:vector <int>, string
Returns:int
Method signature:int getCount(vector <int> B, string operators)


NOTES
-It is guaranteed that the correct answer will always fit into the 32-bit signed integer type.
-The integer 0 (zero) is not positive. It may not occur in Rudolph's original sequence.


CONSTRAINTS
-B will contain between 1 and 50 elements, inclusive.
-operators will contain the same number of characters as the number of elements in B.
-Each element of B will be between -1000000000 (-109) and 1000000000 (109), inclusive.
-Each character in operators will be either '+' or '-' (quotes for clarity).


EXAMPLES

0)
{3, -1, 7}
"+-+"

Returns: 2

From the problem statement.

1)
{1}
"-"

Returns: -1

There are infinitely many pairs of positive integers that differ by one.

2)
{1}
"+"

Returns: 0

Note that all numbers ai have to be positive integers.

3)
{10}
"+"

Returns: 9

4)
{540, 2012, 540, 2012, 540, 2012, 540}
"-+-+-+-"

Returns: 1471

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+-+"; int Arg2 = 2; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-"; int Arg2 = -1; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 0; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 9; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {540, 2012, 540, 2012, 540, 2012, 540}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-+-+-+-"; int Arg2 = 1471; verify_case(4, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ImportantSequence test;

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
