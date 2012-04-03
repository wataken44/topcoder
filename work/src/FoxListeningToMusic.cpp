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

class FoxListeningToMusic {

 public:
  vector <double> getProbabilities(vector <int> length, int T)
  {
    int nSong = length.size();
    double p = 1.0 / nSong * 1.0;

    vector<double> dp(T+1, 0);
    dp[0] = 1.0;
    
    vector <double> result(nSong, 0);
    
    UPTO(t, 0, T) {
      TIMES(i, nSong) {
        int len = length[i];
        if(t + len <= T) {
          dp[t + len] += dp[t] * p;
        }
        if(t + len > T) {
          result[i] += dp[t] * p;
        }
      }
    }
    
    // -- main code --
    
    return result;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// Fox Jiro is going to listen to some music. He has N songs, numbered 0 to N-1, inclusive. The lengths of the songs are given in the vector <int> length, where the i-th element is the length in seconds of song i.

The music player he uses has a shuffle feature. Using this feature, he can listen to the songs in random order. More precisely, first the player chooses one song among all songs with equal probability and plays it. When the song ends, the player chooses the next song in the same fashion and plays it immediately. Note that the player may choose the same song more than once in a row.

You are given an int T. Return a double[] P, where P[i] indicates the probability that the player is playing the i-th song T+0.5 seconds after Jiro starts listening to the music in shuffle mode.

DEFINITION
Class:FoxListeningToMusic
Method:getProbabilities
Parameters:vector <int>, int
Returns:vector <double>
Method signature:vector <double> getProbabilities(vector <int> length, int T)


NOTES
-Each element of the returned array must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-length will contain 1 and 50 elements, inclusive.
-Each element of length will be between 1 and 80,001, inclusive.
-T will be between 0 and 80,000, inclusive.


EXAMPLES

0)
{1, 2}
1

Returns: {0.25, 0.75 }

There are three possible scenarios that lead up to time 1.5:

song 0 -> song 0 (with probability 1/4)
song 0 -> song 1 (with probability 1/4)
song 1 (with probability 1/2)



1)
{1, 10, 100, 1000, 10000}
0

Returns: {0.2, 0.2, 0.2, 0.2, 0.2 }



2)
{5, 8, 4, 7}
10

Returns: {0.1875, 0.3125, 0.1875, 0.3125 }



3)
{10, 1}
9

Returns: {0.9990234375, 9.765625E-4 }



4)
{58, 47, 36, 25, 14, 3}
100

Returns: {0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895, 0.07518634032025856, 0.017071269542683242 }



*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arr2[] = {0.25, 0.75 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 10, 100, 1000, 10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arr2[] = {0.2, 0.2, 0.2, 0.2, 0.2 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5, 8, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arr2[] = {0.1875, 0.3125, 0.1875, 0.3125 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; double Arr2[] = {0.9990234375, 9.765625E-4 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {58, 47, 36, 25, 14, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; double Arr2[] = {0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895, 0.07518634032025856, 0.017071269542683242 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getProbabilities(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  FoxListeningToMusic test;

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
