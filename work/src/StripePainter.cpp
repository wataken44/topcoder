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

using namespace std;

class StripePainter {
  // BEGIN CUT HERE
  /*
  // PROBLEM STATEMENT
  // 
  Karel is a frustrated painter who works by day in an electrical repair
  shop.  Inspired by the color-coded bands on resistors, he is painting
  a series of long, narrow canvases with bold colored stripes.  However, 
  Karel is lazy and wants to minimize the number of brush strokes it takes 
  to paint each canvas.



  Abbreviating each color to a single uppercase letter, Karel would
  write the stripe pattern red-green-blue-green-red as "RGBGR" 
  (quotes added for clarity).  It would take him three brush strokes to
  paint this pattern.
  The first stroke would cover the entire canvas in red (RRRRR).
  The second stroke would leave a band of red on either side and fill
  in the rest with green (RGGGR).
  The final brush stroke would fill in the blue stripe in the center
  (RGBGR).



  Given a stripe pattern stripes as a string, calculate the minimum number of
  brush strokes required to paint that pattern.


  DEFINITION
  Class:StripePainter
  Method:minStrokes
  Parameters:string
  Returns:int
  Method signature:int minStrokes(string stripes)


  NOTES
  -The blank canvas is an ugly color and must not show through.


  CONSTRAINTS
  -stripes will contain only uppercase letters ('A'-'Z', inclusive).
  -stripes will contain between 1 and 50 characters, inclusive.


  EXAMPLES

  0)
  "RGBGR"

  Returns: 3

  Example from introduction.

  1)
  "RGRG"

  Returns: 3

  This example cannot be done in two strokes, even though there are only two colors.
  Suppose you tried to paint both red stripes in one stroke, followed by both green stripes 
  in one stroke.  Then the green stroke would cover up the second red stripe.  If you tried
  to paint both green stripes first, followed the red stripes, then the red stroke would
  cover up the first green stripe.

  2)
  "ABACADA"

  Returns: 4

  One long stroke in color 'A', followed by one stroke each in colors 'B', 'C', and 'D'.

  3)
  "AABBCCDDCCBBAABBCCDD"

  Returns: 7

  4)
  "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"

  Returns: 26

  */
  // END CUT HERE

 public:
  string work;

  typedef pair<int, int> pii;
  typedef pair<int, pii> pipii;
  typedef map<pipii, int> cache;

  cache ch;
  
  int minStrokes(string stripes) {
    // -- main code --

    work = stripes;

    int n = work.size();
    
    return go(0, n, ' ');	
  }

  int go(int i, int j, char b) {
    while(i < j and work[i] == b) {
      ++i;
    }
    while(i < j and work[j - 1] == b) {
      --j;
    }

    if(i == j) {
      return 0;
    }
    if(i + 1 == j) {
      return 1;
    }

    cache::iterator it = ch.find(pipii(i, pii(j, b)));

    if( it != ch.end() ) {
      return it-> second;
    }

    int& r = ch[pipii(i, pii(j, b))];
    r = INT_MAX;

    int k;
    for(k = i + 1; k < j; ++k) {
      r = min(r, go(i, k, b) + go(k, j, b));
    }
    k = 0;
    for(k = 'A'; k <= 'Z'; ++k) {
      r = min(r, 1 + go(i, j, k));
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGBGR"; int Arg1 = 3; verify_case(0, Arg1, minStrokes(Arg0)); }
	void test_case_1() { string Arg0 = "RGRG"; int Arg1 = 3; verify_case(1, Arg1, minStrokes(Arg0)); }
	void test_case_2() { string Arg0 = "ABACADA"; int Arg1 = 4; verify_case(2, Arg1, minStrokes(Arg0)); }
	void test_case_3() { string Arg0 = "AABBCCDDCCBBAABBCCDD"; int Arg1 = 7; verify_case(3, Arg1, minStrokes(Arg0)); }
	void test_case_4() { string Arg0 = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"; int Arg1 = 26; verify_case(4, Arg1, minStrokes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main()
{
  StripePainter test;
  test.run_test(-1);
  
  return 0;
}

// END CUT HERE
