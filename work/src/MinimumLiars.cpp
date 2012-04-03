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

class MinimumLiars {

 public:
  int getMinimum(vector <int> claim)
  {
    sort(claim.begin(), claim.end());

    int sz = claim.size();
    UPTO(i, 0, claim.back()) {
      int c = 0;
      TIMES(k, sz) {
        if(claim[k] > i) ++c;
      }
      if(c == i) return i;
    }
    
    int result = -1;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// There is a group of N people numbered from 0 to N-1. Each of them is either an honest person or a liar. You wish to know how many liars are in the group. To do this, you have asked the same question to every person in the group: "What is the number of liars in this group?". The people in the group themselves know the exact number of liars, but since you are a foreigner in the group, they have not told it to you exactly. Instead, the i-th person answered you as follows: "There are at least claim[i] liars in the group." It is known that statements by honest persons are always true. However, statements by liars are always false. So, if a liar claims that there are at least X liars in the group, then in fact there are less than X liars.

Now, given a vector <int> claim containing the N answers that you received, you would like to determine the number of liars in the group. Unfortunately, there's another twist that makes this problem more complicated.  The people in the group speak a different language than you, so you might have misunderstood some of their answers.  The answers in claim are how you understood them, but they might not match what the people actually told you. If you definitely misunderstood at least one of the answers, return -1. Otherwise, assuming that you understood all answers correctly, return the minimum number of liars that could be in the group.


DEFINITION
Class:MinimumLiars
Method:getMinimum
Parameters:vector <int>
Returns:int
Method signature:int getMinimum(vector <int> claim)


CONSTRAINTS
-claim will contain between 2 and 50 elements, inclusive.
-Each element of claim will be between 0 and 100, inclusive.


EXAMPLES

0)
{1,1,1,2}

Returns: 1

It would be impossible for all the members of the group to be honest because in that case, all of their answers would be 0. It is, however, possible that only the last person is a liar and each of the first three persons is honest. Therefore the correct answer is 1.

1)
{7,8,1}

Returns: 2

The first two people claim that there are at least 7 and 8 liars, respectively, which is impossible as the group only has three people. Thus, they must be lying. The third person claims there is at least one liar, and this is definitely true since we have already identified two liars, so this person is honest.

2)
{5,5,5,5,5}

Returns: -1

Everybody agrees that there are at least 5 liars in the group. The group contains exactly 5 people, so in fact all of them claim that everybody is a liar. We can't assume that some person is honest because this person definitely wouldn't have claimed him/herself as being a liar. We also can't assume that all of them are liars because in this case it will appear that all their statements are true. Every scenario we can try leads to a contradiction, so you must have misunderstood at least one of the answers.

3)
{0,0,0,4,3,0}

Returns: 2



4)
{4,7,5}

Returns: 3

Every claim made is impossible. Therefore all three people in the group must be lying. 

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = {7,8,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = {5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,0,4,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { int Arr0[] = {4,7,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  MinimumLiars test;

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
