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

class Undo {

 public:
  vector<bool> m_enable;
  vector<string> m_typed;
  vector<int> m_time;
  vector<int> m_undo;
  
  string getText(vector <string> commands, vector <int> time)
  {
    // -- main code --

    m_enable = vector<bool>(commands.size(), true);
    m_typed = vector<string>(commands.size(), "");
    m_time = time;
    m_undo = vector<int>(commands.size(), 0);
    
    TIMES(i, commands.size()) {
      istringstream iss(commands[i]);

      string s;
      iss >> s;
      if(s == "type") {
        iss >> s;
        m_typed[i] = s;
      }else {
        int t = 0;
        iss >> t;
        m_undo[i] = t;
        undo(t, i);
      }
    }

    string result = "";
    TIMES(i, m_typed.size()) {
      if(m_enable[i]) result += m_typed[i];
    }

    DUMP(m_enable);
    DUMP(m_typed);
    
    return result;
  }

  void undo(int t, int k)
  {
    DOWNTO(j, k - 1, 0) {
      if(m_time[k] - m_time[j] > t) break;
      m_enable[j] = not m_enable[j];
      if(m_typed[j] == "") {
        undo(m_undo[j], j);
      }
    }
  }
  
// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
You are writing a simple text editor that supports only the following two commands: 

"type c" where c is a character: Append character c to the end of the current text.
"undo t" where t is an integer: Undo all operations that were performed in the previous t seconds in reverse order.



All quotes are for clarity only.  The text in the editor is initially empty.


For example, consider the following sequence of commands:


Second 1: type a
Second 2: type b
Second 3: type c
Second 5: undo 3


At the end of second 3, the text is "abc".  At second 5, all commands performed in the previous 3 seconds are undone in reverse order.  This means 'c' is removed, and then 'b' is removed.  The text becomes just "a".


Note that "undo" commands can also be undone.  For example:


Second 1: type a
Second 2: type b
Second 3: undo 2
Second 4: undo 2


After second 2, the text is "ab".  After second 3, everything is undone, and the text becomes empty.  At second 4, the previous "undo" is undone, so the text becomes "ab" again.  Then, the "type b" is also undone and the text becomes just "a".


You are given a vector <string> commands and a vector <int> time.  Each element of commands is a single command, and commands[i] is performed at time[i].  The commands are given in chronological order.  Return the text after all the commands are executed.


DEFINITION
Class:Undo
Method:getText
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getText(vector <string> commands, vector <int> time)


CONSTRAINTS
-commands will contain between 1 and 50 elements, inclusive.
-Each element of commands will be either "type c" where c is a lowercase letter ('a'-'z') or "undo t" where t is an integer between 1 and 10^9, inclusive, with no leading zeroes (quotes for clarity only).
-time will contain the same number of elements as commands.
-Each element of time will be between 1 and 10^9, inclusive.
-The elements of time will be in strictly ascending order.


EXAMPLES

0)
{"type a", "type b", "type c", "undo 3"}
{1, 2, 3, 5}

Returns: "a"

The first example from the problem statement.

1)
{"type a", "type b", "undo 2", "undo 2"}
{1,2,3,4}

Returns: "a"

The second example from the problem statement.

2)
{"type a", "undo 1", "undo 1"}
{1,2,3}

Returns: "a"



3)
{"type a", "type b", "type c", "undo 10"}
{1, 2, 3, 1000}

Returns: "abc"

Note that "undo" can undo nothing if it is too late.

4)
{"undo 1"}
{1}

Returns: ""



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"type a", "type b", "type c", "undo 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(0, Arg2, getText(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"type a", "type b", "undo 2", "undo 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(1, Arg2, getText(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"type a", "undo 1", "undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(2, Arg2, getText(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"type a", "type b", "type c", "undo 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "abc"; verify_case(3, Arg2, getText(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, getText(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Undo test;

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
