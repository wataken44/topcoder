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

class Flush {

 public:
  double size(vector<int> suits, int number)
  {
    // -- main code --
    vector< map<int, double> > prob(number + 1); 

    const int mod = 16;
    
    int init = 0;
    DOWNTO(i, 3, 0) {
      init = init * mod + suits[i];
    }

    prob[0][init] = 1.0;

    UPTO(k, 1, number) {
      EACH(prob[k-1], it) {
        int ps = it->first;
        double pp = it->second;

        vector<int> s;
        int a = 0;
        TIMES(i, 4) {
          s.push_back(ps % mod);
          a += s.back();
          ps /= mod;
        }

        TIMES(i, 4) {
          if(s[i] == 0) continue;

          int ns = 0;
          DOWNTO(h, 3, 0) {
            if(h == i) {
              ns = ns * mod + s[h] - 1;
            }else {
              ns = ns * mod + s[h];
            }
          }
          if(prob[k].find(ns) == prob[k].end()) {
            prob[k][ns] = 0.0;
          }
          prob[k][ns] += pp * s[i] / a;
        }
      }
    }
    
    double result = 0;
    
    EACH(prob[number], it) {
      int ps = it->first;
      double pr = it->second;

      vector<int> s;

      TIMES(i, 4) {
        s.push_back(ps % mod);
        ps /= mod;
      }

      //DUMP(pr);
      //DUMP(s);
      
      int f = 0;
      TIMES(i, 4) {
        f = max(suits[i] - s[i], f);
      }
      result += pr * f;
    }
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are playing a card game in which large flushes, or sets of cards of the same suit, are beneficial. Your next move is to draw number cards: the larger the flush you get, the better. You wish to know the expected size of the largest flush in the cards you draw. The deck will consist of some number of cards of four suits, given as suits. The ith element of suits is the number of cards of that suit in the deck. Return a double, the expected size of the largest flush your hand will make.

The expected size of the largest flush is calculated as follows: For each possible hand, multiply the size of the largest flush in that hand by the probability of getting that hand. Then add all of these values together to get the expected size of the largest flush. For example, if half of the possible hands give you a flush of size 3, and the rest give you one of size 2, the expected value is (0.5 * 3) + (0.5 * 2) = 2.5.  Also, recall that there are n Choose k = n!/k!/(n-k)! ways to select k cards of one suit out of a total of n cards in that suit, where ! denotes the factorial operation.  Thus, if suits = {3,3,3,3}, then there are (3 Choose 3) * (3 Choose 2) * (3 Choose 1) * (3 Choose 0) = 1 * 3 * 3 * 1 = 9 ways to get 3 cards of the first suit, 2 of the second, 1 of the third, and none of the fourth.


DEFINITION
Class:Flush
Method:size
Parameters:vector <int>, int
Returns:double
Method signature:double size(vector <int> suits, int number)


NOTES
-Look out for overflow! A 32-bit datatype may not be large enough.
-Your return value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-suits will contain exactly four elements.
-Each element of suits is between 0 and 13, inclusive.
-number is between 0 and the sum of the elements of suits, inclusive.


EXAMPLES

0)
{2,2,2,2}
2

Returns: 1.1428571428571428

Draw the first card; you have a 1 out of 7 chance to draw the matching suit for your second card. The expected size is thus (1/7 * 2) + (6/7 * 1) = 8/7 = 1.1428571428571428.

1)
{1,4,7,10}
22

Returns: 10.0

You are drawing all of the cards, so your largest flush will be of size 10.

2)
{13, 13, 13, 13}
49

Returns: 13.0

If you get 12 cards of each suit, you must have drawn 48 cards, so drawing 49, 50, 51, or 52 cards must give you a flush of size 13.

3)
{13, 13, 13, 13}
26

Returns: 8.351195960938014

4)
{13,13,13,13}
0

Returns: 0.0

*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.1428571428571428; verify_case(0, Arg2, size(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; double Arg2 = 10.0; verify_case(1, Arg2, size(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; double Arg2 = 13.0; verify_case(2, Arg2, size(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; double Arg2 = 8.351195960938014; verify_case(3, Arg2, size(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13,13,13,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 0.0; verify_case(4, Arg2, size(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  Flush test;

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
