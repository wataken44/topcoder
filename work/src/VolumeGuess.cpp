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

class VolumeGuess {

 public:
  int correctVolume(vector <string> queries, int numberOfBoxes, int ithBox)
  {
    // -- main code --

    vector<int> qbl;
    vector<int> qbr;
    vector<int> qbv;
    
    FOR(i, 0, queries.size()) {
      string q = queries[i];

      int k = 0;

      int bl = 0;
      while(q[k] != ',') {
        bl = bl * 10 + (q[k] - '0');
        ++k;
      }
      ++k;

      int br = 0;
      while(q[k] != ',') {
        br = br * 10 + (q[k] - '0');
        ++k;
      }
      ++k;

      int bv = 0;
      while(k != static_cast<int>(q.size())) {
        bv = bv * 10 + (q[k] - '0');
        ++k;
      }

      qbl.push_back(bl);
      qbr.push_back(br);
      qbv.push_back(bv);
    }

    // DUMP(qbl);DUMP(qbr);DUMP(qbv);

    vector<int> vol;

    FOR(m, 0, qbl.size()) {
      if(qbl[m] != ithBox && qbr[m] != ithBox) continue; 
      vol.push_back(qbv[m]);
    }

    sort(vol.begin(), vol.end());

    // DUMP(vol);

    FOR(n, 0, vol.size() - 1) {
      if(vol[n] == vol[n+1]) return vol[n];
    }
    
    return -1;	
  }

// BEGIN CUT HERE
  void debug()
  {
  }
/*
// PROBLEM STATEMENT
// You are given a certain number of boxes (numberOfBoxes) of different volumes. The boxes are numbered 1 to numberOfBoxes. After this, I then make comparisions between every pair of boxes and, for each pair, tell you the volume of the smaller box. Given this data, you have to tell me the size of the box numbered ithBox. (The box numbered ithBox will not be one of the two largest boxes.)  You are given a vector <string>, queries, each element of which describes a single comparision and is of the form "box1,box2,volume" (quotes for clarity) where box1 and box2 are the numbers of the two boxes being compared and volume is the volume of the smaller box.  For instance, if I compare the boxes numbered 5 and 6, which have volumes 10 and 99, respectively, the query will be represented as "5,6,10" (quotes for clarity).

DEFINITION
Class:VolumeGuess
Method:correctVolume
Parameters:vector <string>, int, int
Returns:int
Method signature:int correctVolume(vector <string> queries, int numberOfBoxes, int ithBox)


NOTES
-Keep in mind, the volume of the largest box is irrelevant.


CONSTRAINTS
-numberOfBoxes will be between 3 and 9, inclusive.
-queries will contain exactly numberOfBoxes*(numberOfBoxes-1)/2 elements.
-Every element of queries will be in the given format ("box1,box2,volume", quotes for clarity).
-Each element of queries will contain between 5 and 50 characters, inclusive.
-Each box1 will be an integer between 1 and numberOfBoxes, inclusive, with possible leading zeros.
-Each box2 will be an integer between 1 and numberOfBoxes, inclusive, with possible leading zeros.
-Each volume will be an integer between 1 and 500, inclusive, with possible leading zeros.
-queries will contain no duplicates, that is, no pair of boxes will be compared twice.
-No two boxes will have the same volume.
-ithBox will be between 1 and numberOfBoxes, inclusive.
-The given data will be consistent.
-The box numbered ithBox will not be one of the two largest boxes.


EXAMPLES

0)
{"1,2,10","1,3,10","2,3,20"}
3
1

Returns: 10

If box 1 has volume 10, box 2 has volume 20 and box 3 has volume 30, we get the given data.
Another possibility is box 1 has volume 10, box 2 has volume 30 and box 3 has volume 20.
Another is box 1 has volume 10, box 2 has volume 45 and box 3 has volume 20.

There are many possibilities (infinite in fact). However, in all of them box 1 has to have size 10.

1)
{"1,02,10","2,3,010","1,3,20"}
3
2

Returns: 10

If box 1 has volume 20, box 2 has volume 10 and box 3 has volume 30, we get the given data. (Note that leading zeros are allowed.)

2)
{"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}
4
1

Returns: 31

One possibility is box 1 has volume 31, box 2 has volume 50, box 3 has volume 9 and box 4 has volume 32.

3)
{"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}
4
3

Returns: 9

Same situation as above, but asks for a different ithbox.


*/
// END CUT HERE
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1,2,10","1,3,10","2,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 10; verify_case(0, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1,02,10","2,3,010","1,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 10; verify_case(1, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 31; verify_case(2, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 9; verify_case(3, Arg3, correctVolume(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(int argc, char *argv[])
{
  
  VolumeGuess test;

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
