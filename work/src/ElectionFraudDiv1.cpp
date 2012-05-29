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

class ElectionFraudDiv1 {

 public:
  int near(double d)
  {
    return (int)floor(d + 0.5);
  }
  
  int MinimumVoters(vector <int> per)
  {
    sort(per.begin(), per.end());

    int sum = 0;
    int sz = per.size();

    TIMES(i, sz) {
      sum += per[i];
    }

    if(sum * 2 - sz > 200 || sum * 2 + sz <= 200) {
      return -1;
    }

    
    vector<int> cand;
    for(int a = 1; a <= 100000; ++a) {
      vector<double> nl(sz, 0.0);
      vector<double> nu(sz, 0.0);

      TIMES(i, sz) {
        nl[i] = max(0.0, (per[i] - 0.5) / 100.0 * a);
        nu[i] = (per[i] + 0.5) / 100.0 * a;
      }

      // DUMP(a);
      // DUMP(nl);
      // DUMP(nu);
      
      bool ok = true;

      int minsum = 0;
      int maxsum = 0;

      TIMES(i, sz) {
        if(floor(nl[i] - 1e-9) < floor(nu[i] - 1e-9)) {
          minsum += ceil(nl[i] - 1e-9);
          maxsum += floor(nu[i] - 1e-9);
        }else {
          ok = false;
          break;
        }
      }
      // DUMP(minsum);
      // DUMP(maxsum);
      if(!ok) continue;
      if(a < minsum || a > maxsum) continue;
      return a;
    }

    sort(cand.begin(), cand.end());

    //DUMP(cand);
    
    return cand.empty() ? -1 : cand[0];	
  }

  template<typename T>
  T gcd(T a, T b)
  {
    if(a > b) swap(a, b);
    while(a != 0) {
      T t = b % a;
      b = a;
      a = t;
    }
    return b;
  }


// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// In a normal election, one expects the percentages received by each of the candidates to sum to exactly 100 percent.  There are two ways this might not be the case: if the election is fraudulent, or if the reported percentages are rounded.
For example, in an election with 3 voters and 3 candidates, if each voter chooses a different candidate the final percentages would be reported as 33, 33, 33, which only sum to 99.  Conversely, in an election with 7 voters and 3 candidates, if the candidates receive 2, 2, and 3 votes, respectively, the final percentages would be reported as 29, 29, and 43, which sum to 101.
The ministry of voting wants you to help them determine if an election was run fairly or not.  You'll be given a vector <int> percentages, giving the percentage of the vote that went to each candidate, rounded to the nearest whole number (in the case a number lies halfway between 2 consecutive integers, it will be rounded up).  If the election could be legitimate, return the minimum number of voters that could have participated in this election.  If the election is definitely fraudulent, return -1.

DEFINITION
Class:ElectionFraudDiv1
Method:MinimumVoters
Parameters:vector <int>
Returns:int
Method signature:int MinimumVoters(vector <int> percentages)


NOTES
-You may assume that whenever the election may be legitimate, the smallest possible number of voters will fit into a int.


CONSTRAINTS
-percentages will contain between 1 and 50 elements, inclusive.
-Each element of percentages will be between 0 and 100, inclusive.


EXAMPLES

0)
{33, 33, 33}

Returns: 3

The first example from the problem statement.

1)
{29, 29, 43}

Returns: 7

The second example from the problem statement.

2)
{12, 12, 12, 12, 12, 12, 12, 12}

Returns: -1

These results are impossible.

3)
{13, 13, 13, 13, 13, 13, 13, 13}

Returns: 8



4)
{0, 1, 100}

Returns: 200

The only possibility is that the candidates received 0, 1, and 199 votes, respectively.

5)
{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}

Returns: 97



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {33, 33, 33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, MinimumVoters(Arg0)); }
	void test_case_1() { int Arr0[] = {29, 29, 43}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, MinimumVoters(Arg0)); }
	void test_case_2() { int Arr0[] = {12, 12, 12, 12, 12, 12, 12, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, MinimumVoters(Arg0)); }
	void test_case_3() { int Arr0[] = {13, 13, 13, 13, 13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, MinimumVoters(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; verify_case(4, Arg1, MinimumVoters(Arg0)); }
	void test_case_5() { int Arr0[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 97; verify_case(5, Arg1, MinimumVoters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  ElectionFraudDiv1 test;

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
