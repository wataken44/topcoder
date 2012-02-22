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

class DengklekMakingChains {

 public:
  int maxBeauty(vector <string> chains)
  {
    int result = 0;
    // -- main code --

    int sz = chains.size();

    vector<string> left;
    vector<string> right;
    vector<string> split;
    vector<string> all;
    
    TIMES(i, sz) {
      string& s = chains[i];
      if(s[0] != '.' && s[1] != '.' && s[2] != '.') {
        all.push_back(s);
      }else if(s[0] != '.' && s[1] == '.' && s[2] != '.') {
        split.push_back(s);
      }else if(s[0] == '.' && s[2] != '.') {
        right.push_back(s);
      }else if(s[0] != '.' && s[2] == '.') {
        left.push_back(s);
      }else {
        result = max(result, static_cast<int>(s[1] - '0'));
      }
    }

    int ar = 0;
    TIMES(i, all.size()) {
      TIMES(k, all[i].size()) {
        ar += all[i][k] - '0';
      }
    }
    
    int mll = getMaxL(left);
    int mrr = getMaxR(right);
    
    int dr = 0;
    
    int msl = getMaxL(split);
    int msr = getMaxR(split);
    
    dr = max(max(mll, msl) + mrr, mll + max(msr, mrr));

    
    
    result = max(result, ar + dr);
    
    return result;
  }
  
  int getMaxL(vector<string>& v)
  {
    int md = 0;
    TIMES(i, v.size()) {
      int d = 0;
      TIMES(k, v[i].size()) {
        if(v[i][k] == '.') break;
        d += v[i][k] - '0';
      }
      md = max(md, d);
    }
    return md;
  }

  int getMaxR(vector<string>& v)
  {
    int md = 0;
    TIMES(i, v.size()) {
      int d = 0;
      DOWNTO(k, v[i].size() - 1, 0) {
        if(v[i][k] == '.') break;
        d += v[i][k] - '0';
      }
      md = max(md, d);
    }
    return md;
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live together in peace and harmony. 



Mr. Dengklek works as a chain maker. Today, he would like to make a beautiful chain as a decoration for one of his lovely ducks. He will produce the chain from leftovers he found in his workshop. Each of the leftovers is a chain piece consisting of exactly 3 links. Each link is either clean or rusty. Different clean links may have different degrees of beauty.



You are given a vector <string> chains describing the leftovers. Each element of chains is a 3-character string describing one of the chain pieces. A rusty link is represented by a period ('.'), whereas a clean link is represented by a digit ('0'-'9'). The value of the digit in the clean link is the beauty of the link. For example, chains = {".15", "7..", "532", "..3"} means that Mr. Dengklek has 4 chain pieces, and only one of these ("532") has no rusty links.



All links have the same shape, which allows Mr. Dengklek to concatenate any two chain pieces. However, the link shape is not symmetric, therefore he may not reverse the chain pieces. E.g., in the above example he is able to produce the chain "532.15" or the chain ".15..37..", but he cannot produce "5323..".



To produce the chain, Mr. Dengklek will follow these steps:

Concatenate all chain pieces in any order.
Pick a contiguous sequence of links that contains no rusty links. Remove and discard all the remaining links.

The beauty of the new chain is the total beauty of all the links picked in the second step. Of course, Mr. Dengklek would like to create the most beautiful chain possible.



Return the largest possible beauty a chain can have according to the above rules.

DEFINITION
Class:DengklekMakingChains
Method:maxBeauty
Parameters:vector <string>
Returns:int
Method signature:int maxBeauty(vector <string> chains)


NOTES
-Mr. Dengklek is not allowed to remove and discard individual links before concatenating the chain pieces.
-If all links in the input are rusty, Mr. Dengklek is forced to select an empty sequence of links. The beauty of an empty sequence is 0.


CONSTRAINTS
-chains will contain between 1 and 50 elements, inclusive.
-Each element of chains will contain exactly 3 characters.
-Each character in each element of chains will be either a '.' or one of '0'-'9'.


EXAMPLES

0)
{".15", "7..", "402", "..3"}

Returns: 19

One possible solution:


In the first step, concatenate the chain pieces in the order "..3", ".15", "402", "7.." to obtain the chain "..3.154027..".
In the second step, pick the subsequence "154027".

The beauty of the chain in this solution is 1+5+4+0+2+7 = 19.

1)
{"..1", "7..", "567", "24.", "8..", "234"}

Returns: 36

One possible solution is to concatenate the chain pieces in this order:

"..1", "234", "567", "8..", "24.", "7.." -> "..12345678..24.7..",

and then to pick the subsequence "12345678". Its beauty is 1+2+3+4+5+6+7+8 = 36.

2)
{"...", "..."}

Returns: 0

Mr. Dengklek cannot pick any links.

3)
{"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}

Returns: 28



4)
{"..1", "3..", "2..", ".7."}

Returns: 7



5)
{"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}

Returns: 58



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DengklekMakingChains test;

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
