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

class SentenceDecomposition {

 public:
  int decompose(string sentence, vector <string> words)
  {
    // -- main code --
    
    // map<pair<int, int>, int> cost;

    int ssz = sentence.size();
    int INF = 1000000;
    
    vector< vector<int> > cost(ssz + 1, vector<int>(ssz + 1, INF));
    
    TIMES(i, words.size()) {
      string w = words[i];
      string x = w;

      sort(w.begin(), w.end());

      UPTO(k, 0, ssz - w.size()) {
        string v = sentence.substr(k, w.size());
        string y = v;

        sort(v.begin(), v.end());

        if(w != v) continue;

        int c = 0;
        TIMES(m, y.size()) {
          if(x[m] != y[m]) ++c;
        }

        int from = k;
        int to = from + y.size();
        
        if(to > ssz) continue;

        cost[from][to] = min(cost[from][to], c);

      }
    }

    set< pair<int, int> > queue;

    queue.insert(make_pair(0, 0));

    while(queue.empty() == false) {
      set< pair<int, int> >::iterator it = queue.begin();
      
      int c = it->first;
      int p = it->second;

      queue.erase(it);
      
      if(p == ssz) return c;

      TIMES(to, ssz + 1) {
        if(cost[p][to] == INF) continue;
        queue.insert(make_pair(c + cost[p][to], to));
      }
    }
    
    return -1;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Little Bonnie and her friends were dismayed to learn that their parents were reading all of their private communications.  They decided to invent a new language that would allow them to talk freely.  What they finally came up with was a language where sentences are built using a special method. 


All the valid words that can be used in the new language are given in the vector <string> validWords.  A sentence is a concatenation (with no spaces) of a sequence of valid words.  Each valid word can appear 0 or more times in the sentence.  What makes the language special is that each word can be transformed by rearranging its letters before being used.  The cost to transform a word is defined as the number of character positions where the original word and the transformed word differ.  For example, "abc" can be transformed to "abc" with a cost of 0, to "acb", "cba" or "bac" with a cost of 2, and to "bca" or "cab" with a cost of 3. 


Although several different sequences of valid words can produce the same sentence in this language, only the sequence with the least total transformation cost carries the meaning of the sentence.  The advantage of the new language is that the parents can no longer understand what the kids are saying.  The disadvantage is that the kids themselves also do not understand.  They need your help. 


Given a string sentence, return the total cost of transformation of the sequence of valid words which carries the meaning of the sentence, or -1 if no such sequence exists.

DEFINITION
Class:SentenceDecomposition
Method:decompose
Parameters:string, vector <string>
Returns:int
Method signature:int decompose(string sentence, vector <string> validWords)


NOTES
-If a word is used multiple times in a sentence, each occurrence can be transformed differently.


CONSTRAINTS
-sentence will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.
-validWords will contain between 1 and 50 elements, inclusive.
-Each element of validWords will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
"neotowheret"
{"one", "two", "three", "there"}

Returns: 8

The following transformations can be made:

"one" -> "neo" with a cost of 3 
"two" -> "tow" with a cost of 2 
"three" -> "heret" with a cost of 3 
"there" -> "heret" with a cost of 5 

So the sequence {"one", "two", "three"} is the one carrying the meaning of "neotowheret". Its total transformation cost is 3 + 2 + 3 = 8.

1)
"abba"
{"ab", "ac", "ad"}

Returns: 2

The word "ab" is used twice, and each time, it is transformed differently.

2)
"thisismeaningless"
{"this", "is", "meaningful"}

Returns: -1



3)
"ommwreehisymkiml"
{"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}

Returns: 10



4)
"ogodtsneeencs"
{"go", "good", "do", "sentences", "tense", "scen"}

Returns: 8



5)
"sepawaterords"
{"separate","words"}

Returns: -1

You are only allowed to rearrange letters within words, and not in the entire sentence.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "neotowheret"; string Arr1[] = {"one", "two", "three", "there"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, decompose(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abba"; string Arr1[] = {"ab", "ac", "ad"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, decompose(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "thisismeaningless"; string Arr1[] = {"this", "is", "meaningful"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, decompose(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ommwreehisymkiml"; string Arr1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, decompose(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ogodtsneeencs"; string Arr1[] = {"go", "good", "do", "sentences", "tense", "scen"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, decompose(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "sepawaterords"; string Arr1[] = {"separate","words"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, decompose(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  SentenceDecomposition test;

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
