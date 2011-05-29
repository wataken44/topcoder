#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

typedef int int_type;

// -- utility --
// C-style loop
#define FOR(x, a, b) for(int_type x = static_cast<int_type>(a); x < static_cast<int_type>(b); ++x)
#define FORN(x, n) FOR(x, 0, n)
// Ruby-style loop
#define TIMES(x, n) FOR(x, 0, n)
#define STEP(x, a, b, s) for(int_type x = static_cast<int_type>(a); s > 0 ? x <= static_cast<int_type>(b) : x >= static_cast<int_type>(b); x += static_cast<int_type>(s) )
#define UPTO(x, a, b) for(int_type x = static_cast<int_type>(a); x <= static_cast<int_type>(b); ++x)
#define DOWNTO(x, a, b) for(int_type x = static_cast<int_type>(a); x >= static_cast<int_type>(b); --x)
// debug
#define DUMP(x) std::cerr << #x << " = " << x << std::endl;

using namespace std;

class CubeStickers {
 public:
  string isPossible(vector <string> sticker) {
    // -- main code --

    map<string, int> mp;
    TIMES(i, sticker.size()) {
      if(mp.find(sticker[i]) == mp.end()) {
        mp[sticker[i]] = 1;
      }else {
        mp[sticker[i]] += 1;
      }
    }

    vector<int> cnt;
    for(map<string, int>::iterator iter = mp.begin();
        iter != mp.end(); ++iter) {
      cnt.push_back(iter->second);
    }

    int rest = 6;
    TIMES(j, cnt.size()) {
      if(cnt[j] >= 2) rest -= 2;
      if(cnt[j] == 1) rest -= 1;
      if(rest <= 0) break;
    }
    
    return rest <= 0 ? "YES" : "NO";	
  }

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Fox Ciel has a cube and some colored stickers.  You are given a vector <string> sticker, where the i-th element is the color of the i-th sticker.  Ciel wants to choose six of these stickers and apply one on each of the cube's faces.  Each pair of adjacent faces must have different colors.  Two faces are considered adjacent if they share an edge.

If this is possible, return "YES", otherwise, return "NO" (all quotes for clarity).


DEFINITION
Class:CubeStickers
Method:isPossible
Parameters:vector <string>
Returns:string
Method signature:string isPossible(vector <string> sticker)


CONSTRAINTS
-sticker will contain between 6 and 50 elements, inclusive.
-Each element of sticker will contain between 1 and 10 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
{"cyan","magenta","yellow","purple","black","white","purple"}

Returns: "YES"

One of the possible ways is shown in the following picture:



1)
{"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}

Returns: "NO"



2)
{"red","yellow","blue","red","yellow","blue","red","yellow","blue"}

Returns: "YES"



3)
{"purple","orange","orange","purple","black","orange","purple"}

Returns: "NO"



4)
{"white","gray","green","blue","yellow","red","target","admin"}

Returns: "YES"



*/
// END CUT HERE

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"cyan","magenta","yellow","purple","black","white","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { string Arr0[] = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { string Arr0[] = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { string Arr0[] = {"purple","orange","orange","purple","black","orange","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { string Arr0[] = {"white","gray","green","blue","yellow","red","target","admin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, isPossible(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  CubeStickers test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
