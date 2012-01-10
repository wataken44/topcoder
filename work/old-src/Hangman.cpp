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

class Hangman {

 public:
  string guessWord(string feedback, vector <string> words)
  {
    vector<string> candidate;

    FOR(i, 0, words.size()) {
      string& word = words[i];

      if(word.size() != feedback.size()) continue;

      bool ok = true;
      vector<bool> used(257, false);

      FOR(x, 0, feedback.size()) {
        char c = feedback[x];

        if(c == '-') continue;

        if(word[x] != c) {
          ok = false;
          break;
        }

        used[c] = true;
      }

      if(!ok) continue;

      FOR(x, 0, feedback.size()) {
        char c = feedback[x];

        if(c != '-') continue;

        char d = word[x];

        if(used[d]) {
          ok = false;
          break;
        }
      }

      if(!ok) continue;

      candidate.push_back(word);
    }

    if(candidate.size() == 1) {
      return candidate[0];
    }else {
      return "";
    }
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are playing a game of Hangman with your brother. He begins by choosing a word, and he writes down one blank for each letter in the word. You then repeatedly guess letters that you think could be in the word. Every time you guess a letter, your brother indicates every occurrence of that letter in the word by replacing blanks with the corresponding letter. For example, suppose your brother chooses the word, "NINJA".

  - He begins by writing down 5 blanks, indicated here by dashes: "-----".
  - Suppose you first guess the letter 'A'. Then, your brother would reveal the one instance of 'A' in the word: "----A".
  - Suppose you next guess the letter 'N'. Then, your brother would reveal both instances of 'N' in the word: "N-N-A".
  - Suppose you next guess the letter 'E'. Then, your brother would reveal nothing new since 'E' is not in the word: "N-N-A".

Create a class Hangman that contains a method guessWord, which is given a string feedback and a vector <string> words. Since your brother is fairly predictable, you have determined that the word he is thinking of is an element of words. You also have the information he has given you after some number of guesses (possibly 0), given in feedback. As above, blanks are represented by dashes ('-'), and revealed letters are represented by capital letters ('A'-'Z'). You now wish to guess the word that your brother is thinking of. If there is exactly one element of words that is consistent with feedback, the method should return that element. Otherwise, it should return "".


DEFINITION
Class:Hangman
Method:guessWord
Parameters:string, vector <string>
Returns:string
Method signature:string guessWord(string feedback, vector <string> words)


CONSTRAINTS
-feedback will contain between 1 and 50 characters inclusive.
-Each character in feedback will be either a capital letter ('A'-'Z') or a dash ('-').
-words will contain between 1 and 50 elements inclusive.
-Each element in words will contain between 1 and 50 characters inclusive.
-No two elements in words will be equal.
-Each character in each element of words will be a capital letter ('A'-'Z').


EXAMPLES

0)
"N-N-A"
{"NINJA", "NINJAS", "FLIPS", "OUT", "FRISBEE"}

Returns: "NINJA"

As described above, this feedback is consistent with "NINJA" after 'A' and 'N' have been guessed. It is not consistent with "NINJAS", since there are only 5 letters in feedback.

1)
"B--B--"
{"BRINGS", "BARBED", "BUBBLE"}


Returns: "BARBED"

The only correct letter you have guessed is 'B'. If your brother had chosen the word, "BRINGS", then feedback would have been "B-----", and if your brother had chosen the word, "BUBBLE", then feedback would have been "B-BB--". This leaves only the possibility that your brother chose "BARBED", which is, in fact, consistent.

2)
"---------"
{"MONKEY", "FORCE", "IS", "GAINING", "STRENGTH"}

Returns: ""

feedback is consistent with all nine-letter words, but there are no nine-letter words.

3)
"-AAA--"
{"CAAABB", "BAAACC"}


Returns: ""

feedback is consistent with both words.

4)
"---H-O-H-B-OPHOB--"
{"ROSACEA", "GYROVAGUE", "SHACONIAN", "ALTITONANT",
 "BRACHIATION", "CERCOPITHECAN", "SCOLECOPHAGOUS",
 "RESISTENTIALISM", "SLUBBERDEGULLION", 
 "AICHMORHABDOPHOBIA", "SPECTOCLOACAPHOBIA",
 "ULTRACREPIDARIANISM", "HIPPOPOTOMONSTROSESQUIPEDALIAN",
 "CHARGOGGAGOGGMANCHAUGGAGOGGCHAUBUNAGUNGAMAUGG"}

Returns: "AICHMORHABDOPHOBIA"

Your brother has a big vocabulary.

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "N-N-A"; string Arr1[] = {"NINJA", "NINJAS", "FLIPS", "OUT", "FRISBEE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NINJA"; verify_case(0, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "B--B--"; string Arr1[] = {"BRINGS", "BARBED", "BUBBLE"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BARBED"; verify_case(1, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "---------"; string Arr1[] = {"MONKEY", "FORCE", "IS", "GAINING", "STRENGTH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(2, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-AAA--"; string Arr1[] = {"CAAABB", "BAAACC"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(3, Arg2, guessWord(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "---H-O-H-B-OPHOB--"; string Arr1[] = {"ROSACEA", "GYROVAGUE", "SHACONIAN", "ALTITONANT",
 "BRACHIATION", "CERCOPITHECAN", "SCOLECOPHAGOUS",
 "RESISTENTIALISM", "SLUBBERDEGULLION", 
 "AICHMORHABDOPHOBIA", "SPECTOCLOACAPHOBIA",
 "ULTRACREPIDARIANISM", "HIPPOPOTOMONSTROSESQUIPEDALIAN",
 "CHARGOGGAGOGGMANCHAUGGAGOGGCHAUBUNAGUNGAMAUGG"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AICHMORHABDOPHOBIA"; verify_case(4, Arg2, guessWord(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Hangman test;

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
