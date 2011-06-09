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

class PalindromizationDiv1 {

 public:

  map< pair<string, int>, int > memo;

  static const int INF = INT_MAX / 16;
  
  int getMinimumCost(string word, vector <string> operations)
  {
    // -- main code --

    memo.clear();

    int r = go(word, operations, 0) ;
    return r >= INF ? -1 : r;
  }

  int go(string& word, vector<string>& operations, int index)
  {
    pair<string, int> id = make_pair(word, index);
    if(memo.find(id) != memo.end()) {
      return memo[id];
    }

    if(isPalindrome(word)) {
      memo[id] = 0;
      return memo[id];
    }

    if(index == (int)operations.size()) {
      memo[id] = INF;
      return memo[id];
    }

    // do nothing and pass next;
    int m = go(word, operations, index + 1);
    
    istringstream iss(operations[index]);

    string op;
    iss >> op;
    if(op == "add") {
      string ch;
      iss >> ch;
      int cost;
      iss >> cost;

      UPTO(i, 0, word.size()) {
        string nw = word.substr(0, i) + ch + word.substr(i, word.size() - i);
        m = min(m, go(nw, operations, index + 1) + cost);
      }
      memo[id] = m;
      return m;
    }else if(op == "erase") {
      char ch;
      iss >> ch;
      int cost;
      iss >> cost;

      TIMES(i, word.size()) {
        if(word[i] == ch) {
          string nw = word.substr(0, i) + word.substr(i + 1, word.size() - i - 1);
          m = min(m, go(nw, operations, index) + cost);
        }
      }
      memo[id] = m;
      return m;
    }else if(op == "change") {
      char ch1;
      iss >> ch1;
      char ch2;
      iss >> ch2;
      int cost;
      iss >> cost;

      TIMES(i, word.size()) {
        if(word[i] == ch1) {
          string nw = word;
          nw[i] = ch2;
          m = min(m, go(nw, operations, index) + cost);
        }
      }
      memo[id] = m;
      return m;

    }
    DUMP(op);
    return INT_MIN;
  }

  bool isPalindrome(string& word)
  {
    TIMES(i, word.size()) {
      if(word[i] != word[word.size() - i - 1]) return false;
    }
    return true;
  }

// BEGIN CUT HERE
  void debug()
  {

    string Arg0 = "rgyormgmhvyszgnqxyjrifiauyajfbnjuchwltcrjljzzwskli";
    string Arr1[] = {
      "change a b 2240",
      "change b c 9213",
      "change c d 4848",
      "change d e 2861",
      "change e f 3013",
      "change f g 11",
      "change g h 1597",
      "change h i 2975",
      "change i j 2899",
      "change j k 63",
      "change k l 6198",
      "change l m 2717",
      "change m n 433",
      "change n o 2387",
      "change o p 3636",
      "change p q 9636",
      "change q r 7301",
      "change r s 4897",
      "change s t 9269",
      "change t u 1633",
      "change u v 4255",
      "change v w 2011",
      "change w x 3082",
      "change x y 5478",
      "change y z 8902",
      "change z a 6730",
      "add o 3017",
      "erase q 6234",
      "erase l 8059",
      "erase z 2364",
      "add v 1128",
      "add s 160",
      "add a 607",
      "add c 5898",
      "erase f 5005",
      "add n 5308",
      "erase n 9396",
      "erase d 9545",
      "add j 2094",
      "add f 38",
      "add w 4436",
      "erase b 2018",
      "add x 2926",
      "erase t 7785",
      "change z t 2",
      "change y f 4",
      "change c j 8",
      "change h w 7",
      "change o a 3",
      "change v n 9",
    };
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 5; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1));    
  }
/*
// PROBLEM STATEMENT
// Little Arthur loves palindromes. A palindrome is a word that reads the same both forwards and backwards. For example, the words "racecar", "noon", and "w" are palindromes, but the words "computer", "moon", and "oh" are not.

Arthur is given a word word and he would like to transform it into a palindrome. There are three types of operations he can perform:


add a letter at any position in the word (possibly at the beginning or end);
erase a letter;
change one letter to another.


However, each operation can be performed only with certain letters. For example, Arthur could be allowed to erase 'a', add 'b', and change 'c' to 'd'; no other operation would be allowed. Furthermore, nothing in this world is for free and operations with letters is not an exception - each operation Arthur can perform has a certain cost.

The descriptions of the allowed operations and their costs are given as vector <string> operations. Each element of operations is in one of the following forms (all quotes for clarity):

"add c x" where c is a letter and x is a positive integer meaning that it is allowed to add a letter c and it costs x dollars;
"erase c x" where c is a letter and x is a positive integer meaning that it is allowed to erase letter c and it costs x dollars;
"change c1 c2 x" where c1 and c2 are letters and x is a positive integer meaning that it is allowed to change letter c1 to c2 and it costs x dollars.

Note that "change c1 c2 x" does not allow to change letter c2 to c1.

Little Arthur would like to transform word into a palindrome spending the least amount of money. Given word and operations return the minimum number of dollars Arthur needs to create a palindrome. Return -1 if it is impossible.

DEFINITION
Class:PalindromizationDiv1
Method:getMinimumCost
Parameters:string, vector <string>
Returns:int
Method signature:int getMinimumCost(string word, vector <string> operations)


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-Each character in word will be a lowercase letter 'a'-'z'.
-operations will contain between 0 and 50 elements, inclusive.
-Each element of operations will be exactly in the form "add c x", "erase c x", or "change c1 c2 x" (quotes for clarity) where c, c1, c2 are single lowercase letters 'a'-'z' and x is an integer between 1 and 100000, inclusive, with no leading zeros.
-In each operation in form "change c1 c2 x", c1 and c2 will be different. 
-All elements of operations will represent different operations, i.e., all elements of operations without the cost part ("add c", "erase c", or "change c1 c2") will be distinct.


EXAMPLES

0)
"racecar"
{}

Returns: 0

No?operations?are?allowed?but?the?given?word?is?already?a?palindrome.

1)
"topcoder"
{"erase t 1", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}

Returns: 5

Here it is allowed to erase any letter present in word and the cost of each such operation is 1 dollar. Thus, Arthur would like to obtain the longest possible palindrome. Two possible variants to erase only 5 letters result in palindromes "opo" and "oco".

2)
"topcoder"
{"erase t 10", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}

Returns: 7

The same situation as previously except erasing letter 't' now costs 10. Because of that it is no longer optimal to obtain the longest possible palindrome.

3)
"caaaaaab"
{"change b a 100000", "change c a 100000", "change c d 50000", "change b e 50000", "erase d 50000", "erase e 49999"}

Returns: 199999

One way to palindromize "caaaaaab" is to change letters 'c' and 'b' to 'a's right away obtaining "aaaaaaaa". This would cost 200000.

However, a slightly cheaper way is to perform the following sequence of operations:


"caaaaaab" - change 'c' to 'd' (costs 50000)
"daaaaaab" - change 'b' to 'e' (costs 50000)
"daaaaaae" - erase 'd' (costs 50000)
"aaaaaae" - erase 'e' (costs 49999)
"aaaaaa"

This palindromization will cost 199999 in total. 

4)
"moon"
{"erase o 5", "add u 7", "change d p 3", "change m s 12", "change n d 6", "change s l 1"}

Returns: -1

Many words can be constructed here (e.g., "moon", "mood", "mud", "soon", "sun", "loop"), however, no palindrome is obtainable.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "racecar"; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 1", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 10", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "caaaaaab"; string Arr1[] = {"change b a 100000", "change c a 100000", "change c d 50000", "change b e 50000", "erase d 50000", "erase e 49999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 199999; verify_case(3, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "moon"; string Arr1[] = {"erase o 5", "add u 7", "change d p 3", "change m s 12", "change n d 6", "change s l 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  PalindromizationDiv1 test;

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
