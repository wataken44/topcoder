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

class BadVocabulary {

 public:
  int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary)
  {
    int result = 0;
    // -- main code --

    EACH(vocabulary, vi) {
      string v = *vi;
      //DUMP(v);
      //DUMP(v.find(badSubstring));
      if(v.find(badPrefix) == 0) {
        ++result;
        DUMP(badPrefix);
        DUMP(v);
      }else if(v.rfind(badSuffix) != string::npos && v.rfind(badSuffix) == ((int)v.size() - (int)badSuffix.size())) {
        ++result;
        DUMP(badSuffix); 
        DUMP(v.rfind(badSuffix));
        DUMP((v.size() - badSuffix.size()));
        DUMP(v.size());DUMP(badSuffix.size());
        DUMP(v);
      }else if(v.find(badSubstring,1) != 0 && v.find(badSubstring,1) != string::npos && v.find(badSubstring,1) != v.size() - badSubstring.size()) {
        ++result;
        DUMP(badSubstring);
        DUMP(v);
      }
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
    string arr[] = {"abcde", "abc", "bcde", "bcdbcd", "abcd", "aaaa", "abcdefebcde", "aabbccdd"};
    vector<string> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    count("abcd", "bcde", "bcd", v);
  }
/*
// PROBLEM STATEMENT
// Little Teddy and Little Tracy are now learning how to speak words. Their mother, of course, doesn't want them to speak bad words. According to her definition, a word W is bad if at least one of the following conditions hold  (see the notes section for definitions):

W contains the string badPrefix as a prefix.
W contains the string badSuffix as a suffix.
W contains the string badSubstring as a contiguous substring that is neither a prefix nor a suffix of W.


You are given a vector <string> vocabulary representing the words that Teddy and Tracy are going to learn. Return the number of bad words in vocabulary.

DEFINITION
Class:BadVocabulary
Method:count
Parameters:string, string, string, vector <string>
Returns:int
Method signature:int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary)


NOTES
-A prefix of a string is obtained by removing zero or more contiguous characters from the end of the string.
-A suffix of a string is obtained by removing zero or more contiguous characters from the beginning of the string.


CONSTRAINTS
-badPrefix, badSuffix, and badSubstring will each contain between 1 and 50 characters, inclusive.
-vocabulary will contain between 1 and 50 elements, inclusive.
-Each element vocabulary will contain between 1 and 50 characters, inclusive.
-Each character of badPrefix, badSuffix, and badSubstring will be between 'a' and 'z', inclusive.
-Each character in vocabulary will be between 'a' and 'z', inclusive.
-All elements of vocabulary will be distinct.


EXAMPLES

0)
"bug"
"bug"
"bug"
{"buggy", "debugger", "debug"}

Returns: 3



1)
"a"
"b"
"c"
{"a", "b", "tco"}

Returns: 3

"a" is a prefix of "a". "b" is a suffix of "b". "c" is a substring of "tco". So, all words in vocabulary are bad.

2)
"cut"
"sore"
"scar"
{"scary", "oscar"}

Returns: 0

Although "scar" is a substring of "scary", it is also a prefix. Thus, "scary" is not a bad word. Similarly, as "scar" is a suffix of "oscar", "oscar" is not a bad word.

3)
"bar"
"else"
"foo"
{"foofoofoo", "foobar", "elsewhere"}

Returns: 1

Only the word "foofoofoo" is bad.

4)
"pre"
"s"
"all"
{"all", "coders", "be", "prepared", "for", "the", "challenge", "phase"}

Returns: 3



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "bug"; string Arg1 = "bug"; string Arg2 = "bug"; string Arr3[] = {"buggy", "debugger", "debug"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arr3[] = {"a", "b", "tco"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "cut"; string Arg1 = "sore"; string Arg2 = "scar"; string Arr3[] = {"scary", "oscar"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "bar"; string Arg1 = "else"; string Arg2 = "foo"; string Arr3[] = {"foofoofoo", "foobar", "elsewhere"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "pre"; string Arg1 = "s"; string Arg2 = "all"; string Arr3[] = {"all", "coders", "be", "prepared", "for", "the", "challenge", "phase"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BadVocabulary test;

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
