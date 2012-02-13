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

class BestResult {

 public:
  vector <int> findBestResult(vector <string> teams)
  {
    int sz = teams.size();

    vector< vector<int> > med(sz, vector<int>(3, 0));

    TIMES(k, sz) {
      istringstream iss(teams[k]);
      iss >> med[k][0] >> med[k][1] >> med[k][2];
    }
    
    

    
    vector <int> result;
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
The Olympic Games are over and now you need to rank the teams.  You must pick three integers Pg, Ps and Pb, representing the number of points awarded to each team for each gold, silver and bronze medal they won, respectively, where 1000 >= Pg >= Ps >= Pb >= 1.  The teams will be ranked according to the total number of points they have (teams with more points will be ranked higher).  You want to select Pg, Ps and Pb so that your team gets ranked as high as possible.


You will be given a vector <string> teams, the i-th element of which represents the medal counts of the i-th team.  Each element will be formatted as "G S B" (quotes for clarity), where G, S and B are integers representing the total number of gold, silver and bronze medals won by that team, respectively.  Your team is the 0-th team. The highest possible rank is 1, the second highest rank is 2, and so on.  If your team has the same number of total points as some other teams, your team will be ranked higher than those other teams.  In other words, your final ranking will be equal to 1 plus the number of teams that have a strictly greater number of points than your team.


Return a vector <int> containing exactly three elements - the values of Pg, Ps and Pb (in that order) that will give your team the highest ranking.  If there are multiple possible return values, return the one with the smallest value for Pg.  If there are still multiple return values, return the one with the smallest value for Ps. If there are still multiple return values, return the one with the smallest value for Pb.


DEFINITION
Class:BestResult
Method:findBestResult
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> findBestResult(vector <string> teams)


CONSTRAINTS
-Each element of teams will be formatted as "G S B" (quotes for clarity), where G, S and B are integers between 0 and 100000, inclusive, with no extra leading zeroes.
-teams will contain between 2 and 15 elements, inclusive.


EXAMPLES

0)
{"1 1 1", "0 1 2", "2 1 0"}

Returns: {1, 1, 1 }

In this example, your team has won 1 gold, 1 silver and 1 bronze.  There are multiple ways to get your team ranked number 1, but the best way is to assign 1 to Pg, Ps and Pb.  Every team gets 3 points, and your team gets ranked the highest.

1)
{"0 0 0", "1 1 1"}

Returns: {1, 1, 1 }

In this example, no matter what values you choose, your team will always be ranked second.

2)
{"0 1 2", "1 0 0", "0 0 4"}

Returns: {2, 2, 1 }



3)
{"0 3 0", "0 0 4", "3 0 0"}

Returns: {2, 2, 1 }



4)
{"24 0 0", "5 6 7", "5 45 5", "4 4 64"}

Returns: {4, 1, 1 }



5)
{ "1 2 0", "5 4 0", "3 0 1", "0 4 5", "2 3 4" }

Returns: {7, 1, 1 }



6)
{ "6 4 8", "2 0 4", "3 8 1", "0 6 5", "3 6 10", "5 6 7", "8 2 7" }

Returns: {3, 2, 2 }



7)
{ "7 8 5", "8 2 7", "3 10 0", "10 8 0", "5 2 7", "1 10 10", "9 7 1", "5 8 0" }


Returns: {3, 2, 2 }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 1 1", "0 1 2", "2 1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findBestResult(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 0 0", "1 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findBestResult(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 1 2", "1 0 0", "0 0 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findBestResult(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 3 0", "0 0 4", "3 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findBestResult(Arg0)); }
	void test_case_4() { string Arr0[] = {"24 0 0", "5 6 7", "5 45 5", "4 4 64"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findBestResult(Arg0)); }
	void test_case_5() { string Arr0[] = { "1 2 0", "5 4 0", "3 0 1", "0 4 5", "2 3 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findBestResult(Arg0)); }
	void test_case_6() { string Arr0[] = { "6 4 8", "2 0 4", "3 8 1", "0 6 5", "3 6 10", "5 6 7", "8 2 7" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, findBestResult(Arg0)); }
	void test_case_7() { string Arr0[] = { "7 8 5", "8 2 7", "3 10 0", "10 8 0", "5 2 7", "1 10 10", "9 7 1", "5 8 0" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(7, Arg1, findBestResult(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  BestResult test;

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
