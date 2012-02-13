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

class DividingIntoTeams {

 public:
  string findYourTeam(vector <int> alexFriends, vector <int> bobFriends, vector <int> charlieFriends, int k)
  {

    int sz = alexFriends.size();
    vector<bool> choose(sz+1, false);
    choose[0] = true;

    int cnt = 0;
    
    while(true) {
      if(cnt == sz) break;
      TIMES(a, sz) {
        int ac = alexFriends[a];
        if(choose[ac] == false) {
          choose[ac] = true;
          if(ac == k) {
            return "Alex";
          }
          ++cnt;
          break;
        }
      }
      if(cnt == sz) break;
      TIMES(a, sz) {
        int ac = bobFriends[a];
        if(choose[ac] == false) {
          choose[ac] = true;
          if(ac == k) {
            return "Bob";
          }
          ++cnt;
          break;
        }
      }
      if(cnt == sz) break;
      TIMES(a, sz) {
        int ac = charlieFriends[a];
        if(choose[ac] == false) {
          choose[ac] = true;
          if(ac == k) {
            return "Charlie";
          }
          ++cnt;
          break;
        }
      }

    }
    
    string result;
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// 
You want to form three teams from your friends.  You have selected Alex, Bob and Charlie to be the captains of the first, second and third teams, respectively.  You have n other friends, and you have numbered them from 1 to n.


You are given three vector <int>s, alexFriends, bobFriends and charlieFriends, representing the relations between the three captains and the other n friends.  Each vector <int> contains exactly n elements, and is sorted in descending order by preference.  The first element is the number of the captain's best friend - the person he would most want on his team.  The last element is the number of the captain's worst friend - the person he would least want on his team.


The captains will pick their teams as follows.  Alex selects a person, then Bob selects a person, then Charlie selects a person, and then the process continues starting from Alex again.  The process ends after all the people have been selected.  Each person can be selected only once.  During each captain's turn, he will select the person he wants most among the people who have not yet been selected.  Given an int k, return the name of the captain ("Alex", "Bob" or "Charlie", quotes for clarity) who will select person numbered k.


DEFINITION
Class:DividingIntoTeams
Method:findYourTeam
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:string
Method signature:string findYourTeam(vector <int> alexFriends, vector <int> bobFriends, vector <int> charlieFriends, int k)


CONSTRAINTS
-alexFriends, bobFriends and charlieFriends will each contain between 1 and 50 elements, inclusive.
-Each element of alexFriends, bobFriends and charlieFriends will be between 1 and n, inclusive, where n is the number of elements in alexFriends.
-All elements of alexFriends will be distinct.
-All elements of bobFriends will be distinct.
-All elements of charlieFriends will be distinct.
-k will be between 1 and n, inclusive.


EXAMPLES

0)
{1, 2, 3}
{1, 2, 3}
{1, 2, 3}
3

Returns: "Charlie"

In this case Alex selects friend with number 1, Bob - with number 2 and Charlie - with number 3. All the people have been selected, so the process ends.

1)
{1, 2, 3, 5, 4}
{3, 2, 1, 4, 5}
{2, 1, 5, 3, 4}
2

Returns: "Charlie"

In the first captain's turn
Alex selects friend with number 1, Bob - with number 3 and Charlie - with number 2.
In the second turn
Alex selects friend with number 5, Bob - with number 4. All the people have been selected, so the process ends.
 

2)
{1, 2, 3, 4, 5}
{1, 3, 5, 4, 2}
{5, 4, 3, 2, 1}
4

Returns: "Bob"



3)
{1}
{1}
{1}
1

Returns: "Alex"



4)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
{1, 8, 9, 4, 5, 6, 7, 3, 2, 10}
{9, 10, 8, 4, 5, 7, 6, 1, 2, 3}
4

Returns: "Bob"



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; string Arg4 = "Charlie"; verify_case(0, Arg4, findYourTeam(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 5, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 1, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 5, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "Charlie"; verify_case(1, Arg4, findYourTeam(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 5, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 4, 3, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; string Arg4 = "Bob"; verify_case(2, Arg4, findYourTeam(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; string Arg4 = "Alex"; verify_case(3, Arg4, findYourTeam(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 8, 9, 4, 5, 6, 7, 3, 2, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 10, 8, 4, 5, 7, 6, 1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; string Arg4 = "Bob"; verify_case(4, Arg4, findYourTeam(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  DividingIntoTeams test;

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
