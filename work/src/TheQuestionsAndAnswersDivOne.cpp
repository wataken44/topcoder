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

class TheQuestionsAndAnswersDivOne {

 public:
  int find(int questions, vector <string> answers)
  {
    int asz = answers.size();

    int yc = 0;
    int nc = 0;

    FOR(i, 0, asz) {
      if(answers[i] == "Yes") {
        ++yc;
      }else {
        ++nc;
      }
    }

    return count(questions, yc, nc);	
  }

  int count(int q, int yc, int nc)
  {
    int min_y = (yc > 0 ? 1 : 0);
    int max_y = min(yc, (nc > 0 ? q - 1 : q));

    //DUMP(min_y);DUMP(max_y);
    
    int result = 0;
    UPTO(y, min_y, max_y) {
      int n = q - y;
      if(n > nc) continue;
      int r = comb(q, y) * h(yc, y) * h(nc, n);
      //DUMP(q);DUMP(y);DUMP(n);DUMP(r);DUMP(yc); DUMP(h(yc,y));DUMP(nc);DUMP(h(nc,n));
      result += r;
    }
    
    return result;
  }

  int h(int n, int k)
  {
    if(k == 1) return 1;

    int r = power(k, n);
    UPTO(i, 1, k - 1) {
      r -= h(n, i) * comb(k, i);
    }
    // DUMP(n);DUMP(k);DUMP(r); 
    return r;
  }
  
  int power(int b, int e)
  {
    int r = 1;
    FOR(i, 0, e) r *= b;
    return r;
  }

  int comb(int n, int k)
  {
    int r = 1;
    UPTO(i, 1, k) {
      r = r * (n + 1 - i) / i;
    }
    return r;
  }
  
  int fact(int n) 
  {
    int r = 1;
    UPTO(k, 1, n) {
      r *= k;
    }
    return r;
  }

// BEGIN CUT HERE
  void debug()
  {
    cout << count(6, 3, 5) << endl;
  }
/*
// PROBLEM STATEMENT
// 
John and Brus have become very famous people all over the world, especially in Bolivia.
A man in Bolivia decided to write a story about them.
To make the story more truthful, he set up an interview with John.
He prepared a list of distinct simple "Yes" or "No" questions and he enlisted the help of two friends to transcribe the interview.
Each time he asked a question, one friend wrote down the question while the other friend wrote down the answer.
He was very nervous when conducting the interview, so he might have asked some of the questions multiple times.
However, John's answers always remained the same for the same questions.



Unfortunately, the friend who was writing down the questions lost his list.
In a desperate attempt to remember the order in which he asked the questions, the Bolivian has decided to write down all the possible ways that he might have asked them.
He knows for sure that he asked every question from his list at least once.
You are given an int questions, which is the number of questions that were in his list, and a vector <string> answers, the i-th element of which is the answer to the i-th question he asked.
Return the total number of ways in which he might have asked the questions.



DEFINITION
Class:TheQuestionsAndAnswersDivOne
Method:find
Parameters:int, vector <string>
Returns:int
Method signature:int find(int questions, vector <string> answers)


CONSTRAINTS
-questions will be between 2 and 9, inclusive.
-answers will contain between questions and 9 elements, inclusive.
-Each element of answers will be either "Yes" or "No".


EXAMPLES

0)
2
{"No", "Yes"}

Returns: 2

The two possible ways are: the first question followed by the second question, or vice versa.

1)
2
{"No", "No", "No"}

Returns: 6

2)
3
{"Yes", "No", "No", "Yes"}

Returns: 12



3)
3
{"Yes", "Yes", "Yes", "No"}

Returns: 18

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"No", "No", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"Yes", "No", "No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"Yes", "Yes", "Yes", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  TheQuestionsAndAnswersDivOne test;

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
