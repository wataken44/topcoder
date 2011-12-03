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

class ChickenOracle {

 public:
  string theTruth(int n, int eggCount, int lieCount, int liarCount)
  {
    // count of answer egg and chicken 
    int ec = eggCount;
    int cc = n - eggCount;

    bool truthEgg = false;
    bool truthChiken = false;

    int lieMax = lieCount + liarCount;
    int lieMin = abs(lieCount - liarCount);
    
    if(lieMin <= ec && ec <= lieMax) truthChiken = true;
    if(lieMin <= cc && cc <= lieMax) truthEgg = true;
    
    if(truthEgg && truthChiken) return "Ambiguous";
    if(!truthEgg && !truthChiken) return "The oracle is a lie";
    if(truthEgg && !truthChiken) return "The egg";
    if(!truthEgg && truthChiken) return "The chicken";
     
    return "There is some bug...";	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// This time, instead of solving an easy problem with a known solution, you will be in charge in solving an old problem with a solution which was unknown to this date. The old question is whether the egg or the chicken came first. This question has been very difficult to answer over the ages, but a chance has finally come: It is said that a new oracle has appeared which knows everything.

You tried asking the question to the oracle, but the oracle refused to answer, arguing that it has already answered the question to n other people and is tired of answering that question. Not to give up, you decided to interview each of the n people. Of them, eggCount people told you that the answer was "The egg", while the remaining n-eggCount people claimed that the answer was "The chicken". Confused by the results, you asked the oracle a second time. The oracle still refused to answer the question, but instead explained the results: In order to hide the truth to those unworthy, the oracle has intentionally given the wrong answer to exactly lieCount people. On the other hand, also to avoid sharing the secret, exactly liarCount people (not necessarily those that were told the right answer by the oracle) have intentionally given you the opposite answer to the one given to them by the oracle.

You are still suspiscious that the explanation given by the oracle is another lie. Given ints n, eggCount, lieCount and liarCount, find out if scenarios exist such that "The egg"  or "The chicken" is the correct answer. If there exist scenarios such that either answer is correct, return "Ambiguous" (quotes for clarity). If only one answer has a possible scenario, return "The egg" or "The chicken" (quotes for clarity) depending on the answer. If neither of the answers has a possible scenario, return "The oracle is a lie".

 


DEFINITION
Class:ChickenOracle
Method:theTruth
Parameters:int, int, int, int
Returns:string
Method signature:string theTruth(int n, int eggCount, int lieCount, int liarCount)


CONSTRAINTS
-n will be between 1 and 1000000, inclusive.
-eggCount, lieCount and liarCount will each be between 0 and n, inclusive. 


EXAMPLES

0)
10
10
0
0

Returns: "The egg"

In this case, every person has answered correctly.

1)
60
40
0
30

Returns: "The oracle is a lie"

According to the oracle, it has told the correct answer to all 60 people and then 30 of them lied to you. However, it contradicts the fact that 40 people have told you one answer and 20 people have told another one.

2)
60
20
5
25

Returns: "The chicken"



3)
1000
500
250
250

Returns: "Ambiguous"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; string Arg4 = "The egg"; verify_case(0, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 60; int Arg1 = 40; int Arg2 = 0; int Arg3 = 30; string Arg4 = "The oracle is a lie"; verify_case(1, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 60; int Arg1 = 20; int Arg2 = 5; int Arg3 = 25; string Arg4 = "The chicken"; verify_case(2, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 500; int Arg2 = 250; int Arg3 = 250; string Arg4 = "Ambiguous"; verify_case(3, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ChickenOracle test;

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
