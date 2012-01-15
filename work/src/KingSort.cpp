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

class KingSort {

 public:
  int roman(string s)
  {
    string b[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    string t[] = {"", "X", "XX", "XXX", "XL", "L"};

    DOWNTO(m, 5, 0) {
      UPTO(n, 0, 10) {
        string p = t[m] + b[n];
        if(s == p) return m * 10 + n;
      }
    }
    
    return 0;
  }

  vector <string> getSortedList(vector <string> kings)
  {
    vector <string> result;
    // -- main code --

    vector< pair<pair<string, int>, string> > name;

    FOR(i, 0, kings.size()) {
      istringstream iss(kings[i]);
      string n, o;
      iss >> n;
      iss >> o;
      name.push_back(make_pair(make_pair(n, roman(o)), o));
    }

    //DUMP(name);
    sort(name.begin(), name.end());
    DUMP(name);
    
    FOR(i, 0, name.size()) {
      result.push_back(name[i].first.first + string(" ") + name[i].second);
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
    string b[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    string t[] = {"", "X", "XX", "XXX", "XL", "L"};

    vector<string> name;
    DOWNTO(m, 5, 0) {
      UPTO(n, 0, 10) {
        string p = t[m] + b[n];
        string n = "Kwata " + p;
        name.push_back(n);
      }
    }
    getSortedList(name);
  }
/*
// PROBLEM STATEMENT
// 
Every good encyclopedia has an index. The entries in the index are usually sorted in alphabetic order. However, there are some notable exceptions. In this task we will consider one such exception: the names of kings.



In many countries it was common that kings of the same name received ordinal numbers. This ordinal number was written as a Roman numeral and appended to the actual name of the king.
For example, "Louis XIII" (read: Louis the thirteenth) was the thirteenth king of France having the actual name Louis.



In the index of an encyclopedia, kings who share the same name have to be sorted according to their ordinal numbers. For example, Louis the 9th should be listed after Louis the 8th.



You are given a vector <string> kings. Each element of kings is the name of one king. The name of each king consists of his actual name, a single space, and a Roman numeral. Return a vector <string> containing the names
rearranged into their proper order: that is, the kings have to be in ascending lexicographic order according to their actual name, and kings with the same name have to be in the correct numerical order.


DEFINITION
Class:KingSort
Method:getSortedList
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> getSortedList(vector <string> kings)


NOTES
-The Roman numerals for 1 through 10 are I, II, III, IV, V, VI, VII, VIII, IX, and X.
-The Roman numerals for 20, 30, 40, and 50 are XX, XXX, XL, and L.
-The Roman numeral for any other two-digit number less than 50 can be constructed by concatenating the numeral for its tens and the numeral for its ones. For example, 47 is 40 + 7 = "XL" + "VII" = "XLVII".
-Standard string comparison routines give the correct ordering for the actual names of kings.
-Formally, given two different strings A and B we say that A is lexicographically smaller than B if either (A is a prefix of B) or (there is at least one index where A and B differ, and for the smallest such index the character in A has a lower ASCII value than the character in B).


CONSTRAINTS
-Each actual name of a king will be a string containing between 1 and 20 characters, inclusive.
-Each actual name will start by an uppercase letter ('A'-'Z').
-Each other character in each actual name will be a lowercase letter ('a'-'z').
-kings will contain between 1 and 50 elements, inclusive.
-Each element of kings will have the form "ACTUALNAME ORDINAL", where ACTUALNAME is an actual name as defined above, and ORDINAL is a valid Roman numeral representing a number between 1 and 50, inclusive.
-The elements of kings will be pairwise distinct.


EXAMPLES

0)
{"Louis IX", "Louis VIII"}

Returns: {"Louis VIII", "Louis IX" }

Louis the 9th should be listed after Louis the 8th.

1)
{"Louis IX", "Philippe II"}

Returns: {"Louis IX", "Philippe II" }

Actual names take precedence over ordinal numbers.

2)
{"Richard III", "Richard I", "Richard II"}

Returns: {"Richard I", "Richard II", "Richard III" }



3)
{"John X", "John I", "John L", "John V"}

Returns: {"John I", "John V", "John X", "John L" }



4)
{"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}

Returns: {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }

These are the French monarchs who ruled between 1328 and 1483.

5)
{"Philippe II", "Philip II"}

Returns: {"Philip II", "Philippe II" }

"Philippe" and "Philip" are distinct names, and "Philip" is lexicographically smaller than "Philippe".

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Louis IX", "Louis VIII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis VIII", "Louis IX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSortedList(Arg0)); }
	void test_case_1() { string Arr0[] = {"Louis IX", "Philippe II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis IX", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSortedList(Arg0)); }
	void test_case_2() { string Arr0[] = {"Richard III", "Richard I", "Richard II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Richard I", "Richard II", "Richard III" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSortedList(Arg0)); }
	void test_case_3() { string Arr0[] = {"John X", "John I", "John L", "John V"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John I", "John V", "John X", "John L" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSortedList(Arg0)); }
	void test_case_4() { string Arr0[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSortedList(Arg0)); }
	void test_case_5() { string Arr0[] = {"Philippe II", "Philip II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Philip II", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getSortedList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  KingSort test;

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
